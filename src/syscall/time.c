#include "common.h"
#include "noah.h"

#include "linux/common.h"
#include "linux/misc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include <time.h>
#include <sys/time.h>

DEFINE_SYSCALL(time, gaddr_t, tloc_ptr)
{
  return time(guest_to_host(tloc_ptr));
}

DEFINE_SYSCALL(gettimeofday, gaddr_t, tp, gaddr_t, tzp)
{
  return gettimeofday(guest_to_host(tp), guest_to_host(tzp));
}
