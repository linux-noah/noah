#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>
#include <libgen.h>
#include <sys/syslimits.h>

#include "linux/mman.h"

#include "vmm.h"
#include "mm.h"
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

struct vcpu {
  struct list_head list;
  hv_vcpuid_t vcpuid;
};

struct list_head vcpus;
int nr_vcpus;
pthread_rwlock_t alloc_lock;

uint64_t va_map[NR_PAGE_ENTRY], rva_map[NR_PAGE_ENTRY];

_Thread_local static struct vcpu *vcpu;

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
  assert(is_page_aligned(haddr, PAGE_4KB));
  assert(is_page_aligned((void *) gaddr, PAGE_4KB));
  assert(is_page_aligned((void *) size, PAGE_4KB));

  hv_vm_unmap(gaddr, size);
  if (hv_vm_map(haddr, gaddr, size, prot) != HV_SUCCESS) {
    fprintf(stderr, "hv_vm_map failed\n");
    exit(1);
  }

  ulong perm = PTE_U | PTE_P;
  if (prot & HV_MEMORY_WRITE) perm |= PTE_W;
  if ((prot & HV_MEMORY_EXEC) == 0) perm |= PTE_NX;

  for (uint64_t i = 0; i < size / 0x1000; i++) {
    page_map_help(va_map, (uint64_t) haddr, gaddr, perm);
    page_map_help(rva_map, gaddr, (uint64_t) haddr, perm);
    haddr = (char *) haddr + 0x1000;
    gaddr += 0x1000;
  }
}

void
vmm_munmap(gaddr_t gaddr, size_t size)
{
  assert(is_page_aligned((void *) size, PAGE_4KB));

  hv_vm_unmap(gaddr, size);
  for (uint64_t i = 0; i < size / PAGE_SIZE(PAGE_4KB); i++) {
    page_map_help(va_map, 0, gaddr, 0);
    page_map_help(rva_map, gaddr, 0, 0);
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
  if (! page_walk(va_map, gaddr, &haddr, NULL)) {
    return NULL;
  }
  return (void *) haddr;
}

gaddr_t
host_to_guest(void *haddr)
{
  uint64_t gaddr;
  if (! page_walk(rva_map, (uint64_t) haddr, &gaddr, NULL)) {
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

  vmm_write_vmcs(VMCS_CTRL_PIN_BASED, cap2ctrl(vmx_cap_pinbased, 0));
  vmm_write_vmcs(VMCS_CTRL_CPU_BASED, cap2ctrl(vmx_cap_procbased,
                                               CPU_BASED_HLT |
                                               CPU_BASED_CR8_LOAD |
                                               CPU_BASED_CR8_STORE));
  vmm_write_vmcs(VMCS_CTRL_CPU_BASED2, cap2ctrl(vmx_cap_procbased2, 0));
  vmm_write_vmcs(VMCS_CTRL_VMENTRY_CONTROLS,  cap2ctrl(vmx_cap_entry,
                                                       VMENTRY_LOAD_EFER |
                                                       VMENTRY_GUEST_IA32E));
  vmm_write_vmcs(VMCS_CTRL_VMEXIT_CONTROLS, cap2ctrl(vmx_cap_exit, VMEXIT_LOAD_EFER));
  vmm_write_vmcs(VMCS_CTRL_EXC_BITMAP, 0xffffffff);
  vmm_write_vmcs(VMCS_CTRL_CR0_SHADOW, 0);
  vmm_write_vmcs(VMCS_CTRL_CR4_MASK, 0);
  vmm_write_vmcs(VMCS_CTRL_CR4_SHADOW, 0);
}

#define __page_aligned __attribute__((aligned(0x1000)))

static gaddr_t
kmap(void *ptr, size_t size, hv_memory_flags_t flags)
{
  static uint64_t noah_kern_brk = 0x0000007fc0000000ULL;

  assert((size & 0xfff) == 0);
  assert(((uint64_t) ptr & 0xfff) == 0);

  pthread_rwlock_wrlock(&vkern_mm.alloc_lock);

  record_region(&vkern_mm, ptr, noah_kern_brk, size, hv_mflag_to_linux_mprot(flags), -1, -1, 0);
  vmm_mmap(noah_kern_brk, size, flags, ptr);
  noah_kern_brk += size;

  pthread_rwlock_unlock(&vkern_mm.alloc_lock);

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

  vmm_write_vmcs(VMCS_GUEST_CR0, CR0_PG | CR0_PE | CR0_NE);
  vmm_write_vmcs(VMCS_GUEST_CR3, host_to_guest(pml4));
}

void
init_special_regs()
{
  uint64_t cr0;
  vmm_read_vmcs(VMCS_GUEST_CR0, &cr0);
  vmm_write_vmcs(VMCS_GUEST_CR0, (cr0 & ~CR0_EM) | CR0_MP);

  uint64_t cr4;
  vmm_read_vmcs(VMCS_GUEST_CR4, &cr4);
  vmm_write_vmcs(VMCS_GUEST_CR4, cr4 | CR4_PAE | CR4_OSFXSR | CR4_OSXMMEXCPT | CR4_VMXE | CR4_OSXSAVE);

  uint64_t efer;
  vmm_read_vmcs(VMCS_GUEST_IA32_EFER, &efer);
  vmm_write_vmcs(VMCS_GUEST_IA32_EFER, efer | EFER_LME | EFER_LMA);
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

  vmm_write_vmcs(VMCS_GUEST_GDTR_BASE, host_to_guest(gdt));
  vmm_write_vmcs(VMCS_GUEST_GDTR_LIMIT, 3 * 8 - 1);

  vmm_write_vmcs(VMCS_GUEST_TR_BASE, 0);
  vmm_write_vmcs(VMCS_GUEST_TR_LIMIT, 0);
  vmm_write_vmcs(VMCS_GUEST_TR_AR, 0x0000008b);

  vmm_write_vmcs(VMCS_GUEST_LDTR_BASE, 0);
  vmm_write_vmcs(VMCS_GUEST_LDTR_LIMIT, 0);
  vmm_write_vmcs(VMCS_GUEST_LDTR_AR, DESC_UNUSABLE);

  vmm_write_vmcs(VMCS_GUEST_IDTR_BASE, 0);
  vmm_write_vmcs(VMCS_GUEST_IDTR_LIMIT, 0xffff);

  uint32_t codeseg_ar = 0x0000209B;
  uint32_t dataseg_ar = 0x00000093;
  vmm_write_vmcs(VMCS_GUEST_CS_BASE, 0);
  vmm_write_vmcs(VMCS_GUEST_CS_LIMIT, 0);
  vmm_write_vmcs(VMCS_GUEST_CS_AR, codeseg_ar);

  vmm_write_vmcs(VMCS_GUEST_DS_BASE, 0);
  vmm_write_vmcs(VMCS_GUEST_DS_LIMIT, 0);
  vmm_write_vmcs(VMCS_GUEST_DS_AR, dataseg_ar);

  vmm_write_vmcs(VMCS_GUEST_ES, 0);
  vmm_write_vmcs(VMCS_GUEST_ES_BASE, 0);
  vmm_write_vmcs(VMCS_GUEST_ES_LIMIT, 0);
  vmm_write_vmcs(VMCS_GUEST_ES_AR, dataseg_ar);

  vmm_write_vmcs(VMCS_GUEST_FS, 0);
  vmm_write_vmcs(VMCS_GUEST_FS_BASE, 0);
  vmm_write_vmcs(VMCS_GUEST_FS_LIMIT, 0);
  vmm_write_vmcs(VMCS_GUEST_FS_AR, dataseg_ar);

  vmm_write_vmcs(VMCS_GUEST_GS, 0);
  vmm_write_vmcs(VMCS_GUEST_GS_BASE, 0);
  vmm_write_vmcs(VMCS_GUEST_GS_LIMIT, 0);
  vmm_write_vmcs(VMCS_GUEST_GS_AR, dataseg_ar);

  vmm_write_vmcs(VMCS_GUEST_SS, 0);
  vmm_write_vmcs(VMCS_GUEST_SS_BASE, 0);
  vmm_write_vmcs(VMCS_GUEST_SS_LIMIT, 0);
  vmm_write_vmcs(VMCS_GUEST_SS_AR, dataseg_ar);

  vmm_write_register(HV_X86_CS, GSEL(SEG_CODE, 0));
  vmm_write_register(HV_X86_DS, GSEL(SEG_DATA, 0));
  vmm_write_register(HV_X86_ES, GSEL(SEG_DATA, 0));
  vmm_write_register(HV_X86_FS, GSEL(SEG_DATA, 0));
  vmm_write_register(HV_X86_GS, GSEL(SEG_DATA, 0));
  vmm_write_register(HV_X86_SS, GSEL(SEG_DATA, 0));
  vmm_write_register(HV_X86_TR, 0);
  vmm_write_register(HV_X86_LDTR, 0);
}

struct gate_desc idt[256] __page_aligned;

void
init_idt()
{
  kmap(idt, 0x1000, HV_MEMORY_READ | HV_MEMORY_WRITE);

  vmm_write_vmcs(VMCS_GUEST_IDTR_BASE, host_to_guest(idt));
  vmm_write_vmcs(VMCS_GUEST_IDTR_LIMIT, sizeof idt);
}

void
init_regs()
{
  /* set up cpu regs */
  vmm_write_register(HV_X86_RFLAGS, 0x2);
}

void
init_msr()
{
  if (hv_vcpu_enable_native_msr(vcpu->vcpuid, MSR_TIME_STAMP_COUNTER, 1) == HV_SUCCESS &&
      hv_vcpu_enable_native_msr(vcpu->vcpuid, MSR_TSC_AUX, 1) == HV_SUCCESS &&
      hv_vcpu_enable_native_msr(vcpu->vcpuid, MSR_KERNEL_GS_BASE, 1) == HV_SUCCESS) { // MSR_KGSBASE must be set properly later
    printk("MSR initialization failed.\n");
  }
}

void
init_fpu()
{
  struct fxregs_state {
    uint16_t cwd; /* Control Word                    */
    uint16_t swd; /* Status Word                     */
    uint16_t twd; /* Tag Word                        */
    uint16_t fop; /* Last Instruction Opcode         */
    union {
      struct {
        uint64_t rip; /* Instruction Pointer             */
        uint64_t rdp; /* Data Pointer                    */
      };
      struct {
        uint32_t fip; /* FPU IP Offset                   */
        uint32_t fcs; /* FPU IP Selector                 */
        uint32_t foo; /* FPU Operand Offset              */
        uint32_t fos; /* FPU Operand Selector            */
      };
    };
    uint32_t mxcsr;       /* MXCSR Register State */
    uint32_t mxcsr_mask;  /* MXCSR Mask           */
    uint32_t st_space[32]; /* 8*16 bytes for each FP-reg = 128 bytes */
    uint32_t xmm_space[64]; /* 16*16 bytes for each XMM-reg = 256 bytes */
    uint32_t __padding[12];
    union {
      uint32_t __padding1[12];
      uint32_t sw_reserved[12];
    };
  } __attribute__((aligned(16))) fx;

  /* emulate 'fninit'
   * - http://www.felixcloutier.com/x86/FINIT:FNINIT.html
   */
  fx.cwd = 0x037f;
  fx.swd = 0;
  fx.twd = 0xffff;
  fx.fop = 0;
  fx.rip = 0;
  fx.rdp = 0;

  /* default configuration for the SIMD core */
  fx.mxcsr = 0x1f80;
  fx.mxcsr_mask = 0;

  hv_vcpu_write_fpstate(vcpu->vcpuid, &fx, sizeof fx);
}

void
vmm_create()
{
  hv_return_t ret;

  /* initialize global variables */
  pthread_rwlock_init(&alloc_lock, NULL);
  INIT_LIST_HEAD(&vcpus);
  nr_vcpus = 0;

  /* create the VM */
  ret = hv_vm_create(HV_VM_DEFAULT);
  if (ret != HV_SUCCESS) {
    printk("could not create the vm: error code %x", ret);
    return;
  }

  printk("successfully created the vm\n");

  vmm_create_vcpu(NULL);

  printk("successfully created a vcpu\n");
}

void
vmm_destroy()
{
  hv_return_t ret;

  struct vcpu *vcpu;
  list_for_each_entry (vcpu, &vcpus, list) {
    ret = hv_vcpu_destroy(vcpu->vcpuid);
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
vmm_create_vcpu(struct vcpu_snapshot *snapshot)
{
  hv_return_t ret;
  hv_vcpuid_t vcpuid;

  ret = hv_vcpu_create(&vcpuid, HV_VCPU_DEFAULT);
  if (ret != HV_SUCCESS) {
    printk("could not create a vcpu: error code %x", ret);
    return;
  }

  assert(vcpu == NULL);

  vcpu = calloc(sizeof(struct vcpu), 1);
  vcpu->vcpuid = vcpuid;

  if (snapshot) {
    vmm_restore_vcpu(snapshot);
  }

  pthread_rwlock_wrlock(&alloc_lock);
  list_add(&vcpu->list, &vcpus);
  nr_vcpus++;
  pthread_rwlock_unlock(&alloc_lock);
}

void
vmm_destroy_vcpu(void)
{
  pthread_rwlock_wrlock(&alloc_lock);
  list_del(&vcpu->list);
  nr_vcpus--;
  hv_vcpu_destroy(vcpu->vcpuid);
  free(vcpu);
  vcpu = NULL;
  pthread_rwlock_unlock(&alloc_lock);
}

void
print_regs()
{
  uint64_t value;

  vmm_read_register(HV_X86_RIP, &value);
  printk("\trip = 0x%llx\n", value);
  vmm_read_register(HV_X86_RAX, &value);
  printk("\trax = 0x%llx\n", value);
  vmm_read_register(HV_X86_RBX, &value);
  printk("\trbx = 0x%llx\n", value);
  vmm_read_register(HV_X86_RCX, &value);
  printk("\trcx = 0x%llx\n", value);
  vmm_read_register(HV_X86_RDX, &value);
  printk("\trdx = 0x%llx\n", value);
  vmm_read_register(HV_X86_RDI, &value);
  printk("\trdi = 0x%llx\n", value);
  vmm_read_register(HV_X86_RSI, &value);
  printk("\trsi = 0x%llx\n", value);
  vmm_read_register(HV_X86_RBP, &value);
  printk("\trbp = 0x%llx\n", value);
}

void
dump_instr()
{
  uint64_t instlen, rip;
  vmm_read_vmcs(VMCS_RO_VMEXIT_INSTR_LEN, &instlen);
  vmm_read_register(HV_X86_RIP, &rip);
  char inst_str[instlen * 3 + 1];
  for (size_t i = 0; i < instlen; i ++) {
    unsigned char *ip = guest_to_host(rip);
    if (ip) {
      sprintf(inst_str + 3 * i, "%02x ", ip[i]);
    } else {
      printk("rip is in invalid user address: 0x%016llx\n", rip);
      volatile int raise_segv = ip[i]; // Raise segmentation fault in host
      return;
    }
  }
  inst_str[instlen * 3] = '\0';
  printk("len: %lld, instruction: %s\n", instlen, inst_str);
}

void
vmm_snapshot_vcpu(struct vcpu_snapshot *snapshot)
{
  /* snapshot registers */
  for (uint64_t i = 0; i < NR_X86_REG_LIST; i++) {
    vmm_read_register(x86_reg_list[i], &snapshot->vcpu_reg[i]);
  }
  /* snapshot vmcs */
  for (uint64_t i = 0; i < NR_VMCS_FIELD; i++) {
    vmm_read_vmcs(vmcs_field_list[i], &snapshot->vmcs[i]);
  }
  hv_vcpu_read_fpstate(vcpu->vcpuid, snapshot->fpu_states, sizeof snapshot->fpu_states);
}

void
vmm_snapshot(struct vmm_snapshot *snapshot)
{
  printk("vmm_snapshot\n");

  pthread_rwlock_rdlock(&alloc_lock);

  if (nr_vcpus > 1) {
    fprintf(stderr, "multi-threaded fork is not implemented yet.\n");
    exit(1);
  }

  vmm_snapshot_vcpu(&snapshot->first_vcpu_snapshot);

  pthread_rwlock_unlock(&alloc_lock);
}

void
vmm_restore_vcpu(struct vcpu_snapshot *snapshot)
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
    vmm_write_vmcs(vmcs_field_list[i], snapshot->vmcs[i]);
cont: ;
  }

  /* restore registers */
  for (uint64_t i = 0; i < NR_X86_REG_LIST; i++) {
    vmm_write_register(x86_reg_list[i], snapshot->vcpu_reg[i]);
  }

  /* restore fpu states */
  hv_vcpu_write_fpstate(vcpu->vcpuid, snapshot->fpu_states, sizeof snapshot->fpu_states);

  /* restore MSRs. Initializing them is enough now */
  init_msr();
}

bool
restore_ept()
{
  struct list_head *list;

  list_for_each (list, &vkern_mm.mm_regions) {
    struct mm_region *p = list_entry(list, struct mm_region, list);
    if (hv_vm_map(p->haddr, p->gaddr, p->size, linux_mprot_to_hv_mflag(p->prot)) != HV_SUCCESS)
      return false;
  }
  list_for_each (list, &proc.mm->mm_regions) {
    struct mm_region *p = list_entry(list, struct mm_region, list);
    if (hv_vm_map(p->haddr, p->gaddr, p->size, linux_mprot_to_hv_mflag(p->prot)) != HV_SUCCESS)
      return false;
  }
  return true;
}

void
vmm_reentry(struct vmm_snapshot *snapshot)
{
  hv_return_t ret;

  printk("vmm_restore\n");
  ret = hv_vm_create(HV_VM_DEFAULT);
  if (ret != HV_SUCCESS) {
    printk("could not create the vm: error code %x", ret);
    return;
  }
  printk("successfully created vm\n");

  pthread_rwlock_rdlock(&alloc_lock);

  if (nr_vcpus > 1) {
    fprintf(stderr, "multi-threaded fork is not implemented yet.\n");
    exit(1);
  }

  ret = hv_vcpu_create(&vcpu->vcpuid, HV_VCPU_DEFAULT);
  if (ret != HV_SUCCESS) {
    printk("could not create a vcpu: error code %x", ret);
    return;
  }
  vmm_restore_vcpu(&snapshot->first_vcpu_snapshot);

  pthread_rwlock_unlock(&alloc_lock);
  printk("vcpu_restore done\n");

  restore_ept();
  printk("ept_restore done\n");

}

void
vmm_read_register(hv_x86_reg_t reg, uint64_t *val)
{
  if (hv_vcpu_read_register(vcpu->vcpuid, reg, val) != HV_SUCCESS) {
    fprintf(stderr, "read_register failed\n");
    abort();
  }
}

void
vmm_write_register(hv_x86_reg_t reg, uint64_t val) {
  if (hv_vcpu_write_register(vcpu->vcpuid, reg, val) != HV_SUCCESS) {
    fprintf(stderr, "write_register failed\n");
    abort();
  }
}

void
vmm_read_msr(hv_x86_reg_t reg, uint64_t *val)
{
  if (hv_vcpu_read_msr(vcpu->vcpuid, reg, val) != HV_SUCCESS) {
    fprintf(stderr, "read_msr failed\n");
    abort();
  }
}

void
vmm_write_msr(hv_x86_reg_t reg, uint64_t val) {
  if (hv_vcpu_write_msr(vcpu->vcpuid, reg, val) != HV_SUCCESS) {
    fprintf(stderr, "write_msr failed\n");
    abort();
  }
}

void
vmm_read_vmcs(hv_x86_reg_t field, uint64_t *val)
{
  if (hv_vmx_vcpu_read_vmcs(vcpu->vcpuid, field, val) != HV_SUCCESS) {
    fprintf(stderr, "read_vmcs failed\n");
    abort();
  }
}

void
vmm_write_vmcs(hv_x86_reg_t field, uint64_t val) {
  if (hv_vmx_vcpu_write_vmcs(vcpu->vcpuid, field, val) != HV_SUCCESS) {
    /* FIXME! it fails for the VMCS_CTRL_TSC_OFFSET field on some platforms */
    //fprintf(stderr, "write_vmcs failed: %s\n", vmcs_field_to_str(field));
    //    abort();
  }
}

int
vmm_run()
{
  if (hv_vcpu_run(vcpu->vcpuid) == HV_SUCCESS) {
    return 0;
  }
  return -1;
}
