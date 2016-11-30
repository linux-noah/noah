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
#include "linux/socket.h"

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
  int (*readv)(struct file *f, struct iovec *iov, size_t iovcnt);
  int (*writev)(struct file *f, const struct iovec *iov, size_t iovcnt);
  int (*close)(struct file *f);
  int (*stat)(struct file *f, struct l_newstat *stat);
  int (*fchown)(struct file *f, l_uid_t uid, l_gid_t gid);
  int (*fchmod)(struct file *f, l_mode_t mode);
  int (*ioctl)(struct file *f, int cmd, uint64_t val0);
  int (*lseek)(struct file *f, l_off_t offset, int whence);
  int (*getdents)(struct file *f, char *buf, uint count);
  int (*fcntl)(struct file *f, unsigned int cmd, unsigned long arg);
  int (*fstatfs)(struct file *f, struct l_statfs *buf);
  int (*fsync)(struct file *f);
};

int
darwinfs_writev(struct file *file, const struct iovec *iov, size_t iovcnt)
{
  return syswrap(writev(file->fd, iov, iovcnt));
}

int
darwinfs_readv(struct file *file, struct iovec *iov, size_t iovcnt)
{
  return syswrap(readv(file->fd, iov, iovcnt));
}

int
darwinfs_close(struct file *file)
{
  return syswrap(close(file->fd));
}

int
darwinfs_stat(struct file *file, struct l_newstat *l_st)
{
  struct stat st;
  int ret = syswrap(fstat(file->fd, &st));
  if (ret < 0) {
    return ret;
  }
  stat_darwin_to_linux(&st, l_st);
  return ret;
}

int
darwinfs_fchown(struct file *file, l_uid_t uid, l_gid_t gid)
{
  return syswrap(fchown(file->fd, uid, gid));
}

int
darwinfs_fchmod(struct file *file, l_mode_t mode)
{
  return syswrap(fchmod(file->fd, mode));
}

int
darwinfs_ioctl(struct file *file, int cmd, uint64_t val0)
{
  int fd = file->fd;
  int r;

  switch (cmd) {
  case LINUX_TCGETS: {
    struct termios dios;
    struct linux_termios lios;

    if ((r = syswrap(tcgetattr(fd, &dios))) < 0) {
      return r;
    }
    darwin_to_linux_termios(&dios, &lios);
    if (copy_to_user(val0, &lios, sizeof lios)) {
      return -LINUX_EFAULT;
    }
    return r;
  }
  case LINUX_TCSETS: {
    struct termios dios;
    struct linux_termios lios;
    if (copy_from_user(&lios, val0, sizeof lios)) {
      return -LINUX_EFAULT;
    }
    linux_to_darwin_termios(&lios, &dios);
    return syswrap(tcsetattr(fd, TCSANOW, &dios));
  }
  case LINUX_TCSETSW: {
    struct termios dios;
    struct linux_termios lios;
    if (copy_from_user(&lios, val0, sizeof lios)) {
      return -LINUX_EFAULT;
    }
    linux_to_darwin_termios(&lios, &dios);
    return syswrap(tcsetattr(fd, TCSADRAIN, &dios));
  }
  case LINUX_TIOCGPGRP: {
    l_pid_t pgrp;
    if ((r = syswrap(ioctl(fd, TIOCGPGRP, &pgrp))) < 0) {
      return r;
    }
    if (copy_to_user(val0, &pgrp, sizeof pgrp)) {
      return -LINUX_EFAULT;
    }
    return r;
  }
  /* case LINUX_TIOCSPGRP: { */
  /*   l_pid_t pgrp; */
  /*   if (copy_from_user(&pgrp, val0, sizeof pgrp)) { */
  /*     return -LINUX_EFAULT; */
  /*   } */
  /*   if ((r = syswrap(ioctl(fd, TIOCSPGRP, &pgrp))) < 0) { */
  /*     return r; */
  /*   } */
  /*   return 0; */
  /* } */
  case LINUX_TIOCGWINSZ: {
    struct winsize ws;
    if ((r = syswrap(ioctl(fd, TIOCGWINSZ, &ws))) < 0) {
      return r;
    }
    struct linux_winsize lws;
    darwin_to_linux_winsize(&ws, &lws);
    if (copy_to_user(val0, &lws, sizeof lws)) {
      return -LINUX_EFAULT;
    }
    return r;
  }
  case LINUX_TIOCSWINSZ: {
    struct linux_winsize lws;
    struct winsize ws;
    if (copy_from_user(&lws, val0, sizeof lws)) {
      return -LINUX_EFAULT;
    }
    linux_to_darwin_winsize(&ws, &lws);
    return syswrap(ioctl(fd, TIOCSWINSZ, &ws));
  }
  case LINUX_TCFLSH: {
    int sel;
    switch (val0) {
    case LINUX_TCIFLUSH: sel = TCIFLUSH; break;
    case LINUX_TCOFLUSH: sel = TCOFLUSH; break;
    case LINUX_TCIOFLUSH: sel = TCIOFLUSH; break;
    default:
      return -LINUX_EINVAL;
    }
    return syswrap(tcflush(fd, sel));
  }
  default:
    printk("unhandled darwinfs ioctl (fd = %08x, cmd = 0x%08x)\n", fd, cmd);
    return -LINUX_EPERM;
  }
}

int
darwinfs_lseek(struct file *file, l_off_t offset, int whence)
{
  return syswrap(lseek(file->fd, offset, whence));
}

int
darwinfs_getdents(struct file *file, char *direntp, unsigned count)
{
  int fd = dup(file->fd);
  DIR *dir = fdopendir(fd);

  if (dir == NULL) {
    return -darwin_to_linux_errno(errno);
  }
  struct dirent *dent;
  size_t pos = 0;
  long loc = telldir(dir);
  errno = 0;
  while ((dent = readdir(dir)) != NULL) {
    size_t reclen = roundup(offsetof(struct l_dirent, d_name) + dent->d_namlen + 2, 8);
    if (pos + reclen > count) {
      seekdir(dir, loc);
      goto end;
    }
    /* fill dirent buffer */
    struct l_dirent *dp = (struct l_dirent *) (direntp + pos);
    dp->d_reclen = reclen;
    dp->d_ino = dent->d_ino;
    dp->d_off = dent->d_seekoff;
    memcpy(dp->d_name, dent->d_name, dent->d_namlen + 1);
    ((char *) dp)[reclen - 1] = dent->d_type;

    pos += reclen;
    loc = telldir(dir);
  }
  if (errno) {
    return -darwin_to_linux_errno(errno);
  }
 end:
  closedir(dir);
  return pos;
}

int
darwinfs_fcntl(struct file *file, unsigned int cmd, unsigned long arg)
{
  return syswrap(fcntl(file->fd, cmd, arg));
}

int
darwinfs_fstatfs(struct file *file, struct l_statfs *buf)
{
  struct statfs st;
  int r = syswrap(fstatfs(file->fd, &st));
  if (r < 0)
    return r;
  statfs_darwin_to_linux(&st, buf);
  return r;
}

int
darwinfs_fsync(struct file *file)
{
  return syswrap(fsync(file->fd));
}

struct file *
vfs_acquire(int fd)
{
  static struct file_operations ops = {
    darwinfs_readv,
    darwinfs_writev,
    darwinfs_close,
    darwinfs_stat,
    darwinfs_fchown,
    darwinfs_fchmod,
    darwinfs_ioctl,
    darwinfs_lseek,
    darwinfs_getdents,
    darwinfs_fcntl,
    darwinfs_fstatfs,
    darwinfs_fsync,
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
  if (copy_from_user(buf, buf_ptr, size)) {
    return -LINUX_EFAULT;
  }
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int r;
  if (file->ops->writev == NULL) {
    r = -LINUX_EBADF;
    goto out;
  }
  struct iovec iov = { buf, size };
  r = file->ops->writev(file, &iov, 1);
 out:
  vfs_release(file);
  return r;
}

DEFINE_SYSCALL(read, int, fd, gaddr_t, buf_ptr, size_t, size)
{
  char buf[size];
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int r;
  if (file->ops->readv == NULL) {
    r = -LINUX_EBADF;
    goto out;
  }
  struct iovec iov = { buf, size };
  r = file->ops->readv(file, &iov, 1);
  if (r < 0) {
    goto out;
  }
  if (copy_to_user(buf_ptr, buf, r)) {
    r = -LINUX_EFAULT;
    goto out;
  }
 out:
  vfs_release(file);
  return r;
}

DEFINE_SYSCALL(writev, int, fd, gaddr_t, iov_ptr, int, iovcnt)
{
  struct l_iovec *liov = alloca(sizeof(struct l_iovec) * iovcnt);

  if (copy_from_user(liov, iov_ptr, sizeof(struct l_iovec) * iovcnt))
    return -LINUX_EFAULT;

  struct iovec *iov = alloca(sizeof(struct iovec) * iovcnt);
  for (int i = 0; i < iovcnt; ++i) {
    iov[i].iov_len = liov[i].iov_len;
    iov[i].iov_base = alloca(liov[i].iov_len);
    if (copy_from_user(iov[i].iov_base, liov[i].iov_base, iov[i].iov_len))
      return -LINUX_EFAULT;
  }

  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int r;
  if (file->ops->writev == NULL) {
    r = -LINUX_EBADF;
    goto out;
  }
  r = file->ops->writev(file, iov, iovcnt);
 out:
  vfs_release(file);
  return r;
}

DEFINE_SYSCALL(readv, int, fd, gaddr_t, iov_ptr, int, iovcnt)
{
  struct l_iovec *liov = alloca(sizeof(struct l_iovec) * iovcnt);

  if (copy_from_user(liov, iov_ptr, sizeof(struct l_iovec) * iovcnt))
    return -LINUX_EFAULT;

  struct iovec *iov = alloca(sizeof(struct iovec) * iovcnt);
  for (int i = 0; i < iovcnt; ++i) {
    iov[i].iov_base = alloca(liov[i].iov_len);
    iov[i].iov_len = liov[i].iov_len;
  }

  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int r;
  if (file->ops->readv == NULL) {
    r = -LINUX_EBADF;
    goto out;
  }
  r = file->ops->readv(file, iov, iovcnt);
  if (r < 0) {
    goto out;
  }
  size_t size = r;
  for (int i = 0; i < iovcnt; ++i) {
    size_t s = MIN(size, iov[i].iov_len);
    if (copy_to_user(liov[i].iov_base, iov[i].iov_base, s)) {
      r = -LINUX_EFAULT;
      goto out;
    }
    size -= s;
    if (size == 0)
      break;
  }
 out:
  vfs_release(file);
  return r;
}

int
do_close(int fd)
{
  /* FIXME: free fd slot */
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int n = file->ops->close(file);
  vfs_release(file);
  return n;
}

DEFINE_SYSCALL(close, int, fd)
{
  return do_close(fd);
}

DEFINE_SYSCALL(fstat, int, fd, gaddr_t, st_ptr)
{
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  struct l_newstat st;
  int n = file->ops->stat(file, &st);
  if (n < 0)
    goto out;
  if (copy_to_user(st_ptr, &st, sizeof st)) {
    n = -LINUX_EFAULT;
    goto out;
  }
 out:
  vfs_release(file);
  return n;
}

DEFINE_SYSCALL(fchown, int, fd, l_uid_t, uid, l_gid_t, gid)
{
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int n = file->ops->fchown(file, uid, gid);
  vfs_release(file);
  return n;
}

DEFINE_SYSCALL(fchmod, int, fd, l_mode_t, mode)
{
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int n = file->ops->fchmod(file, mode);
  vfs_release(file);
  return n;
}

DEFINE_SYSCALL(ioctl, int, fd, int, cmd, uint64_t, val0)
{
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int r;
  if (file->ops->ioctl == NULL) {
    r = -LINUX_ENOTTY;
    goto out;
  }
  r = file->ops->ioctl(file, cmd, val0);
 out:
  vfs_release(file);
  return r;
}

DEFINE_SYSCALL(lseek, int, fd, off_t, offset, int, whence)
{
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int r = file->ops->lseek(file, offset, whence);
  vfs_release(file);
  return r;
}

DEFINE_SYSCALL(getdents, unsigned int, fd, gaddr_t, dirent_ptr, unsigned int, count)
{
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  char buf[count];
  int r = file->ops->getdents(file, buf, count);
  if (r < 0) {
    goto out;
  }
  if (copy_to_user(dirent_ptr, buf, count)) {
    r = -LINUX_EFAULT;
    goto out;
  }
 out:
  vfs_release(file);
  return r;
}

DEFINE_SYSCALL(fcntl, unsigned int, fd, unsigned int, cmd, unsigned long, arg)
{
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int r = file->ops->fcntl(file, cmd, arg);
  vfs_release(file);
  return r;
}

DEFINE_SYSCALL(fstatfs, int, fd, gaddr_t, buf_ptr)
{
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  struct l_statfs st;
  int n = file->ops->fstatfs(file, &st);
  if (n < 0)
    goto out;
  if (copy_to_user(buf_ptr, &st, sizeof st)) {
    n = -LINUX_EFAULT;
    goto out;
  }
 out:
  vfs_release(file);
  return n;
}

DEFINE_SYSCALL(fsync, int, fd)
{
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int r = file->ops->fsync(file);
  vfs_release(file);
  return r;
}

struct dir {
  int fd;
};

struct path {
  struct fs *fs;
  struct dir *dir;
  char subpath[LINUX_PATH_MAX];
};

struct fs {
  struct fs_operations *ops;
};

struct fs_operations {
  int (*openat)(struct fs *fs, struct dir *dir, const char *path, int flags, int mode); /* TODO: return struct file * instaed of file descripter */
  int (*symlinkat)(struct fs *fs, const char *target, struct dir *dir, const char *name);
  int (*faccessat)(struct fs *fs, struct dir *dir, const char *path, int mode);
  int (*renameat)(struct fs *fs, struct dir *dir1, const char *from, struct dir *dir2, const char *to);
  int (*linkat)(struct fs *fs, struct dir *dir1, const char *from, struct dir *dir2, const char *to, int flags);
  int (*unlinkat)(struct fs *fs, struct dir *dir, const char *path, int flags);
  int (*readlinkat)(struct fs *fs, struct dir *dir, const char *path, char *buf, int bufsize);
  int (*mkdir)(struct fs *fs, struct dir *dir, const char *path, int mode);
};

int
darwinfs_openat(struct fs *fs, struct dir *dir, const char *path, int l_flags, int mode)
{
  int flags = linux_to_darwin_o_flags(l_flags);
  return syswrap(openat(dir->fd, path, flags, mode));
}

int
darwinfs_symlinkat(struct fs *fs, const char *target, struct dir *dir, const char *name)
{
  return syswrap(symlinkat(target, dir->fd, name));
}

int
darwinfs_faccessat(struct fs *fs, struct dir *dir, const char *path, int mode)
{
  return syswrap(faccessat(dir->fd, path, mode, 0));
}

int
darwinfs_renameat(struct fs *fs, struct dir *dir1, const char *from, struct dir *dir2, const char *to)
{
  return syswrap(renameat(dir1->fd, from, dir2->fd, to));
}

int
darwinfs_linkat(struct fs *fs, struct dir *dir1, const char *from, struct dir *dir2, const char *to, int l_flags)
{
  int flags = linux_to_darwin_at_flags(l_flags);
  return syswrap(linkat(dir1->fd, from, dir2->fd, to, flags));
}

int
darwinfs_unlinkat(struct fs *fs, struct dir *dir, const char *path, int l_flags)
{
  int flags = linux_to_darwin_at_flags(l_flags);
  /* You must treat E_ACCESS as E_REMOVEDIR in unlinkat */\
  if (flags & AT_EACCESS) {
    flags &= ~AT_EACCESS;
    flags |= AT_REMOVEDIR;
  }
  return syswrap(unlinkat(dir->fd, path, flags));
}

int
darwinfs_readlinkat(struct fs *fs, struct dir *dir, const char *path, char *buf, int bufsize)
{
  return syswrap(readlinkat(dir->fd, path, buf, bufsize));
}

int
darwinfs_mkdir(struct fs *fs, struct dir *dir, const char *path, int mode)
{
  return syswrap(mkdirat(dir->fd, path, mode));
}

#define LOOKUP_NOFOLLOW   0x0001
#define LOOKUP_DIRECTORY  0x0002
/* #define LOOKUP_CONTINUE   0x0004 */
/* #define LOOKUP_AUTOMOUNT  0x0008 */
/* #define LOOKUP_PARENT     0x0010 */
/* #define LOOKUP_REVAL      0x0020 */

int
vfs_grab_dir(int dirfd, const char *name, int flags, struct path *path)
{
  static struct fs_operations ops = {
    darwinfs_openat,
    darwinfs_symlinkat,
    darwinfs_faccessat,
    darwinfs_renameat,
    darwinfs_linkat,
    darwinfs_unlinkat,
    darwinfs_readlinkat,
    darwinfs_mkdir,
  };

  static struct fs darwinfs = {
    .ops = &ops,
  };

  if (flags & ~(LOOKUP_NOFOLLOW | LOOKUP_DIRECTORY)) {
    return -LINUX_EINVAL;
  }

  path->dir = malloc(sizeof(struct dir));
  if (dirfd == LINUX_AT_FDCWD) {
    path->dir->fd = AT_FDCWD;
  } else {
    path->dir->fd = dirfd;
  }
  path->fs = &darwinfs;
  if (strncmp(name, "/Users", sizeof "/Users" - 1) == 0 || strncmp(name, "/Volumes", sizeof "/Volumes" - 1) == 0 || strncmp(name, "/dev", sizeof "/dev" - 1) == 0) {
    strcpy(path->subpath, name);
  } else if (name[0] == '/') {
    sprintf(path->subpath, "%s%s", proc.root, name);
  } else {
    strcpy(path->subpath, name);
  }
  return 0;
}

void
vfs_ungrab_dir(struct path *path)
{
  free(path->dir);
}

int
do_openat(int dirfd, const char *name, int flags, int mode)
{
  int lkflag = 0;
  if (flags & LINUX_O_NOFOLLOW) {
    lkflag |= LOOKUP_NOFOLLOW;
  }
  if (flags & LINUX_O_DIRECTORY) {
    lkflag |= LOOKUP_DIRECTORY;
  }

  struct path path;
  int r = vfs_grab_dir(dirfd, name, lkflag, &path);
  if (r < 0) {
    return r;
  }
  r = path.fs->ops->openat(path.fs, path.dir, path.subpath, flags, mode);
  vfs_ungrab_dir(&path);
  return r;
}

int
do_open(const char *path, int l_flags, int mode)
{
  return do_openat(LINUX_AT_FDCWD, path, l_flags, mode);
}

DEFINE_SYSCALL(openat, int, dirfd, gstr_t, path_ptr, int, flags, int, mode)
{
  char path[LINUX_PATH_MAX];
  strncpy_from_user(path, path_ptr, sizeof path);
  return do_openat(dirfd, path, flags, mode);
}

DEFINE_SYSCALL(open, gstr_t, path_ptr, int, flags, int, mode)
{
  return sys_openat(LINUX_AT_FDCWD, path_ptr, flags, mode);
}

DEFINE_SYSCALL(creat, gstr_t, path_ptr, int, mode)
{
  return sys_open(path_ptr, LINUX_O_CREAT | LINUX_O_TRUNC | LINUX_O_WRONLY, mode);
}

DEFINE_SYSCALL(symlinkat, gstr_t, path1_ptr, int, dirfd, gstr_t, path2_ptr)
{
  char path1[LINUX_PATH_MAX], path2[LINUX_PATH_MAX];

  strncpy_from_user(path1, path1_ptr, sizeof path1);
  strncpy_from_user(path2, path2_ptr, sizeof path2);

  struct path path;
  int r = vfs_grab_dir(dirfd, path2, 0, &path);
  if (r < 0) {
    return r;
  }
  r = path.fs->ops->symlinkat(path.fs, path1, path.dir, path.subpath);
  vfs_ungrab_dir(&path);
  return r;
}

DEFINE_SYSCALL(symlink, gstr_t, path1_ptr, gstr_t, path2_ptr)
{
  return sys_symlinkat(path1_ptr, LINUX_AT_FDCWD, path2_ptr);
}

DEFINE_SYSCALL(newfstatat, int, dirfd, gstr_t, path_ptr, gaddr_t, st_ptr, int, flags)
{
  char path[LINUX_PATH_MAX];
  strncpy_from_user(path, path_ptr, sizeof path);
  if (flags & ~(LINUX_AT_SYMLINK_NOFOLLOW)) {
    return -LINUX_EINVAL;
  }
  int oflags = flags & LINUX_AT_SYMLINK_NOFOLLOW ? LINUX_O_PATH | LINUX_O_NOFOLLOW : 0;
  int fd = do_openat(dirfd, path, oflags, 0);
  if (fd < 0)
    return fd;
  int r = sys_fstat(fd, st_ptr);
  do_close(fd);
  return r;
}

DEFINE_SYSCALL(stat, gstr_t, path, gaddr_t, st)
{
  return sys_newfstatat(LINUX_AT_FDCWD, path, st, 0);
}

DEFINE_SYSCALL(lstat, gstr_t, path, gaddr_t, st)
{
  return sys_newfstatat(LINUX_AT_FDCWD, path, st, LINUX_AT_SYMLINK_NOFOLLOW);
}

DEFINE_SYSCALL(fchownat, int, dirfd, gstr_t, path_ptr, l_uid_t, user, l_gid_t, group, int, flags)
{
  char path[LINUX_PATH_MAX];
  strncpy_from_user(path, path_ptr, sizeof path);
  if (flags & ~(LINUX_AT_SYMLINK_NOFOLLOW)) {
    return -LINUX_EINVAL;
  }
  int oflags = flags & LINUX_AT_SYMLINK_NOFOLLOW ? LINUX_O_PATH | LINUX_O_NOFOLLOW : 0;
  int fd = do_openat(dirfd, path, oflags, 0);
  if (fd < 0)
    return fd;
  int r = sys_fchown(fd, user, group);
  do_close(fd);
  return r;
}

DEFINE_SYSCALL(chown, gstr_t, path, int, uid, int, gid)
{
  return sys_fchownat(LINUX_AT_FDCWD, path, uid, gid, 0);
}

DEFINE_SYSCALL(lchown, gstr_t, path, int, uid, int, gid)
{
  return sys_fchownat(LINUX_AT_FDCWD, path, uid, gid, LINUX_AT_SYMLINK_NOFOLLOW);
}

DEFINE_SYSCALL(fchmodat, int, dirfd, gstr_t, path_ptr, l_mode_t, mode)
{
  char path[LINUX_PATH_MAX];
  strncpy_from_user(path, path_ptr, sizeof path);
  int fd = do_openat(dirfd, path, 0, 0);
  if (fd < 0)
    return fd;
  int r = sys_fchmod(fd, mode);
  do_close(fd);
  return r;
}

DEFINE_SYSCALL(chmod, gstr_t, path, int, mode)
{
  return sys_fchmodat(LINUX_AT_FDCWD, path, mode);
}

DEFINE_SYSCALL(statfs, gstr_t, path_ptr, gaddr_t, buf_ptr)
{
  char path[LINUX_PATH_MAX];
  strncpy_from_user(path, path_ptr, sizeof path);
  int fd = do_openat(LINUX_AT_FDCWD, path, 0, 0);
  if (fd < 0)
    return fd;
  int r = sys_fstatfs(fd, buf_ptr);
  do_close(fd);
  return r;
}

int
do_faccessat(int dirfd, const char *name, int mode)
{
  struct path path;
  int r = vfs_grab_dir(dirfd, name, 0, &path);
  if (r < 0) {
    return r;
  }
  r = path.fs->ops->faccessat(path.fs, path.dir, path.subpath, mode);
  vfs_ungrab_dir(&path);
  return r;
}

int do_access(const char *path, int mode)
{
  return do_faccessat(LINUX_AT_FDCWD, path, mode);
}

DEFINE_SYSCALL(faccessat, int, dirfd, gstr_t, path_ptr, int, mode)
{
  char path[LINUX_PATH_MAX];
  strncpy_from_user(path, path_ptr, sizeof path);
  return do_faccessat(dirfd, path, mode);
}

DEFINE_SYSCALL(access, gstr_t, path_ptr, int, mode)
{
  return sys_faccessat(LINUX_AT_FDCWD, path_ptr, mode);
}

DEFINE_SYSCALL(renameat, int, oldfd, gstr_t, oldpath_ptr, int, newfd, gstr_t, newpath_ptr)
{
  char oldname[LINUX_PATH_MAX], newname[LINUX_PATH_MAX];

  strncpy_from_user(oldname, oldpath_ptr, sizeof oldname);
  strncpy_from_user(newname, newpath_ptr, sizeof newname);

  struct path oldpath, newpath;
  int r;
  if ((r = vfs_grab_dir(oldfd, oldname, 0, &oldpath)) < 0) {
    goto out1;
  }
  if ((r = vfs_grab_dir(newfd, newname, 0, &newpath)) < 0) {
    goto out2;
  }
  if (oldpath.fs != newpath.fs) {
    r = -LINUX_EXDEV;
    goto out2;
  }
  r = newpath.fs->ops->renameat(newpath.fs, oldpath.dir, oldpath.subpath, newpath.dir, newpath.subpath);
  vfs_ungrab_dir(&newpath);
 out2:
  vfs_ungrab_dir(&oldpath);
 out1:
  return r;
}

DEFINE_SYSCALL(rename, gstr_t, oldpath_ptr, gstr_t, newpath_ptr)
{
  return sys_renameat(LINUX_AT_FDCWD, oldpath_ptr, LINUX_AT_FDCWD, newpath_ptr);
}

DEFINE_SYSCALL(unlinkat, int, dirfd, gstr_t, path_ptr, int, flags)
{
  char name[LINUX_PATH_MAX];
  strncpy_from_user(name, path_ptr, sizeof name);

  struct path path;
  int r;
  if ((r = vfs_grab_dir(dirfd, name, 0, &path)) < 0) {
    return r;
  }
  r = path.fs->ops->unlinkat(path.fs, path.dir, path.subpath, flags);
  vfs_ungrab_dir(&path);
  return r;
}

DEFINE_SYSCALL(unlink, gstr_t, path)
{
  return sys_unlinkat(LINUX_AT_FDCWD, path, 0);
}

DEFINE_SYSCALL(rmdir, gstr_t, path)
{
  return sys_unlinkat(LINUX_AT_FDCWD, path, LINUX_AT_REMOVEDIR);
}

DEFINE_SYSCALL(linkat, int, oldfd, gstr_t, oldpath_ptr, int, newfd, gstr_t, newpath_ptr, int, flags)
{
  char oldname[LINUX_PATH_MAX], newname[LINUX_PATH_MAX];

  strncpy_from_user(oldname, oldpath_ptr, sizeof oldname);
  strncpy_from_user(newname, newpath_ptr, sizeof newname);

  if (flags & ~LINUX_AT_SYMLINK_FOLLOW) {
    return -LINUX_EINVAL;
  }

  int lkflag = flags & LINUX_AT_SYMLINK_FOLLOW ? 0 : LOOKUP_NOFOLLOW;

  struct path oldpath, newpath;
  int r;
  if ((r = vfs_grab_dir(oldfd, oldname, lkflag, &oldpath)) < 0) {
    goto out1;
  }
  if ((r = vfs_grab_dir(newfd, newname, 0, &newpath)) < 0) {
    goto out2;
  }
  if (oldpath.fs != newpath.fs) {
    r = -LINUX_EXDEV;
    goto out2;
  }
  r = newpath.fs->ops->linkat(newpath.fs, oldpath.dir, oldpath.subpath, newpath.dir, newpath.subpath, flags);
  vfs_ungrab_dir(&newpath);
 out2:
  vfs_ungrab_dir(&oldpath);
 out1:
  return r;
}

DEFINE_SYSCALL(link, gstr_t, oldpath, gstr_t, newpath)
{
  return sys_linkat(LINUX_AT_FDCWD, oldpath, LINUX_AT_FDCWD, newpath, 0);
}

DEFINE_SYSCALL(readlinkat, int, dirfd, gstr_t, path_ptr, gaddr_t, buf_ptr, int, bufsize)
{
  char name[LINUX_PATH_MAX];
  strncpy_from_user(name, path_ptr, sizeof name);

  struct path path;
  int r;
  if ((r = vfs_grab_dir(dirfd, name, 0, &path)) < 0) {
    return r;
  }
  char buf[bufsize];
  r = path.fs->ops->readlinkat(path.fs, path.dir, path.subpath, buf, bufsize);
  if (r < 0) {
    goto out;
  }
  if (copy_to_user(buf_ptr, buf, bufsize)) {
    r = -LINUX_EFAULT;
    goto out;
  }
 out:
  vfs_ungrab_dir(&path);
  return r;
}

DEFINE_SYSCALL(readlink, gstr_t, path_ptr, gaddr_t, buf_ptr, int, bufsize)
{
  return sys_readlinkat(LINUX_AT_FDCWD, path_ptr, buf_ptr, bufsize);
}

DEFINE_SYSCALL(mkdirat, int, dirfd, gstr_t, path_ptr, int, mode)
{
  char name[LINUX_PATH_MAX];
  strncpy_from_user(name, path_ptr, sizeof name);

  struct path path;
  int r;
  if ((r = vfs_grab_dir(dirfd, name, 0, &path)) < 0) {
    return r;
  }
  r = path.fs->ops->mkdir(path.fs, path.dir, path.subpath, mode);
  vfs_ungrab_dir(&path);
  return r;
}

DEFINE_SYSCALL(mkdir, gstr_t, path_ptr, int, mode)
{
  return sys_mkdirat(LINUX_AT_FDCWD, path_ptr, mode);
}

int
vfs_getcwd(char *buf, size_t size)
{
  char *ptr = getcwd(buf, size); /* FIXME: path translation */
  if (! ptr) {
    return -darwin_to_linux_errno(errno);
  }
  return 0;
}

int
vfs_fchdir(int fd)
{
  return syswrap(fchdir(fd));
}

int
vfs_umask(int mask)
{
  return syswrap(umask(mask));
}

DEFINE_SYSCALL(getcwd, gaddr_t, buf_ptr, unsigned long, size)
{
  char buf[size];
  memset(buf, 0, sizeof buf);
  int r;
  if ((r = vfs_getcwd(buf, size)) < 0) {
    return r;
  }
  if (copy_to_user(buf_ptr, buf, size)) {
    return -LINUX_EFAULT;
  }
  return buf_ptr;
}

DEFINE_SYSCALL(fchdir, int, fd)
{
  return vfs_fchdir(fd);
}

DEFINE_SYSCALL(chdir, gstr_t, path_ptr)
{
  char path[LINUX_PATH_MAX];
  strncpy_from_user(path, path_ptr, sizeof path);
  int fd = do_openat(LINUX_AT_FDCWD, path, LINUX_O_DIRECTORY, 0);
  if (fd < 0)
    return fd;
  int r = sys_fchdir(fd);
  do_close(fd);
  return r;
}

DEFINE_SYSCALL(umask, int, mask)
{
  return vfs_umask(mask);
}


/* TODO: functions below are not yet ported to the new vfs archtecture. */


DEFINE_SYSCALL(pipe, gaddr_t, fildes_ptr)
{
  int fd[2];
  int r = syswrap(pipe(fd));
  if (r < 0) {
    return r;
  }
  if (copy_to_user(fildes_ptr, fd, sizeof fd)) {
    return -LINUX_EFAULT;
  }
  return 0;
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

  if (copy_to_user(fildes_ptr, fildes, sizeof(fildes))) {
    return -LINUX_EFAULT;
  }

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

DEFINE_SYSCALL(pread64, unsigned int, fd, gstr_t, buf_ptr, size_t, count, off_t, pos)
{
  char buf[count];
  int r = syswrap(pread(fd, buf, count, pos));
  if (r < 0) {
    return r;
  }
  if (copy_to_user(buf_ptr, buf, r)) {
    return -LINUX_EFAULT;
  }
  return r;
}

DEFINE_SYSCALL(getxattr, gstr_t, path_ptr, gstr_t, name_ptr, gaddr_t, value, size_t, size)
{
  printk("getxattr is unimplemented\n");
  return -LINUX_ENOTSUP;
}

DEFINE_SYSCALL(fadvise64, int, fd, off_t, offset, size_t, len, int, advice)
{
  printk("fadvise is unimplemented\n");
  return 0;
}

DEFINE_SYSCALL(select, int, nfds, gaddr_t, readfds_ptr, gaddr_t, writefds_ptr, gaddr_t, errorfds_ptr, gaddr_t, timeout_ptr)
{
  // Darwin's fd_set and timeval is compatible with those of Linux

  struct timeval timeout;
  fd_set readfds, writefds, errorfds;
  struct timeval *to;
  fd_set *rfds, *wfds, *efds;

  if (timeout_ptr == 0) {
    to = NULL;
  } else {
    if (copy_from_user(&timeout, timeout_ptr, sizeof timeout))
      return -LINUX_EFAULT;
    to = &timeout;
  }
  if (readfds_ptr == 0) {
    rfds = NULL;
  } else {
    if (copy_from_user(&readfds, readfds_ptr, sizeof readfds))
      return -LINUX_EFAULT;
    rfds = &readfds;
  }
  if (writefds_ptr == 0) {
    wfds = NULL;
  } else {
    if (copy_from_user(&writefds, writefds_ptr, sizeof writefds))
      return -LINUX_EFAULT;
    wfds = &writefds;
  }
  if (errorfds_ptr == 0) {
    efds = NULL;
  } else {
    if (copy_from_user(&errorfds, errorfds_ptr, sizeof errorfds))
      return -LINUX_EFAULT;
    efds = &errorfds;
  }

  int r = syswrap(select(nfds, rfds, wfds, efds, to));
  if (r < 0)
    return r;

  if (readfds_ptr != 0 && copy_to_user(readfds_ptr, &readfds, sizeof readfds))
    return -LINUX_EFAULT;
  if (writefds_ptr != 0 && copy_to_user(writefds_ptr, &writefds, sizeof writefds))
    return -LINUX_EFAULT;
  if (errorfds_ptr != 0 && copy_to_user(errorfds_ptr, &errorfds, sizeof errorfds))
    return -LINUX_EFAULT;
  return r;
}

DEFINE_SYSCALL(pselect6, int, nfds, gaddr_t, readfds_ptr, gaddr_t, writefds_ptr, gaddr_t, errorfds_ptr, gaddr_t, timeout_ptr, gaddr_t, sigmask_ptr)
{
  // Darwin's fd_set and timeval is compatible with those of Linux

  struct timespec timeout;
  fd_set readfds, writefds, errorfds;
  struct timespec *to;
  fd_set *rfds, *wfds, *efds;

  if (timeout_ptr == 0) {
    to = NULL;
  } else {
    if (copy_from_user(&timeout, timeout_ptr, sizeof timeout))
      return -LINUX_EFAULT;
    to = &timeout;
  }
  if (readfds_ptr == 0) {
    rfds = NULL;
  } else {
    if (copy_from_user(&readfds, readfds_ptr, sizeof readfds))
      return -LINUX_EFAULT;
    rfds = &readfds;
  }
  if (writefds_ptr == 0) {
    wfds = NULL;
  } else {
    if (copy_from_user(&writefds, writefds_ptr, sizeof writefds))
      return -LINUX_EFAULT;
    wfds = &writefds;
  }
  if (errorfds_ptr == 0) {
    efds = NULL;
  } else {
    if (copy_from_user(&errorfds, errorfds_ptr, sizeof errorfds))
      return -LINUX_EFAULT;
    efds = &errorfds;
  }

  // FIXME: Ignore sigmask now. Support it after implementing signal handling
  int r = syswrap(pselect(nfds, rfds, wfds, efds, to, NULL));
  if (r < 0)
    return r;

  if (readfds_ptr != 0 && copy_to_user(readfds_ptr, &readfds, sizeof readfds))
    return -LINUX_EFAULT;
  if (writefds_ptr != 0 && copy_to_user(writefds_ptr, &writefds, sizeof writefds))
    return -LINUX_EFAULT;
  if (errorfds_ptr != 0 && copy_to_user(errorfds_ptr, &errorfds, sizeof errorfds))
    return -LINUX_EFAULT;
  return r;
}

DEFINE_SYSCALL(poll, gaddr_t, fds_ptr, int, nfds, int, timeout)
{
  /* FIXME! event numbers should be translated */

  struct pollfd fds[nfds];

  if (copy_from_user(fds, fds_ptr, sizeof fds))
    return -LINUX_EFAULT;

  int r = syswrap(poll(fds, nfds, timeout));
  if (r < 0)
    return r;

  if (copy_to_user(fds_ptr, fds, sizeof fds))
    return -LINUX_EFAULT;

  return r;
}

DEFINE_SYSCALL(chroot, gstr_t, path_ptr)
{
  char path[PATH_MAX];
  int len = strncpy_from_user(path, path_ptr, sizeof path);
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

  /* for pacman */
  if (! (path[0] == '/' && path[1] == '\0')) {
    return -LINUX_EACCES;
  }
  return 0;
}
