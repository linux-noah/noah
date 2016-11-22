#ifndef NOAH_H
#define NOAH_H

#include <stdint.h>
#include <pthread.h>
#include "types.h"
#include "util/misc.h"
#include "util/list.h"
#include "malloc.h"
#include "version.h"

/* privilege management */

void drop_privilege(void);
void elevate_privilege(void);

/* interface to user memory */

gaddr_t host_to_guest(void *);
void *guest_to_host(gaddr_t);

size_t copy_from_user(void *haddr, gaddr_t gaddr, size_t n); /* returns 0 on success */
ssize_t strncpy_from_user(void *haddr, gaddr_t gaddr, size_t n);
size_t copy_to_user(gaddr_t gaddr, const void *haddr, size_t n);
ssize_t strnlen_user(gaddr_t gaddr, size_t n);

/* linux emulation */

int do_exec(const char *elf_path, int argc, char *argv[], char **envp);
int do_open(const char *path, int flags, int mode);
int do_openat(int fd, const char *path, int flags, int mode);
int do_close(int fd);
int do_faccessat(int l_dirfd, const char *l_path, int l_mode);
int do_access(const char *path, int l_mode);
int do_futex_wake(gaddr_t uaddr, int count);

void main_loop();

/* task related data */

#include "linux/signal.h"

struct task {
  gaddr_t set_child_tid, clear_child_tid;
  l_sigset_t sigmask;
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
#define LINUX_VERSION "✋(´・ω・｀) やあ "

#define LINUX_PATH_MAX 4096         /* including null */

/* conversion */

struct stat;
struct l_newstat;
struct statfs;
struct termios;
struct linux_termios;
struct l_statfs;
struct winsize;
struct linux_winsize;

int linux_to_darwin_at_flags(int flags);
int linux_to_darwin_o_flags(int l_flags);
void stat_darwin_to_linux(struct stat *stat, struct l_newstat *lstat);
void statfs_darwin_to_linux(struct statfs *statfs, struct l_statfs *l_statfs);
void darwin_to_linux_termios(struct termios *bios, struct linux_termios *lios);
void linux_to_darwin_termios(struct linux_termios *lios, struct termios *bios);
void darwin_to_linux_winsize(struct winsize *ws, struct linux_winsize *lws);
void linux_to_darwin_winsize(struct winsize *ws, struct linux_winsize *lws);
int linux_to_darwin_signal(int signum);
int darwin_to_linux_signal(int signum);


/* debug */

#include "debug.h"

#endif
