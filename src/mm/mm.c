#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/mman.h>

#include "util/list.h"
#include "mm.h"
#include "vmm.h"
#include "noah.h"

#include "x86/page.h"

void init_mmap();
void init_brk();

void
init_mm(struct mm *mm)
{
  init_mmap();
  init_brk();

  INIT_LIST_HEAD(&mm->mm_regions);
  pthread_rwlock_init(&mm->alloc_lock, NULL);
}

/* Look up the first mm_region which gaddr in [mm_region->gaddr, +size) */
struct mm_region*
find_region(gaddr_t gaddr, struct mm *mm)
{
  struct mm_region *r;
  list_for_each_entry (r, &mm->mm_regions, list) {
    if (gaddr < r->gaddr)
      break;
    if (gaddr < r->gaddr + r->size && gaddr >= r->gaddr)
      return r;
  }
  return NULL;
}

void
split_region(struct mm_region *region, gaddr_t gaddr)
{
  assert(is_page_aligned((void*)gaddr, PAGE_4KB));

  struct mm_region *tail = malloc(sizeof(struct mm_region));
  int offset = gaddr - region->gaddr;
  tail->haddr = region->haddr + offset;
  tail->gaddr = gaddr;
  tail->size = region->size - offset;
  tail->prot = region->prot;
  tail->mm_flags = region->mm_flags;
  tail->mm_fd = region->mm_fd;
  tail->pgoff = region->pgoff;
  tail->is_global = region->is_global;

  region->size = offset;
  list_add(&tail->list, &region->list);
}

struct mm_region*
record_region(void *haddr, gaddr_t gaddr, size_t size, int prot, int mm_flags, int mm_fd, int pgoff, bool global)
{
  struct list_head *list, *t;
  struct mm_region *region, *r;

  region = malloc(sizeof *region);
  region->haddr = haddr;
  region->gaddr = gaddr;
  region->size = size;
  region->prot = prot;
  region->mm_flags = mm_flags;
  region->mm_fd = mm_fd;
  region->pgoff = pgoff;
  region->is_global = global;

  if (list_empty(&proc.mm->mm_regions)) { /* fast path */
    list_add(&region->list, &proc.mm->mm_regions);
    return region;
  }
  /* unmap */
  list_for_each_safe (list, t, &proc.mm->mm_regions) {
    r = list_entry(list, struct mm_region, list);
    if (gaddr + size <= r->gaddr)
      break;
    if (r->gaddr + r->size <= gaddr)
      continue;
    list_del(list);
    if (gaddr <= r->gaddr && r->gaddr + r->size <= gaddr + size) {
      free(r);
      continue;
    }
    /* split r */
    if (r->gaddr < gaddr) {
      struct mm_region *s = malloc(sizeof *s);
      s->haddr = r->haddr;
      s->gaddr = r->gaddr;
      s->size = gaddr - r->gaddr;
      s->prot = r->prot;
      s->mm_flags = r->mm_flags;
      s->mm_fd = r->mm_fd;
      s->pgoff = r->pgoff;
      s->is_global = r->is_global;
      list_add(&s->list, list->prev);
    }
    if (gaddr + size < r->gaddr + r->size) {
      uint64_t offset = gaddr + size - r->gaddr;
      struct mm_region *s = malloc(sizeof *s);
      s->haddr = (char *) r->haddr + offset;
      s->gaddr = r->gaddr + offset;
      s->size = r->size - offset;
      s->prot = prot;
      s->mm_flags = mm_flags;
      s->mm_fd = mm_fd;
      s->pgoff = pgoff;
      s->is_global = global;
      list_add_tail(&s->list, list->next);
    }
  }
  /* map */
  gaddr_t prev = 0;
  list_for_each (list, &proc.mm->mm_regions) {
    r = list_entry(list, struct mm_region, list);
    if (prev <= gaddr && gaddr + size <= r->gaddr) {
      list_add(&region->list, list->prev);
      return region;
    }
    prev = r->gaddr + r->size;
  }
  list_add_tail(&region->list, list);

  return region;
}

// Unmap and free all local regions.
// Global pages remain, so this does not destoy whole mm
void
clear_mm(struct mm *mm, bool clear_global)
{
  struct list_head *list, *t;
  list_for_each_safe (list, t, &mm->mm_regions) {
    struct mm_region *r = list_entry(list, struct mm_region, list);
    if (r->is_global && !clear_global) {
      continue;
    }
    list_del(list);
    munmap(r->haddr, r->size);
    vmm_munmap(r->gaddr, r->size);
    free(r);
  }

  init_mmap(); // reinitialize user mmap area
  init_brk();
}
