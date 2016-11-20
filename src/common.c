#include "common.h"
#include "noah.h"
#include "vmm.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linux/errno.h"

size_t
copy_from_user(void *to, gaddr_t src_ptr, size_t n)
{
  while (n > 0) {
    const void *src = guest_to_host(src_ptr);
    if (src == NULL) {
      return n;
    }
    size_t size = MIN(rounddown(src_ptr + 4096, 4096) - src_ptr, n);
    memcpy(to, src, size);
    to = (char *) to + size;
    src_ptr += size;
    n -= size;
  }
  return 0;
}

ssize_t
strncpy_from_user(void *to, gaddr_t src_ptr, size_t n)
{
  const void *src = guest_to_host(src_ptr);
  char *end = stpncpy(to, src, n);
  return end - (char *) to;
}

// Get the size of a user string INCLUDING trailing NULL in the same manner as Linux kernel's strnlen_user
// Check retruen value <= n to make sure that the str is not too long
ssize_t
strnsize_user(gaddr_t src_ptr, size_t n)
{
  const void *src = guest_to_host(src_ptr);
  size_t ret = strnlen(src, n) + 1;
  return ret;
}

size_t
copy_to_user(gaddr_t to_ptr, const void *src, size_t n)
{
  while (n > 0) {
    void *to = guest_to_host(to_ptr);
    if (to == NULL) {
      return n;
    }
    size_t size = MIN(rounddown(to_ptr + 4096, 4096) - to_ptr, n);
    memcpy(to, src, size);
    to_ptr += size;
    src = (char *) src + size;
    n -= size;
  }
  return 0;
}

DEFINE_SYSCALL(unimplemented)
{
  uint64_t rax;

  vmm_read_register(HV_X86_RAX, &rax);

  printk("unimplemented syscall: %lld\n", rax);
  fprintf(stderr, "unimplemented syscall: %lld\n", rax);
  exit(1);
}

#include "syscall.h"

#define sys_unimplemented __ignore_me__
#define SYSCALL(n, name) uint64_t _sys_##name(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);
SYSCALLS
#undef SYSCALL
#undef sys_unimplemented

sc_handler_t sc_handler_table[NR_SYSCALLS] = {
#define SYSCALL(n, name) [n] = ((sc_handler_t) _sys_##name),
  SYSCALLS
#undef SYSCALL
};

char *sc_name_table[NR_SYSCALLS] = {
#define SYSCALL(n, name) [n] = #name,
  SYSCALLS
#undef SYSCALL
};
