#include "common.h"

#include "noah.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

DEFINE_SYSCALL(rt_sigaction, int, sig, const struct sigaction *, act, struct sigaction *, oact, size_t, size)
{
  return 0;
}

DEFINE_SYSCALL(rt_sigprocmask, int, how, sigset_t *, nset, sigset_t *, oset, size_t, size)
{
  return 0;
}

DEFINE_SYSCALL(rt_sigpending, gaddr_t, set, size_t, size)
{
  return 0;
}
