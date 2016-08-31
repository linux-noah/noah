#include "common.h"
#include "noah.h"
#include "linux/common.h"
#include "linux/futex.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int
do_futex_wake(gaddr_t uaddr, int count)
{
  return 0;
}

DEFINE_SYSCALL(futex, gaddr_t, uaddr, int, op, uint32_t, val, gaddr_t, timeout_ptr, gaddr_t, uaddr2_ptr, uint32_t, val3)
{
  /* uint32_t *l_uaddr = guest_to_host(uaddr_ptr); */
  /* const struct l_timespec *l_timeout = guest_to_host(timeout_ptr); */
  /* uint32_t *l_uaddr2 = guest_to_host(uaddr2_ptr); */

  bool private = op & LINUX_FUTEX_PRIVATE_FLAG;
  bool realtime = op & LINUX_FUTEX_CLOCK_REALTIME;

  assert(private);
  assert(! realtime);

  switch (op & LINUX_FUTEX_CMD_MASK) {
  case LINUX_FUTEX_WAKE: return do_futex_wake(uaddr, val);
  default:
    fprintf(stderr, "unsupported futex command: %d\n", op);
    return -ENOSYS;
  }
}
