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

static void
init_task(unsigned long clone_flags, gaddr_t child_tid, gaddr_t tls)
{
  LINUX_SIGEMPTYSET(&task.sigmask);
  INIT_SIGBIT(&task.sigpending);

  if (clone_flags & LINUX_CLONE_THREAD) {
    pthread_threadid_np(NULL, &task.tid);
  } else {
    task.tid = getpid();
  }

  task.set_child_tid = task.clear_child_tid = 0;
  if (clone_flags & LINUX_CLONE_CHILD_SETTID) {
    task.set_child_tid = child_tid;
  }
  if (clone_flags & LINUX_CLONE_CHILD_CLEARTID) {
    task.clear_child_tid = child_tid;
  }

  if (task.set_child_tid != 0) {
    int tid = do_gettid();
    if (copy_to_user(task.set_child_tid, &tid, sizeof tid)) {
      assert(false);
    }
  }

  /* TODO: do we need to clear task.robust_list when CLONE_THREAD is set? */
  /* task.robust_list = 0; */
  /* task.robust_list_len = 0; */

  if (clone_flags & LINUX_CLONE_SETTLS) {
    vmm_write_vmcs(VMCS_GUEST_FS_BASE, tls);
  }
}

int
__do_clone_process(unsigned long clone_flags, unsigned long newsp, gaddr_t parent_tid, gaddr_t child_tid, gaddr_t tls)
{
  // Because Apple Hypervisor Framwork won't let us use multiple VMs,
  // we destroy the current vm and restore it later
  struct vmm_snapshot snapshot;
  vmm_snapshot(&snapshot);
  vmm_destroy();

  int ret = syswrap(fork());

  vmm_reentry(&snapshot);

  if (ret < 0) {
    return ret;
  }

  if (ret == 0) {
    /* NB: we don't yet support multi-threaded execve so comment out the following: */
    /* proc.nr_tasks = 1; */
    /* INIT_LIST_HEAD(&proc.tasks); */
    /* list_add(&task.head, &proc.tasks); */
    init_task(clone_flags, child_tid, tls);
    if (clone_flags & LINUX_CLONE_PARENT_SETTID) {
      int tid = getpid();
      if (copy_to_user(parent_tid, &tid, sizeof tid)) {
        return -LINUX_EFAULT;
      }
    }
  } else {
    if (clone_flags & LINUX_CLONE_PARENT_SETTID) {
      if (copy_to_user(parent_tid, &ret, sizeof ret)) {
        return -LINUX_EFAULT;
      }
    }
  }

  return ret;
}

struct clone_thread_arg {
  unsigned long clone_flags;
  unsigned long newsp;
  gaddr_t parent_tid;
  gaddr_t child_tid;
  gaddr_t tls;
  pthread_cond_t cond;
  pthread_mutex_t mutex;
  struct vcpu_snapshot vcpu_snapshot;
};

static void*
__start_thread(struct clone_thread_arg *arg)
{
  uint64_t rip;

  pthread_mutex_lock(&arg->mutex);

  printk("__start_thread\n");

  vmm_create_vcpu(&arg->vcpu_snapshot);
  vmm_write_register(HV_X86_RAX, 0);
  vmm_write_register(HV_X86_RSP, arg->newsp);
  vmm_read_register(HV_X86_RIP, &rip);
  vmm_write_register(HV_X86_RIP, rip + 2);

  pthread_rwlock_wrlock(&proc.lock);
  proc.nr_tasks++;
  list_add(&task.head, &proc.tasks);
  pthread_rwlock_unlock(&proc.lock);

  INIT_SIGBIT(&task.sigpending);

  init_task(arg->clone_flags, arg->child_tid, arg->tls);

  pthread_cond_signal(&arg->cond);

  pthread_mutex_unlock(&arg->mutex);

  main_loop(0);

  return NULL; // hv_vcpu_run failed for some reason
}

int
__do_clone_thread(unsigned long clone_flags, unsigned long newsp, gaddr_t parent_tid, gaddr_t child_tid, gaddr_t tls)
{
  printk("clone_thread\n");
  uint64_t tid;
  pthread_t threadid;

  struct clone_thread_arg *arg = malloc(sizeof *arg);
  *arg = (struct clone_thread_arg){clone_flags, newsp, parent_tid, child_tid, tls};
  vmm_snapshot_vcpu(&arg->vcpu_snapshot);
  pthread_cond_init(&arg->cond, NULL);
  pthread_mutex_init(&arg->mutex, NULL);
  pthread_mutex_lock(&arg->mutex);
  pthread_create(&threadid, NULL, (void *)__start_thread, arg);
  pthread_cond_wait(&arg->cond, &arg->mutex);
  pthread_mutex_unlock(&arg->mutex);
  pthread_cond_destroy(&arg->cond);
  pthread_mutex_destroy(&arg->mutex);
  free(arg);

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
    warnk("unsupported clone_flags: %lx\n", clone_flags);
    return -LINUX_EINVAL;
  }


  if (clone_flags & LINUX_CLONE_THREAD) {
    return __do_clone_thread(clone_flags, newsp, parent_tid, child_tid, tls);
  } else {
    return __do_clone_process(clone_flags, newsp, parent_tid, child_tid, tls);
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
