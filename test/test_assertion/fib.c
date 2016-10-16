#include "test_assert.h"

int fib(int n)
{
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fib(n - 2) + fib(n - 1);
  }
}

int main()
{
  nr_tests(1);

  assert_true(fib(10) == 55);
  return 0;
}

