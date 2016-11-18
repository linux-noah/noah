#include "common.h"

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

DEFINE_SYSCALL(rt_sigaction, int, sig, gaddr_t, act, gaddr_t, oact, size_t, size)
{
  return 0;
}

DEFINE_SYSCALL(rt_sigprocmask, int, how, gaddr_t, nset, gaddr_t, oset, size_t, size)
{
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
