#include <stdio.h>
#include <unistd.h>
#include "test_assert.h"

int main()
{
  pid_t parent_pid = getpid();
  pid_t fork_pid = fork();
  if (fork_pid == 0) {
    assert_true(parent_pid != getpid());
  } else {
    assert_true(fork_pid > 0);
    assert_true(parent_pid == getpid());
    assert_true(fork_pid != getpid());
  }
}

