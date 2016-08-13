#include "common.h"

#include "../sandbox.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

DEFINE_SYSCALL(exit, int, reason)
{
  _exit(reason);
}

DEFINE_SYSCALL(exit_group, int, reason)
{
  _exit(reason);
}

DEFINE_SYSCALL(arch_prctl, int, code, uint64_t, addr)
{
  puts("FIXME: arch_prctl");
  return 0;
}

DEFINE_SYSCALL(set_tid_address, int *, tidptr)
{
  puts("FIXME: set_tid_address");
  return 0;
}
