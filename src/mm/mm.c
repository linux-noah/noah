#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <strings.h>

#include "common.h"
#include "util/list.h"
#include "mm.h"
#include "vmm.h"
#include "noah.h"

#include "linux/mman.h"

#include "x86/vm.h"

/* 
 * Manage kernel memory space allocated by kmap.
 * Some members related to user memory space such as start_brk are meaningless in vkern_mm.
 */
struct mm vkern_mm;

void init_mmap(struct mm *mm);

void
init_mm(struct mm *mm)
{
  bzero(mm, sizeof(struct mm));
  init_mmap(mm);

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

  region->size = offset;
  list_add(&tail->list, &region->list);
}

struct mm_region*
record_region(struct mm *mm, void *haddr, gaddr_t gaddr, size_t size, int prot, int mm_flags, int mm_fd, int pgoff)
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

  if (list_empty(&mm->mm_regions)) { /* fast path */
    list_add(&region->list, &mm->mm_regions);
    return region;
  }
  /* unmap */
  list_for_each_safe (list, t, &mm->mm_regions) {
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
      list_add_tail(&s->list, list->next);
    }
  }
  /* map */
  gaddr_t prev = 0;
  list_for_each (list, &mm->mm_regions) {
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

void
destroy_mm(struct mm *mm)
{
  struct list_head *list, *t;
  list_for_each_safe (list, t, &mm->mm_regions) {
    struct mm_region *r = list_entry(list, struct mm_region, list);
    list_del(list);
    munmap(r->haddr, r->size);
    vmm_munmap(r->gaddr, r->size);
    free(r);
  }
}

DEFINE_SYSCALL(madvise, gaddr_t, addr, size_t, length, int, advice)
{
  printk("madvise is not implemented\n");
  return 0;

}

DEFINE_SYSCALL(mlock, gaddr_t, addr, size_t, length)
{
  printk("mlock is not implemented\n");
  return 0;
}

DEFINE_SYSCALL(munlock, gaddr_t, addr, size_t, length)
{
  printk("munlock is not implemented\n");
  return 0;
}

DEFINE_SYSCALL(brk, unsigned long, brk)
{
  uint64_t ret;
  brk = roundup(brk, PAGE_SIZE(PAGE_4KB));

  pthread_rwlock_wrlock(&proc.mm->alloc_lock);
  if (brk < proc.mm->start_brk) {
    ret = proc.mm->start_brk;
    goto out;
  }

  if (brk < proc.mm->current_brk) {
    ret = proc.mm->current_brk = brk;
    goto out;
  }

  do_mmap(proc.mm->current_brk, brk - proc.mm->current_brk, PROT_READ | PROT_WRITE, LINUX_PROT_READ | LINUX_PROT_WRITE, LINUX_MAP_PRIVATE | LINUX_MAP_FIXED | LINUX_MAP_ANONYMOUS, -1, 0);
  ret = proc.mm->current_brk = brk;

out:
  pthread_rwlock_unlock(&proc.mm->alloc_lock);

  return ret;
}
