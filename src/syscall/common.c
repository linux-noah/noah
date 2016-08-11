#include "syscall.h"

#include <stdlib.h>
#include <stdio.h>

DEFINE_SYSCALL(unimplemented, int, ignore)
{
  (void)ignore;

  fprintf(stderr, "unimplemented syscall\n");
  exit(1);
}
