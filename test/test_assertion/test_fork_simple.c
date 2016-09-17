#include <stdio.h>
#include <unistd.h>
#include "test_assert.h"

#define SYS_FORK 57

pid_t sys_fork(void)
{
  return syscall(SYS_FORK);
}


int main()
{
  pid_t parent_pid = getpid();
  pid_t fork_pid = sys_fork();
  if (fork_pid == 0) {
    assert_true(parent_pid != getpid());
    printf("fork,child getpid:%d\n", getpid());
  } else {
    assert_true(fork_pid > 0);
    assert_true(parent_pid == getpid());
    assert_true(fork_pid != getpid());
    printf("fork,parent getpid:%d, fork_pid%d\n", getpid(), fork_pid);
  }
}

