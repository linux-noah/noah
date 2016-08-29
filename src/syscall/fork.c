#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <unistd.h>

#include "common.h"
#include "noah.h"

#include "linux/common.h"
#include "linux/misc.h"
#include "linux/signal.h"

int
do_fork(unsigned long clone_flags, unsigned long newsp, gaddr_t parent_tid, gaddr_t child_tid)
{
  int sigtype = clone_flags & 0xff;
  clone_flags &= -0x100;

  assert(newsp == 0);
  assert(parent_tid == 0);
  assert(sigtype == LINUX_SIGCHLD);

  if ((clone_flags & ~(LINUX_CLONE_CHILD_CLEARTID | LINUX_CLONE_CHILD_SETTID)) != 0) {
    fprintf(stderr, "unsupported clone flags: %lx\n", clone_flags);
    exit(1);
  }

  // Because Apple Hypervisor Framwork won't let us use multiple VMs,
  // we destroy the current vm and restore it later
  vmm_snapshot();
  vmm_destroy();

  pid_t pid = fork();

  int ret;
  if (pid < 0) {
    ret = -1;
  } else {
    ret = pid;
  }

  vmm_reentry();

  if (pid == 0) {
    task.set_child_tid = task.clear_child_tid = 0;
    if (clone_flags & LINUX_CLONE_CHILD_SETTID) {
      task.set_child_tid = child_tid;
    }
    if (clone_flags & LINUX_CLONE_CHILD_CLEARTID) {
      task.clear_child_tid = child_tid;
    }

    if (task.set_child_tid != 0) {
      *(int *) guest_to_host(task.set_child_tid) = getpid();
    }
  }

  return ret;
}

DEFINE_SYSCALL(clone, unsigned long, clone_flags, unsigned long, newsp, gaddr_t, parent_tid, gaddr_t, child_tid)
{
  return do_fork(clone_flags, newsp, parent_tid, child_tid);
}

DEFINE_SYSCALL(fork)
{
  return do_fork(LINUX_SIGCHLD, 0, 0, 0);
}

DEFINE_SYSCALL(vfork)
{
  return do_fork(LINUX_SIGCHLD, 0, 0, 0);
}
