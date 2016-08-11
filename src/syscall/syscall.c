#include "syscall.h"

#define SYSCALL(n, name) uint64_t sys_##name(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);

SYSCALLS

#undef SYSCALL
#define SYSCALL(n, name) [n] = ((sc_handler_t) sys_##name),

sc_handler_t sc_handler_table[NR_SYSCALLS] = {
  SYSCALLS
};
