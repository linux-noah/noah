#include "syscall.h"
#include "../sandbox.h"

#include <fcntl.h>
#include <unistd.h>

DEFINE_SYSCALL(write, int, fd, const void *, buf, size_t, size)
{
  return write(fd, copy_from_user(buf), size);
}

DEFINE_SYSCALL(read, int, fd, void *, buf, size_t, size)
{
  return read(fd, copy_from_user(buf), size);
}

DEFINE_SYSCALL(open, const char *, path, int, flags, int, mode)
{
  return open(path, flags, mode);
}

DEFINE_SYSCALL(close, int, fd)
{
  return close(fd);
}

DEFINE_SYSCALL(exit, int, reason)
{
  _exit(reason);
}
