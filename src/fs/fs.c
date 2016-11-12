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
#include "linux/time.h"
#include "linux/fs.h"
#include "linux/misc.h"
#include "linux/errno.h"
#include "linux/ioctl.h"
#include "linux/termios.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
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
#include <sys/mount.h>
#include <sys/syslimits.h>
#include <dirent.h>
#include <termios.h>
#include <sys/ioctl.h>

#include <mach-o/dyld.h>

struct file {
  struct file_operations *ops;
  int fd;
};

struct file_operations {
  int (*write)(struct file *f, const char *buf, size_t size);
  int (*read)(struct file *f, char *buf, size_t size);
};

int
darwinfs_write(struct file *file, const char *buf, size_t size)
{
  return syswrap(write(file->fd, buf, size));
}

int
darwinfs_read(struct file *file, char *buf, size_t size)
{
  return syswrap(read(file->fd, buf, size));
}

struct file *
vfs_acquire(int fd)
{
  static struct file_operations ops = {
    .write = darwinfs_write,
    .read = darwinfs_read,
  };

  struct file *file;
  file = malloc(sizeof *file);
  file->ops = &ops;
  file->fd = fd;
  return file;
}

void
vfs_release(struct file *file)
{
  free(file);
}

DEFINE_SYSCALL(write, int, fd, gaddr_t, buf_ptr, size_t, size)
{
  char buf[size];
  copy_from_user(buf, buf_ptr, size);
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int r = file->ops->write(file, buf, size);
  vfs_release(file);
  return r;
}

DEFINE_SYSCALL(read, int, fd, gaddr_t, buf_ptr, size_t, size)
{
  char buf[size];
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int n = file->ops->read(file, buf, size);
  if (n > 0) {
    copy_to_user(buf_ptr, buf, n);
  }
  vfs_release(file);
  return n;
}

char*
to_host_path(const char *path)
{
  if (path[0] == '/') {
    int len = snprintf(NULL, 0, "%s/%s", proc.root, path);
    char *mnt_path = malloc(len + 1);
    snprintf(mnt_path, len + 1, "%s/%s", proc.root, path);
    return mnt_path;
  }
  return strdup(path);
}

int
do_open_at(int l_fd, const char *path, int l_flags, int mode)
{
  int flags = linux_to_darwin_o_flags(l_flags);
  char *host_path = to_host_path(path);
  if (l_fd == LINUX_AT_FDCWD) {
    l_fd = AT_FDCWD;
  }

  int ret = syswrap(openat(l_fd, host_path, flags, mode));

  free(host_path);
  return ret;
}

int
do_open(const char *path, int l_flags, int mode)
{
  return do_open_at(LINUX_AT_FDCWD, path, l_flags, mode);
}

DEFINE_SYSCALL(open, gstr_t, path, int, flags, int, mode)
{
  return do_open(guest_to_host(path), flags, mode);
}

DEFINE_SYSCALL(close, int, fd)
{
  return syswrap(close(fd));
}

DEFINE_SYSCALL(stat, gstr_t, path, gaddr_t, st)
{
  char *host_path = to_host_path(guest_to_host(path));
  struct l_newstat *l_st = guest_to_host(st);
  struct stat d_st;

  int ret = syswrap(stat(host_path, &d_st));
  free(host_path);
  if (ret < 0) {
    return ret;
  }

  stat_darwin_to_linux(&d_st, l_st);

  return 0;
}

DEFINE_SYSCALL(newfstatat, int, dirfd, gstr_t, path, gaddr_t, st, int, flags)
{
  char *host_path = to_host_path(guest_to_host(path));
  struct l_newstat *l_st = guest_to_host(st);
  struct stat d_st;

  int ret = syswrap(fstatat(dirfd, host_path, &d_st, linux_to_darwin_at_flags(flags)));
  free(host_path);
  if (ret < 0) {
    return ret;
  }

  stat_darwin_to_linux(&d_st, l_st);

  return 0;
}

DEFINE_SYSCALL(fstat, int, fd, gaddr_t, st)
{
  struct l_newstat *l_st = guest_to_host(st);
  struct stat d_st;

  int ret = syswrap(fstat(fd, &d_st));
  if (ret < 0)
    return ret;

  stat_darwin_to_linux(&d_st, l_st);

  return 0;
}

DEFINE_SYSCALL(lstat, gstr_t, path, gaddr_t, st)
{
  char *host_path = to_host_path(guest_to_host(path));
  struct l_newstat *l_st = guest_to_host(st);
  struct stat d_st;

  int ret = syswrap(lstat(host_path, &d_st));
  free(host_path);
  if (ret < 0) {
    return ret;
  }

  stat_darwin_to_linux(&d_st, l_st);

  return 0;
}

int do_faccessat(int l_dirfd, const char *l_path, int l_mode)
{
  char *host_path = to_host_path(l_path);
  if (l_dirfd == LINUX_AT_FDCWD) {
    l_dirfd = AT_FDCWD;
  }

  int ret = syswrap(faccessat(l_dirfd, host_path, l_mode, 0));
  free(host_path);

  return ret;
}

int do_access(const char *path, int l_mode)
{
  return do_faccessat(LINUX_AT_FDCWD, path, l_mode);
}

DEFINE_SYSCALL(access, gstr_t, path, int, mode)
{
  return do_access(guest_to_host(path), mode);
}

// Linux implementation of faccessat actually does not have "flags"
DEFINE_SYSCALL(faccessat, int, dirfd, gstr_t, path, int, mode)
{
  return do_faccessat(dirfd, guest_to_host(path), mode);
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
    return -errno;
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
  return syswrap(pipe(guest_to_host(fildes_ptr)));
}

DEFINE_SYSCALL(pipe2, gaddr_t, fildes_ptr, int, flags)
{
  if (flags & ~(LINUX_O_NONBLOCK | LINUX_O_CLOEXEC | LINUX_O_DIRECT)) {
    return -LINUX_EINVAL;
  }

  int fildes[2];

  int err = pipe(fildes);
  if (err < 0) {
    return err;
  }

  int err0, err1;
  if (flags & LINUX_O_CLOEXEC) {
    // TODO: This implementation does not prevent race condition
    //       Make sure that exec closes fds after robust fd control is implemented (i.e. VFS)
    err0 = syswrap(fcntl(fildes[0], F_SETFD, FD_CLOEXEC));
    err1 = syswrap(fcntl(fildes[1], F_SETFD, FD_CLOEXEC));
    if (err0 < 0 || err1 < 0) {
      goto fail_fcntl;
    }
  }
  if (flags & LINUX_O_NONBLOCK) {
    err0 = syswrap(fcntl(fildes[0], F_SETFL, O_NONBLOCK));
    err1 = syswrap(fcntl(fildes[1], F_SETFL, O_NONBLOCK));
    if (err0 < 0 || err1 < 0) {
      goto fail_fcntl;
    }
  }
  if (flags & LINUX_O_DIRECT) {
    err0 = syswrap(fcntl(fildes[0], F_NOCACHE, 1));
    err1 = syswrap(fcntl(fildes[1], F_NOCACHE, 1));
    if (err0 < 0 || err1 < 0) {
      goto fail_fcntl;
    }
  }

  copy_to_user(fildes_ptr, fildes, sizeof(fildes));

  return 0;

fail_fcntl:
  close(fildes[0]);
  close(fildes[1]);
  return (err0 < 0) ? err0 : err1;
}

DEFINE_SYSCALL(dup, unsigned int, fd)
{
  return syswrap(dup(fd));
}

DEFINE_SYSCALL(dup2, unsigned int, fd1, unsigned int, fd2)
{
  return syswrap(dup2(fd1, fd2));
}

DEFINE_SYSCALL(dup3, unsigned int, oldfd, unsigned int, newfd, int, flags)
{
  if (flags & ~LINUX_O_CLOEXEC) {
    return -LINUX_EINVAL;
  }
  if (oldfd == newfd) {
    return -LINUX_EINVAL;
  }

  // TODO: This implementation does not prevent race condition
  //       Make sure that exec closes fds after robust fd control is implemented (i.e. VFS)
  int ret = syswrap(dup2(oldfd, newfd));
  if (ret == 0 && (flags & LINUX_O_CLOEXEC)) {
    ret = syswrap(fcntl(newfd, F_SETFD, FD_CLOEXEC));
  }

  return ret;
}

DEFINE_SYSCALL(getcwd, gaddr_t, buf, unsigned long, size)
{
  int ret = syswrap((int)getcwd(guest_to_host(buf), size));
  if (ret < 0) {
    return ret;
  } else {
    return buf;
  }
}

DEFINE_SYSCALL(rename, gstr_t, oldpath, gstr_t, newpath)
{
  char *host_oldpath = to_host_path(guest_to_host(oldpath));
  char *host_newpath = to_host_path(guest_to_host(newpath));

  int ret = syswrap(rename(host_oldpath, host_newpath));
  
  free(host_oldpath);
  free(host_newpath);
  return ret;
}

DEFINE_SYSCALL(pread64, unsigned int, fd, gstr_t, buf, size_t, count, off_t, pos)
{
  return syswrap(pread(fd, guest_to_host(buf), count, pos));
}

DEFINE_SYSCALL(getxattr, gstr_t, path_ptr, gstr_t, name_ptr, gaddr_t, value, size_t, size)
{
  printk("getxattr is unimplemented\n");
  return -LINUX_ENOTSUP;
}

DEFINE_SYSCALL(ioctl, int, fd, int, cmd, uint64_t, val0)
{
  printk("ioctl (fd = %08x, cmd = %d)\n", fd, cmd);
  if (fd == 1 && cmd == LINUX_TCGETS) {
    struct termios dios;
    struct linux_termios lios;

    int ret = syswrap(ioctl(fd, TIOCGETA, &dios));
    if (ret < 0) {
      return ret;
    }
    darwin_to_linux_termios(&dios, &lios);
    *(struct linux_termios*)(guest_to_host(val0)) = lios;

    return ret;
  } else if (fd == 1 && cmd == LINUX_TIOCGWINSZ) {
    return syswrap(ioctl(fd, TIOCGWINSZ, guest_to_host(val0)));
  }

  return -LINUX_EPERM;
}

DEFINE_SYSCALL(fcntl, unsigned int, fd, unsigned int, cmd, unsigned long, arg)
{
  return syswrap(fcntl(fd, cmd, arg));
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
  return syswrap(writev(fd, dst, iovcnt));
}

DEFINE_SYSCALL(symlink, gstr_t, path1, gstr_t, path2)
{
  char *host_path1 = to_host_path(guest_to_host(path1));
  char *host_path2 = to_host_path(guest_to_host(path2));

  int ret = syswrap(symlink(host_path1, host_path2));

  free(host_path1);
  free(host_path2);
  return ret;
}

DEFINE_SYSCALL(readlink, gstr_t, path, gaddr_t, buf, int, bufsize)
{
  char *host_path = to_host_path(guest_to_host(path));
  int ret = syswrap(readlink(host_path, guest_to_host(buf), bufsize));

  free(host_path);
  return ret;
}

DEFINE_SYSCALL(unlink, gstr_t, path)
{
  char *host_path = to_host_path(guest_to_host(path));
  int ret = syswrap(unlink(host_path));

  free(host_path);
  return ret;
}

DEFINE_SYSCALL(unlinkat, int, fd, gstr_t, path, int, flags)
{
  char *host_path = to_host_path(guest_to_host(path));
  int dflags = linux_to_darwin_at_flags(flags);
  /* You must treat E_ACCESS as E_REMOVEDIR in unlinkat */\
  if (flags & LINUX_AT_EACCESS) {
    dflags &= ~AT_EACCESS;
    dflags |= AT_REMOVEDIR;
  }
  int ret = syswrap(unlinkat(fd, host_path, dflags));

  free(host_path);
  return ret;
}

DEFINE_SYSCALL(link, gstr_t, oldpath, gstr_t, newpath)
{
  char *host_oldpath = to_host_path(guest_to_host(oldpath));
  char *host_newpath = to_host_path(guest_to_host(newpath));

  int ret = syswrap(link(host_oldpath, host_newpath));

  free(host_oldpath);
  free(host_newpath);
  return ret;
}

DEFINE_SYSCALL(linkat, int, olddirfd, gstr_t, oldpath, int, newdirfd, gstr_t, newpath, int, flags)
{
  char *host_oldpath = to_host_path(guest_to_host(oldpath));
  char *host_newpath = to_host_path(guest_to_host(newpath));
  int dflags = linux_to_darwin_at_flags(flags);

  int ret = syswrap(linkat(olddirfd, host_oldpath, newdirfd, host_newpath, dflags));

  free(host_oldpath);
  free(host_newpath);
  return ret;
}

DEFINE_SYSCALL(fadvise64, int, fd, off_t, offset, size_t, len, int, advice)
{
  return -1;
}

DEFINE_SYSCALL(select, int, nfds, gaddr_t, readfds, gaddr_t, writefds, gaddr_t, errorfds, gaddr_t, timeout)
{
  // Darwin's fd_set and timeval is compatible with those of Linux
  struct timeval *h_timeout = (struct timeval*)guest_to_host(timeout);

  fd_set *h_readfds = guest_to_host(readfds), *h_writefds = guest_to_host(writefds), *h_errorfds = guest_to_host(errorfds);

  return syswrap(select(nfds, h_readfds, h_writefds, h_errorfds, h_timeout));
}

DEFINE_SYSCALL(pselect6, int, nfds, gaddr_t, readfds, gaddr_t, writefds, gaddr_t, errorfds, gaddr_t, timeout, gaddr_t, sigmask)
{
  // Darwin's fd_set and timeval is compatible with those of Linux
  struct timespec *h_timeout = (struct timespec *) guest_to_host(timeout);

  fd_set *h_readfds = guest_to_host(readfds), *h_writefds = guest_to_host(writefds), *h_errorfds = guest_to_host(errorfds);
  // FIXME: Ignore sigmask now. Support it after implementing signal handling

  return syswrap(pselect(nfds, h_readfds, h_writefds, h_errorfds, h_timeout, NULL));
}

DEFINE_SYSCALL(poll, gaddr_t, fds, int, nfds, int, timeout)
{
  return syswrap(poll(guest_to_host(fds), nfds, timeout));
}

DEFINE_SYSCALL(chdir, gstr_t, path)
{
  char *host_path = to_host_path(guest_to_host(path));
  int ret = syswrap(chdir(host_path));

  free(host_path);
  return ret;
}

DEFINE_SYSCALL(fchdir, int, fd)
{
  return syswrap(fchdir(fd));
}

DEFINE_SYSCALL(chmod, gstr_t, path, int, mode)
{
  char *host_path = to_host_path(guest_to_host(path));
  int ret = syswrap(chmod(host_path, mode));

  free(host_path);
  return ret;
}

DEFINE_SYSCALL(fchmod, int, fd, int, mode)
{
  return syswrap(fchmod(fd, mode));
}

DEFINE_SYSCALL(fchown, int, fildes, int, uid, int, gid)
{
  return syswrap(fchown(fildes, uid, gid));
}

DEFINE_SYSCALL(chown, gstr_t, path, int, uid, int, gid)
{
  char *host_path = to_host_path(guest_to_host(path));
  int ret = syswrap(chown(guest_to_host(path), uid, gid));

  free(host_path);
  return ret;
}

DEFINE_SYSCALL(lchown, gstr_t, path, int, uid, int, gid)
{
  char *host_path = to_host_path(guest_to_host(path));
  int ret = syswrap(lchown(guest_to_host(path), uid, gid));

  free(host_path);
  return ret;
}

DEFINE_SYSCALL(lseek, int, fildes, off_t, offset, int, whence)
{
  return syswrap(lseek(fildes, offset, whence));
}

DEFINE_SYSCALL(mkdir, gstr_t, path, int, mode)
{
  char *host_path = to_host_path(guest_to_host(path));
  int ret = syswrap(mkdir(host_path, mode));
  free(host_path);
  return ret;
}

DEFINE_SYSCALL(rmdir, gstr_t, path)
{
  char *host_path = to_host_path(guest_to_host(path));
  int ret = syswrap(rmdir(host_path));

  free(host_path);
  return ret;
}

DEFINE_SYSCALL(umask, int, mask)
{
  return syswrap(umask(mask));
}

DEFINE_SYSCALL(statfs, gstr_t, path, gaddr_t, buf)
{
  struct statfs h_buf;
  char *host_path = to_host_path(guest_to_host(path));

  int ret = syswrap(statfs(host_path, &h_buf));
  statfs_darwin_to_linux(&h_buf, guest_to_host(buf));

  free(host_path);
  return ret;
}

DEFINE_SYSCALL(chroot, gstr_t, path)
{
  char l_path[PATH_MAX];
  int len = strncpy_from_user(l_path, path, PATH_MAX);
  if (len == PATH_MAX) {
    return -LINUX_ENAMETOOLONG;
  }
  if (len < 0) {
    return -LINUX_EFAULT;
  }

  /* We have not impelemented caps, just check if user is root */
  if (getuid() != 0) {
    return -LINUX_EPERM;
  }

  char *host_path = to_host_path(l_path);

  int error = syswrap(access(host_path, X_OK | R_OK));
  if (error < 0) {
    free(host_path);
    return error;
  }

  free(proc.root);
  proc.root = host_path;
  return 0;
}
