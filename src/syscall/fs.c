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
#include <libgen.h>

#include <mach-o/dyld.h>


DEFINE_SYSCALL(write, int, fd, gaddr_t, buf_ptr, size_t, size)
{
  char buf[size];
  copy_from_user(buf, buf_ptr, size);
  return syswrap(write(fd, buf, size));
}

DEFINE_SYSCALL(read, int, fd, gaddr_t, buf_ptr, size_t, size)
{
  char buf[size];
  int n = read(fd, buf, size);
  if (n < 0) {
    return -errno;
  }
  copy_to_user(buf_ptr, buf, n);
  return n;
}

char*
cat_linux_mnt(const char *path)
{
  uint32_t noah_path_len = 0;
  _NSGetExecutablePath(NULL, &noah_path_len);
  char noah_path[noah_path_len];
  _NSGetExecutablePath(noah_path, &noah_path_len);

  char *dir_path = dirname(noah_path);
  int mnt_len = strlen(dir_path) + strlen("/../mnt/");

  char buf[strnlen(path, LINUX_PATH_MAX) + mnt_len];
  strcpy(buf, dir_path);
  strcat(buf, "/../mnt/");
  strcat(buf, path);

  return strdup(buf);
}

char*
to_host_path(const char *path)
{
  if (path[0] == '/') {
    char *mnt_path = cat_linux_mnt(path);
    //if (access(mnt_path, F_OK) == 0) {
      return mnt_path;
    //}
    //free(mnt_path);
  }
  return strdup(path);
}

int
do_open(const char *path, int l_flags, int mode)
{
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

  char *host_path = to_host_path(path);
  int ret = syswrap(open(host_path, flags, mode));

  free(host_path);
  return ret;
}

DEFINE_SYSCALL(open, gstr_t, path, int, flags, int, mode)
{
  return do_open(guest_to_host(path), flags, mode);
}

DEFINE_SYSCALL(close, int, fd)
{
  return syswrap(close(fd));
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

int
linux_to_darwin_at_flags(int flags)
{
  int ret = 0;
  if (flags & LINUX_AT_FDCWD) {
    ret |= AT_FDCWD;
    flags &= ~LINUX_AT_FDCWD;
  }
  if (flags & LINUX_AT_SYMLINK_NOFOLLOW) {
    ret |= AT_SYMLINK_NOFOLLOW;
    flags &= ~LINUX_AT_SYMLINK_NOFOLLOW;
  }
  /* You must treat E_ACCESS as E_REMOVEDIR in unlinkat */\
  if (flags & LINUX_AT_EACCESS) {
    ret |= AT_EACCESS;
    flags &= ~LINUX_AT_EACCESS;
  }
  if (flags & LINUX_AT_SYMLINK_FOLLOW) {
    ret |= AT_SYMLINK_FOLLOW;
    flags &= ~LINUX_AT_SYMLINK_FOLLOW;
  }

  if (flags) {
    printk("unsupported at flags:0x%x\n", flags);
    fprintf(stderr, "unsupported at flags:0x%x\n", flags);
  }

  return ret;
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

DEFINE_SYSCALL(access, gstr_t, path, int, mode)
{
  char *host_path = to_host_path(guest_to_host(path));

  int ret = syswrap(access(host_path, mode));

  free(host_path);
  return ret;
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

DEFINE_SYSCALL(dup, unsigned int, fd)
{
  return syswrap(dup(fd));
}

DEFINE_SYSCALL(dup2, unsigned int, fd1, unsigned int, fd2)
{
  return syswrap(dup2(fd1, fd2));
}

DEFINE_SYSCALL(getcwd, gaddr_t, buf, unsigned long, size)
{
  getcwd(guest_to_host(buf), size);
  return 0;
}

DEFINE_SYSCALL(rename, gstr_t, oldpath, gstr_t, newpath)
{
  char *host_oldpath, *host_newpath;

  host_oldpath = to_host_path(guest_to_host(oldpath));
  if  (strcmp(host_oldpath, guest_to_host(oldpath)) != 0) {
    host_newpath = cat_linux_mnt(guest_to_host(newpath));
  } else {
    host_newpath = strdup(guest_to_host(newpath));
  }

  int ret = syswrap(rename(host_oldpath, host_newpath));
  
  free(host_oldpath);
  free(host_newpath);
  return ret;
}

DEFINE_SYSCALL(getxattr, gstr_t, path_ptr, gstr_t, name_ptr, gaddr_t, value, size_t, size)
{
  printk("getxattr is unimplemented\n");
  return -LINUX_ENOTSUP;
}

DEFINE_SYSCALL(ioctl, int, fd, int, cmd)
{
  printk("ioctl (fd = %08x, cmd = %d)\n", fd, cmd);
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
  char *host_path1, *host_path2;
  
  host_path1 = to_host_path(guest_to_host(path1));
  if  (strcmp(host_path1, guest_to_host(path2)) != 0) {
    host_path2 = cat_linux_mnt(guest_to_host(path2));
  } else {
    host_path2 = strdup(guest_to_host(path2));
  }

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

DEFINE_SYSCALL(fadvise64, int, fd, off_t, offset, size_t, len, int, advice)
{
  return -1;
}

DEFINE_SYSCALL(select, int, nfds, gaddr_t, readfds, gaddr_t, writefds, gaddr_t, errorfds, gaddr_t, timeout)
{
  struct timeval *h_timeout = (struct timeval*)guest_to_host(timeout);

  // Darwin's fd_set is compatible with that of Linux
  fd_set *h_readfds = guest_to_host(readfds), *h_writefds = guest_to_host(writefds), *h_errorfds = guest_to_host(errorfds);

  return syswrap(select(nfds, h_readfds, h_writefds, h_errorfds, h_timeout));
}

DEFINE_SYSCALL(poll, gaddr_t, fds, int, nfds, int, timeout)
{
  return syswrap(poll(guest_to_host(fds), nfds, timeout));
}

DEFINE_SYSCALL(chdir, gstr_t, path)
{
  return syswrap(chdir(guest_to_host(path)));
}

DEFINE_SYSCALL(fchdir, int, fd)
{
  return syswrap(fchdir(fd));
}

DEFINE_SYSCALL(chmod, gstr_t, path, int, mode)
{
  char *host_path = to_host_path(guest_to_host(path));
  int ret = syswrap(chmod(guest_to_host(path), mode));

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

void
statfs_darwin_to_linux(struct statfs *statfs, struct l_statfs *l_statfs)
{
#define HFS_SUPER_MAGIC 0x4244
  if (!statfs && !l_statfs) {
    return;
  }

  l_statfs->f_type = HFS_SUPER_MAGIC;
  l_statfs->f_bsize = statfs->f_bsize;
  l_statfs->f_type = statfs->f_type;
  l_statfs->f_bsize = statfs->f_bsize;
  l_statfs->f_blocks = statfs->f_blocks;
  l_statfs->f_bfree = statfs->f_bfree;
  l_statfs->f_bavail = statfs->f_bavail;
  l_statfs->f_files = statfs->f_files;
  l_statfs->f_ffree = statfs->f_ffree;
  l_statfs->f_fsid.val[0] = statfs->f_fsid.val[0];
  l_statfs->f_fsid.val[1] = statfs->f_fsid.val[1];
  l_statfs->f_namelen = NAME_MAX;
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
  fprintf(stderr, "chroot is not implemented yet, ignoring...\n");
  printk("chroot is not implemented yet, ignoring...\n");

  return -LINUX_ENOSYS;
}
