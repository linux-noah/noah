#include "noah.h"

int _start()
{
  const char str[] = "hello, world!\n";
  write(1, str, sizeof str - 1);
  _exit(0);
}
