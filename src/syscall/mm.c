#include "common.h"
#include "../common.h"
#include "../sandbox.h"
#include "../x86/page.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

DEFINE_SYSCALL(mprotect, void *, addr, size_t, len, int, prot)
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

  void *mem = kalloc(brk - current_brk);

  vm_map(current_brk, to_vmpa(mem), brk - current_brk, PAGE_4KB, PTE_W | PTE_P | PTE_U);

  return current_brk = brk;
}
