#ifndef NOAH_H
#define NOAH_H

#include <stdint.h>
#include <stdint.h>
#include <unistd.h>

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

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


/* hypervisor */

#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>
#include <Hypervisor/hv_arch_vmx.h>

#include "util/list.h"
#include "x86/page.h"
#include "x86/vmx.h"

struct vcpu_snapshot {
  uint64_t vcpu_reg[NR_X86_REG_LIST];
  uint64_t vmcs[NR_VMCS_FIELD];
};

struct vm_snapshot {
  struct vcpu_snapshot first_vcpu_snapshot;
};

void vmm_create(void);
void vmm_destroy(void);
void vmm_snapshot(struct vm_snapshot*);
void vmm_reentry(struct vm_snapshot*);
void vcpu_snapshot(struct vcpu_snapshot*);
void vcpu_restore(struct vcpu_snapshot*);

void init_msr(hv_vcpuid_t);

typedef uint64_t gaddr_t;
typedef gaddr_t  gstr_t;

gaddr_t host_to_guest(void *);
void *guest_to_host(gaddr_t);

/* prot is obtained by or'ing HV_MEMORY_READ, HV_MEMORY_EXEC, HV_MEMORY_WRITE */
void vmm_mmap(gaddr_t addr, size_t len, int prot, void *ptr);

/* linux emulation */

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
};

struct task {
  hv_vcpuid_t vcpuid;
  gaddr_t set_child_tid, clear_child_tid;
  struct list_head tasks; // Tasks in the current proc
};

struct proc {
  struct list_head tasks;
  int nr_tasks;
  pthread_rwlock_t alloc_lock; // Protection for tasks (and nr_tasks), mm
  struct mm *mm;
};

extern struct proc proc;
_Thread_local extern struct task *task;

size_t copy_from_user(void *haddr, gaddr_t gaddr, size_t n); /* returns 0 on success */
ssize_t strncpy_from_user(void *haddr, gaddr_t gaddr, size_t n);
size_t copy_to_user(gaddr_t gaddr, const void *haddr, size_t n);

int do_exec(const char *elf_path, int argc, char *argv[], char **envp);
gaddr_t do_mmap(gaddr_t addr, size_t len, int prot, int flags, int fd, off_t offset);
int do_open(const char *path, int flags, int mode);
int do_futex_wake(gaddr_t uaddr, int count);

void run_task();

#define LINUX_RELEASE "4.6.4"
#define LINUX_VERSION "#1 SMP PREEMPT Mon Jul 11 19:12:32 CEST 2016" /* FIXME */

#define LINUX_PATH_MAX 4096         /* including null */

#define LINUX_PROT_NONE  0x0
#define LINUX_PROT_READ  0x1
#define LINUX_PROT_WRITE 0x2
#define LINUX_PROT_EXEC  0x4

#define LINUX_MAP_FILE       0
#define LINUX_MAP_SHARED     0x1
#define LINUX_MAP_PRIVATE    0x2
#define LINUX_MAP_TYPE       0xf
#define LINUX_MAP_FIXED      0x10
#define LINUX_MAP_ANON       0x20
#define LINUX_MAP_ANONYMOUS  LINUX_MAP_ANON
#define LINUX_MAP_GROWSDOWN  0x0100
#define LINUX_MAP_DENYWRITE  0x0800
#define LINUX_MAP_EXECUTABLE 0x1000
#define LINUX_MAP_LOCKED     0x2000
#define LINUX_MAP_NORESERVE  0x4000
#define LINUX_MAP_POPULATE   0x8000
#define LINUX_MAP_NONBLOCK   0x10000
#define LINUX_MAP_STACK      0x20000
#define LINUX_MAP_HUGETLB    0x40000

/* debug */

#include "debug.h"

#endif
