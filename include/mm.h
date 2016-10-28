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
  int prot;            /* Access permission that consists of LINUX_PROT_* */
  int mm_flags;        /* mm flags in the form of LINUX_MAP_* */
  int mm_fd;
  int pgoff;           /* offset within mm_fd in page size */
  bool is_global;      /* global page flag. Preserved during exec if global */
  struct list_head list;
};

struct mm {
  struct list_head mm_regions;
  uint64_t start_brk, current_brk;
  uint64_t current_mmap_top;
  pthread_rwlock_t alloc_lock;
};

extern struct mm vkern_mm;

void init_mm(struct mm *mm);
void init_shm_malloc();

struct mm_region *find_region(gaddr_t gaddr, struct mm *mm);
struct mm_region *record_region(struct mm *mm, void *haddr, gaddr_t gaddr, size_t size, int prot, int mm_flags, int mm_fd, int pgoff);
void split_region(struct mm_region *region, gaddr_t gaddr);
void destroy_mm(struct mm *mm);

gaddr_t do_mmap(gaddr_t addr, size_t len, int d_prot, int l_prot, int l_flags, int fd, off_t offset);

int hv_mflag_to_linux_mprot(hv_memory_flags_t mflag);
hv_memory_flags_t linux_mprot_to_hv_mflag(int mprot);

#endif
