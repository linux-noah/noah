#include "common.h"
#include "noah.h"

#include <stdlib.h>
#include <stdio.h>
#include "linux/errno.h"

DEFINE_SYSCALL(unimplemented)
{
  uint64_t rax;

  hv_vcpu_read_register(vcpuid, HV_X86_RAX, &rax);

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
