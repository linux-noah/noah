#include "common.h"
#include "linux/signal.h"

#include "noah.h"
#include "vmm.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <assert.h>
#include <stdatomic.h>

_Thread_local atomic_sigbits_t task_sigpending;  // sigpending cannot be inside task struct because thread local variables referred by signal handler should be atomic type

static inline int should_deliver(int sig);
static void
set_sigpending(int signum, siginfo_t *info, ucontext_t *context)
{
  int l_signum = darwin_to_linux_signal(signum);
  sigbits_addbit(&task_sigpending, l_signum);
}

int
send_signal(pid_t pid, int signum)
{
  // Currently, just kill it to them
  if (signum >= LINUX_SIGRTMIN) {
    warnk("RT signal is raised: %d\n", signum);
    return 0;
  }
  return syswrap(kill(pid, linux_to_darwin_signal(signum)));
}

void
init_signal(struct proc *proc)
{
#ifndef ATOMIC_INT_LOCK_FREE // Workaround of the incorrect atomic macro name bug of Clang
#define __GCC_ATOMIC_INT_T_LOCK_FREE __GCC_ATOMIC_INT_LOCK_FREE
#define ATOMIC_INT_LOCK_FREE ATOMIC_INT_T_LOCK_FREE
#endif
  static_assert(ATOMIC_INT_LOCK_FREE == 2, "The compiler must support lock-free atomic int");

  for (int i = 0; i < NSIG; i++) {
    struct sigaction oact;
    sigaction(i + 1, NULL, &oact);
    if (!(oact.sa_handler == SIG_IGN || oact.sa_handler == SIG_DFL)) {
      warnk("sa_handler:%d\n", (int)oact.sa_handler);
    }
    assert(oact.sa_handler == SIG_IGN || oact.sa_handler == SIG_DFL);
    // flags, restorer, and mask will be flushed in execve, so just leave them 0
    proc->sighand.sigaction[i] = (l_sigaction_t) {
      .lsa_handler = (gaddr_t) oact.sa_handler,
      .lsa_flags = 0,
      .lsa_restorer= 0,
      .lsa_mask = {0}
    };
  }
  assert(proc->nr_tasks == 1);
  struct task *t = list_entry(proc->tasks.next, struct task, tasks);
  sigset_t set;
  sigprocmask(0, NULL, &set);
  darwin_to_linux_sigset(&set, &t->sigmask);
  t->sigpending = &task_sigpending;
  sigbits_emptyset(t->sigpending);
  sigpending(&set);
  sigset_to_sigbits(&proc->sigpending, &set);
}

void
flush_signal(struct proc *proc)
{
  for (int i = 0; i < NSIG; i++) {
    if (proc->sighand.sigaction[i].lsa_handler == (l_handler_t) SIG_DFL || proc->sighand.sigaction[i].lsa_handler == (l_handler_t) SIG_IGN) {
      continue;
    }
    proc->sighand.sigaction[i] = (l_sigaction_t) {
      .lsa_handler = (l_handler_t) SIG_DFL,
      .lsa_flags = 0,
      .lsa_restorer= 0,
      .lsa_mask = {0}
    };
    struct sigaction dact;
    linux_to_darwin_sigaction(&proc->sighand.sigaction[i], &dact, SIG_DFL);
    sigaction(i + 1, &dact, NULL);
  }
}

static inline int
should_deliver(int sig)
{
  if (sig == 0) {
    return 0;
  }
  return (1 << (sig - 1)) & ~LINUX_SIGSET_TO_UI64(&task.sigmask);
}

static inline int
fetch_sig_from_sigbits(atomic_sigbits_t *sigbits)
{
  uint64_t bits, sig = 1;

  if ((bits = *sigbits) == 0) {
    return 0;
  }
  assert(bits < (1UL << 32));

  while (sig <= 32){
    if (((bits >> (sig - 1)) & 1) && should_deliver(sig)) {
      break;
    }
    sig++;
  }

  if (!(sigbits_delbit(sigbits, sig) & (1 << (sig - 1)))) {
    // Other threads delivered the signal, retry
    return fetch_sig_from_sigbits(sigbits);
  }

  return sig;
}

static inline int
fetch_sig_to_deliver()
{
  int sig = fetch_sig_from_sigbits(&proc.sigpending);
  if (sig) {
    return sig;
  }
  return fetch_sig_from_sigbits(task.sigpending);
}

bool
has_sigpending()
{
  return proc.sigpending || task.sigpending;
}

static const struct retcode {
  uint16_t poplmovl;
  uint32_t nr_sigreturn;
  uint64_t syscall;
} __attribute__((packed)) retcode_bin = {
  0xb858, // popl %eax; movl $..., %eax
  NR_rt_sigreturn,
  0x0f05, // syscall
};

struct sigcontext {
  uint64_t vcpu_reg[NR_X86_REG_LIST]; //temporarily, FIXME
  int signum;
  l_sigset_t oldmask;
};

struct sigframe {
  struct l_rt_sigframe rt_sigframe;
  struct retcode retcode;
  struct sigcontext sigcontext;
};

int
setup_sigframe(int signum)
{
  int err = 0;
  struct sigframe frame;

  assert(signum <= LINUX_NSIG);
  static_assert(is_aligned(sizeof frame, sizeof(uint64_t)), "signal frame should be aligned");
  static_assert(is_aligned(offsetof(struct sigframe, retcode), sizeof(uint64_t)), "signal retcode should be aligned");

  uint64_t rsp;
  vmm_read_register(HV_X86_RSP, &rsp);

  /* Setup sigframe */
  if (proc.sighand.sigaction[signum - 1].lsa_flags & LINUX_SA_RESTORER) {
    frame.rt_sigframe.sf_pretcode = (gaddr_t) proc.sighand.sigaction[signum - 1].lsa_restorer;
  } else {
    // Depending on the fact that we currently allow any data to be executed.
    frame.rt_sigframe.sf_pretcode = rsp + offsetof(struct sigframe, retcode);
  }
  frame.retcode = retcode_bin;


  /* Setup sigcontext */
  for (uint64_t i = 0; i < NR_X86_REG_LIST; i++) {
    if (x86_reg_list[i] == HV_X86_IDT_BASE) {
      break;
    }
    //TODO: save some segment related regs
    //TODO: save FPU state
    vmm_read_register(x86_reg_list[i], &frame.sigcontext.vcpu_reg[i]);
  }

  sigset_t dset;
  frame.sigcontext.oldmask = task.sigmask;
  l_sigset_t newmask = proc.sighand.sigaction[signum - 1].lsa_mask;
  if (!(proc.sighand.sigaction[signum - 1].lsa_flags & LINUX_SA_NOMASK)) {
    LINUX_SIGADDSET(&newmask, signum);
  }
  task.sigmask = newmask;
  linux_to_darwin_sigset(&newmask, &dset);
  sigprocmask(SIG_SETMASK, &dset, NULL);

  frame.sigcontext.signum = signum;

  /* OK, push them then... */
  rsp -= sizeof frame;
  vmm_write_register(HV_X86_RSP, rsp);
  if (copy_to_user(rsp, &frame, sizeof frame)) {
    err = -LINUX_EFAULT;
    goto error;
  }

  /* Setup registers */
  vmm_write_register(HV_X86_RDI, signum);
  vmm_write_register(HV_X86_RSI, 0); // TODO: siginfo
  vmm_write_register(HV_X86_RDI, 0); // TODO: ucontext

  vmm_write_register(HV_X86_RAX, 0);
  vmm_write_register(HV_X86_RIP, proc.sighand.sigaction[signum - 1].lsa_handler);

  return 0;

error:
  task.sigmask = frame.sigcontext.oldmask;
  linux_to_darwin_sigset(&task.sigmask, &dset);
  sigprocmask(SIG_SETMASK, &dset, NULL);

  return err;
}

void
wake_sighandler()
{
  pthread_rwlock_rdlock(&proc.sighand.lock);

  int sig;
  while ((sig = fetch_sig_to_deliver()) != 0) {

    meta_strace_sigdeliver(sig);
    switch (proc.sighand.sigaction[sig - 1].lsa_handler) {
      case (l_handler_t) SIG_DFL:
        warnk("Handling default signal in Noah is not implemented yet\n");
        /* fall through */
      case (l_handler_t) SIG_IGN:
        continue;

      default:
        if (setup_sigframe(sig) < 0) {
          die_with_forcedsig(SIGSEGV);
        }
        if (proc.sighand.sigaction[sig - 1].lsa_flags & LINUX_SA_ONESHOT) {
          proc.sighand.sigaction[sig - 1].lsa_handler = (l_handler_t) SIG_DFL;
          // Host signal handler must be set to SIG_DFL already by Darwin kernel
        }
        goto out;
    }
  }

out:
  pthread_rwlock_unlock(&proc.sighand.lock);
}

DEFINE_SYSCALL(alarm, unsigned int, seconds)
{
  assert(seconds == 0);
  return 0;
}

inline void
sigbits_emptyset(atomic_sigbits_t *sigbits)
{
  *sigbits = ATOMIC_VAR_INIT(0);
}

inline int
sigbits_ismember(atomic_sigbits_t *sigbits, int sig)
{
  return *sigbits & (1UL << (sig - 1));
}

inline uint64_t
sigbits_load(atomic_sigbits_t *sigbits)
{
  return atomic_load(sigbits);
}

inline uint64_t
sigbits_addbit(atomic_sigbits_t *sigbits, int sig)
{
  return atomic_fetch_or(sigbits, (1UL << (sig - 1)));
}

inline uint64_t
sigbits_delbit(atomic_sigbits_t *sigbits, int sig)
{
  return atomic_fetch_and(sigbits, ~(1UL << (sig - 1)));
}

inline uint64_t
sigbits_addset(atomic_sigbits_t *sigbits, l_sigset_t *set)
{
  return atomic_fetch_or(sigbits, LINUX_SIGSET_TO_UI64(set));
}

inline uint64_t
sigbits_delset(atomic_sigbits_t *sigbits, l_sigset_t *set)
{
  return atomic_fetch_and(sigbits, ~(LINUX_SIGSET_TO_UI64(set)));
}

inline uint64_t
sigbits_replace(atomic_sigbits_t *sigbits, l_sigset_t *set)
{
  return atomic_exchange(sigbits, LINUX_SIGSET_TO_UI64(set));
}

inline void
sigset_to_sigbits(atomic_sigbits_t *sigbits, sigset_t *set)
{
  for (int i = 1; i <= NSIG; i++) {
    if (!sigismember(set, i))
      continue;
    int num = darwin_to_linux_signal(i);
    if (num) {
      sigbits_addbit(sigbits, num);
    }
  }
}

DEFINE_SYSCALL(rt_sigaction, int, sig, gaddr_t, act, gaddr_t, oact, size_t, size)
{
  if (sig <= 0 || sig > LINUX_NSIG || sig == LINUX_SIGKILL || sig == LINUX_SIGSTOP) {
    return -LINUX_EINVAL;
  }

  l_sigaction_t lact;
  struct sigaction dact, doact;
  int dsig;

  if (oact != 0) {
    int n = copy_to_user(oact, &proc.sighand.sigaction[sig - 1], sizeof(l_sigaction_t));
    if (n > 0)
      return -LINUX_EFAULT;
  }

  if (act == 0) {
    return 0;
  }

  if (copy_from_user(&lact, act, sizeof(l_sigaction_t)))  {
    return -LINUX_EFAULT;
  }

  if (lact.lsa_flags & (LINUX_SA_SIGINFO | LINUX_SA_ONSTACK)) {
    warnk("unimplemented sa_flags is passed: 0x%llx\n", lact.lsa_flags);
  }

  void *handler;
  if ((void *) lact.lsa_handler == SIG_DFL || (void *) lact.lsa_handler == SIG_IGN) {
    handler = (void *) lact.lsa_handler;
  } else {
    lact.lsa_flags |= LINUX_SA_SIGINFO;
    handler = set_sigpending;
  }
  linux_to_darwin_sigaction(&lact, &dact, handler);
  dsig = linux_to_darwin_signal(sig);
  // TODO: make handlings of linux specific signals consistent

  int err = 0;
  pthread_rwlock_wrlock(&proc.sighand.lock);
  
  err = syswrap(sigaction(dsig, &dact, &doact));
  if (err >= 0) {
    proc.sighand.sigaction[sig - 1] = lact;
  }

  pthread_rwlock_unlock(&proc.sighand.lock);

  return err;
}

DEFINE_SYSCALL(rt_sigprocmask, int, how, gaddr_t, nset, gaddr_t, oset, size_t, size)
{
  l_sigset_t lset, loset;
  sigset_t dset, doset;

  // TODO: Fix the NULL nset handling
  if (copy_from_user(&lset, nset, sizeof(l_sigset_t)))  {
    return -LINUX_EFAULT;
  }
  LINUX_SIGDELSET(&lset, LINUX_SIGKILL);
  LINUX_SIGDELSET(&lset, LINUX_SIGSTOP);

  int dhow;
  switch (how) {
    case LINUX_SIG_BLOCK:
      dhow = SIG_BLOCK;
      LINUX_SIGSET_ADD(&task.sigmask, &lset);
      break;
    case LINUX_SIG_UNBLOCK:
      dhow = SIG_UNBLOCK;
      LINUX_SIGSET_DEL(&task.sigmask, &lset);
      break;
    case LINUX_SIG_SETMASK:
      dhow = SIG_SETMASK;
      LINUX_SIGSET_SET(&task.sigmask, &lset);
      break;
    default:
      return -LINUX_EINVAL;
  }

  linux_to_darwin_sigset(&lset, &dset);

  int err = syswrap(sigprocmask(dhow, &dset, &doset));
  if (err < 0) {
    return err;
  }

  if (oset != 0) {
    darwin_to_linux_sigset(&doset, &loset);
    if (copy_to_user(oset, &loset, sizeof(l_sigset_t))) {
      sigprocmask(SIG_SETMASK, &doset, NULL);
      return -LINUX_EFAULT;
    }
  }

  task.sigmask = lset;

  return 0;
}

DEFINE_SYSCALL(rt_sigpending, gaddr_t, set, size_t, size)
{
  return 0;
}

DEFINE_SYSCALL(rt_sigreturn)
{
  uint64_t rsp;
  vmm_read_register(HV_X86_RSP, &rsp);

  struct sigframe frame;
  if (copy_from_user(&frame, rsp - sizeof frame.rt_sigframe.sf_pretcode, sizeof frame)) {
    die_with_forcedsig(LINUX_SIGSEGV);
  }

  /* Restore sigcontext */
  for (uint64_t i = 0; i < NR_X86_REG_LIST; i++) {
    if (x86_reg_list[i] == HV_X86_IDT_BASE) {
      break;
    }
    //TODO: restore some segment related regs
    //TODO: restore FPU state
    vmm_write_register(x86_reg_list[i], frame.sigcontext.vcpu_reg[i]);
  }

  sigset_t dset;
  task.sigmask = frame.sigcontext.oldmask;
  linux_to_darwin_sigset(&task.sigmask, &dset);
  sigprocmask(SIG_SETMASK, &dset, NULL);

  uint64_t rip;
  vmm_read_register(HV_X86_RIP, &rip);
  vmm_write_register(HV_X86_RIP, rip - 2); // Because syshandler add 2 when returning to guest

  return 0;
}

DEFINE_SYSCALL(sigaltstack, gaddr_t, uss, gaddr_t, uoss)
{
  return 0;
}

DEFINE_SYSCALL(kill, l_pid_t, pid, int, sig)
{
  return send_signal(pid, sig);
}
