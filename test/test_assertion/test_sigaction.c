#include <stdio.h>
#include <signal.h>

#include "test_assert.h"

int handle_count = 0;

void
handle(int signum)
{
  handle_count++;
  assert_true(handle_count == 1);
}

int
main()
{
  nr_tests(2);

  struct sigaction act, oact;
  act.sa_handler = handle;
  act.sa_flags = SA_RESETHAND;

  sigaction(SIGCONT, &act, &oact); // Chosen because default action is ignore, and the number is different in Linux and Darwin
  kill(getpid(), SIGCONT); // Must cause "handle"
  kill(getpid(), SIGCONT); // Must be ignored

  act.sa_handler = SIG_IGN;
  act.sa_flags = 0;
  sigaction(SIGINT, &act, &oact);

  kill(getpid(), SIGINT); // Must be ignored

  assert_true(1); // Must arrive here
}
