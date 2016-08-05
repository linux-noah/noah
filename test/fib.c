#include "noah.h"

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

int _start()
{
  int fib10 = fib(10);
  _exit(fib10);
}

