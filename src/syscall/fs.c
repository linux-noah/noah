/*-
 * Copyright (c) 2016 Yuichi Nishiwaki and Takaya Saeki
 * Copyright (c) 1994-1995 Søren Schmidt
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer
 *    in this position and unchanged.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "common.h"
#include "noah.h"

#include "linux/common.h"
#include "linux/fs.h"
#include "linux/misc.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/select.h>
#include <sys/poll.h>
#include <dirent.h>

DEFINE_SYSCALL(write, int, fd, gaddr_t, buf, size_t, size)
{
  return write(fd, guest_to_host(buf), size);
}

DEFINE_SYSCALL(read, int, fd, gaddr_t, buf, size_t, size)
{
  return read(fd, guest_to_host(buf), size);
}

int
do_open(const char *path, int l_flags, int mode)
{
  char buf[LINUX_PATH_MAX + sizeof "./mnt/" - 1];

  int flags = 0;
  switch (l_flags & LINUX_O_ACCMODE) {
  case LINUX_O_WRONLY:
    flags |= O_WRONLY;
    break;
  case LINUX_O_RDWR:
    flags |= O_RDWR;
    break;
  default:                      /* Note: LINUX_O_RDONLY == 0 */
    flags |= O_RDONLY;
  }
  if (l_flags & LINUX_O_NDELAY)
    flags |= O_NONBLOCK;
  if (l_flags & LINUX_O_APPEND)
    flags |= O_APPEND;
  if (l_flags & LINUX_O_SYNC)
    flags |= O_FSYNC;
  if (l_flags & LINUX_O_NONBLOCK)
    flags |= O_NONBLOCK;
  if (l_flags & LINUX_FASYNC)
    flags |= O_ASYNC;
  if (l_flags & LINUX_O_CREAT)
    flags |= O_CREAT;
  if (l_flags & LINUX_O_TRUNC)
    flags |= O_TRUNC;
  if (l_flags & LINUX_O_EXCL)
    flags |= O_EXCL;
  if (l_flags & LINUX_O_NOCTTY)
    flags |= O_NOCTTY;
  /* if (l_flags & LINUX_O_DIRECT) */
  /*   flags |= O_DIRECT; */
  if (l_flags & LINUX_O_NOFOLLOW)
    flags |= O_NOFOLLOW;
  if (l_flags & LINUX_O_DIRECTORY)
    flags |= O_DIRECTORY;

  if (path[0] == '/') {
    strcpy(buf, "./mnt/");
    strcat(buf, path);
    int fd = open(buf, flags, mode);
    if (fd >= 0)
      return fd;
    /* fall through... */
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

static void
stat_darwin_to_linux(struct stat *stat, struct l_newstat *lstat)
{
  lstat->st_dev = minor(stat->st_dev) | (major(stat->st_dev) << 8);
  lstat->st_ino = stat->st_ino;
  lstat->st_mode = stat->st_mode;
  lstat->st_nlink = stat->st_nlink;
  lstat->st_uid = stat->st_uid;
  lstat->st_gid = stat->st_gid;
  lstat->st_rdev = stat->st_rdev;
  lstat->st_size = stat->st_size;
  lstat->st_atim.tv_sec = stat->st_atimespec.tv_sec;
  lstat->st_atim.tv_nsec = stat->st_atimespec.tv_nsec;
  lstat->st_mtim.tv_sec = stat->st_mtimespec.tv_sec;
  lstat->st_mtim.tv_nsec = stat->st_mtimespec.tv_nsec;
  lstat->st_ctim.tv_sec = stat->st_ctimespec.tv_sec;
  lstat->st_ctim.tv_nsec = stat->st_ctimespec.tv_nsec;
  lstat->st_blksize = stat->st_blksize;
  lstat->st_blocks = stat->st_blocks;
}

DEFINE_SYSCALL(stat, gaddr_t, path, gaddr_t, st)
{
  const char *l_path = guest_to_host(path);
  struct l_newstat *l_st = guest_to_host(st);
  struct stat d_st;

  int ret = stat(l_path, &d_st);
  if (ret < 0)
    return ret;

  stat_darwin_to_linux(&d_st, l_st);

  return 0;
}

DEFINE_SYSCALL(fstat, int, fd, gaddr_t, st)
{
  struct l_newstat *l_st = guest_to_host(st);
  struct stat d_st;

  int ret = fstat(fd, &d_st);
  if (ret < 0)
    return ret;

  stat_darwin_to_linux(&d_st, l_st);

  return 0;
}

DEFINE_SYSCALL(lstat, gaddr_t, path, gaddr_t, st)
{
  const char *l_path = guest_to_host(path);
  struct l_newstat *l_st = guest_to_host(st);
  struct stat d_st;

  int ret = lstat(l_path, &d_st);
  if (ret < 0)
    return ret;

  stat_darwin_to_linux(&d_st, l_st);

  return 0;
}

DEFINE_SYSCALL(access, gaddr_t, path, int, mode)
{
  return access(guest_to_host(path), mode);
}

DEFINE_SYSCALL(getdents, unsigned int, fd, gaddr_t, dirent_ptr, unsigned int, count)
{
  long base;
  char buf[count];
  struct dirent *d;
  int bpos;

  struct l_dirent *l_d;
  char *l_buf = guest_to_host(dirent_ptr);
  unsigned int l_bpos = 0;

  int nread = syscall(SYS_getdirentries64, fd, buf, count, &base);
  if (nread < 0) {
    return -1;
  }
  for (bpos = 0; bpos < nread; bpos += d->d_reclen) {
    d = (struct dirent *) (buf + bpos);

    size_t l_reclen = roundup(offsetof(struct l_dirent, d_name) + d->d_namlen + 2, 8);
    assert(l_bpos + l_reclen <= count);

    /* fill dirent buffer */
    l_d = (struct l_dirent *) (l_buf + l_bpos);
    l_d->d_ino = d->d_ino;
    l_d->d_reclen = l_reclen;
    l_d->d_off = d->d_seekoff;
    memcpy(l_d->d_name, d->d_name, d->d_namlen + 1);
    (l_buf + l_bpos)[l_d->d_reclen - 1] = d->d_type;

    l_bpos += l_d->d_reclen;
  }
  return l_bpos;
}

DEFINE_SYSCALL(pipe, gaddr_t, fildes_ptr)
{
  return pipe(guest_to_host(fildes_ptr));
}

DEFINE_SYSCALL(dup, unsigned int, fd)
{
  return dup(fd);
}

DEFINE_SYSCALL(dup2, unsigned int, fd1, unsigned int, fd2)
{
  return dup2(fd1, fd2);
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

DEFINE_SYSCALL(symlink, gaddr_t, path1, gaddr_t, path2)
{
  return symlink(guest_to_host(path1), guest_to_host(path2));
}

DEFINE_SYSCALL(readlink, gaddr_t, pathname, gaddr_t, buf, int, bufsize)
{
  return readlink(guest_to_host(pathname), guest_to_host(buf), bufsize);
}

DEFINE_SYSCALL(unlink, gaddr_t, pathname)
{
  return unlink(guest_to_host(pathname));
}

DEFINE_SYSCALL(fadvise64, int, fd, off_t, offset, size_t, len, int, advice)
{
  return -1;
}

DEFINE_SYSCALL(select, int, nfds, gaddr_t, readfds, gaddr_t, writefds, gaddr_t, errorfds, gaddr_t, timeout)
{
  struct timeval *h_timeout = (struct timeval*)guest_to_host(timeout);

  // Darwin's fd_set is compatible with that of Linux
  fd_set *h_readfds = guest_to_host(readfds), *h_writefds = guest_to_host(writefds), *h_errorfds = guest_to_host(errorfds);

  return select(nfds, h_readfds, h_writefds, h_errorfds, h_timeout);
}

DEFINE_SYSCALL(poll, gaddr_t, fds, int, nfds, int, timeout)
{
  return poll(guest_to_host(fds), nfds, timeout);
}

DEFINE_SYSCALL(chdir, gaddr_t, path)
{
  return chdir(guest_to_host(path));
}

DEFINE_SYSCALL(fchdir, int, fd)
{
  return fchdir(fd);
}

DEFINE_SYSCALL(chmod, gaddr_t, path, int, mode)
{
  return chmod(guest_to_host(path), mode);
}

DEFINE_SYSCALL(fchmod, int, fd, int, mode)
{
  return fchmod(fd, mode);
}

DEFINE_SYSCALL(fchown, int, fildes, int, uid, int, gid)
{
  return fchown(fildes, uid, gid);
}

DEFINE_SYSCALL(chown, gaddr_t, path, int, uid, int, gid)
{
  return chown(guest_to_host(path), uid, gid);
}

DEFINE_SYSCALL(lchown, gaddr_t, path, int, uid, int, gid)
{
  return lchown(guest_to_host(path), uid, gid);
}

DEFINE_SYSCALL(lseek, int, fildes, off_t, offset, int, whence)
{
  return lseek(fildes, offset, whence);
}

DEFINE_SYSCALL(mkdir, gaddr_t, path, int, mode)
{
  return mkdir(guest_to_host(path), mode);
}

DEFINE_SYSCALL(rmdir, gaddr_t, path)
{
  return rmdir(guest_to_host(path));
}
