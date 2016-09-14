#include "common.h"

#include "noah.h"
#include "vmm.h"
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

gaddr_t
alloc_region(size_t len)
{
  static uint64_t current_mmap_top = 0x00000000c0000000;

  len = roundup(len, PAGE_SIZE(PAGE_4KB));

  current_mmap_top += len;

  return current_mmap_top - len;
}

gaddr_t
do_mmap(gaddr_t addr, size_t len, int prot, int flags, int fd, off_t offset)
{
  assert((addr & 0xfff) == 0);

  /* some flags are obsolete and just ignored */
  flags &= ~LINUX_MAP_DENYWRITE;
  flags &= ~LINUX_MAP_EXECUTABLE;

  /* the linux kernel does nothing for LINUX_MAP_STACK */
  flags &= ~LINUX_MAP_STACK;

  if ((flags & ~(LINUX_MAP_SHARED | LINUX_MAP_PRIVATE | LINUX_MAP_FIXED | LINUX_MAP_ANON)) != 0) {
    fprintf(stderr, "unsupported mmap flags: %x\n", flags);
    exit(1);
  }
  if (flags & LINUX_MAP_ANON) {
    fd = -1;
    offset = 0;
  }
  if ((flags & LINUX_MAP_FIXED) == 0) {
    addr = alloc_region(len);
  }

  int mflags = 0;
  if (flags & LINUX_MAP_SHARED) mflags |= MAP_SHARED;
  if (flags & LINUX_MAP_PRIVATE) mflags |= MAP_PRIVATE;
  if (flags & LINUX_MAP_ANON) mflags |= MAP_ANON;

  void *ptr = mmap(0, len, PROT_READ | PROT_WRITE | PROT_EXEC, mflags, fd, offset);

  if (ptr == MAP_FAILED) {
    perror("holy cow!");
    exit(1);
  }

  hv_memory_flags_t mprot = 0;
  if (prot & LINUX_PROT_READ) mprot |= HV_MEMORY_READ;
  if (prot & LINUX_PROT_WRITE) mprot |= HV_MEMORY_WRITE;
  if (prot & LINUX_PROT_EXEC) mprot |= HV_MEMORY_EXEC;
  /* FIXME */
  /* vmm_mmap(addr, len, mprot, ptr); */
  vmm_mmap(addr, len, HV_MEMORY_READ | HV_MEMORY_WRITE | HV_MEMORY_EXEC, ptr);

  return addr;
}

DEFINE_SYSCALL(mmap, gaddr_t, addr, size_t, len, int, prot, int, flags, int, fd, off_t, offset)
{
  return do_mmap(addr, len, prot, flags, fd, offset);
}

DEFINE_SYSCALL(mprotect, gaddr_t, addr, size_t, len, int, prot)
{
  printk("mprotect: addr = 0x%llx, len = 0x%zx, prot = %d\n", addr, len, prot);
  return 0;
}

DEFINE_SYSCALL(munmap, gaddr_t, gaddr, size_t, size)
{
  return 0;
}

uint64_t brk_min, current_brk;

DEFINE_SYSCALL(brk, unsigned long, brk)
{
  if (current_brk == 0)
    current_brk = brk_min;

  brk = roundup(brk, PAGE_SIZE(PAGE_4KB));

  if (brk < brk_min)
    return brk_min;

  if (brk < current_brk)
    return current_brk = brk;

  do_mmap(current_brk, brk - current_brk, LINUX_PROT_READ | LINUX_PROT_WRITE, LINUX_MAP_PRIVATE | LINUX_MAP_FIXED | LINUX_MAP_ANONYMOUS, -1, 0);

  return current_brk = brk;
}

DEFINE_SYSCALL(madvise, gaddr_t, addr, size_t, length, int, advice)
{
  printk("madvise is not implemented");
  return 0;
}
