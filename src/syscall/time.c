#include "common.h"
#include "noah.h"

#include "linux/common.h"
#include "linux/misc.h"
#include "linux/time.h"

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

DEFINE_SYSCALL(nanosleep, gaddr_t, rqtp, gaddr_t, rmtp)
{
  return nanosleep(guest_to_host(rqtp), guest_to_host(rmtp));
}

DEFINE_SYSCALL(utimes, gaddr_t, filename, gaddr_t, timevals)
{
  return utimes(guest_to_host(filename), guest_to_host(timevals));
}

DEFINE_SYSCALL(utimensat, gaddr_t, filename, gaddr_t, timevals)
{
  // HFS+ suppots only second precision timestamp
  struct timeval times[2];
  int ret = utimes(guest_to_host(filename), times);
  if (ret < 0) {
    return ret;
  }

  struct l_timespec (*l_times)[2] = guest_to_host(timevals);
  *l_times[0]= (struct l_timespec){times[0].tv_sec, 0};
  *l_times[1]= (struct l_timespec){times[1].tv_sec, 0};

  return ret;
}
