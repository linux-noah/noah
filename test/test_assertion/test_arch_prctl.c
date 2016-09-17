#include "syscall.h"
#include "test_assert.h"

/*
 *  Omit libc in order to set fs and gs registers manually
 */

#define SYS_ARCH_PRCTL 158

int arch_prctl_set(int code, unsigned long addr)
{
  return syscall(SYS_ARCH_PRCTL, code, addr, 0);
}

int arch_prctl_get(int code, unsigned long *addr)
{
  return syscall(SYS_ARCH_PRCTL, code, (uint64_t)addr, 0);
}

int main()
{
  static const int SET_GS = 0x1001, SET_FS = 0x1002, GET_GS = 0x1003, GET_FS = 0x1004;
  unsigned long value;

  arch_prctl_set(SET_FS, 0xbeef);
  arch_prctl_set(SET_GS, 0xbeef);

  value = 0;
  arch_prctl_get(GET_GS, &value);
  assert_true(value == 0xbeef);

  value = 0;
  arch_prctl_get(GET_FS, &value);
  assert_true(value == 0xbeef);

  return 0;
}
