#include "noah.h"

int print(const char *str)
{
  long offset = 0, n = strlen(str), w;
  while ((w = write(1, str + offset, n)) > 0) {
    offset += w;
    n -= w;
  }
  return w == 0;
}

int main(int argc, char *argv[])
{
  for (int i = 1; i < argc; ++i) {
    if (i > 1) {
      print(" ");
    }
    if (! print(argv[i]))
      return 1;
  }
  print("\n");
  return 0;
}
