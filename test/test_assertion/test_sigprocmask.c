#include <stdio.h>
#include <signal.h>

#include "test_assert.h"

int main()
{
  nr_tests(3);
  sigset_t set, oset;

  sigemptyset(&set);
  sigaddset(&set, SIGINT);

  // Test SIGINT is blocked
  sigprocmask(SIG_BLOCK, &set, NULL);
  kill(getpid(), SIGINT); // This should be blocked
  assert_true(1);         // And this line should run
  
  // Test oset is updated
  sigemptyset(&set);
  sigemptyset(&oset);
  assert_false(sigismember(&oset, SIGINT));
  sigprocmask(SIG_BLOCK, &set, &oset);
  assert_true(sigismember(&oset, SIGINT));
}
