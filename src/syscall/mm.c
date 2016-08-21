#include "common.h"

#include "noah.h"
#include "x86/page.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

gaddr_t
do_mmap(gaddr_t addr, size_t len, int prot, int flags, int fd, off_t offset)
{
  assert((addr & 0xfff) == 0);
  assert((len & 0xfff) == 0);
  assert((flags & MAP_FIXED));

  void *ptr = mmap(0, len, PROT_READ | PROT_WRITE | PROT_EXEC, flags & ~MAP_FIXED, fd, offset);

  PRINTF("do_mmap: addr = 0x%llx, len = %zu, haddr = %p\n", addr, len, ptr);

  vmm_mmap(addr, len, prot, ptr);

  return addr;
}

DEFINE_SYSCALL(mmap, gaddr_t, addr, size_t, len, int, prot, int, flags, int, fd, off_t, offset)
{
  if ((flags & ~(MAP_SHARED | MAP_PRIVATE | MAP_FIXED | MAP_ANON)) != 0) {
    fprintf(stderr, "unsupported mmap flags: %x\n", flags);
    _exit(1);
  }

  return do_mmap(addr, len, prot, flags, fd, offset);
}

DEFINE_SYSCALL(mprotect, gaddr_t, addr, size_t, len, int, prot)
{
  return 0;
}

uint64_t brk_min, current_brk;

DEFINE_SYSCALL(brk, unsigned long, brk)
{
  if (current_brk == 0)
    current_brk = brk_min;

  if (brk < brk_min)
    return brk_min;

  if (brk < current_brk)
    return current_brk = brk;

  do_mmap(current_brk, brk - current_brk, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_FIXED | MAP_ANONYMOUS, -1, 0);

  return current_brk = brk;
}
