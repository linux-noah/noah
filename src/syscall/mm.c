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
  assert((flags & L_MAP_FIXED));

  void *ptr = mmap(0, len, PROT_READ | PROT_WRITE | PROT_EXEC, flags & ~L_MAP_FIXED, fd, offset);

  PRINTF("do_mmap: addr = 0x%llx, len = %zu, haddr = %p\n", addr, len, ptr);

  hv_memory_flags_t mprot = 0;
  if (prot & L_PROT_READ) mprot |= HV_MEMORY_READ;
  if (prot & L_PROT_WRITE) mprot |= HV_MEMORY_WRITE;
  if (prot & L_PROT_EXEC) mprot |= HV_MEMORY_EXEC;
  vmm_mmap(addr, len, mprot, ptr);

  return addr;
}

DEFINE_SYSCALL(mmap, gaddr_t, addr, size_t, len, int, prot, int, flags, int, fd, off_t, offset)
{
  if ((flags & ~(L_MAP_SHARED | L_MAP_PRIVATE | L_MAP_FIXED | L_MAP_ANON)) != 0) {
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

  do_mmap(current_brk, brk - current_brk, L_PROT_READ | L_PROT_WRITE, L_MAP_PRIVATE | L_MAP_FIXED | L_MAP_ANONYMOUS, -1, 0);

  return current_brk = brk;
}
