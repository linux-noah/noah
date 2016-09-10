#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "test_assert.h"

int count;

void*
thread_start(void *arg)
{
  count++;
  return NULL;
}

void
test_thread_create()
{
  pthread_t thread;
  pthread_create(&thread, NULL, thread_start, NULL);
  usleep(5000); // FIXME: replace with pthread_join after implementing futex
  assert_true(count == 1);
}

int main()
{
  test_thread_create();
}
