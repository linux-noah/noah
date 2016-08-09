#include "noah.h"

int main()
{
  const char str[] = "hello, world!\n";
  write(1, str, sizeof str - 1);
  return 0;
}
