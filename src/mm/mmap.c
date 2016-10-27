#include "common.h"

#include "noah.h"
#include "vmm.h"
#include "mm.h"
#include "x86/page.h"

#include "linux/mman.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <pthread.h>

#include <Hypervisor/hv.h>

void
init_mmap()
{
  proc.mm->current_mmap_top = 0x00000000c0000000;
}

gaddr_t
alloc_region(size_t len)
{
  len = roundup(len, PAGE_SIZE(PAGE_4KB));
  proc.mm->current_mmap_top += len;
  return proc.mm->current_mmap_top - len;
}

gaddr_t
do_mmap(gaddr_t addr, size_t len, int d_prot, int l_prot, int l_flags, int fd, off_t offset)
{
  assert((addr & 0xfff) == 0);

  /* some l_flags are obsolete and just ignored */
  l_flags &= ~LINUX_MAP_DENYWRITE;
  l_flags &= ~LINUX_MAP_EXECUTABLE;

  /* We ignore these currenlty */
  l_flags &= ~LINUX_MAP_NORESERVE;

  /* the linux kernel does nothing for LINUX_MAP_STACK */
  l_flags &= ~LINUX_MAP_STACK;

  len = roundup(len, PAGE_SIZE(PAGE_4KB));

  if ((l_flags & ~(LINUX_MAP_SHARED | LINUX_MAP_PRIVATE | LINUX_MAP_FIXED | LINUX_MAP_ANON)) != 0) {
    fprintf(stderr, "unsupported mmap l_flags: 0x%x\n", l_flags);
    exit(1);
  }
  if (l_flags & LINUX_MAP_ANON) {
    fd = -1;
    offset = 0;
  }
  if ((l_flags & LINUX_MAP_FIXED) == 0) {
    addr = alloc_region(len);
  }

  int mflags = 0;
  if (l_flags & LINUX_MAP_SHARED) mflags |= MAP_SHARED;
  if (l_flags & LINUX_MAP_PRIVATE) mflags |= MAP_PRIVATE;
  if (l_flags & LINUX_MAP_ANON) mflags |= MAP_ANON;

  void *ptr = mmap(0, len, d_prot, mflags, fd, offset);
  if (ptr == MAP_FAILED) {
    perror("holy cow!");
    fprintf(stderr, "addr :0x%llx, len: 0x%lux, prot: %d, l_flags: %d, fd: %d, offset: 0x%llx\n", addr, len, l_prot, l_flags, fd, offset);
    print_bt();
    exit(1);
  }

  hv_memory_flags_t mprot = 0;
  if (l_prot & LINUX_PROT_READ) mprot |= HV_MEMORY_READ;
  if (l_prot & LINUX_PROT_WRITE) mprot |= HV_MEMORY_WRITE;
  if (l_prot & LINUX_PROT_EXEC) mprot |= HV_MEMORY_EXEC;

  record_region(ptr, addr, len, mprot, l_flags, fd, offset, false);
  vmm_mmap(addr, len, mprot, ptr);

  return addr;
}

int
do_munmap(gaddr_t gaddr, size_t size)
{
  if (!is_page_aligned((void*)gaddr, PAGE_4KB)) {
    return -LINUX_EINVAL;
  }
  size = roundup(size, PAGE_SIZE(PAGE_4KB)); // Linux kernel also does this

  int ret =0;

  struct mm_region *region = find_region(gaddr + size, proc.mm);
  if (region && region->gaddr < gaddr + size) {
    split_region(region, gaddr + size);
  }
  region = find_region(gaddr, proc.mm);
  if (region == NULL) {
    return -LINUX_ENOMEM;
  }
  if (region->gaddr < gaddr) {
    split_region(region, gaddr);
    region = list_entry(region->list.next, struct mm_region, list);
  }

  while (region->gaddr + region->size <= gaddr + size) {
    struct mm_region *next = list_entry(region->list.next, struct mm_region, list);
    list_del(&region->list);
    munmap(region->haddr, region->size);
    hv_vm_unmap(region->gaddr, region->size);
    free(region);
    region = next;
  }

  return ret;
}

DEFINE_SYSCALL(mmap, gaddr_t, addr, size_t, len, int, prot, int, flags, int, fd, off_t, offset)
{
  uint64_t ret;
  pthread_rwlock_wrlock(&proc.mm->alloc_lock);
  ret = do_mmap(addr, len, prot, prot, flags, fd, offset);
  pthread_rwlock_unlock(&proc.mm->alloc_lock);
  return  ret;
}

DEFINE_SYSCALL(mremap, gaddr_t, old_addr, size_t, old_size, size_t, new_size, int, flags, gaddr_t, new_addr)
{
  if (flags & ~(LINUX_MREMAP_FIXED | LINUX_MREMAP_MAYMOVE))
    return -LINUX_EINVAL;
  if (flags & LINUX_MREMAP_FIXED && !(flags & LINUX_MREMAP_MAYMOVE))
    return -LINUX_EINVAL;
  if (is_page_aligned((void*)old_addr, PAGE_4KB))
    return -LINUX_EINVAL;
  if (!(flags & LINUX_MREMAP_MAYMOVE)) {
    printk("unsupported mremap flags: 0x%x\n", flags);
    fprintf(stderr, "unsupported mremap flags: 0x%x\n", flags);
    return -LINUX_ENOSYS;
  }

  if (new_size == 0)
    return -LINUX_EINVAL;

  /* Linux kernel also does these aligning */
  old_size = roundup(old_size, PAGE_SIZE(PAGE_4KB));
  new_size = roundup(new_size, PAGE_SIZE(PAGE_4KB));

  gaddr_t ret = old_addr;

  pthread_rwlock_wrlock(&proc.mm->alloc_lock);

  struct mm_region *region = find_region(old_addr, proc.mm);
  /* Linux requires old_addr is the exact address of start of vm_area  */
  if (!region || region->gaddr != old_addr) {
    ret = -LINUX_EFAULT;
    goto out;
  }
  /* The region must not be across multiple regions */
  if (region->size < old_size) {
    ret = -LINUX_EFAULT;
    goto out;
  }

  /* new_size <= old_size. We can just shrink */
  if (new_size <= old_size) {
    munmap(region->haddr + new_size, region->size - new_size);
    hv_vm_unmap(region->gaddr + new_size, region->size - new_size);
    region->size = new_size;
    goto out;
  }

  /* new_size > old_size */
  void *moved_to = mmap(0, new_size, PROT_NONE, region->mm_flags, region->mm_fd, region->pgoff);
  if (moved_to == MAP_FAILED) {
    perror("ieeee!");
    fprintf(stderr, "mremap old_addr :0x%llx, old_size: 0x%lux, new_size: 0x%lux, flags:0x%ux, new_addr: 0x%llx", old_addr, old_size, new_size, flags, new_addr);
    print_bt();
    exit(1);
  }
  if (!(region->mm_flags & LINUX_MAP_ANONYMOUS)) {
    /* A file is mapped to this region. We have to take the file permission into account */
    int d_prot = 0;
    if (region->prot & HV_MEMORY_READ) d_prot |= PROT_READ;
    if (region->prot & HV_MEMORY_WRITE) d_prot |= PROT_WRITE;
    mprotect(moved_to, new_size, d_prot);
  } else {
    /* Anonymous page. Copy contents to new area */
    mprotect(moved_to, new_size, PROT_READ | PROT_WRITE);
    memcpy(moved_to, region->haddr, old_size);
  }

  /* Unmap the old page */
  if (old_size < region->size) {
    split_region(region, region->gaddr + old_size);
  }
  list_del(&region->list);
  munmap(region->haddr, region->size);
  hv_vm_unmap(region->gaddr, region->size);

  /* Map new one */
  ret = alloc_region(new_size);
  struct mm_region *new = record_region(moved_to, ret, new_size, region->prot, region->mm_flags, region->mm_fd, region->pgoff, region->is_global);
  vmm_mmap(new->gaddr, new->size, new->prot, new->haddr);

  free(region);

out:
  pthread_rwlock_unlock(&proc.mm->alloc_lock);

  return 0;
}

DEFINE_SYSCALL(mprotect, gaddr_t, addr, size_t, len, int, prot)
{
  if (!is_page_aligned((void*)addr, PAGE_4KB) || len == 0) {
    return -LINUX_EINVAL;
  }
  // TODO check if user is permiited to access the addr

  len = roundup(len, PAGE_SIZE(PAGE_4KB));
  gaddr_t end = addr + len;

  hv_memory_flags_t hvprot = 0;
  if (prot & LINUX_PROT_READ) hvprot |= HV_MEMORY_READ;
  if (prot & LINUX_PROT_WRITE) hvprot |= HV_MEMORY_WRITE;
  if (prot & LINUX_PROT_EXEC) hvprot |= HV_MEMORY_EXEC;

  int ret = 0;

  pthread_rwlock_wrlock(&proc.mm->alloc_lock);

  struct mm_region *region = find_region(addr, proc.mm);
  if (!region) {
    ret = -LINUX_ENOMEM;
    goto out;
  }
  if (addr > region->gaddr) {
    split_region(region, addr);
    region = list_entry(region->list.next, struct mm_region, list);

    hv_vm_protect(region->gaddr, region->size, hvprot);
    mprotect(region->haddr, region->size, prot);
    region->prot = hvprot;
  }
  while (region->gaddr + region->size <= end) {
    hv_vm_protect(region->gaddr, region->size, hvprot);
    mprotect(region->haddr, region->size, prot);
    region->prot = hvprot;

    if (region->list.next == &proc.mm->mm_regions) {
      ret = -LINUX_ENOMEM;
      goto out;
    }
    struct mm_region *next = list_entry(region->list.next, struct mm_region, list);
    if (next->gaddr != region->gaddr + region->size) {
      ret = -LINUX_ENOMEM;
      goto out;
    }
    region = next;
  }
  if (region->gaddr < end) {
    split_region(region, end);
    hv_vm_protect(region->gaddr, region->size, hvprot);
    mprotect(region->haddr, region->size, prot);
    region->prot = hvprot;
  }

out:
  pthread_rwlock_unlock(&proc.mm->alloc_lock);

  return 0;
}

DEFINE_SYSCALL(munmap, gaddr_t, gaddr, size_t, size)
{
  uint64_t ret;
  pthread_rwlock_wrlock(&proc.mm->alloc_lock);
  ret = do_munmap(gaddr, size);
  pthread_rwlock_unlock(&proc.mm->alloc_lock);
  return ret;
}

void
init_brk()
{
  proc.mm->current_brk = proc.mm->start_brk;
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

DEFINE_SYSCALL(madvise, gaddr_t, addr, size_t, length, int, advice)
{
  printk("madvise is not implemented");
  return 0;

}

DEFINE_SYSCALL(mlock, gaddr_t, addr, size_t, length)
{
  return syswrap(mlock(guest_to_host(addr), length));
}

DEFINE_SYSCALL(munlock, gaddr_t, addr, size_t, length)
{
  return syswrap(munlock(guest_to_host(addr), length));
}
