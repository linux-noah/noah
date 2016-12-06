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

static void
handle_syscall(void)
{
  uint64_t rax;
  vmm_read_register(HV_X86_RAX, &rax);
  if (rax >= NR_SYSCALLS) {
    fprintf(stderr, "unknown system call: %lld\n", rax);
    exit(1);            /* TODO: signal something */
  }
  uint64_t rdi, rsi, rdx, r10, r8, r9;
  vmm_read_register(HV_X86_RDI, &rdi);
  vmm_read_register(HV_X86_RSI, &rsi);
  vmm_read_register(HV_X86_RDX, &rdx);
  vmm_read_register(HV_X86_R10, &r10);
  vmm_read_register(HV_X86_R8, &r8);
  vmm_read_register(HV_X86_R9, &r9);
  uint64_t retval = sc_handler_table[rax](rdi, rsi, rdx, r10, r8, r9);
  vmm_write_register(HV_X86_RAX, retval);
}

void
main_loop()
{
  while (vmm_run() == 0) {

    /* dump_instr(); */
    /* print_regs(); */

    uint64_t exit_reason;
    vmm_read_vmcs(VMCS_RO_EXIT_REASON, &exit_reason);

    switch (exit_reason) {
    case VMX_REASON_VMCALL:
      printk("reason: vmcall\n");
      assert(false);
      break;

    case VMX_REASON_EXC_NMI: {
      /* References:
       * - Intel SDM 27.2.2, Table 24-15: Information for VM Exits Due to Vectored Events
       */
      uint64_t exc_info;
      vmm_read_vmcs(VMCS_RO_VMEXIT_IRQ_INFO, &exc_info);

#define VMCS_EXCTYPE_EXTERNAL_INTERRUPT 0
#define VMCS_EXCTYPE_NONMASKTABLE_INTERRUPT 2
#define VMCS_EXCTYPE_HARDWARE_EXCEPTION 3
#define VMCS_EXCTYPE_SOFTWARE_EXCEPTION 6

      int int_type = (exc_info & 0x700) >> 8;
      switch (int_type) {
      default:
        assert(false);
      case VMCS_EXCTYPE_EXTERNAL_INTERRUPT:
      case VMCS_EXCTYPE_NONMASKTABLE_INTERRUPT:
        /* nothing we can do, host os handles it */
        continue;
      case VMCS_EXCTYPE_HARDWARE_EXCEPTION: /* including invalid opcode */
      case VMCS_EXCTYPE_SOFTWARE_EXCEPTION: /* including break points, overflows */
        break;
      }

      /* See also http://wiki.osdev.org/Exceptions#Virtualization_Exception */
#define X86_VEC_DE 0            /* division by zero */
#define X86_VEC_DB 1            /* debug */
#define X86_VEC_BP 3            /* breakpoint */
#define X86_VEC_OF 4            /* overflow */
#define X86_VEC_BR 5            /* bound range exceeded */
#define X86_VEC_UD 6            /* invalid opcode */
#define X86_VEC_NM 7            /* device not available */
#define X86_VEC_DF 8            /* double fault */
#define X86_VEC_TS 10           /* invalid TSS */
#define X86_VEC_NP 11           /* segment not present */
#define X86_VEC_SS 12           /* stack segment fault */
#define X86_VEC_GP 13           /* general protection fault */
#define X86_VEC_PF 14           /* page fault */
#define X86_VEC_MF 16           /* x87 floating-point exception */
#define X86_VEC_AC 17           /* alignment check */
#define X86_VEC_MC 18           /* machine check */
#define X86_VEC_XM 19           /* SIMD floating-point exception */
#define X86_VEC_VE 20           /* virtualization exception */
#define X86_VEC_SX 30           /* security exception */

      int exc_vec = exc_info & 0xff;
      switch (exc_vec) {
      case X86_VEC_PF: {
        /* FIXME */
        uint64_t gladdr;
        vmm_read_vmcs(VMCS_RO_EXIT_QUALIFIC, &gladdr);
        fprintf(stderr, "page fault: caused by guest linear address 0x%llx\n", gladdr);
        exit(1);                /* TODO: signal segv */
      }
      case X86_VEC_UD: {
        uint64_t instlen, rip;
        vmm_read_vmcs(VMCS_RO_VMEXIT_INSTR_LEN, &instlen);
        vmm_read_register(HV_X86_RIP, &rip);
        if (is_syscall(instlen, rip)) {
          handle_syscall();
          vmm_read_register(HV_X86_RIP, &rip); /* reload rip for execve */
          vmm_write_register(HV_X86_RIP, rip + 2);
          continue;
        }
        /* FIXME */
        fprintf(stderr, "invalid opcode! (rip = %p): ", (void *) rip);
        unsigned char inst[instlen];
        if (copy_from_user(inst, rip, instlen))
          assert(false);
        for (uint64_t i = 0; i < instlen; ++i)
          fprintf(stderr, "%02x ", inst[i] & 0xff);
        fprintf(stderr, "\n");
        exit(1);                /* TODO: signal SIGILL */
      }
      case X86_VEC_DE:
      case X86_VEC_DB:
      case X86_VEC_BP:
      case X86_VEC_OF:
      case X86_VEC_BR:
      case X86_VEC_NM:
      case X86_VEC_DF:
      case X86_VEC_TS:
      case X86_VEC_NP:
      case X86_VEC_SS:
      case X86_VEC_GP:
      case X86_VEC_MF:
      case X86_VEC_AC:
      case X86_VEC_MC:
      case X86_VEC_XM:
      case X86_VEC_VE:
      case X86_VEC_SX:
      default:
        /* FIXME */
        fprintf(stderr, "exception thrown: %d\n", exc_vec);
        uint64_t instlen, rip;
        vmm_read_vmcs(VMCS_RO_VMEXIT_INSTR_LEN, &instlen);
        vmm_read_register(HV_X86_RIP, &rip);
        fprintf(stderr, "inst: \n");
        unsigned char inst[instlen];
        if (copy_from_user(inst, rip, instlen))
          assert(false);
        for (uint64_t i = 0; i < instlen; ++i)
          fprintf(stderr, "%02x ", inst[i] & 0xff);
        fprintf(stderr, "\n");
        exit(1);                /* TODO */
      }
      break;
    }

    case VMX_REASON_EPT_VIOLATION:
#if 0
      printk("reason: ept_violation\n");

      uint64_t gpaddr;
      vmm_read_vmcs(VMCS_GUEST_PHYSICAL_ADDRESS, &gpaddr);
      printk("guest-physical address = 0x%llx\n", gpaddr);

      uint64_t qual;

      vmm_read_vmcs(VMCS_RO_EXIT_QUALIFIC, &qual);
      printk("exit qualification = 0x%llx\n", qual);

      if (qual & (1 << 0)) printk("cause: data read\n");
      if (qual & (1 << 1)) printk("cause: data write\n");
      if (qual & (1 << 2)) printk("cause: inst fetch\n");

      if (qual & (1 << 7)) {
        uint64_t gladdr;
        vmm_read_vmcs(VMCS_RO_GUEST_LIN_ADDR, &gladdr);
        printk("guest linear address = 0x%llx\n", gladdr);
      } else {
        printk("guest linear address = (unavailable)\n");
      }
#endif
      break;

    case VMX_REASON_CPUID: {
      uint64_t rax;
      vmm_read_register(HV_X86_RAX, &rax);
      unsigned eax, ebx, ecx, edx;
      __get_cpuid(rax, &eax, &ebx, &ecx, &edx);

      vmm_write_register(HV_X86_RAX, eax);
      vmm_write_register(HV_X86_RBX, ebx);
      vmm_write_register(HV_X86_RCX, ecx);
      vmm_write_register(HV_X86_RDX, edx);

      uint64_t rip;
      vmm_read_register(HV_X86_RIP, &rip);
      vmm_write_register(HV_X86_RIP, rip + 2);

      break;
    }

    case VMX_REASON_IRQ: {
      break;
    }

    default:
      printk("other reason: %llu\n", exit_reason);
    }
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
  init_fpu();
}

static void
default_mnt(char *path)
{
  uint32_t bufsize;
  _NSGetExecutablePath(NULL, &bufsize);
  char abs_self[bufsize];
  _NSGetExecutablePath(abs_self, &bufsize);
  realpath(abs_self, path);
  char *dir = dirname(path);
  sprintf(path, "%s/../mnt", dir);
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
      argv[optind - 1] = root;
      break;
    }
  }

  argc -= optind;
  argv += optind;

  if (argc == 0) {
    abort();
  }

  vmm_create();
  init_vkernel();

  if (root[0] == 0) {
    default_mnt(root);
  }
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
