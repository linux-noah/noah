#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>
#include <unistd.h>

#include "test_assert.h"

void *sas_sp;

void
handle_sigaction(int signum, siginfo_t *info, void *context)
{
  stack_t osas;

  assert_true(((ucontext_t *) context)->uc_stack.ss_sp == sas_sp);
  sigaltstack(NULL, &osas);
  assert_true(osas.ss_flags == SS_ONSTACK);
  osas.ss_flags = 0;
  assert_true(sigaltstack(&osas, NULL) == -1 && errno == EPERM);
}

int
main()
{
  nr_tests(6);

  stack_t sas, osas;

  sas_sp = malloc(SIGSTKSZ);
  sas.ss_sp = sas_sp;
  sas.ss_flags = 0;
  sas.ss_size = SIGSTKSZ;
  sigaltstack(&sas, &osas);
  assert_true(osas.ss_flags == SS_DISABLE);

  osas = (stack_t) {};
  sigaltstack(NULL, &osas);
  assert_true(osas.ss_sp == sas_sp);

  struct sigaction act;
  act.sa_sigaction = handle_sigaction;
  act.sa_flags = SA_SIGINFO | SA_ONSTACK;

  sigaction(SIGCONT, &act, NULL);
  kill(getpid(), SIGCONT);

  assert_true(1); // Must arrive here
}
