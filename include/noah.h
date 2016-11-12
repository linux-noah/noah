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
#define NOAH_MINOR_VERSION "3"
#define NOAH_PATCH_VERSION "0"

/* privilege management */

void drop_privilege(void);
void elevate_privilege(void);

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
int do_openat(int fd, const char *path, int flags, int mode);
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

void set_initial_proc(struct proc *proc, char *root);

#define LINUX_RELEASE "4.6.4"
#define LINUX_VERSION "#1 SMP PREEMPT Mon Jul 11 19:12:32 CEST 2016" /* FIXME */

#define LINUX_PATH_MAX 4096         /* including null */

/* conversion */

struct stat;
struct l_newstat;
struct statfs;
struct termios;
struct linux_termios;
struct l_statfs;

int linux_to_darwin_at_flags(int flags);
int linux_to_darwin_o_flags(int l_flags);
void stat_darwin_to_linux(struct stat *stat, struct l_newstat *lstat);
void statfs_darwin_to_linux(struct statfs *statfs, struct l_statfs *l_statfs);
void darwin_to_linux_termios(struct termios *bios, struct linux_termios *lios);


/* debug */

#include "debug.h"

#endif
