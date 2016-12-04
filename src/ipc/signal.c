#include "common.h"
#include "linux/signal.h"

#include "noah.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <assert.h>
#include <stdatomic.h>

_Thread_local atomic_sigbits_t task_sigpending;  // sigpending cannot be inside task struct because thread local variables referred by signal handler should be atomic type

void
set_sigpending(int signum)
{
  int l_signum = darwin_to_linux_signal(signum);
  // locking proc structure also blcoks signals, so don't need to acquire rdlock of proc
  sigbits_addbit(&task_sigpending, l_signum);
  printf("sigpendin!, sig:%llx\n", task_sigpending);
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
      fprintf(stderr, "sa_handler:%d\n", (int)oact.sa_handler);
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
  t->sigpending = &task_sigpending; //TODO
  sigbits_emptyset(t->sigpending);
  sigpending(&set);
  darwin_to_linux_sigset(&set, &proc->sigpending);
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

DEFINE_SYSCALL(rt_sigaction, int, sig, gaddr_t, act, gaddr_t, oact, size_t, size)
{
  if (sig <= 0 || sig > LINUX_NSIG || sig == LINUX_SIGKILL || sig == LINUX_SIGSTOP) {
    return -LINUX_EINVAL;
  }

  l_sigaction_t lact;
  struct sigaction dact, doact;

  if (copy_from_user(&lact, act, sizeof(l_sigaction_t)))  {
    return -LINUX_EFAULT;
  }

  linux_to_darwin_sigaction(&lact, &dact, set_sigpending);

  int err = 0;
  pthread_rwlock_wrlock(&proc.sighand.lock);
  
  err = syswrap(sigaction(sig, &dact, &doact));
  if (err < 0) {
    goto out;
  }
  if (oact != 0 && copy_to_user(oact, &proc.sighand.sigaction[sig - 1], sizeof(l_sigaction_t))) {
    sigaction(sig, &doact, NULL);
    err = -LINUX_EFAULT;
    goto out;
  }
  proc.sighand.sigaction[sig - 1] = lact;

out:
  pthread_rwlock_unlock(&proc.sighand.lock);

  return err;
}

DEFINE_SYSCALL(rt_sigprocmask, int, how, gaddr_t, nset, gaddr_t, oset, size_t, size)
{
  l_sigset_t lset, loset;
  sigset_t dset, doset;

  if (copy_from_user(&lset, nset, sizeof(l_sigset_t)))  {
    return -LINUX_EFAULT;
  }
  LINUX_SIGDELSET(&lset, SIGKILL);
  LINUX_SIGDELSET(&lset, SIGSTOP);

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
  sigset_t *p_doset = (oset == 0) ? NULL : &doset;

  int err = syswrap(sigprocmask(dhow, &dset, p_doset));
  if (err < 0) {
    return err;
  }

  if (p_doset == NULL) {
    return 0;
  }

  darwin_to_linux_sigset(&doset, &loset);
  if (copy_to_user(oset, &loset, sizeof(l_sigset_t))) {
    return -LINUX_EFAULT;
  }

  return 0;
}

DEFINE_SYSCALL(rt_sigpending, gaddr_t, set, size_t, size)
{
  return 0;
}

DEFINE_SYSCALL(rt_sigreturn)
{
  printf("sig return!\n");
  return 0;
}

DEFINE_SYSCALL(sigaltstack, gaddr_t, uss, gaddr_t, uoss)
{
  return 0;
}

DEFINE_SYSCALL(kill, l_pid_t, pid, int, sig)
{
  return syswrap(kill(pid, linux_to_darwin_signal(sig)));
}
