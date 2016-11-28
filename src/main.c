#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cpuid.h>
#include <getopt.h>
#include <string.h>
#include <sys/syslimits.h>
#include <libgen.h>

#include "vmm.h"
#include "mm.h"
#include "noah.h"
#include "syscall.h"
#include "linux/errno.h"

#include <mach-o/dyld.h>

static bool
is_syscall(int instlen, uint64_t rip)
{
  static const ushort OP_SYSCALL = 0x050f;
  if (instlen != 2)
    return false;
  ushort op;
  if (copy_from_user(&op, rip, sizeof op))
    return false;
  return op == OP_SYSCALL;
}

void
main_loop()
{
  uint64_t value;

  while (vmm_run() == 0) {

    dump_instr();
    print_regs();

    uint64_t exit_reason;
    vmm_read_vmcs(VMCS_RO_EXIT_REASON, &exit_reason);

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
      vmm_read_vmcs(VMCS_RO_VMEXIT_INSTR_LEN, &instlen);
      printk("instr length = 0x%llx\n", instlen);
      vmm_read_register(HV_X86_RIP, &rip);
      printk("rip = 0x%llx\n", rip);
      vmm_read_vmcs(VMCS_RO_VMEXIT_IRQ_INFO, &irqvec);
      printk("irq info = %lld\n", irqvec);
      vmm_read_vmcs(VMCS_RO_VMEXIT_IRQ_ERROR, &irqerr);
      printk("irq error = %lld\n", irqerr);
      vmm_read_vmcs(VMCS_GUEST_INT_STATUS, &intstatus);
      printk("guest int status = %lld\n", intstatus);
      vmm_read_vmcs(VMCS_RO_EXIT_QUALIFIC, &exit_qual);
      printk("exit qualification = 0x%llx\n", exit_qual);

      if (! is_syscall(instlen, rip)) {
        if (exit_qual != 0) { // Page Fault
          fprintf(stderr, "page fault: %llx\n", exit_qual);
          exit(1);
        }

        // Exception such as #P
        printk("!!MAYBE AN Ignorable Exception!!\n");
        vmm_write_vmcs(VMCS_GUEST_RIP, instlen + rip);
        continue;
      }

      vmm_read_register(HV_X86_RAX, &rax);

      if (rax >= NR_SYSCALLS) {
        printf("unknown system call: %lld\n", rax);
        exit(1);
      }

      vmm_read_register(HV_X86_RDI, &rdi);
      vmm_read_register(HV_X86_RSI, &rsi);
      vmm_read_register(HV_X86_RDX, &rdx);
      vmm_read_register(HV_X86_R10, &r10);
      vmm_read_register(HV_X86_R8, &r8);
      vmm_read_register(HV_X86_R9, &r9);

      printk(">>>start syscall handling...: %s (%lld)\n", sc_name_table[rax], rax);
      retval = sc_handler_table[rax](rdi, rsi, rdx, r10, r8, r9);
      printk("<<<syscall done: %lld\n", retval);

      vmm_write_register(HV_X86_RAX, retval);

      vmm_read_register(HV_X86_RIP, &value);
      vmm_write_register(HV_X86_RIP, value + 2);

      break;
    }

    case VMX_REASON_EPT_VIOLATION:
      printk("reason: ept_violation\n");

      vmm_read_vmcs(VMCS_GUEST_PHYSICAL_ADDRESS, &value);
      printk("guest-physical address = 0x%llx\n", value);

      uint64_t qual;

      vmm_read_vmcs(VMCS_RO_EXIT_QUALIFIC, &qual);
      printk("exit qualification = 0x%llx\n", qual);

      if (qual & (1 << 0)) printk("cause: data read\n");
      if (qual & (1 << 1)) printk("cause: data write\n");
      if (qual & (1 << 2)) printk("cause: inst fetch\n");

      if (qual & (1 << 7)) {
        vmm_read_vmcs(VMCS_RO_GUEST_LIN_ADDR, &value);
        printk("guest linear address = 0x%llx\n", value);
      } else {
        printk("guest linear address = (unavailable)\n");
      }

      break;

    case VMX_REASON_CPUID: {
      unsigned eax, ebx, ecx, edx;

      __get_cpuid(rax, &eax, &ebx, &ecx, &edx);

      vmm_write_register(HV_X86_RAX, eax);
      vmm_write_register(HV_X86_RBX, ebx);
      vmm_write_register(HV_X86_RCX, ecx);
      vmm_write_register(HV_X86_RDX, edx);

      vmm_read_register(HV_X86_RIP, &value);
      vmm_write_register(HV_X86_RIP, value + 2);

      break;
    }

    case VMX_REASON_IRQ: {
      printk("external interruption\n");
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
init_vkernel()
{
  init_mm(&vkern_mm);
  init_shm_malloc();
  init_vmcs();
  init_msr();
  init_page();
  init_special_regs();
  init_segment();
  init_idt();
  init_regs();
}

void
drop_privilege(void)
{
  if (seteuid(getuid()) != 0) {
    abort();
  }
}

void
elevate_privilege(void)
{
  if (seteuid(0) != 0) {
    abort();
  }
}

int
main(int argc, char *argv[], char **envp)
{
  drop_privilege();

  static struct option long_options[] = {
    { "output", required_argument, NULL, 'o' },
    { "strace", required_argument, NULL, 's' },
    { "mnt", required_argument, NULL, 'm' },
    { 0, 0, 0, 0 }
  };
  int c, option_index = 0;

  char root[PATH_MAX] = {0};

  while ((c = getopt_long(argc, argv, "+o:s:m:", long_options, &option_index)) != -1) {
    switch (c) {
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
      break;
    }
  }
  if (root[0] == 0) {
    exit(1);
  }

  argc -= optind;
  argv += optind;

  if (argc == 0) {
    abort();
  }

  vmm_create();
  init_vkernel();

  set_initial_proc(&proc, strdup(root));

  int err;
  if ((err = do_exec(argv[0], argc, argv, envp)) < 0) {
    errno = linux_to_darwin_errno(-err);
    perror("Error");
    exit(1);
  }

  main_loop();

  vmm_destroy();

  return 0;
}
