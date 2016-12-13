#include <stdio.h>
#include <signal.h>
#include <sched.h>

#include "test_assert.h"

int handle_count = 0;

void
handle(int signum)
{
  handle_count++;
  assert_true(handle_count == 1);
}

int handle_nodefer_count = 0;

void
handle_nodefer(int signum)
{
  handle_nodefer_count++;
  if (handle_nodefer_count == 1) {
    kill(getpid(), SIGINT);
    sched_yield();
  }
  else if (handle_nodefer_count == 2) {
    assert_true(1);
    kill(getpid(), SIGCONT);
    sched_yield();
  }
  else if (handle_nodefer_count == 3) {
    assert_true(0);
  }
  handle_nodefer_count--;
}

int
main()
{
  nr_tests(5);

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

  act.sa_handler = handle_nodefer;
  act.sa_flags = SA_NODEFER;
  sigemptyset(&act.sa_mask);
  sigaddset(&act.sa_mask, SIGCONT);
  sigaction(SIGINT, &act, &oact);

  kill(getpid(), SIGINT);
  assert_true(oact.sa_handler == SIG_IGN);

  sigaction(SIGINT, NULL, &oact);
  assert_true(oact.sa_handler == handle_nodefer);

  assert_true(1); // Must arrive here
}
