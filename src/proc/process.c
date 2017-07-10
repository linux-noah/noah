#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <pthread.h>
#include <assert.h>

#include "common.h"
#include "noah.h"
#include "vmm.h"
#include "mm.h"

#include "linux/common.h"
#include "linux/misc.h"
#include "linux/errno.h"
#include "linux/futex.h"

#include <sys/sysctl.h>

struct proc proc;
_Thread_local struct task task;

DEFINE_SYSCALL(exit, int, reason)
{
  _exit(reason);
}
