#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cpuid.h>

#include "noah.h"
#include "syscall.h"

void
main_loop()
{
  hv_return_t ret;
  uint64_t value;

  while (true) {
    if ((ret = hv_vcpu_run(vcpuid)) != HV_SUCCESS) {
      PUTS("oops, hv_vcpu_run fails");
      return;
    }

    hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_RIP, &value);
    PRINTF("\tguest-rip = 0x%llx\n", value);

    hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_VMEXIT_INSTR_LEN, &value);
    PRINTF("\tinstr length = 0x%llx\n", value);

    print_regs();

    uint64_t exit_reason;
    hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_EXIT_REASON, &exit_reason);

    switch (exit_reason) {
      uint64_t rax, rdi, rsi, rdx, r10, r8, r9;

    case VMX_REASON_VMCALL:
      PUTS("reason: vmcall");
      assert(false);
      break;

    case VMX_REASON_EXC_NMI: {
      uint64_t retval;

      PUTS("reason: exc or nmi");
      PUTS("");
      hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_IDT_VECTOR_INFO, &value);
      PRINTF("idt info = %lld\n", value);
      hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_IDT_VECTOR_ERROR, &value);
      PRINTF("idt error = %lld\n", value);
      hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_INT_STATUS, &value);
      PRINTF("guest int status = %lld\n", value);
      hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_EXIT_QUALIFIC, &value);
      PRINTF("exit qualification = 0x%llx\n", value);
      PUTS("!!MAYBE A SYSENTER!!");

      hv_vcpu_read_register(vcpuid, HV_X86_RAX, &rax);

      if (rax >= NR_SYSCALLS) {
        printf("unknown system call: %llu\n", rax);
        exit(1);
      }

      hv_vcpu_read_register(vcpuid, HV_X86_RDI, &rdi);
      hv_vcpu_read_register(vcpuid, HV_X86_RSI, &rsi);
      hv_vcpu_read_register(vcpuid, HV_X86_RDX, &rdx);
      hv_vcpu_read_register(vcpuid, HV_X86_R10, &r10);
      hv_vcpu_read_register(vcpuid, HV_X86_R8, &r8);
      hv_vcpu_read_register(vcpuid, HV_X86_R9, &r9);

      PRINTF(">>>start syscall handling...: %llu\n", rax);
      retval = sc_handler_table[rax](rdi, rsi, rdx, r10, r8, r9);
      PUTS("<<<done");

      hv_vcpu_write_register(vcpuid, HV_X86_RAX, retval);

      hv_vcpu_read_register(vcpuid, HV_X86_RIP, &value);
      hv_vcpu_write_register(vcpuid, HV_X86_RIP, value + 2);

      break;
    }

    case VMX_REASON_EPT_VIOLATION:
      PRINTF("reason: ept_violation\n");

      hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_PHYSICAL_ADDRESS, &value);
      PRINTF("guest-physical address = 0x%llx\n", value);

      uint64_t qual;

      hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_EXIT_QUALIFIC, &qual);
      PRINTF("exit qualification = 0x%llx\n", qual);

      if (qual & (1 << 0)) PUTS("cause: data read");
      if (qual & (1 << 1)) PUTS("cause: data write");
      if (qual & (1 << 2)) PUTS("cause: inst fetch");

      if (qual & (1 << 7)) {
        hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_GUEST_LIN_ADDR, &value);
        PRINTF("guest linear address = 0x%llx\n", value);
      } else {
        PUTS("guest linear address = (unavailable)");
      }

      break;

    case VMX_REASON_CPUID: {
      unsigned eax, ebx, ecx, edx;

      __get_cpuid(rax, &eax, &ebx, &ecx, &edx);

      hv_vcpu_write_register(vcpuid, HV_X86_RAX, eax);
      hv_vcpu_write_register(vcpuid, HV_X86_RBX, ebx);
      hv_vcpu_write_register(vcpuid, HV_X86_RCX, ecx);
      hv_vcpu_write_register(vcpuid, HV_X86_RDX, edx);

      hv_vcpu_read_register(vcpuid, HV_X86_RIP, &value);
      hv_vcpu_write_register(vcpuid, HV_X86_RIP, value + 2);

      break;
    }

    default:
      PRINTF("reason: %lld\n", exit_reason);
    }

#if DEBUG_MODE
    PUTS("[press <enter> to step or C-D to continue...]");
    getchar();
#endif

    PUTS("");
  }

  PUTS("exit...");
}

int
main(int argc, char *argv[], char **envp)
{
  if (argc == 1) {
    fprintf(stderr, "usage: %s elf_file ...\n", argv[0]);
    exit(1);
  }

  vmm_create();

  if (do_exec(argv[1], argc - 1, argv + 1, envp) < 0) {
    exit(1);
  };

  main_loop();

  vmm_destroy();

  return 0;
}
