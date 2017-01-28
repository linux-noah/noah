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
#include <pthread.h>

static void
set_sigpending(int signum, siginfo_t *info, ucontext_t *context)
{
  int l_signum = darwin_to_linux_signal(signum);
  sigbits_addbit(&task.sigpending, l_signum);
}

int
send_signal(pid_t pid, int signum)
{
  // Currently, just kill it to them
  if (signum >= LINUX_SIGRTMIN) {
    warnk("RT signal is raised: %d\n", signum);
    return 0;
  }
  int dsignum = (signum == 0) ? 0 : linux_to_darwin_signal(signum);
  return syswrap(kill(pid, dsignum));
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
  sigbits_emptyset(&t->sigpending);
  sigpending(&set);
  sigset_to_sigbits(&proc->sigpending, &set);
}

static void
reset_sas()
{
  task.sas = (l_stack_t) {
    .ss_sp = 0,
    .ss_flags = LINUX_SS_DISABLE,
    .ss_size = 0
  };
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
  reset_sas();
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
  uint64_t bits, sig;

 retry:
  sig = 1;
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
  if (sig > 32) {
    return 0;
  }

  if (!(sigbits_delbit(sigbits, sig) & (1 << (sig - 1)))) {
    // any other thread among the process took this signal
    goto retry;
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
  return fetch_sig_from_sigbits(&task.sigpending);
}

bool
has_sigpending()
{
  return (proc.sigpending | task.sigpending) & ~LINUX_SIGSET_TO_UI64(&task.sigmask);
}

static void
setup_sigcontext(struct l_sigcontext *mcontext)
{
  vmm_read_register(HV_X86_R8, &mcontext->sc_r8);
  vmm_read_register(HV_X86_R9, &mcontext->sc_r9);
  vmm_read_register(HV_X86_R10, &mcontext->sc_r10);
  vmm_read_register(HV_X86_R11, &mcontext->sc_r11);
  vmm_read_register(HV_X86_R12, &mcontext->sc_r12);
  vmm_read_register(HV_X86_R13, &mcontext->sc_r13);
  vmm_read_register(HV_X86_R14, &mcontext->sc_r14);
  vmm_read_register(HV_X86_R15, &mcontext->sc_r15);
  vmm_read_register(HV_X86_RDI, &mcontext->sc_rdi);
  vmm_read_register(HV_X86_RSI, &mcontext->sc_rsi);
  vmm_read_register(HV_X86_RBP, &mcontext->sc_rbp);
  vmm_read_register(HV_X86_RBX, &mcontext->sc_rbx);
  vmm_read_register(HV_X86_RDX, &mcontext->sc_rdx);
  vmm_read_register(HV_X86_RAX, &mcontext->sc_rax);
  vmm_read_register(HV_X86_RCX, &mcontext->sc_rcx);
  vmm_read_register(HV_X86_RSP, &mcontext->sc_rsp);
  vmm_read_register(HV_X86_RIP, &mcontext->sc_rip);
  vmm_read_register(HV_X86_RFLAGS, &mcontext->sc_rflags);
  uint64_t cs, gs, fs, ss;
  vmm_read_register(HV_X86_CS, &cs); // Is saving segment indices really suffice? Manipulating base, limit may be needed.
  vmm_read_register(HV_X86_GS, &gs);
  vmm_read_register(HV_X86_FS, &fs);
  vmm_read_register(HV_X86_SS, &ss);
  mcontext->sc_cs = cs;
  mcontext->sc_gs = gs;
  mcontext->sc_fs = fs;
  mcontext->sc_ss = ss;
  // TODO: err, trapno
  mcontext->sc_mask = task.sigmask;
  // TODO: cr2
  // TODO: save FPU state
}

static void
restore_sigcontext(struct l_sigcontext *mcontext)
{
  vmm_write_register(HV_X86_R8, mcontext->sc_r8);
  vmm_write_register(HV_X86_R9, mcontext->sc_r9);
  vmm_write_register(HV_X86_R10, mcontext->sc_r10);
  vmm_write_register(HV_X86_R11, mcontext->sc_r11);
  vmm_write_register(HV_X86_R12, mcontext->sc_r12);
  vmm_write_register(HV_X86_R13, mcontext->sc_r13);
  vmm_write_register(HV_X86_R14, mcontext->sc_r14);
  vmm_write_register(HV_X86_R15, mcontext->sc_r15);
  vmm_write_register(HV_X86_RDI, mcontext->sc_rdi);
  vmm_write_register(HV_X86_RSI, mcontext->sc_rsi);
  vmm_write_register(HV_X86_RBP, mcontext->sc_rbp);
  vmm_write_register(HV_X86_RBX, mcontext->sc_rbx);
  vmm_write_register(HV_X86_RDX, mcontext->sc_rdx);
  vmm_write_register(HV_X86_RAX, mcontext->sc_rax);
  vmm_write_register(HV_X86_RCX, mcontext->sc_rcx);
  vmm_write_register(HV_X86_RSP, mcontext->sc_rsp);
  vmm_write_register(HV_X86_RIP, mcontext->sc_rip);
  vmm_write_register(HV_X86_RFLAGS, mcontext->sc_rflags); // TODO: fix some flags after implementing proper rflags initialization
  // TODO: set user mode bits
  vmm_write_register(HV_X86_CS, mcontext->sc_cs);
  vmm_write_register(HV_X86_GS, mcontext->sc_gs);
  vmm_write_register(HV_X86_FS, mcontext->sc_fs);
  vmm_write_register(HV_X86_SS, mcontext->sc_ss); // TODO: handle ss register more carefully if you want to support software such as DOSEMU
  
  // TODO: restore FPU state
}

static l_int
sas_ss_flags(uint64_t rsp)
{
  if (task.sas.ss_flags & LINUX_SS_DISABLE || task.sas.ss_size == 0) {
    return LINUX_SS_DISABLE;
  }
  if (rsp > task.sas.ss_sp && rsp - task.sas.ss_sp < task.sas.ss_size) {
    return LINUX_SS_ONSTACK | task.sas.ss_flags;
  }
  return task.sas.ss_flags;
}

static int
setup_sigframe(int signum)
{
  struct l_rt_sigframe frame;

  assert(signum <= LINUX_NSIG);
  static_assert(is_aligned(sizeof frame, sizeof(uint64_t)), "signal frame size should be aligned");

  uint64_t rsp;
  vmm_read_register(HV_X86_RSP, &rsp);
  if ((proc.sighand.sigaction[signum - 1].lsa_flags & LINUX_SA_ONSTACK) && (sas_ss_flags(rsp) & ~LINUX_SS_AUTODISARM) == 0) {
    rsp = task.sas.ss_sp + task.sas.ss_size;
  }

  /* Setup sigframe */
  if (proc.sighand.sigaction[signum - 1].lsa_flags & LINUX_SA_RESTORER) {
    frame.sf_pretcode = (gaddr_t) proc.sighand.sigaction[signum - 1].lsa_restorer;
  } else {
    // x86_64 should always use SA_RESTORER
    return -LINUX_EFAULT;
  }
  bzero(&frame.sf_si, sizeof(l_siginfo_t));
  frame.sf_si.lsi_signo = signum;

  /* Setup ucontext */
  frame.sf_sc.uc_flags = LINUX_UC_FP_XSTATE | LINUX_UC_SIGCONTEXT_SS | LINUX_UC_STRICT_RESTORE_SS; // Handle more carefully if you want to support DOSEMU
  frame.sf_sc.uc_link = 0;
  frame.sf_sc.uc_sigmask = task.sigmask;
  frame.sf_sc.uc_stack = task.sas;
  if (task.sas.ss_flags & LINUX_SS_AUTODISARM) {
    reset_sas();
  }
  setup_sigcontext(&frame.sf_sc.uc_mcontext);

  sigset_t dset;
  frame.sf_sc.uc_mcontext.sc_mask = task.sigmask;
  l_sigset_t newmask = proc.sighand.sigaction[signum - 1].lsa_mask;
  if (!(proc.sighand.sigaction[signum - 1].lsa_flags & LINUX_SA_NOMASK)) {
    LINUX_SIGADDSET(&newmask, signum);
  }
  task.sigmask = newmask;
  linux_to_darwin_sigset(&newmask, &dset);
  sigprocmask(SIG_SETMASK, &dset, NULL);

  /* OK, push them then... */
  rsp -= sizeof frame;
  vmm_write_register(HV_X86_RSP, rsp);
  if (copy_to_user(rsp, &frame, sizeof frame)) {
    return -LINUX_EFAULT;
  }

  /* Setup registers */
  vmm_write_register(HV_X86_RDI, signum);
  vmm_write_register(HV_X86_RSI, rsp + offsetof(struct l_rt_sigframe, sf_si));
  vmm_write_register(HV_X86_RDX, rsp + offsetof(struct l_rt_sigframe, sf_sc));

  vmm_write_register(HV_X86_RAX, 0);
  vmm_write_register(HV_X86_RIP, proc.sighand.sigaction[signum - 1].lsa_handler);

  return 0;
}

static void
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
          die_with_forcedsig(LINUX_SIGSEGV);
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

void
handle_signal()
{
  wake_sighandler();
  main_loop(1);
}

DEFINE_SYSCALL(alarm, unsigned int, seconds)
{
  return syswrap(alarm(seconds));
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
  if (sig <= 0 || sig > LINUX_NSIG || sig == LINUX_SIGKILL || sig == LINUX_SIGSTOP || size != sizeof(l_sigset_t)) {
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

  if (lact.lsa_flags & (LINUX_SA_SIGINFO)) {
    warnk("SA_SIGINFO implementaion is incomplete: 0x%llx\n", lact.lsa_flags);
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
  l_sigset_t lset;
  sigset_t dset;

  if (size != sizeof(l_sigset_t)) {
    return -LINUX_EINVAL;
  }

  if (oset != 0) {
    if (copy_to_user(oset, &task.sigmask, sizeof task.sigmask)) {
      return -LINUX_EFAULT;
    }
  }

  if (nset == 0) {
    return 0;
  }

  if (copy_from_user(&lset, nset, sizeof(l_sigset_t)))  {
    return -LINUX_EFAULT;
  }
  LINUX_SIGDELSET(&lset, LINUX_SIGKILL);
  LINUX_SIGDELSET(&lset, LINUX_SIGSTOP);

  switch (how) {
    case LINUX_SIG_BLOCK:
      LINUX_SIGSET_ADD(&task.sigmask, &lset);
      break;
    case LINUX_SIG_UNBLOCK:
      LINUX_SIGSET_DEL(&task.sigmask, &lset);
      break;
    case LINUX_SIG_SETMASK:
      LINUX_SIGSET_SET(&task.sigmask, &lset);
      break;
    default:
      return -LINUX_EINVAL;
  }

  linux_to_darwin_sigset(&task.sigmask, &dset);

  int err = syswrap(pthread_sigmask(SIG_SETMASK, &dset, NULL));
  if (err < 0) {
    return err;
  }

  return 0;
}

DEFINE_SYSCALL(rt_sigsuspend, gaddr_t, nset, size_t, size)
{
  if (size != sizeof(l_sigset_t)) {
    return -LINUX_EINVAL;
  }

  l_sigset_t lnset, loset = task.sigmask;

  if (copy_from_user(&lnset, nset, sizeof(l_sigset_t))) {
    return -LINUX_EFAULT;
  }
  LINUX_SIGDELSET(&lnset, LINUX_SIGKILL);
  LINUX_SIGDELSET(&lnset, LINUX_SIGSTOP);
  task.sigmask = lnset;

  while (1) {
    /* NB: macOS's sleep is implemented using nanosleep. That's why we can use
       sleep to implement sugsuspend without worrying about alarm(2). */
    sleep(114514);
    if (has_sigpending()) {
      break;
    }
  }
  handle_signal();
  warnk("signal handled\n");
  task.sigmask = loset;
  return -LINUX_EINTR;          /* returns -EINTR when its execution ends NORMALLY */
}

DEFINE_SYSCALL(rt_sigpending, gaddr_t, set, size_t, size)
{
  if (size > sizeof(l_sigset_t)) {
    return -LINUX_EINVAL;
  }
  int ret = 0;

  pthread_rwlock_rdlock(&proc.sighand.lock);
  if (copy_to_user(set, &task.sigpending, size) > 0) {
    ret = -LINUX_EFAULT;
  }
  pthread_rwlock_unlock(&proc.sighand.lock);

  return ret;
}

DEFINE_SYSCALL(rt_sigreturn)
{
  uint64_t rsp;
  vmm_read_register(HV_X86_RSP, &rsp);

  struct l_rt_sigframe frame;
  if (copy_from_user(&frame, rsp - sizeof frame.sf_pretcode, sizeof frame)) {
    die_with_forcedsig(LINUX_SIGSEGV);
  }

  restore_sigcontext(&frame.sf_sc.uc_mcontext);
  sigset_t dset;
  task.sigmask = frame.sf_sc.uc_mcontext.sc_mask;
  linux_to_darwin_sigset(&task.sigmask, &dset);
  sigprocmask(SIG_SETMASK, &dset, NULL);

  uint64_t rip;
  vmm_read_register(HV_X86_RIP, &rip);
  vmm_write_register(HV_X86_RIP, rip - 2); // Because syshandler add 2 when returning to guest

  return 0;
}

DEFINE_SYSCALL(sigaltstack, gaddr_t, uss, gaddr_t, uoss)
{
  uint64_t rsp;
  vmm_read_register(HV_X86_RSP, &rsp);
  l_stack_t ss, oss = task.sas;
  oss.ss_flags = sas_ss_flags(rsp);

  if (uoss != 0) {
    if (copy_to_user(uoss, &oss, sizeof task.sas)) {
      return -LINUX_EFAULT;
    }
  }
  if (uss == 0) {
    return 0;
  }
  if (oss.ss_flags & LINUX_SS_ONSTACK) {
    return -LINUX_EPERM;
  }

  if (copy_from_user(&ss, uss, sizeof ss)) {
    return -LINUX_EFAULT;
  }

  if (ss.ss_size < LINUX_MINSIGSTKSZ) {
    return -LINUX_ENOMEM;
  }
  int mode = ss.ss_flags & ~LINUX_SS_AUTODISARM;
  if (mode != SS_DISABLE && mode != SS_ONSTACK && mode != 0) { // Linux allows only SS_ONSTACK to be passed against man
    return -LINUX_EINVAL;
  }

  task.sas = ss;

  return 0;
}

DEFINE_SYSCALL(kill, l_pid_t, pid, int, sig)
{
  return send_signal(pid, sig);
}
