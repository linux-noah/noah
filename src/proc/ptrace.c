#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <pthread.h>

#include "common.h"
#include "noah.h"
#include "vmm.h"
#include "mm.h"

#include "linux/common.h"
#include "linux/misc.h"
#include "linux/errno.h"
#include "linux/ptrace.h"

DEFINE_SYSCALL(ptrace, long, request, long, pid, unsigned long, addr, unsigned long, data)
{
  switch (request) {
  case LINUX_PTRACE_GETEVENTMSG:
    break;
  case LINUX_PTRACE_GETREGSET:
    break;
  case LINUX_PTRACE_GETSIGINFO:
    break;
  case LINUX_PTRACE_INTERRUPT:
    break;
  case LINUX_PTRACE_LISTEN:
    break;
  case LINUX_PTRACE_SEIZE:
    break;
  case LINUX_PTRACE_SYSCALL:
    break;
  }
  return -LINUX_ENOSYS;
}
