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

#if DEBUG_MODE
#define PUTS(...) puts(__VA_ARGS__)
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PUTS(...) 0
#define PRINTF(...) 0
#endif

void
init_vmcs(hv_vcpuid_t vcpuid)
{
  uint64_t vmx_cap_pinbased, vmx_cap_procbased, vmx_cap_procbased2, vmx_cap_entry;

  hv_vmx_read_capability(HV_VMX_CAP_PINBASED, &vmx_cap_pinbased);
  hv_vmx_read_capability(HV_VMX_CAP_PROCBASED, &vmx_cap_procbased);
  hv_vmx_read_capability(HV_VMX_CAP_PROCBASED2, &vmx_cap_procbased2);
  hv_vmx_read_capability(HV_VMX_CAP_ENTRY, &vmx_cap_entry);

  /* set up vmcs */

#define VMCS_PRI_PROC_BASED_CTLS_HLT           (1 << 7)
#define VMCS_PRI_PROC_BASED_CTLS_CR8_LOAD      (1 << 19)
#define VMCS_PRI_PROC_BASED_CTLS_CR8_STORE     (1 << 20)

#define cap2ctrl(cap,ctrl) (((ctrl) | ((cap) & 0xffffffff)) & ((cap) >> 32))

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_PIN_BASED, cap2ctrl(vmx_cap_pinbased, 0));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CPU_BASED, cap2ctrl(vmx_cap_procbased,
                                                 VMCS_PRI_PROC_BASED_CTLS_HLT |
                                                 VMCS_PRI_PROC_BASED_CTLS_CR8_LOAD |
                                                 VMCS_PRI_PROC_BASED_CTLS_CR8_STORE));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CPU_BASED2, cap2ctrl(vmx_cap_procbased2, 0));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_VMENTRY_CONTROLS, cap2ctrl(vmx_cap_entry, 0));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_EXC_BITMAP, 0xffffffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CR0_SHADOW, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CR4_MASK, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CR4_SHADOW, 0);

}

void
init_page(hv_vcpuid_t vcpuid, uint64_t pgdir_addr)
{
  static const uint32_t entrypgdir[1024] = {
    // Map VA's [4MB, 8MB) to PA's [0, 4MB)
    [1] = 0 | PTE_P | PTE_W | PTE_PS,
  };
  void *mem = valloc(sizeof entrypgdir);
  memcpy(mem, entrypgdir, sizeof entrypgdir);

  hv_return_t ret = hv_vm_map(mem, pgdir_addr, sizeof entrypgdir, HV_MEMORY_READ | HV_MEMORY_WRITE | HV_MEMORY_EXEC);
  if (ret != HV_SUCCESS) {
    PRINTF("could not map a page map region: error code %x", ret);
    return;
  }

  uint64_t cr4;
  hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_CR4, &cr4);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CR4, cr4 | CR4_PSE | CR4_VMXE);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CR3, pgdir_addr);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CR0, CR0_PG | CR0_PE | CR0_NE);
}

void
init_segment(hv_vcpuid_t vcpuid, uint64_t gdt_addr)
{
  // init segment
  static struct segment_descriptor gdt[] = {
    { .sd_lolimit = 0, .sd_type = 0, /* NULL */
      .sd_p = 0, .sd_hilimit = 0, .sd_def32 = 0, .sd_gran = 0},

    { .sd_lolimit = 0xffff, .sd_type = SDT_MEMER, /* CODE */
      .sd_p = 1, .sd_hilimit = 0xf, .sd_def32 = 1, .sd_gran = 1 },

    { .sd_lolimit = 0xffff, .sd_type = SDT_MEMRW, /* DATA */
      .sd_p = 1, .sd_hilimit = 0xf, .sd_def32 = 1, .sd_gran = 1 },

    { .sd_lolimit = I386_TSS_SIZE - 1, /* TSS */
      .sd_type = SDT_SYS386TSS, .sd_p = 1 }
  };
  uint64_t tss_addr = gdt_addr + 1000; // 0x2000
  gdt[3].sd_lobase = tss_addr;

  void *mem = valloc(0x2000);
  memcpy(mem, &gdt, sizeof(gdt));

  hv_return_t ret = hv_vm_map(mem, gdt_addr, 0x2000, HV_MEMORY_READ | HV_MEMORY_WRITE | HV_MEMORY_EXEC);
  if (ret != HV_SUCCESS) {
    PRINTF("could not map a gdt region: error code %x", ret);
    return;
  }

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GDTR_BASE, gdt_addr);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GDTR_LIMIT, sizeof(gdt) - 1);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_TR_BASE, tss_addr);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_TR_LIMIT, I386_TSS_SIZE - 1);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_TR_AR, DESC_PRESENT | SDT_SYS386BSY);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_LDTR_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_LDTR_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_LDTR_AR, DESC_UNUSABLE);

  uint32_t codeseg_ar = DESC_GRAN | DESC_DEF32 | DESC_PRESENT | SDT_MEMERA;
  uint32_t dataseg_ar = DESC_GRAN | DESC_DEF32 | DESC_PRESENT | SDT_MEMRWA;
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CS, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CS_LIMIT, 0xffffffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CS_AR, codeseg_ar);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_DS, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_DS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_DS_LIMIT, 0xffffffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_DS_AR, dataseg_ar);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_ES, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_ES_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_ES_LIMIT, 0xffffffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_ES_AR, dataseg_ar);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS_LIMIT, 0xffffffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS_AR, dataseg_ar);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS_LIMIT, 0xffffffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS_AR, dataseg_ar);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_SS, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_SS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_SS_LIMIT, 0xffffffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_SS_AR, dataseg_ar);

  hv_vcpu_write_register(vcpuid, HV_X86_CS, GSEL(SEG_CODE, 0));
  hv_vcpu_write_register(vcpuid, HV_X86_DS, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(vcpuid, HV_X86_ES, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(vcpuid, HV_X86_FS, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(vcpuid, HV_X86_GS, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(vcpuid, HV_X86_SS, GSEL(SEG_DATA, 0));
  hv_vcpu_write_register(vcpuid, HV_X86_TR, GSEL(SEG_TSS, 0));
  hv_vcpu_write_register(vcpuid, HV_X86_LDTR, 0);
}

struct gate_desc idt[256];

void
init_idt(hv_vcpuid_t vcpuid, uint64_t idt_addr)
{
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
  hv_vcpu_write_register(vcpuid, HV_X86_RSP, 0x400100);
  hv_vcpu_write_register(vcpuid, HV_X86_RBP, 0x400100);
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
  init_segment(vcpuid, 0x1000);
  init_page(vcpuid, 0x3000);
  init_idt(vcpuid, 0x4000);
  init_regs(vcpuid);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_RIP, entry - vaddr + 0x400100);

  PUTS("successfully set regs");

  /* now vm is ready */

  PUTS("now vm is ready");

  hv_vcpu_write_register(vcpuid, HV_X86_RAX, 1);
  hv_vcpu_write_register(vcpuid, HV_X86_RBX, 2);

  print_regs(vcpuid);

  for (int i = 0; i < 5; ++i) {
    if ((ret = hv_vcpu_run(vcpuid)) != HV_SUCCESS) {
      PUTS("oops");
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
  PRINTF("size: %d\n", h.ehsize);
  PRINTF("entry: 0x%08x\n", h.entry);

  assert(h.phoff != 0);
  assert(h.phnum == 1);

  fseek(file, h.phoff, SEEK_SET);
  fread(&p, sizeof p, 1, file);

  PUTS("# program header");

  PRINTF("vaddr = 0x%08x\n", p.vaddr);
  PRINTF("paddr = 0x%08x\n", p.paddr);
  PRINTF("type = %ul\n", p.type);
  PRINTF("filesz = 0x%x\n", p.filesz);
  PRINTF("offset = 0x%x\n", p.offset);

  char *text = malloc(p.filesz);

  fseek(file, p.offset, SEEK_SET);
  fread(text, p.filesz, 1, file);

  run(text, p.filesz, p.vaddr, h.entry);

  return 0;
}
