#include <stdio.h>
#include <signal.h>

#include "test_assert.h"

int main()
{
  nr_tests(3);
  sigset_t set;

  sigemptyset(&set);
  sigaddset(&set, SIGINT);

  sigprocmask(SIG_BLOCK, &set, NULL);
  kill(getpid(), SIGINT);
  assert_true(1); // This line should run

  sigset_t pending;
  sigpending(&pending);
  assert_true(sigismember(&pending, SIGINT));
}
