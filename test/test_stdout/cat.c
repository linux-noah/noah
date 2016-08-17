#include <unistd.h>
#include <fcntl.h>

int writeall(int fd)
{
  char buf[256];
  long n;
  while ((n = read(fd, buf, sizeof buf)) > 0) {
    long offset = 0, w;
    while ((w = write(1, buf + offset, n)) > 0) {
      offset += w;
      n -= w;
    }
    if (w != 0)
      return -1;
  }
  if (n != 0)
    return -1;
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc == 1) {
    writeall(0);
  }
  for (int i = 1; i < argc; ++i) {
    int fd = open(argv[i], O_RDONLY);
    writeall(fd);
    close(fd);
  }
  return 0;
}
