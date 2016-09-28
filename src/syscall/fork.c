#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <pthread.h>
#include <strings.h>

#include "common.h"
#include "noah.h"
#include "vmm.h"

#include "linux/common.h"
#include "linux/misc.h"
#include "linux/signal.h"

int
post_clone(pid_t clone_ret, unsigned long clone_flags, unsigned long newsp, gaddr_t parent_tid, gaddr_t child_tid, gaddr_t tls)
{
  if (clone_ret < 0) {
    return clone_ret;
  }

  if (clone_ret == 0) {
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

    if (clone_flags & LINUX_CLONE_SETTLS) {
      hv_vmx_vcpu_write_vmcs(task->vcpuid, VMCS_GUEST_FS_BASE, tls);
    }

  } else {
    if (clone_flags & LINUX_CLONE_PARENT_SETTID) {
      *(int *) guest_to_host(parent_tid) = clone_ret;
    }
  }

  return clone_ret;
}

int
clone_proc(unsigned long clone_flags, unsigned long newsp, gaddr_t parent_tid, gaddr_t child_tid, gaddr_t tls)
{
  // Because Apple Hypervisor Framwork won't let us use multiple VMs,
  // we destroy the current vm and restore it later
  struct vm_snapshot snapshot;
  vmm_snapshot(&snapshot);
  vmm_destroy();

  int ret = syswrap(fork());

  vmm_reentry(&snapshot);

  return post_clone(ret, clone_flags, newsp, parent_tid, child_tid, tls);
}

struct clone_thread_arg {
  unsigned long clone_flags;
  unsigned long newsp;
  gaddr_t parent_tid;
  gaddr_t child_tid;
  gaddr_t tls;
  struct vcpu_snapshot *vcpu_snapshot;
};

static void*
clone_thread_entry(void *varg)
{
  printk("clone_thread_entry\n");
  struct clone_thread_arg *arg = varg;
  task = malloc(sizeof(struct task));
  bzero(task, sizeof(struct task));

  hv_vcpu_create(&task->vcpuid, HV_VCPU_DEFAULT);

  vcpu_restore(arg->vcpu_snapshot);

  pthread_rwlock_wrlock(&proc.alloc_lock);
  proc.nr_tasks++;
  list_add_tail(&task->tasks, &proc.tasks);
  pthread_rwlock_unlock(&proc.alloc_lock);

  int sys_ret = post_clone(0, arg->clone_flags, arg->newsp, arg->parent_tid, arg->child_tid, arg->tls);

  uint64_t rip;
  hv_vcpu_write_register(task->vcpuid, HV_X86_RAX, sys_ret);
  hv_vcpu_write_register(task->vcpuid, HV_X86_RSP, arg->newsp);
  hv_vcpu_read_register(task->vcpuid, HV_X86_RIP, &rip);
  hv_vcpu_write_register(task->vcpuid, HV_X86_RIP, rip + 2);

  free(arg->vcpu_snapshot);
  free(varg);

  run_task();

  return NULL; // hv_vcpu_run failed for some reason
}

int
clone_thread(unsigned long clone_flags, unsigned long newsp, gaddr_t parent_tid, gaddr_t child_tid, gaddr_t tls)
{
  printk("clone_thread\n");
  uint64_t tid;
  pthread_t threadid;

  struct vcpu_snapshot *snapshot = malloc(sizeof(struct vcpu_snapshot));
  struct clone_thread_arg *arg = malloc(sizeof(struct clone_thread_arg));
  *arg = (struct clone_thread_arg){clone_flags, newsp, parent_tid, child_tid, tls, snapshot};
  vcpu_snapshot(snapshot);
  pthread_create(&threadid, NULL, clone_thread_entry, arg);
  pthread_threadid_np(threadid, &tid);

  return tid;
}

int
do_clone(unsigned long clone_flags, unsigned long newsp, gaddr_t parent_tid, gaddr_t child_tid, gaddr_t tls)
{
  int sigtype = clone_flags & 0xff;
  assert(sigtype == LINUX_SIGCHLD || sigtype == 0);

  clone_flags &= -0x100;
  unsigned long implemented = LINUX_CLONE_THREAD | LINUX_CLONE_DETACHED | LINUX_CLONE_SETTLS | LINUX_CLONE_CHILD_SETTID | LINUX_CLONE_CHILD_CLEARTID | LINUX_CLONE_PARENT_SETTID;
  unsigned long needed = 0;
  if (clone_flags & LINUX_CLONE_THREAD) {
    int needed = LINUX_CLONE_VM | LINUX_CLONE_FS | LINUX_CLONE_FILES | LINUX_CLONE_SIGHAND | LINUX_CLONE_SYSVSEM;
    implemented |= needed;
  }
  if ((clone_flags & ~implemented) || (clone_flags & needed) != needed) {
    fprintf(stderr, "unsupported clone_flags: %lx\n", clone_flags);
    printk("unsupported clone_flags: %lx\n", clone_flags);
    return -LINUX_EINVAL;
  }


  if (clone_flags & LINUX_CLONE_THREAD) {
    return clone_thread(clone_flags, newsp, parent_tid, child_tid, tls);
  } else {
    return clone_proc(clone_flags, newsp, parent_tid, child_tid, tls);
  }
}

DEFINE_SYSCALL(clone, unsigned long, clone_flags, unsigned long, newsp, gaddr_t, parent_tid, gaddr_t, child_tid, gaddr_t, tls)
{
  return do_clone(clone_flags, newsp, parent_tid, child_tid, tls);
}

DEFINE_SYSCALL(fork)
{
  return do_clone(LINUX_SIGCHLD, 0, 0, 0, 0);
}

DEFINE_SYSCALL(vfork)
{
  return do_clone(LINUX_SIGCHLD, 0, 0, 0, 0);
}
