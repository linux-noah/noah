#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "common.h"
#include "noah.h"

DEFINE_SYSCALL(fork)
{
  int ret;

  // Because Apple Hypervisor Framwork won't let us use multiple VMs,
  // we destroy the current vm and restore it later
  vmm_snapshot();
  vmm_destroy();

  pid_t pid = fork();

  if (pid < 0) {
    ret = -1;
  } else {
    ret = pid;
  }

  vmm_restore();

  return ret;
}
