#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cpuid.h>
#include <getopt.h>
#include <string.h>
#include <sys/syslimits.h>

#include "vmm.h"
#include "noah.h"
#include "syscall.h"

#include <mach-o/dyld.h>

void
run_task()
{
  hv_return_t ret;
  uint64_t value;

  while (true) {
    if ((ret = hv_vcpu_run(task->vcpuid)) != HV_SUCCESS) {
      printk("oops, hv_vcpu_run fails\n");
      return;
    }

    dump_instr();
    print_regs();

    uint64_t exit_reason;
    hv_vmx_vcpu_read_vmcs(task->vcpuid, VMCS_RO_EXIT_REASON, &exit_reason);

    switch (exit_reason) {
      uint64_t rax, rdi, rsi, rdx, r10, r8, r9;

    case VMX_REASON_VMCALL:
      printk("reason: vmcall\n");
      assert(false);
      break;

    case VMX_REASON_EXC_NMI: {
      uint64_t instlen, rip, irqvec, irqerr, intstatus, exit_qual;
      uint64_t retval;

      printk("reason: exc or nmi\n");
      printk("\n");
      hv_vmx_vcpu_read_vmcs(task->vcpuid, VMCS_RO_VMEXIT_INSTR_LEN, &instlen);
      printk("instr length = 0x%llx\n", instlen);
      hv_vcpu_read_register(task->vcpuid, HV_X86_RIP, &rip);
      printk("rip = 0x%llx\n", rip);
      hv_vmx_vcpu_read_vmcs(task->vcpuid, VMCS_RO_VMEXIT_IRQ_INFO, &irqvec);
      printk("irq info = %lld\n", irqvec);
      hv_vmx_vcpu_read_vmcs(task->vcpuid, VMCS_RO_VMEXIT_IRQ_ERROR, &irqerr);
      printk("irq error = %lld\n", irqerr);
      hv_vmx_vcpu_read_vmcs(task->vcpuid, VMCS_GUEST_INT_STATUS, &intstatus);
      printk("guest int status = %lld\n", intstatus);
      hv_vmx_vcpu_read_vmcs(task->vcpuid, VMCS_RO_EXIT_QUALIFIC, &exit_qual);
      printk("exit qualification = 0x%llx\n", exit_qual);

      // FIXME
      // Exception
      const ushort syscall_op = 0x0f05;
      if (instlen != 2 && (*(ushort*)guest_to_host(rip)) != syscall_op) {
        if (exit_qual != 0) { // Page Fault
          fprintf(stderr, "page fault: %llx\n", exit_qual);
          exit(1);
        }

        // Exception such as #P
        printk("!!MAYBE AN Ignorable Exception!!\n");
        hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_RIP, instlen + rip);
        continue;
      }

      // Syscall
      printk("!!MAYBE A SYSENTER!!\n");

      hv_vcpu_read_register(task->vcpuid, HV_X86_RAX, &rax);

      if (rax >= NR_SYSCALLS) {
        printf("unknown system call: %lld\n", rax);
        exit(1);
      }

      hv_vcpu_read_register(task->vcpuid, HV_X86_RDI, &rdi);
      hv_vcpu_read_register(task->vcpuid, HV_X86_RSI, &rsi);
      hv_vcpu_read_register(task->vcpuid, HV_X86_RDX, &rdx);
      hv_vcpu_read_register(task->vcpuid, HV_X86_R10, &r10);
      hv_vcpu_read_register(task->vcpuid, HV_X86_R8, &r8);
      hv_vcpu_read_register(task->vcpuid, HV_X86_R9, &r9);

      printk(">>>start syscall handling...: %s (%lld)\n", sc_name_table[rax], rax);
      retval = sc_handler_table[rax](rdi, rsi, rdx, r10, r8, r9);
      printk("<<<syscall done: %lld\n", retval);

      hv_vcpu_write_register(task->vcpuid, HV_X86_RAX, retval);

      hv_vcpu_read_register(task->vcpuid, HV_X86_RIP, &value);
      hv_vcpu_write_register(task->vcpuid, HV_X86_RIP, value + 2);

      break;
    }

    case VMX_REASON_EPT_VIOLATION:
      printk("reason: ept_violation\n");

      hv_vmx_vcpu_read_vmcs(task->vcpuid, VMCS_GUEST_PHYSICAL_ADDRESS, &value);
      printk("guest-physical address = 0x%llx\n", value);

      uint64_t qual;

      hv_vmx_vcpu_read_vmcs(task->vcpuid, VMCS_RO_EXIT_QUALIFIC, &qual);
      printk("exit qualification = 0x%llx\n", qual);

      if (qual & (1 << 0)) printk("cause: data read\n");
      if (qual & (1 << 1)) printk("cause: data write\n");
      if (qual & (1 << 2)) printk("cause: inst fetch\n");

      if (qual & (1 << 7)) {
        hv_vmx_vcpu_read_vmcs(task->vcpuid, VMCS_RO_GUEST_LIN_ADDR, &value);
        printk("guest linear address = 0x%llx\n", value);
      } else {
        printk("guest linear address = (unavailable)\n");
      }

      break;

    case VMX_REASON_CPUID: {
      unsigned eax, ebx, ecx, edx;

      __get_cpuid(rax, &eax, &ebx, &ecx, &edx);

      hv_vcpu_write_register(task->vcpuid, HV_X86_RAX, eax);
      hv_vcpu_write_register(task->vcpuid, HV_X86_RBX, ebx);
      hv_vcpu_write_register(task->vcpuid, HV_X86_RCX, ecx);
      hv_vcpu_write_register(task->vcpuid, HV_X86_RDX, edx);

      hv_vcpu_read_register(task->vcpuid, HV_X86_RIP, &value);
      hv_vcpu_write_register(task->vcpuid, HV_X86_RIP, value + 2);

      break;
    }

    default:
      printk("other reason: %llu\n", exit_reason);
    }
    printk("\n");
  }

  printk("exit...\n");
}

void
__attribute__((noreturn)) version()
{
  fprintf(stderr, "%s\n", NOAH_VERSION);
  exit(1);
}

void
__attribute__((noreturn)) usage()
{
  fprintf(stderr, "usage: noah [OPTION] elf_file ...\n");
  exit(1);
}

struct noah_run_info noah_run_info;

int
main(int argc, char *argv[], char **envp)
{
  static struct option long_options[] = {
    { "help", no_argument, NULL, 'h' },
    { "version", no_argument, NULL, 'v' },
    { "output", required_argument, NULL, 'o' },
    { "strace", required_argument, NULL, 's' },
    { "mnt", required_argument, NULL, 'm' },
    { 0, 0, 0, 0 }
  };
  int c, option_index = 0;

  char root[PATH_MAX] = {0};

  while ((c = getopt_long(argc, argv, "+hvo:s:m:", long_options, &option_index)) != -1) {
    switch (c) {
    default:
      usage();
    case 'v':
      version();
    case 'o':
      init_printk(optarg);
      break;
    case 's':
      init_meta_strace(optarg);
      break;
    case 'm':
      if (realpath(optarg, root) == NULL) {
        perror("Invalid --mnt flag: ");
        exit(1);
      }
      argv[optind - 1] = root;
      break;
    }
  }

  /* get this executable's path */
  uint32_t bufsize;
  _NSGetExecutablePath(NULL, &bufsize);
  char abs_self[bufsize];
  if (_NSGetExecutablePath(abs_self, &bufsize)) {
    return -1;
  }
  noah_run_info = (struct noah_run_info) {.self_path = abs_self, .argc = argc, .argv = argv, .optind = optind};

  argc -= optind;
  argv += optind;

  if (argc == 0) {
    usage();
  }

  vmm_create();

  if (root[0] != '\0') {
    free(proc.root);
    proc.root = strdup(root);
  }

  if (do_exec(argv[0], argc, argv, envp) < 0) {
    exit(1);
  };

  run_task();

  vmm_destroy();

  return 0;
}
