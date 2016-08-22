#include "common.h"

#include "noah.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/stat.h>

DEFINE_SYSCALL(write, int, fd, gaddr_t, buf, size_t, size)
{
  return write(fd, guest_to_host(buf), size);
}

DEFINE_SYSCALL(read, int, fd, gaddr_t, buf, size_t, size)
{
  return read(fd, guest_to_host(buf), size);
}

int
do_open(const char *path, int flags, int mode)
{
  char buf[L_PATH_MAX + sizeof "./mnt/" - 1];

  if (path[0] == '/') {
    strcpy(buf, "./mnt/");
    strcat(buf, path);
    path = buf;
  }
  return open(path, flags, mode);
}

DEFINE_SYSCALL(open, gaddr_t, path, int, flags, int, mode)
{
  return do_open(guest_to_host(path), flags, mode);
}

DEFINE_SYSCALL(close, int, fd)
{
  return close(fd);
}

DEFINE_SYSCALL(stat, gaddr_t, path, gaddr_t, st)
{
  return stat(guest_to_host(path), guest_to_host(st));
}

DEFINE_SYSCALL(fstat, int, fd, gaddr_t, st)
{
  return fstat(fd, guest_to_host(st));
}

DEFINE_SYSCALL(access, gaddr_t, path, int, mode)
{
  return access(guest_to_host(path), mode);
}

DEFINE_SYSCALL(getcwd, gaddr_t, buf, unsigned long, size)
{
  getcwd(guest_to_host(buf), size);
  return 0;
}

DEFINE_SYSCALL(rename, gaddr_t, oldpath, gaddr_t, newpath)
{
  return rename(guest_to_host(oldpath), guest_to_host(newpath));
}

DEFINE_SYSCALL(ioctl, int, fd, int, cmd)
{
  PRINTF("ioctl (fd = %08x, cmd = %d)\n", fd, cmd);
  return -1;
}

DEFINE_SYSCALL(fcntl, unsigned int, fd, unsigned int, cmd, unsigned long, arg)
{
  return fcntl(fd, cmd, arg);
}

struct l_iovec {
  gaddr_t iov_base;
  size_t iov_len;
};

DEFINE_SYSCALL(writev, int, fd, gaddr_t, iov, int, iovcnt)
{
  struct l_iovec *src = guest_to_host(iov);
  struct iovec dst[iovcnt];

  for (int i = 0; i < iovcnt; ++i) {
    dst[i].iov_base = guest_to_host(src[i].iov_base);
    dst[i].iov_len = src[i].iov_len;
  }
  return writev(fd, dst, iovcnt);
}

DEFINE_SYSCALL(readlink, gaddr_t, pathname, gaddr_t, buf, int, bufsize)
{
  return -1;
}
