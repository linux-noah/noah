#include "noah.h"

int main(int argc, char *argv[])
{
  char buf[256];
  long n;
  while ((n = read(0, buf, sizeof buf)) > 0) {
    long offset = 0, w;
    while ((w = write(1, buf + offset, n)) > 0) {
      offset += w;
      n -= w;
    }
  }
  _exit(0);
}
