#include "common.h"
#include "../common.h"
#include "../sandbox.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/uio.h>

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

DEFINE_SYSCALL(rename, const char *, oldpath, const char *, newpath)
{
  return rename(copy_from_user(oldpath), copy_from_user(newpath));
}

DEFINE_SYSCALL(ioctl, int, fd, int, cmd)
{
  PRINTF("ioctl (fd = %08x, cmd = %d)\n", fd, cmd);
  return -1;
}

DEFINE_SYSCALL(writev, int, fd, const struct iovec *, iov, int, iovcnt)
{
  struct iovec *src = copy_from_user(iov), dst[iovcnt];

  for (int i = 0; i < iovcnt; ++i) {
    dst[i].iov_base = copy_from_user(src[i].iov_base);
    dst[i].iov_len = src[i].iov_len;
  }
  return writev(fd, dst, iovcnt);
}
