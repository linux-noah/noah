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

#include "linux/common.h"
#include "linux/misc.h"
#include "linux/errno.h"

struct proc proc;
_Thread_local struct task task;

DEFINE_SYSCALL(getpid)
{
  return syswrap(getpid());
}

DEFINE_SYSCALL(getuid)
{
  return syswrap(getuid());
}

DEFINE_SYSCALL(getgid)
{
  return syswrap(getgid());
}

DEFINE_SYSCALL(setuid, l_uid_t, uid)
{
  return syswrap(setuid(uid));
}

DEFINE_SYSCALL(setgid, l_gid_t, gid)
{
  return syswrap(setgid(gid));
}

DEFINE_SYSCALL(geteuid)
{
  return syswrap(geteuid());
}

DEFINE_SYSCALL(getegid)
{
  return syswrap(getegid());
}

DEFINE_SYSCALL(setpgid, pid_t, pid, pid_t, pgid)
{
  return syswrap(setpgid(pid, pgid));
}

DEFINE_SYSCALL(getppid)
{
  return syswrap(getppid());
}

DEFINE_SYSCALL(getpgrp)
{
  return syswrap(getpgrp());
}

DEFINE_SYSCALL(gettid)
{
  uint64_t tid;
  pthread_threadid_np(NULL, &tid);
  return tid;
}

DEFINE_SYSCALL(getrlimit, int, l_resource, gaddr_t, rl_ptr)
{
  struct rlimit *l_rl = guest_to_host(rl_ptr);

  int resource = 0;
  switch (l_resource) {
  case LINUX_RLIMIT_CPU: resource = RLIMIT_CPU; break;
  case LINUX_RLIMIT_FSIZE: resource = RLIMIT_FSIZE; break;
  case LINUX_RLIMIT_DATA: resource = RLIMIT_DATA; break;
  case LINUX_RLIMIT_STACK: resource = RLIMIT_STACK; break;
  case LINUX_RLIMIT_CORE: resource = RLIMIT_CORE; break;
  case LINUX_RLIMIT_RSS: resource = RLIMIT_RSS; break;
  case LINUX_RLIMIT_NPROC: resource = RLIMIT_NPROC; break;
  case LINUX_RLIMIT_NOFILE: resource = RLIMIT_NOFILE; break;
  case LINUX_RLIMIT_MEMLOCK: resource = RLIMIT_MEMLOCK; break;
  case LINUX_RLIMIT_AS: resource = RLIMIT_AS; break;
  }

  return syswrap(getrlimit(resource, l_rl));
}

DEFINE_SYSCALL(setrlimit, unsigned int, resource, gaddr_t, rlim)
{
  return 0;
}

DEFINE_SYSCALL(exit, int, reason)
{
  if (task.clear_child_tid) {
    *(int*)guest_to_host(task.clear_child_tid) = 0;
    do_futex_wake(task.clear_child_tid, 1);
  }
  vmm_destroy_vcpu();
  pthread_rwlock_wrlock(&proc.lock);
  if (proc.nr_tasks == 1) {
    _exit(reason);
  } else {
    proc.nr_tasks--;
    pthread_rwlock_unlock(&proc.lock);
    pthread_exit(&reason);
  }
}

DEFINE_SYSCALL(exit_group, int, reason)
{
  if (task.clear_child_tid) {
    *(int*)guest_to_host(task.clear_child_tid) = 0;
    do_futex_wake(task.clear_child_tid, 1);
  }
  _exit(reason);
}

DEFINE_SYSCALL(capget, gaddr_t, header_ptr, gaddr_t, data_ptr)
{
  printk("capget is unimplemented\n");
  return 0;
}

struct utsname {
  char sysname[65];
  char nodename[65];
  char release[65];
  char version[65];
  char machine[65];
  char domainname[65];
};

DEFINE_SYSCALL(uname, gaddr_t, buf)
{
  struct utsname *_buf = guest_to_host(buf);

  strncpy(_buf->sysname, "Linux", sizeof _buf->sysname - 1);
  strncpy(_buf->release, LINUX_RELEASE, sizeof _buf->release - 1);
  strncpy(_buf->version, LINUX_VERSION, sizeof _buf->version - 1);
  strncpy(_buf->machine, "x86_64", sizeof _buf->machine - 1);
  strncpy(_buf->domainname, "GNU/Linux", sizeof _buf->domainname - 1);

  return syswrap(gethostname(_buf->nodename, sizeof _buf->nodename - 1) < 0);
}

DEFINE_SYSCALL(arch_prctl, int, code, gaddr_t, addr)
{
  switch (code) {
  case LINUX_ARCH_SET_GS:
    vmm_write_vmcs(VMCS_GUEST_GS_BASE, addr);
    return 0;
  case LINUX_ARCH_SET_FS:
    vmm_write_vmcs(VMCS_GUEST_FS_BASE, addr);
    return 0;
  case LINUX_ARCH_GET_FS:
    vmm_read_vmcs(VMCS_GUEST_FS_BASE, guest_to_host(addr));
    return 0;
  case LINUX_ARCH_GET_GS:
    vmm_read_vmcs(VMCS_GUEST_GS_BASE, guest_to_host(addr));
    return 0;
  default:
    return -LINUX_EINVAL;
  }
}

DEFINE_SYSCALL(set_tid_address, gaddr_t, tidptr)
{
  task.clear_child_tid = tidptr;
  return 0;
}

DEFINE_SYSCALL(set_robust_list, gaddr_t, head, size_t, len)
{
  return 0;
}

DEFINE_SYSCALL(wait4, int, pid, gaddr_t, gstatus, int, options, gaddr_t, grusage)
{
  int *status = (int*)guest_to_host(gstatus);
  struct rusage *rusage = (struct rusage*)guest_to_host(grusage);

  return syswrap(wait4(pid, status, options, rusage));
}

static void
darwin_to_linux_rusage(struct rusage *ru, struct l_rusage *lru)
{
  lru->ru_utime.tv_sec = ru->ru_utime.tv_sec;
  lru->ru_utime.tv_usec = ru->ru_utime.tv_usec;
  lru->ru_stime.tv_sec = ru->ru_stime.tv_sec;
  lru->ru_stime.tv_usec = ru->ru_stime.tv_usec;
  lru->ru_maxrss = ru->ru_maxrss;
  lru->ru_ixrss = ru->ru_ixrss;
  lru->ru_idrss = ru->ru_idrss;
  lru->ru_isrss = ru->ru_isrss;
  lru->ru_minflt = ru->ru_minflt;
  lru->ru_majflt = ru->ru_majflt;
  lru->ru_nswap = ru->ru_nswap;
  lru->ru_inblock = ru->ru_inblock;
  lru->ru_oublock = ru->ru_oublock;
  lru->ru_msgsnd = ru->ru_msgsnd;
  lru->ru_msgrcv = ru->ru_msgrcv;
  lru->ru_nsignals = ru->ru_nsignals;
  lru->ru_nvcsw = ru->ru_nvcsw;
  lru->ru_nivcsw = ru->ru_nivcsw;
}

DEFINE_SYSCALL(getrusage, int, who, gaddr_t, rusage)
{
  struct rusage h_rusage;
  if (getrusage(who, &h_rusage) < 0) {
    return -errno;
  }

  darwin_to_linux_rusage(&h_rusage, guest_to_host(rusage));

  return 0;
}
