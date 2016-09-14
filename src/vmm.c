#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>

#include "noah.h"
#include "vmm.h"
#include "util/list.h"

#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>
#include <Hypervisor/hv_arch_vmx.h>

#include "x86/specialreg.h"
#include "x86/page.h"
#include "x86/segment.h"
#include "x86/idt.h"
#include "x86/msr.h"
#include "x86/vmemparam.h"
#include "x86/vmx.h"


void
record_region(void *haddr, gaddr_t gaddr, size_t size, int prot)
{
  struct list_head *list, *t;
  struct mm_region *region, *r;

  region = malloc(sizeof *region);
  region->haddr = haddr;
  region->gaddr = gaddr;
  region->size = size;
  region->prot = prot;

  if (list_empty(&proc.mm->mm_regions)) { /* fast path */
    list_add(&region->list, &proc.mm->mm_regions);
    return;
  }
  /* unmap */
  list_for_each_safe (list, t, &proc.mm->mm_regions) {
    r = list_entry(list, struct mm_region, list);
    if (gaddr + size <= r->gaddr)
      break;
    if (r->gaddr + r->size <= gaddr)
      continue;
    list_del(list);
    if (gaddr <= r->gaddr && r->gaddr + r->size <= gaddr + size) {
      free(r);
      continue;
    }
    /* split r */
    if (r->gaddr < gaddr) {
      struct mm_region *s = malloc(sizeof *s);
      s->haddr = r->haddr;
      s->gaddr = r->gaddr;
      s->size = gaddr - r->gaddr;
      s->prot = prot;
      list_add(&s->list, list->prev);
    }
    if (gaddr + size < r->gaddr + r->size) {
      uint64_t offset = gaddr + size - r->gaddr;
      struct mm_region *s = malloc(sizeof *s);
      s->haddr = (char *) r->haddr + offset;
      s->gaddr = r->gaddr + offset;
      s->size = r->size - offset;
      s->prot = prot;
      list_add_tail(&s->list, list->next);
    }
  }
  /* map */
  gaddr_t prev = 0;
  list_for_each (list, &proc.mm->mm_regions) {
    r = list_entry(list, struct mm_region, list);
    if (prev <= gaddr && gaddr + size <= r->gaddr) {
      list_add(&region->list, list->prev);
      return;
    }
    prev = r->gaddr + r->size;
  }
  list_add_tail(&region->list, list);
}

void
page_map_help(uint64_t *table, uint64_t haddr, uint64_t gaddr, uint64_t perm)
{
  uint64_t index, entry;
  int shift;

  assert((gaddr & (1ul << 47)) == 0); /* FIXME */

  for (shift = 39; shift > 12; shift -= 9) {
    index = (gaddr >> shift) & 0x1ff;
    entry = table[index];
    if ((entry & PTE_P) == 0) {
      void *ptr = valloc(4096);
      bzero(ptr, 4096);
      table[index] = (uint64_t) ptr & 0x000ffffffffff000ul;
      table[index] |= perm;
    }
    table = (void *)(table[index] & 0x000ffffffffff000ul);
  }
  index = (gaddr >> shift) & 0x1ff;
  entry = table[index];
  table[index] = (haddr & 0x000ffffffffff000ul) | perm;
}

void
vmm_mmap(gaddr_t gaddr, size_t size, int prot, void *haddr)
{
  assert(((uint64_t) haddr & 0xfff) == 0);
  assert((gaddr & 0xfff) == 0);

  size = roundup(size, PAGE_SIZE(PAGE_4KB));

  hv_vm_unmap(gaddr, size);
  if (hv_vm_map(haddr, gaddr, size, prot) != HV_SUCCESS) {
    fprintf(stderr, "hv_vm_map failed\n");
    exit(1);
  }
  record_region(haddr, gaddr, size, prot);

  ulong perm = PTE_U | PTE_P;
  if (prot & HV_MEMORY_WRITE) perm |= PTE_W;
  if ((prot & HV_MEMORY_EXEC) == 0) perm |= PTE_NX;

  for (uint64_t i = 0; i < size / 0x1000; i++) {
    page_map_help(proc.mm->ept, (uint64_t) haddr, gaddr, perm);
    page_map_help(proc.mm->rept, gaddr, (uint64_t) haddr, perm);
    haddr = (char *) haddr + 0x1000;
    gaddr += 0x1000;
  }
}

bool
page_walk(uint64_t *table, uint64_t addr, uint64_t *res, uint64_t *perm)
{
  uint64_t entry, mask;
  int shift;

  for (shift = 39; ; shift -= 9) {
    entry = table[(addr >> shift) & 0x1ff];
    if ((entry & PTE_P) == 0)
      goto fail;
    if ((entry & PTE_PS) != 0 || shift == 12)
      goto hit;
    table = (void *)(entry & 0x000ffffffffff000);
  }

 hit:
  mask = (1ul << shift) - 1;
  if (res != NULL) {
    assert((entry & (1ul << 47)) == 0); /* FIXME */
    *res = (entry & 0x000ffffffffff000) + (addr & mask);
  }
  if (perm != NULL) {
    *perm = entry & mask;
  }
  return true;

 fail:
  return false;
}

void *
guest_to_host(gaddr_t gaddr)
{
  uint64_t haddr;
  if (! page_walk(proc.mm->ept, gaddr, &haddr, NULL)) {
    return NULL;
  }
  return (void *) haddr;
}

gaddr_t
host_to_guest(void *haddr)
{
  uint64_t gaddr;
  if (! page_walk(proc.mm->rept, (uint64_t) haddr, &gaddr, NULL)) {
    return 0;
  }
  return gaddr;
}

void
init_vmcs()
{
  uint64_t vmx_cap_pinbased, vmx_cap_procbased, vmx_cap_procbased2, vmx_cap_entry, vmx_cap_exit;

  hv_vmx_read_capability(HV_VMX_CAP_PINBASED, &vmx_cap_pinbased);
  hv_vmx_read_capability(HV_VMX_CAP_PROCBASED, &vmx_cap_procbased);
  hv_vmx_read_capability(HV_VMX_CAP_PROCBASED2, &vmx_cap_procbased2);
  hv_vmx_read_capability(HV_VMX_CAP_ENTRY, &vmx_cap_entry);
  hv_vmx_read_capability(HV_VMX_CAP_EXIT, &vmx_cap_exit);

  /* set up vmcs misc */

#define cap2ctrl(cap,ctrl) (((ctrl) | ((cap) & 0xffffffff)) & ((cap) >> 32))

  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_CTRL_PIN_BASED, cap2ctrl(vmx_cap_pinbased, 0));
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_CTRL_CPU_BASED, cap2ctrl(vmx_cap_procbased,
                                                 CPU_BASED_HLT |
                                                 CPU_BASED_CR8_LOAD |
                                                 CPU_BASED_CR8_STORE));
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_CTRL_CPU_BASED2, cap2ctrl(vmx_cap_procbased2, 0));
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_CTRL_VMENTRY_CONTROLS,  cap2ctrl(vmx_cap_entry,
                                                 VMENTRY_LOAD_EFER |
                                                 VMENTRY_GUEST_IA32E));
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_CTRL_VMEXIT_CONTROLS, cap2ctrl(vmx_cap_exit, VMEXIT_LOAD_EFER));
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_CTRL_EXC_BITMAP, 0xffffffff);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_CTRL_CR0_SHADOW, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_CTRL_CR4_MASK, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_CTRL_CR4_SHADOW, 0);
}

#define __page_aligned __attribute__((aligned(0x1000)))

static gaddr_t
kmap(void *ptr, size_t size, hv_memory_flags_t flags)
{
  static uint64_t noah_kern_brk = 0x0000007fc0000000ULL;

  assert((size & 0xfff) == 0);
  assert(((uint64_t) ptr & 0xfff) == 0);

  vmm_mmap(noah_kern_brk, size, flags, ptr);

  noah_kern_brk += size;

  return noah_kern_brk - size;
}

uint64_t pml4[NR_PAGE_ENTRY] __page_aligned = {
  [0] = PTE_U | PTE_W | PTE_P,
};

uint64_t pdp[NR_PAGE_ENTRY] __page_aligned = {
  /* straight mapping */
#include "vmm_pdp.h"
};

void
init_page()
{
  kmap(pml4, 0x1000, HV_MEMORY_READ | HV_MEMORY_WRITE);
  pml4[0] |= kmap(pdp, 0x1000, HV_MEMORY_READ | HV_MEMORY_WRITE) & 0x000ffffffffff000ul;

  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_CR0, CR0_PG | CR0_PE | CR0_NE);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_CR3, host_to_guest(pml4));
}

void
init_special_regs()
{
  uint64_t cr4;
  hv_vmx_vcpu_read_vmcs(task->vcpuid, VMCS_GUEST_CR4, &cr4);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_CR4, cr4 | CR4_PAE | CR4_OSFXSR | CR4_VMXE);

  uint64_t efer;
  hv_vmx_vcpu_read_vmcs(task->vcpuid, VMCS_GUEST_IA32_EFER, &efer);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_IA32_EFER, efer | EFER_LME | EFER_LMA);
}

uint64_t gdt[3] __page_aligned = {
  [SEG_NULL] = 0,                  // NULL SEL
  [SEG_CODE] = 0x0020980000000000, // CODE SEL
  [SEG_DATA] = 0x0000900000000000, // DATA SEL
};

void
init_segment()
{
  kmap(gdt, 0x1000, HV_MEMORY_READ | HV_MEMORY_WRITE);

  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_GDTR_BASE, host_to_guest(gdt));
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_GDTR_LIMIT, 3 * 8 - 1);

  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_TR_BASE, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_TR_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_TR_AR, 0x0000008b);

  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_LDTR_BASE, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_LDTR_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_LDTR_AR, DESC_UNUSABLE);

  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_IDTR_BASE, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_IDTR_LIMIT, 0xffff);

  uint32_t codeseg_ar = 0x0000209B;
  uint32_t dataseg_ar = 0x00000093;
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_CS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_CS_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_CS_AR, codeseg_ar);

  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_DS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_DS_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_DS_AR, dataseg_ar);

  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_ES, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_ES_BASE, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_ES_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_ES_AR, dataseg_ar);

  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_FS, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_FS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_FS_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_FS_AR, dataseg_ar);

  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_GS, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_GS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_GS_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_GS_AR, dataseg_ar);

  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_SS, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_SS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_SS_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_SS_AR, dataseg_ar);

  hv_vcpu_write_register(task->vcpuid, HV_X86_CS, GSEL(SEG_CODE, 0));
  hv_vcpu_write_register(task->vcpuid, HV_X86_DS, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(task->vcpuid, HV_X86_ES, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(task->vcpuid, HV_X86_FS, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(task->vcpuid, HV_X86_GS, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(task->vcpuid, HV_X86_SS, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(task->vcpuid, HV_X86_TR, 0);
  hv_vcpu_write_register(task->vcpuid, HV_X86_LDTR, 0);
}

struct gate_desc idt[256] __page_aligned;

void
init_idt()
{
  kmap(idt, 0x1000, HV_MEMORY_READ | HV_MEMORY_WRITE);

  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_IDTR_BASE, host_to_guest(idt));
  hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_IDTR_LIMIT, sizeof idt);
}

void
init_regs()
{
  /* set up cpu regs */
  hv_vcpu_write_register(task->vcpuid, HV_X86_RFLAGS, 0x2);
}

void
init_msr()
{
  if (hv_vcpu_enable_native_msr(task->vcpuid, MSR_TIME_STAMP_COUNTER, 1) == HV_SUCCESS &&
      hv_vcpu_enable_native_msr(task->vcpuid, MSR_TSC_AUX, 1) == HV_SUCCESS &&
      hv_vcpu_enable_native_msr(task->vcpuid, MSR_KERNEL_GS_BASE, 1) == HV_SUCCESS) { // MSR_KGSBASE must be set properly later
    printk("MSR initialization failed.\n");
  }
}

void
vmm_create()
{
  hv_return_t ret;

  ret = hv_vm_create(HV_VM_DEFAULT);
  if (ret != HV_SUCCESS) {
    printk("could not create the vm: error code %x", ret);
    return;
  }

  printk("successfully created the vm\n");

  task = malloc(sizeof(struct task));
  bzero(task, sizeof(struct task));

  ret = hv_vcpu_create(&task->vcpuid, HV_VCPU_DEFAULT);
  if (ret != HV_SUCCESS) {
    printk("could not create a vcpu: error code %x", ret);
    return;
  }

  printk("successfully created a vcpu\n");

  proc.mm = malloc(sizeof(struct mm));
  pthread_rwlock_init(&proc.alloc_lock, NULL);
  INIT_LIST_HEAD(&proc.mm->mm_regions);
  INIT_LIST_HEAD(&proc.tasks);
  list_add(&task->tasks, &proc.tasks);
  proc.nr_tasks = 1;

  init_vmcs();
  init_msr();
  init_page();
  init_special_regs();
  init_segment();
  init_idt();
  init_regs();
}

void
vmm_destroy()
{
  hv_return_t ret;

  struct task *t;
  list_for_each_entry (t, &proc.tasks, tasks) {
    ret = hv_vcpu_destroy(t->vcpuid);
    if (ret != HV_SUCCESS) {
      printk("could not destroy the vcpu: error code %x", ret);
      exit(1);
    }
  }

  printk("successfully destroyed the vcpu\n");

  ret = hv_vm_destroy();
  if (ret != HV_SUCCESS) {
    printk("could not destroy the vm: error code %x", ret);
    exit(1);
  }

  printk("successfully destroyed the vm\n");
}

void
print_regs()
{
  uint64_t value;

  hv_vcpu_read_register(task->vcpuid, HV_X86_RIP, &value);
  printk("\trip = 0x%llx\n", value);
  hv_vcpu_read_register(task->vcpuid, HV_X86_RAX, &value);
  printk("\trax = 0x%llx\n", value);
  hv_vcpu_read_register(task->vcpuid, HV_X86_RBX, &value);
  printk("\trbx = 0x%llx\n", value);
  hv_vcpu_read_register(task->vcpuid, HV_X86_RCX, &value);
  printk("\trcx = 0x%llx\n", value);
  hv_vcpu_read_register(task->vcpuid, HV_X86_RDX, &value);
  printk("\trdx = 0x%llx\n", value);
  hv_vcpu_read_register(task->vcpuid, HV_X86_RDI, &value);
  printk("\trdi = 0x%llx\n", value);
  hv_vcpu_read_register(task->vcpuid, HV_X86_RSI, &value);
  printk("\trsi = 0x%llx\n", value);
  hv_vcpu_read_register(task->vcpuid, HV_X86_RBP, &value);
  printk("\trbp = 0x%llx\n", value);
}

void
dump_instr()
{
  uint64_t instlen, rip;
  hv_vmx_vcpu_read_vmcs(task->vcpuid, VMCS_RO_VMEXIT_INSTR_LEN, &instlen);
  hv_vcpu_read_register(task->vcpuid, HV_X86_RIP, &rip);
  char inst_str[instlen * 3 + 1];
  for (int i = 0; i < instlen; i ++) {
    sprintf(inst_str + 3 * i, "%02x ", *((uchar*)guest_to_host(rip) + i));
  }
  inst_str[instlen * 3] = '\0';
  printk("len: %lld, instruction: %s\n", instlen, inst_str);
}

void
vcpu_snapshot(struct vcpu_snapshot *snapshot)
{
  /* snapshot registers */
  for (uint64_t i = 0; i < NR_X86_REG_LIST; i++) {
    if (hv_vcpu_read_register(task->vcpuid, x86_reg_list[i], &snapshot->vcpu_reg[i]) != HV_SUCCESS) {
      printk("store_regs failed\n");
      return;
    }
  }
  /* snapshot vmcs */
  for (uint64_t i = 0; i < NR_VMCS_FIELD; i++) {
    uint64_t success = hv_vmx_vcpu_read_vmcs(task->vcpuid, vmcs_field_list[i], &snapshot->vmcs[i]);
    if (success != HV_SUCCESS) {
      printk("store_vmcs failed\n");
      return;
    }
  }
}

void
vmm_snapshot(struct vm_snapshot *snapshot)
{
  printk("vmm_snapshot\n");

  pthread_rwlock_rdlock(&proc.alloc_lock);

  if (proc.nr_tasks > 1) {
    fprintf(stderr, "multi-threaded fork is not implemented yet.\n");
    exit(1);
  }

  vcpu_snapshot(&snapshot->first_vcpu_snapshot);

  pthread_rwlock_unlock(&proc.alloc_lock);
}

void
vcpu_restore(struct vcpu_snapshot *snapshot)
{
  /* restore vmcs */
  static const uint32_t restore_mask[] = {
    VMCS_VPID,
    VMCS_HOST_ES,
    VMCS_HOST_CS,
    VMCS_HOST_SS,
    VMCS_HOST_DS,
    VMCS_HOST_FS,
    VMCS_HOST_GS,
    VMCS_HOST_TR,
    VMCS_HOST_IA32_PAT,
    VMCS_HOST_IA32_EFER,
    VMCS_HOST_IA32_PERF_GLOBAL_CTRL,
    VMCS_GUEST_PHYSICAL_ADDRESS,
    VMCS_RO_INSTR_ERROR,
    VMCS_RO_EXIT_REASON,
    VMCS_RO_VMEXIT_IRQ_INFO,
    VMCS_RO_VMEXIT_IRQ_ERROR,
    VMCS_RO_IDT_VECTOR_INFO,
    VMCS_RO_IDT_VECTOR_ERROR,
    VMCS_RO_VMEXIT_INSTR_LEN,
    VMCS_RO_VMX_INSTR_INFO,
    VMCS_RO_EXIT_QUALIFIC,
    VMCS_RO_IO_RCX,
    VMCS_RO_IO_RSI,
    VMCS_RO_IO_RDI,
    VMCS_RO_IO_RIP,
    VMCS_RO_GUEST_LIN_ADDR,
    VMCS_HOST_CR0,
    VMCS_HOST_CR3,
    VMCS_HOST_CR4,
    VMCS_HOST_FS_BASE,
    VMCS_HOST_GS_BASE,
    VMCS_HOST_TR_BASE,
    VMCS_HOST_GDTR_BASE,
    VMCS_HOST_IDTR_BASE,
    VMCS_HOST_IA32_SYSENTER_ESP,
    VMCS_HOST_IA32_SYSENTER_EIP,
    VMCS_HOST_RSP,
    VMCS_HOST_RIP,
  };

  for (uint64_t i = 0; i < NR_VMCS_FIELD; i++) {
    for (uint64_t j = 0; j < sizeof restore_mask / sizeof restore_mask[0]; j++) {
      if (restore_mask[j] == vmcs_field_list[i]) {
        goto cont;
      }
    }
    uint64_t success = hv_vmx_vcpu_write_vmcs(task->vcpuid, vmcs_field_list[i], snapshot->vmcs[i]);
    if (success != HV_SUCCESS) {
      printk("restore vmcs failed, %s\n", vmcs_field_str[i]);
    }
cont: ;
  }

  /* restore registers */
  for (uint64_t i = 0; i < NR_X86_REG_LIST; i++) {
    if (hv_vcpu_write_register(task->vcpuid, x86_reg_list[i], snapshot->vcpu_reg[i]) != HV_SUCCESS) {
      printk("restore regs failed\n");
      return;
    }
  }

  /* restore MSRs. Initializing them is enough now */
  init_msr();
}

bool
restore_ept()
{
  struct list_head *list;

  list_for_each (list, &proc.mm->mm_regions) {
    struct mm_region *p = list_entry(list, struct mm_region, list);
    if (hv_vm_map(p->haddr, p->gaddr, p->size, p->prot) != HV_SUCCESS)
      return false;
  }
  return true;
}

void
vmm_reentry(struct vm_snapshot *snapshot)
{
  hv_return_t ret;

  printk("vmm_restore\n");
  ret = hv_vm_create(HV_VM_DEFAULT);
  if (ret != HV_SUCCESS) {
    printk("could not create the vm: error code %x", ret);
    return;
  }
  printk("successfully created vm\n");

  pthread_rwlock_rdlock(&proc.alloc_lock);

  if (proc.nr_tasks > 1) {
    fprintf(stderr, "multi-threaded fork is not implemented yet.\n");
    exit(1);
  }

  ret = hv_vcpu_create(&task->vcpuid, HV_VCPU_DEFAULT);
  if (ret != HV_SUCCESS) {
    printk("could not create a vcpu: error code %x", ret);
    return;
  }
  vcpu_restore(&snapshot->first_vcpu_snapshot);

  pthread_rwlock_unlock(&proc.alloc_lock);
  printk("vcpu_restore done\n");

  restore_ept();
  printk("ept_restore done\n");

}
