#ifndef NOAH_MM_H
#define NOAH_MM_H

#include <pthread.h>
#include <stdbool.h>

#include "types.h"
#include "util/list.h"
#include "x86/page.h"
#include "noah.h"

struct mm_region {
  void *haddr;
  gaddr_t gaddr;
  size_t size;
  int prot;            /* Access permission in hv_memory_flags_t */
  int mm_flags;        /* mm flags in the form of LINUX_MAP_* */
  int mm_fd;
  int pgoff;           /* offset within mm_fd in page size */
  bool is_global;      /* global page flag. Preserved during exec if global */
  struct list_head list;
};

struct mm {
  struct list_head mm_regions;
  uint64_t ept[NR_PAGE_ENTRY], rept[NR_PAGE_ENTRY];
  uint64_t brk_min, current_brk;
  uint64_t current_mmap_top;
  pthread_rwlock_t alloc_lock;
};

void init_mm(struct mm *mm);
void init_shm_malloc();

/* prot is obtained by or'ing HV_MEMORY_READ, HV_MEMORY_EXEC, HV_MEMORY_WRITE */
struct mm_region *find_region(gaddr_t gaddr, struct mm *mm);
struct mm_region *record_region(void *haddr, gaddr_t gaddr, size_t size, int prot, int mm_flags, int mm_fd, int pgoff, bool global);
void split_region(struct mm_region *region, gaddr_t gaddr);
void clear_mm(struct mm *mm, bool clear_global);

gaddr_t do_mmap(gaddr_t addr, size_t len, int d_prot, int l_prot, int l_flags, int fd, off_t offset);

#endif
