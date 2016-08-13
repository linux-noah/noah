#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

#include "common.h"
#include "sandbox.h"

#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>
#include <Hypervisor/hv_arch_vmx.h>

#include "x86/page.h"
#include "x86/segment.h"
#include "x86/idt.h"
#include "x86/msr.h"
#include "vmem.h"

hv_vcpuid_t vcpuid;

uint64_t (*pml4)[NR_PAGE_ENTRY];
static int phys_addr_bit_num = 39;

uint64_t
to_vmpa(void *haddr)
{
  uint64_t vmpaddr = ((1ULL << phys_addr_bit_num) - 1) & (uint64_t)haddr;
  // Assert truncated bits are all "1"
  assert(((uint64_t)haddr >> phys_addr_bit_num) == ((1ULL << (47 - phys_addr_bit_num)) - 1));

  return vmpaddr;
}

void*
to_haddrp(uint64_t vmpaddr)
{
  // Assume the bits over max phys bits are all 1.
  // Write serious "kalloc" after introducing multi-process model
  return (void*)(vmpaddr | (CANONICAL_LOWER_END ^ ((1ULL << phys_addr_bit_num) - 1)));
}

void*
kalloc(size_t size)
{
  void *mem;
  uint64_t vmpaddr;

  mem = valloc(size);
  if (mem == NULL) {
    PRINTF("could not valloc requested size: %ld\n", size);
    exit(1);
  }
  if (!(((uint64_t)mem >> phys_addr_bit_num) == ((1ULL << (47 - phys_addr_bit_num)) - 1))) {
    // If truncated bits are not all 1, fill them
    mem = mmap((void*)(0x7f8000000000 | (uint64_t)mem), size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_FIXED | MAP_SHARED | MAP_ANON, -1, 0);
    if (mem == NULL) {
      PRINTF("could not mmap requested area\n");
      exit(1);
    }
  }
  vmpaddr = to_vmpa(mem);
  hv_return_t ret = hv_vm_map(mem, vmpaddr, size, HV_MEMORY_READ | HV_MEMORY_WRITE | HV_MEMORY_EXEC);
  if (ret != HV_SUCCESS) {
    PRINTF("mapping %p to 0x%016llx, size:0x%lx\n", mem, vmpaddr, size);
    PRINTF("could not map a memory region: error code %x\n", ret);
    exit(1);
  }
  return mem;
}

uint64_t
rounddown(uint64_t x, uint64_t y)
{
  return x / y * y;
}

uint64_t
roundup(uint64_t x, uint64_t y)
{
  return (x + y - 1) / y * y;
}

void
vm_map_rec(int depth, uint64_t (*table)[NR_PAGE_ENTRY], uint64_t vmvaddr, uint64_t vmpaddr, page_type_t page_type, int perm)
{
  page_type_t walking = PAGE_PML4E - depth;
  int index = (vmvaddr >> PAGE_SHIFT(walking)) & 0x1ff;

  if (walking == page_type) {
    perm |= (page_type == PAGE_4KB) ? 0 : PTE_PS;
    (*table)[index] = rounddown(vmpaddr, PAGE_SIZE(page_type)) | perm;
  } else {
    uint64_t (*next)[NR_PAGE_ENTRY];
    if (!(*table)[index]) {
      next = kalloc(sizeof(uint64_t[NR_PAGE_ENTRY]));
      bzero(next, sizeof(uint64_t[NR_PAGE_ENTRY]));
      (*table)[index] = to_vmpa(next) | perm;
    } else {
      next = to_haddrp(rounddown((*table)[index], PAGE_SIZE(PAGE_4KB)));
    }
    vm_map_rec(depth + 1, next, vmvaddr, vmpaddr, page_type, perm);
  }
}

void
vm_map(uint64_t vmvaddr, uint64_t vmpaddr, size_t size, page_type_t page_type, int perm)
{
  uint64_t offset = vmvaddr - rounddown(vmvaddr, PAGE_SIZE(page_type));
  int page_num = roundup(size + offset, PAGE_SIZE(page_type)) / PAGE_SIZE(page_type);
  for (int i = 0; i < page_num; i++) {
    vm_map_rec(0, pml4, vmvaddr - offset, vmpaddr - offset, page_type, perm);
    vmvaddr += PAGE_SIZE(page_type);
    vmpaddr += PAGE_SIZE(page_type);
  }
}

bool
vm_walk_rec(int depth, uint64_t (*table)[NR_PAGE_ENTRY], uint64_t vmvaddr, uint64_t *vmpaddr, uint64_t *perm)
{
  page_type_t walking = PAGE_PML4E - depth;
  uint64_t pt_entry = (*table)[(vmvaddr >> PAGE_SHIFT(walking)) & 0x1ff];

  if (pt_entry & PTE_P) {
    if (walking == PAGE_4KB || (pt_entry & PTE_PS)) {
      uint64_t mask = (1 << PAGE_SHIFT(walking)) - 1;
      if (vmpaddr != NULL) {
        *vmpaddr = (pt_entry & ~mask) + (vmvaddr & mask);
      }
      if (perm != NULL) {
        *perm = pt_entry & mask;
      }
      return true;
    } else {
      return vm_walk_rec(depth + 1, to_haddrp(rounddown(pt_entry, PAGE_SIZE(PAGE_4KB))), vmvaddr, vmpaddr, perm);
    }
  }
  return false;
}

bool
vm_walk(uint64_t vmvaddr, uint64_t *vmpaddr, uint64_t *perm)
{
  return vm_walk_rec(0, pml4, vmvaddr, vmpaddr, perm);
}

void *
copy_from_user(const void *vmvaddr)
{
  uint64_t str_paddr;
  bool suc = vm_walk((uint64_t) vmvaddr, &str_paddr, NULL);
  if (!suc) {
    return NULL;
  }
  return to_haddrp(str_paddr);
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

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_PIN_BASED, cap2ctrl(vmx_cap_pinbased, 0));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CPU_BASED, cap2ctrl(vmx_cap_procbased,
                                                 CPU_BASED_HLT |
                                                 CPU_BASED_CR8_LOAD |
                                                 CPU_BASED_CR8_STORE));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CPU_BASED2, cap2ctrl(vmx_cap_procbased2, 0));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_VMENTRY_CONTROLS,  cap2ctrl(vmx_cap_entry,
                                                 VMENTRY_LOAD_EFER |
                                                 VMENTRY_GUEST_IA32E));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_VMEXIT_CONTROLS, cap2ctrl(vmx_cap_exit, VMEXIT_LOAD_EFER));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_EXC_BITMAP, 0xffffffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CR0_SHADOW, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CR4_MASK, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CR4_SHADOW, 0);
}

void
init_page()
{
  pml4 = kalloc(sizeof(uint64_t[NR_PAGE_ENTRY]));
  bzero(pml4, sizeof(uint64_t[NR_PAGE_ENTRY]));
  vm_map(KERN_BASE, 0, UINT64_MAX - KERN_BASE, PAGE_1GB, PTE_W | PTE_P);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CR0, CR0_PG | CR0_PE | CR0_NE);

  uint64_t cr4;
  hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_CR4, &cr4);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CR4, cr4 | CR4_PAE | CR4_VMXE);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CR3, to_vmpa(pml4));
  
  uint64_t efer;
  hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_IA32_EFER, &efer);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_IA32_EFER, efer | EFER_LME | EFER_LMA);
}

void
init_segment()
{
  uint64_t gdt[3];
  gdt[SEG_NULL] = 0; // NULL SEL
  gdt[SEG_CODE] = 0x0020980000000000; // CODE SEL
  gdt[SEG_DATA] = 0x0000900000000000; // DATA SEL

  void *mem = kalloc(sizeof gdt);

  memcpy(mem, &gdt, sizeof gdt);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GDTR_BASE, to_vmpa(mem));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GDTR_LIMIT, 3 * 8 - 1);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_TR_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_TR_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_TR_AR, 0x0000008b);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_LDTR_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_LDTR_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_LDTR_AR, DESC_UNUSABLE);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_IDTR_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_IDTR_LIMIT, 0xffff);

  uint32_t codeseg_ar = 0x0000209B;
  uint32_t dataseg_ar = 0x00000093;
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CS_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CS_AR, codeseg_ar);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_DS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_DS_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_DS_AR, dataseg_ar);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_ES, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_ES_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_ES_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_ES_AR, dataseg_ar);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS_AR, dataseg_ar);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS_AR, dataseg_ar);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_SS, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_SS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_SS_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_SS_AR, dataseg_ar);

  hv_vcpu_write_register(vcpuid, HV_X86_CS, GSEL(SEG_CODE, 0));
  hv_vcpu_write_register(vcpuid, HV_X86_DS, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(vcpuid, HV_X86_ES, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(vcpuid, HV_X86_FS, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(vcpuid, HV_X86_GS, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(vcpuid, HV_X86_SS, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(vcpuid, HV_X86_TR, 0);
  hv_vcpu_write_register(vcpuid, HV_X86_LDTR, 0);
}

void
init_idt()
{
  struct gate_desc (*idt)[256] = kalloc(sizeof(struct gate_desc[256]));

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_IDTR_BASE, to_vmpa(idt));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_IDTR_LIMIT, sizeof idt);
}

void
init_regs()
{
  /* set up cpu regs */
  hv_vcpu_write_register(vcpuid, HV_X86_RFLAGS, 0x2);
}

void
init_msr()
{
  if (hv_vcpu_enable_native_msr(vcpuid, MSR_TIME_STAMP_COUNTER, 1) == HV_SUCCESS && 
      hv_vcpu_enable_native_msr(vcpuid, MSR_TSC_AUX, 1) == HV_SUCCESS &&
      hv_vcpu_enable_native_msr(vcpuid, MSR_KERNEL_GS_BASE, 1) == HV_SUCCESS) { // MSR_KGSBASE must be set properly later
    PRINTF("MSR initialization failed.\n");
  }
}

void
create_sandbox()
{
  hv_return_t ret;

  ret = hv_vm_create(HV_VM_DEFAULT);
  if (ret != HV_SUCCESS) {
    PRINTF("could not create the vm: error code %x", ret);
    return;
  }

  PUTS("successfully created the vm");

  ret = hv_vcpu_create(&vcpuid, HV_VCPU_DEFAULT);
  if (ret != HV_SUCCESS) {
    PRINTF("could not create a vcpu: error code %x", ret);
    return;
  }

  PUTS("successfully created a vcpu");

  init_vmcs();
  init_msr();
  init_page();
  init_segment();
  init_idt();
  init_regs();
}

void
destroy_sandbox()
{
  hv_return_t ret;

  ret = hv_vcpu_destroy(vcpuid);
  if (ret != HV_SUCCESS) {
    PRINTF("could not destroy the vcpu: error code %x", ret);
    return;
  }

  PUTS("successfully destroyed the vcpu");

  ret = hv_vm_destroy();
  if (ret != HV_SUCCESS) {
    PRINTF("could not destroy the vm: error code %x", ret);
    return;
  }

  PUTS("successfully destroyed the vm");
}

void
print_regs()
{
  uint64_t value;

  hv_vcpu_read_register(vcpuid, HV_X86_RAX, &value);
  PRINTF("rax = 0x%llx\n", value);
  hv_vcpu_read_register(vcpuid, HV_X86_RBX, &value);
  PRINTF("rbx = 0x%llx\n", value);
  hv_vcpu_read_register(vcpuid, HV_X86_RCX, &value);
  PRINTF("rcx = 0x%llx\n", value);
  hv_vcpu_read_register(vcpuid, HV_X86_RDX, &value);
  PRINTF("rdx = 0x%llx\n", value);
  hv_vcpu_read_register(vcpuid, HV_X86_RDI, &value);
  PRINTF("rdi = 0x%llx\n", value);
  hv_vcpu_read_register(vcpuid, HV_X86_RSI, &value);
  PRINTF("rsi = 0x%llx\n", value);
  hv_vcpu_read_register(vcpuid, HV_X86_RBP, &value);
  PRINTF("rbp = 0x%llx\n", value);
}
