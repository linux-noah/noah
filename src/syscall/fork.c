#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "common.h"
#include "noah.h"

DEFINE_SYSCALL(fork)
{
  save_regs(&vcpu);
  save_vmcs(&vcpu);
  vmm_destroy();

  pid_t pid = fork();
  if (pid > 0) {
    PRINTF("fork parent, pid:%d\n", getpid());
    vmm_clone();
    return pid;
  } else if (pid == 0) {
    PRINTF("fork child, pid:%d\n", getpid());
    vmm_clone();
    return 0;
  } else {
    fprintf(stderr, "fork failed");
    exit(1);
  }
}
