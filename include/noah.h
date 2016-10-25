#ifndef NOAH_H
#define NOAH_H

#include <stdint.h>
#include <pthread.h>
#include "types.h"
#include "util/misc.h"
#include "util/list.h"
#include "malloc.h"

#define NOAH_VERSION NOAH_MAJOR_VERSION "." NOAH_MINOR_VERSION "." NOAH_PATCH_VERSION
#define NOAH_MAJOR_VERSION "0"
#define NOAH_MINOR_VERSION "2"
#define NOAH_PATCH_VERSION "5"

extern struct noah_run_info {
  char *self_path;
  int  argc;
  char **argv;
  int  optind;
} noah_run_info;

/* interface to user memory */

gaddr_t host_to_guest(void *);
void *guest_to_host(gaddr_t);

size_t copy_from_user(void *haddr, gaddr_t gaddr, size_t n); /* returns 0 on success */
ssize_t strncpy_from_user(void *haddr, gaddr_t gaddr, size_t n);
size_t copy_to_user(gaddr_t gaddr, const void *haddr, size_t n);
ssize_t strnsize_user(gaddr_t gaddr, size_t n);

/* linux emulation */

int do_exec(const char *elf_path, int argc, char *argv[], char **envp);
int do_open(const char *path, int flags, int mode);
int do_open_at(int fd, const char *path, int flags, int mode);
int do_faccessat(int l_dirfd, const char *l_path, int l_mode);
int do_access(const char *path, int l_mode);
int do_futex_wake(gaddr_t uaddr, int count);

void main_loop();

/* task related data */

struct task {
  gaddr_t set_child_tid, clear_child_tid;
  struct task_group *tgrp;
};

struct proc {
  int nr_tasks;
  pthread_rwlock_t lock;
  struct mm *mm;
  char *root; /* FS root */
};

extern struct proc proc;
_Thread_local extern struct task task;

void init_proc(struct proc* proc);

#define LINUX_RELEASE "4.6.4"
#define LINUX_VERSION "#1 SMP PREEMPT Mon Jul 11 19:12:32 CEST 2016" /* FIXME */

#define LINUX_PATH_MAX 4096         /* including null */

/* debug */

#include "debug.h"

#endif
