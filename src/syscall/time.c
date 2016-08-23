#include "common.h"
#include "noah.h"
#include "linux/misc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include <time.h>

DEFINE_SYSCALL(time, gaddr_t, tloc_ptr)
{
  return time(guest_to_host(tloc_ptr));
}
