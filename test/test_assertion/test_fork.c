#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "test_assert.h"

int global_var = 1;

int main()
{
  nr_tests(5);
  pid_t parent_pid = getpid();
  pid_t fork_pid = fork();
  if (fork_pid == 0) {
    assert_true(parent_pid != getpid());
    global_var = 0;
  } else {
    assert_true(fork_pid > 0);
    assert_true(parent_pid == getpid());
    assert_true(fork_pid != getpid());

    /* Test that unistdunistdmory space of parents and childs are separated */
    int stat;
    wait4(fork_pid, &stat, 0, NULL);
    assert_true(global_var == 1);
  }
}

