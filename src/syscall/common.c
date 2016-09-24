#include "common.h"
#include "noah.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linux/errno.h"

size_t
copy_from_user(void *to, gaddr_t src_ptr, size_t n)
{
  const void *src = guest_to_host(src_ptr);
  memcpy(to, src, n);
  return 0;
}

ssize_t
strncpy_from_user(void *to, gaddr_t src_ptr, size_t n)
{
  const void *src = guest_to_host(src_ptr);
  char *end = stpncpy(to, src, n);
  return end - (char *) to;
}

size_t
copy_to_user(gaddr_t to_ptr, const void *src, size_t n)
{
  void *to = guest_to_host(to_ptr);
  memcpy(to, src, n);
  return 0;
}

DEFINE_SYSCALL(unimplemented)
{
  uint64_t rax;

  hv_vcpu_read_register(task->vcpuid, HV_X86_RAX, &rax);

  printk("unimplemented syscall: %lld\n", rax);
  fprintf(stderr, "unimplemented syscall: %lld\n", rax);
  exit(1);
}

#include "syscall.h"

#define sys_unimplemented __ignore_me__
#define SYSCALL(n, name) uint64_t sys_##name(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);
SYSCALLS
#undef SYSCALL
#undef sys_unimplemented

sc_handler_t sc_handler_table[NR_SYSCALLS] = {
#define SYSCALL(n, name) [n] = ((sc_handler_t) sys_##name),
  SYSCALLS
#undef SYSCALL
};

char *sc_name_table[NR_SYSCALLS] = {
#define SYSCALL(n, name) [n] = #name,
  SYSCALLS
#undef SYSCALL
};
