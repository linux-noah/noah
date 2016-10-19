#include "common.h"
#include "noah.h"

#include "linux/common.h"
#include "linux/misc.h"
#include "linux/time.h"
#include "linux/fs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <ctype.h>

#include <time.h>
#include <sys/time.h>
#include <mach/clock.h>
#include <mach/mach.h>

DEFINE_SYSCALL(time, gaddr_t, tloc_ptr)
{
  return syswrap(time(guest_to_host(tloc_ptr)));
}

DEFINE_SYSCALL(gettimeofday, gaddr_t, tp, gaddr_t, tzp)
{
  return syswrap(gettimeofday(guest_to_host(tp), guest_to_host(tzp)));
}

DEFINE_SYSCALL(nanosleep, gaddr_t, rqtp, gaddr_t, rmtp)
{
  return syswrap(nanosleep(guest_to_host(rqtp), guest_to_host(rmtp)));
}

DEFINE_SYSCALL(utimes, gaddr_t, filename, gaddr_t, timevals)
{
  return syswrap(utimes(guest_to_host(filename), guest_to_host(timevals)));
}

DEFINE_SYSCALL(utimensat, int, dirfd, gaddr_t, filename, gaddr_t, timevals, int, flags)
{
  // HFS+ suppots only second precision timestamp
  struct timeval times[2];
  int fd;

  if (filename == 0) {
    fd = dirfd; // Linux allows filename to be NULL and treat dirfd as fd
  } else {
    fd = do_open_at(dirfd, guest_to_host(filename), flags, LINUX_O_RDWR);
  }
  int ret = syswrap(futimes(fd, times));

  return ret;
}

DEFINE_SYSCALL(clock_gettime, l_clockid_t, id, gaddr_t, spec)
{
  struct timespec *l_ts = guest_to_host(spec);

  if (id != LINUX_CLOCK_MONOTONIC && id != LINUX_CLOCK_MONOTONIC_COARSE && id != LINUX_CLOCK_REALTIME) {
    fprintf(stderr, "id:%d\n", id);
    exit(1);
  }

  clock_serv_t cclock;
  mach_timespec_t mts;
  host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
  clock_get_time(cclock, &mts);
  mach_port_deallocate(mach_task_self(), cclock);
  l_ts->tv_sec = mts.tv_sec;
  l_ts->tv_nsec = mts.tv_nsec;

  return 0;
}
