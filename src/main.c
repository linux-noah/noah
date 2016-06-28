#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>
#include <Hypervisor/hv_arch_vmx.h>

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

#include "page.h"
#include "segment.h"
#include "idt.h"
#include "elf.h"
#include "msr.h"
#include "debug.h"

void
init_vmcs(hv_vcpuid_t vcpuid)
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
init_page(hv_vcpuid_t vcpuid, uint64_t pgdir_addr, uint64_t max_size)
{
  if (max_size < 0x4000) {
    PRINTF("memory region is too short for page initialization\n");
    return;
  }

  void *mem = valloc(0x4000);

  // Map [0x0, 0x200000] to [0x0, 0x200000]
  bzero(mem, 0x4000);
  assert(sizeof (uint64_t[512]) == 0x1000);
  uint64_t (*lv4_pg_map)[512] = mem;
  uint64_t (*pdp)[512] = (void*)((char*)mem + 0x1000);
  uint64_t (*pg)[512] = (void*)((char*)mem + 0x2000);
  uint64_t (*pt)[512] = (void*)((char*)mem + 0x3000);

  (*lv4_pg_map)[0] = (uint64_t) (pgdir_addr + 0x1000) | PTE_P | PTE_W | PTE_U;
  (*pdp)[0] = (uint64_t) (pgdir_addr + 0x2000) | PTE_P | PTE_W | PTE_U;
  (*pg)[0] = (uint64_t) (pgdir_addr + 0x3000) | PTE_P | PTE_W | PTE_U;
  for (int i = 0; i < 512; i++) {
      (*pt)[i] = (uint64_t) (0x1000 * i) | PTE_P | PTE_W | PTE_U;
  }

  hv_return_t ret = hv_vm_map(mem, pgdir_addr, 0x4000, HV_MEMORY_READ | HV_MEMORY_WRITE | HV_MEMORY_EXEC);
  if (ret != HV_SUCCESS) {
    PRINTF("could not map a page map region: error code %x", ret);
    return;
  }

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CR0, CR0_PG | CR0_PE | CR0_NE);

  uint64_t cr4;
  hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_CR4, &cr4);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CR4, cr4 | CR4_PAE | CR4_VMXE);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CR3, pgdir_addr);
  
  uint64_t efer;
  hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_IA32_EFER, &efer);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_IA32_EFER, efer | EFER_LME | EFER_LMA);
}

void
init_segment(hv_vcpuid_t vcpuid, uint64_t gdt_addr, uint64_t max_size)
{
  uint64_t gdt[3];
  gdt[SEG_NULL] = 0; // NULL SEL
  gdt[SEG_CODE] = 0x0020980000000000; // CODE SEL
  gdt[SEG_DATA] = 0x0000900000000000; // DATA SEL

  if (max_size < sizeof gdt) {
    PRINTF("memory region is too short for segment initialization\n");
    return;
  }

  void *mem = valloc(sizeof gdt);

  memcpy(mem, &gdt, sizeof gdt);

  hv_return_t ret = hv_vm_map(mem, gdt_addr, sizeof gdt, HV_MEMORY_READ | HV_MEMORY_WRITE | HV_MEMORY_EXEC);
  if (ret != HV_SUCCESS) {
    PRINTF("could not map a gdt region: error code %x", ret);
    return;
  }

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GDTR_BASE, gdt_addr);
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

struct gate_desc idt[256];

void
init_idt(hv_vcpuid_t vcpuid, uint64_t idt_addr, uint64_t max_size)
{
  if (max_size < sizeof idt) {
    PRINTF("memory region is too short for idt initialization\n");
    return;
  }

  hv_return_t ret = hv_vm_map(idt, idt_addr, sizeof idt, HV_MEMORY_READ | HV_MEMORY_WRITE | HV_MEMORY_EXEC);
  if (ret != HV_SUCCESS) {
    PRINTF("could not map a idt region: error code %x", ret);
    return;
  }

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_IDTR_BASE, idt_addr);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_IDTR_LIMIT, sizeof idt);
}

void
init_regs(hv_vcpuid_t vcpuid)
{
  /* set up cpu regs */
  hv_vcpu_write_register(vcpuid, HV_X86_RFLAGS, 0x2);
  hv_vcpu_write_register(vcpuid, HV_X86_RSP, 0x10000);
  hv_vcpu_write_register(vcpuid, HV_X86_RBP, 0x10000);
}

void
print_regs(hv_vcpuid_t vcpuid)
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
  hv_vcpu_read_register(vcpuid, HV_X86_RSP, &value);
  PRINTF("rsp = 0x%llx\n", value);
  hv_vcpu_read_register(vcpuid, HV_X86_RBP, &value);
  PRINTF("rbp = 0x%llx\n", value);
}
    
void
init_msr(hv_vcpuid_t vcpuid)
{
  if (hv_vcpu_enable_native_msr(vcpuid, MSR_TIME_STAMP_COUNTER, 1) == HV_SUCCESS && 
      hv_vcpu_enable_native_msr(vcpuid, MSR_TSC_AUX, 1) == HV_SUCCESS &&
      hv_vcpu_enable_native_msr(vcpuid, MSR_KERNEL_GS_BASE, 1) == HV_SUCCESS) { // MSR_KGSBASE must be set properly later
    PRINTF("MSR initialization failed.\n");
  }
}

void
run(const char *text, size_t tsize, size_t vaddr, size_t entry)
{
  hv_return_t ret;
  hv_vcpuid_t vcpuid;
  void *mem;
  uint64_t value;

  ret = hv_vm_create(HV_VM_DEFAULT);
  if (ret != HV_SUCCESS) {
    PRINTF("could not create the vm: error code %x", ret);
    return;
  }

  PUTS("successfully created the vm");

  mem = valloc(0x1000);
  assert(mem);
  memcpy((char *)mem + 0x100, text, tsize);

  ret = hv_vm_map(mem, 0, 0x1000, HV_MEMORY_READ | HV_MEMORY_WRITE | HV_MEMORY_EXEC);
  if (ret != HV_SUCCESS) {
    PRINTF("could not map a text region: error code %x", ret);
    return;
  }

  PUTS("successfully created a text mapping");

  ret = hv_vcpu_create(&vcpuid, HV_VCPU_DEFAULT);
  if (ret != HV_SUCCESS) {
    PRINTF("could not create a vcpu: error code %x", ret);
    return;
  }

  PUTS("successfully created a vcpu");

  init_vmcs(vcpuid);
  init_msr(vcpuid);
  init_page(vcpuid, 0x3000, 0x4000);
  init_segment(vcpuid, 0x7000, 0x5000);
  init_idt(vcpuid, 0x12000, 0x1000);
  init_regs(vcpuid);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_RIP, entry - vaddr + 0x100);

  PUTS("successfully set regs");

  /* now vm is ready */

  PUTS("now vm is ready");

  hv_vcpu_write_register(vcpuid, HV_X86_RAX, 1);
  hv_vcpu_write_register(vcpuid, HV_X86_RBX, 2);

  print_regs(vcpuid);

  for (int i = 0; i < 8; ++i) {
    if ((ret = hv_vcpu_run(vcpuid)) != HV_SUCCESS) {
      PUTS("oops, hv_vcpu_run fails");
      return;
    }

    hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_EXIT_REASON, &value);
    PRINTF("exit reason = 0x%llx\n", value);

    print_regs(vcpuid);

    switch (value) {
      uint64_t rax, rbx, rcx, rdx;

    case VMX_REASON_VMCALL:
      PUTS("reason: vmcall");
      assert(false);
      break;

    case VMX_REASON_EXC_NMI:
      PUTS("reason: exc or nmi");
      PUTS("");
      hv_vcpu_read_register(vcpuid, VMCS_RO_IDT_VECTOR_INFO, &value);
      PRINTF("idt info = %lld\n", value);
      hv_vcpu_read_register(vcpuid, VMCS_RO_IDT_VECTOR_ERROR, &value);
      PRINTF("idt error = %lld\n", value);
      hv_vcpu_read_register(vcpuid, VMCS_GUEST_INT_STATUS, &value);
      PRINTF("guest int status = %lld\n", value);
      PUTS("!!MAYBE A SYSENTER!!");
      PUTS(">>>start syscall handling...");
      hv_vcpu_read_register(vcpuid, HV_X86_RAX, &rax);
      hv_vcpu_read_register(vcpuid, HV_X86_RBX, &rbx);
      hv_vcpu_read_register(vcpuid, HV_X86_RCX, &rcx);
      hv_vcpu_read_register(vcpuid, HV_X86_RDX, &rdx);
      switch (rax) {
      case 1:
        PUTS("exit...");
        exit(rbx);
        break;
      case 4:
        write(rbx, rcx - vaddr + (char *)text, rdx);
        break;
      default:
        PRINTF("UNKNOWN SYSCALL!: %lld\n", rax);
        abort();
      }
      PUTS("<<<done");

      hv_vcpu_read_register(vcpuid, HV_X86_RIP, &value);
      hv_vcpu_write_register(vcpuid, HV_X86_RIP, value + 2);

      break;

    default:
      PRINTF("reason: %lld\n", value);
    }

    hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_EXIT_QUALIFIC, &value);
    PRINTF("exit qualification = 0x%llx\n", value);

    hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_PHYSICAL_ADDRESS, &value);
    PRINTF("guest-physical address = 0x%llx\n", value);

    hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_RIP, &value);
    PRINTF("guest-rip = 0x%llx\n", value);

    PUTS("");
  }

  PUTS("exit...");

  /* exit... */

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

int
main(int argc, char *argv[])
{
  assert(argc == 2);

  FILE *file = fopen(argv[1], "r");
  struct elf_header h;
  struct program_header p;

  fread(&h, sizeof h, 1, file);

  PRINTF("magic: 0x%08x\n", h.magic);
  PRINTF("cpubit: 0x%08x\n", h.cpubit);
  PRINTF("size: %d\n", h.ehsize);
  PRINTF("entry: 0x%016lx\n", h.entry);
  PRINTF("phnum: %d\n", h.phnum);

  assert(h.phoff != 0);
  assert(h.phnum >= 1);
  if (h.phnum != 1) {
      PRINTF("WARNING: phnum != 1. Using only the first header...\n");
  }

  fseek(file, h.phoff, SEEK_SET);
  fread(&p, sizeof p, 1, file);

  PUTS("# program header");

  PRINTF("vaddr = 0x%016lx\n", p.vaddr);
  PRINTF("paddr = 0x%016lx\n", p.paddr);
  PRINTF("type = %ul\n", p.type);
  PRINTF("filesz = 0x%lx\n", p.filesz);
  PRINTF("offset = 0x%lx\n", p.offset);

  char *text = malloc(p.filesz);

  fseek(file, p.offset, SEEK_SET);
  fread(text, p.filesz, 1, file);

  run(text, p.filesz, p.vaddr, h.entry);

  return 0;
}
