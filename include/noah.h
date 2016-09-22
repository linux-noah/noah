#ifndef NOAH_H
#define NOAH_H

#include <stdint.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

static inline uint64_t rounddown(uint64_t x, uint64_t y) {
  return x / y * y;
}

static inline uint64_t roundup(uint64_t x, uint64_t y) {
  return (x + y - 1) / y * y;
}


#define NOAH_VERSION NOAH_MAJOR_VERSION "." NOAH_MINOR_VERSION "." NOAH_PATCH_VERSION
#define NOAH_MAJOR_VERSION "0"
#define NOAH_MINOR_VERSION "1"
#define NOAH_PATCH_VERSION "0"

extern struct noah_run_info {
  char *self_path;
  int  argc;
  char **argv;
  int  optind;
} noah_run_info;

#include "types.h"
#include "util/list.h"
#include "x86/page.h"

/* uacces */

gaddr_t host_to_guest(void *);
void *guest_to_host(gaddr_t);

size_t copy_from_user(void *haddr, gaddr_t gaddr, size_t n); /* returns 0 on success */
ssize_t strncpy_from_user(void *haddr, gaddr_t gaddr, size_t n);
size_t copy_to_user(gaddr_t gaddr, const void *haddr, size_t n);

/* linux emulation */

int do_exec(const char *elf_path, int argc, char *argv[], char **envp);
gaddr_t do_mmap(gaddr_t addr, size_t len, int d_prot, int l_prot, int l_flags, int fd, off_t offset);
int do_open(const char *path, int flags, int mode);
int do_open_at(int fd,const char *path, int flags, int mode);
int do_futex_wake(gaddr_t uaddr, int count);

void run_task();

#include <Hypervisor/hv.h>

/* mm structures */

struct mm_region {
  void *haddr;
  gaddr_t gaddr;
  size_t size;
  int prot;
  struct list_head list;
};

struct mm {
  struct list_head mm_regions;
  uint64_t ept[NR_PAGE_ENTRY], rept[NR_PAGE_ENTRY];
  pthread_rwlock_t alloc_lock;
};

/* task related data */

struct task {
  hv_vcpuid_t vcpuid;
  gaddr_t set_child_tid, clear_child_tid;
  struct list_head tasks; /* Tasks in the current proc */
};

struct proc {
  struct list_head tasks;
  int nr_tasks;
  pthread_rwlock_t alloc_lock; /* Protection for tasks (and nr_tasks) */
  struct mm *mm;
  char *root; /* FS root */
};

extern struct proc proc;
_Thread_local extern struct task *task;


#define LINUX_RELEASE "4.6.4"
#define LINUX_VERSION "#1 SMP PREEMPT Mon Jul 11 19:12:32 CEST 2016" /* FIXME */

#define LINUX_PATH_MAX 4096         /* including null */

/* debug */

#include "debug.h"

#endif
