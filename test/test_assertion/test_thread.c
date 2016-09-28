#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "test_assert.h"

int count;

__thread int tls_data = 0xbeef;

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

void*
thread_tls(void *arg)
{
  assert_true(tls_data == 0xbeef);
  tls_data = 0xdead;
  assert_true(tls_data == 0xdead);
  return NULL;
}

void
test_tls()
{
  assert_true(tls_data == 0xbeef);
  tls_data = 0xface;
  assert_true(tls_data == 0xface);
  pthread_t thread;
  pthread_create(&thread, NULL, thread_tls, NULL);
  usleep(5000); // FIXME: replace with pthread_join after implementing futex
  assert_true(tls_data == 0xface);
}

int main()
{
  test_thread_create();
  test_tls();
}
