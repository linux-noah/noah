#include "common.h"
#include "linux/signal.h"

#include "noah.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <assert.h>

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
  return 0;
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

DEFINE_SYSCALL(sigaltstack, gaddr_t, uss, gaddr_t, uoss)
{
  return 0;
}

DEFINE_SYSCALL(kill, l_pid_t, pid, int, sig)
{
  return syswrap(kill(pid, linux_to_darwin_signal(sig)));
}
