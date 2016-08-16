#include "common.h"
#include "../common.h"
#include "../sandbox.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

DEFINE_SYSCALL(mprotect, void *, addr, size_t, len, int, prot)
{
  return 0;
}
