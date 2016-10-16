#ifndef NOAH_MM_H
#define NOAH_MM_H

#include <pthread.h>

#include "types.h"
#include "util/list.h"
#include "x86/page.h"

struct mm_region {
  void *haddr;
  gaddr_t gaddr;
  size_t size;
  int prot;            /* Access permission in hv_memory_flags_t */
  int mm_flags;        /* mm flags in the form of LINUX_MAP_* */
  int mm_fd;
  int pgoff;           /* offset within mm_fd in page size */
  struct list_head list;
};

struct mm {
  struct list_head mm_regions;
  uint64_t ept[NR_PAGE_ENTRY], rept[NR_PAGE_ENTRY];
  pthread_rwlock_t alloc_lock;
};

/* prot is obtained by or'ing HV_MEMORY_READ, HV_MEMORY_EXEC, HV_MEMORY_WRITE */
struct mm_region *find_region(gaddr_t gaddr, struct mm *mm);
struct mm_region *record_region(void *haddr, gaddr_t gaddr, size_t size, int prot, int mm_flags, int mm_fd, int pgoff);
void split_region(struct mm_region *region, gaddr_t gaddr);

#endif
