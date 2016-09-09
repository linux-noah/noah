#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <unistd.h>
#include <pthread.h>
#include <strings.h>

#include "common.h"
#include "noah.h"

#include "linux/common.h"
#include "linux/misc.h"
#include "linux/signal.h"

int
post_clone(pid_t pid, unsigned long clone_flags, unsigned long newsp, gaddr_t parent_tid, gaddr_t child_tid)
{
  if (pid < 0) {
    return pid;
  }

  if (pid == 0) {
    task->set_child_tid = task->clear_child_tid = 0;
    if (clone_flags & LINUX_CLONE_CHILD_SETTID) {
      task->set_child_tid = child_tid;
    }
    if (clone_flags & LINUX_CLONE_CHILD_CLEARTID) {
      task->clear_child_tid = child_tid;
    }

    if (task->set_child_tid != 0) {
      *(int *) guest_to_host(task->set_child_tid) = getpid();
    }
  }

  return pid;
}

int
clone_proc(unsigned long clone_flags, unsigned long newsp, gaddr_t parent_tid, gaddr_t child_tid)
{
  // Because Apple Hypervisor Framwork won't let us use multiple VMs,
  // we destroy the current vm and restore it later
  struct vm_snapshot snapshot;
  vmm_snapshot(&snapshot);
  vmm_destroy();

  int ret = syswrap(fork());

  vmm_reentry(&snapshot);

  return post_clone(ret, clone_flags, newsp, parent_tid, child_tid);
}

int
clone_thread(unsigned long clone_flags, unsigned long newsp, gaddr_t parent_tid, gaddr_t child_tid)
{
  return -LINUX_EINVAL;
}

int
do_clone(unsigned long clone_flags, unsigned long newsp, gaddr_t parent_tid, gaddr_t child_tid)
{
  int ret;
  int sigtype = clone_flags & 0xff;
  clone_flags &= -0x100;

  assert(newsp == 0);
  assert(parent_tid == 0);
  assert(sigtype == LINUX_SIGCHLD);

  if ((clone_flags & ~(LINUX_CLONE_CHILD_CLEARTID | LINUX_CLONE_CHILD_SETTID)) != 0) {
    goto unsupported_flag;
  }
  if ((clone_flags & LINUX_CLONE_VM) && !(clone_flags & LINUX_CLONE_THREAD)) {
    goto unsupported_flag;
  }

  if (clone_flags & (LINUX_CLONE_VM | LINUX_CLONE_THREAD)) {
    return clone_thread(clone_flags, newsp, parent_tid, child_tid);
  } else {
    return clone_proc(clone_flags, newsp, parent_tid, child_tid);
  }

unsupported_flag:
  fprintf(stderr, "unsupported clone_flags: %lx\n", clone_flags);
  printk("unsupported clone_flags: %lx\n", clone_flags);
  return -LINUX_EINVAL;
}

DEFINE_SYSCALL(clone, unsigned long, clone_flags, unsigned long, newsp, gaddr_t, parent_tid, gaddr_t, child_tid)
{
  return do_clone(clone_flags, newsp, parent_tid, child_tid);
}

DEFINE_SYSCALL(fork)
{
  return do_clone(LINUX_SIGCHLD, 0, 0, 0);
}

DEFINE_SYSCALL(vfork)
{
  return do_clone(LINUX_SIGCHLD, 0, 0, 0);
}
