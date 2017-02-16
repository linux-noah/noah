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
  usleep(500);
  return (void *)&count;
}

void
test_thread_create()
{
  pthread_t thread;
  pthread_create(&thread, NULL, thread_start, NULL);
  void *ret;
  pthread_join(thread, &ret);
  assert_true(count == 1);
  assert_true(ret == &count);
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
  pthread_join(thread, NULL);
  assert_true(tls_data == 0xface);
}

int main()
{
  nr_tests(7);
  test_thread_create();
  test_tls();
}
