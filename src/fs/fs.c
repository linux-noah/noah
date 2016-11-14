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
  int (*close)(struct file *f);
  int (*stat)(struct file *f, struct l_newstat *stat);
  int (*ioctl)(struct file *f, int cmd, uint64_t val0);
  int (*lseek)(struct file *f, l_off_t offset, int whence);
  int (*getdents)(struct file *f, char *buf, uint count);
  int (*fcntl)(struct file *f, unsigned int cmd, unsigned long arg);
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
darwinfs_ioctl(struct file *file, int cmd, uint64_t val0)
{
  int fd = file->fd;
  printk("darwinfs ioctl (fd = %08x, cmd = %d)\n", fd, cmd);
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

int
darwinfs_lseek(struct file *file, l_off_t offset, int whence)
{
  return syswrap(lseek(file->fd, offset, whence));
}

int
darwinfs_getdents(struct file *file, char *direntp, unsigned count)
{
  long base;
  char buf[count];
  struct dirent *d;
  int bpos;

  struct l_dirent *l_d;
  unsigned int l_bpos = 0;

  int nread = syscall(SYS_getdirentries64, file->fd, buf, count, &base);
  if (nread < 0) {
    return -errno;
  }
  for (bpos = 0; bpos < nread; bpos += d->d_reclen) {
    d = (struct dirent *) (buf + bpos);

    size_t l_reclen = roundup(offsetof(struct l_dirent, d_name) + d->d_namlen + 2, 8);
    assert(l_bpos + l_reclen <= count);

    /* fill dirent buffer */
    l_d = (struct l_dirent *) (direntp + l_bpos);
    l_d->d_ino = d->d_ino;
    l_d->d_reclen = l_reclen;
    l_d->d_off = d->d_seekoff;
    memcpy(l_d->d_name, d->d_name, d->d_namlen + 1);
    (direntp + l_bpos)[l_d->d_reclen - 1] = d->d_type;

    l_bpos += l_d->d_reclen;
  }
  return l_bpos;
}

int
darwinfs_fcntl(struct file *file, unsigned int cmd, unsigned long arg)
{
  return syswrap(fcntl(file->fd, cmd, arg));
}

struct file *
vfs_acquire(int fd)
{
  static struct file_operations ops = {
    darwinfs_write,
    darwinfs_read,
    darwinfs_close,
    darwinfs_stat,
    darwinfs_ioctl,
    darwinfs_lseek,
    darwinfs_getdents,
    darwinfs_fcntl,
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
  int r;
  if (file->ops->write == NULL) {
    r = -LINUX_EBADF;
    goto out;
  }
  r = file->ops->write(file, buf, size);
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
  if (file->ops->read == NULL) {
    r = -LINUX_EBADF;
    goto out;
  }
  r = file->ops->read(file, buf, size);
  if (r > 0) {
    copy_to_user(buf_ptr, buf, r);
  }
 out:
  vfs_release(file);
  return r;
}

DEFINE_SYSCALL(close, int, fd)
{
  /* FIXME: free fd slot */
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  int n = file->ops->close(file);
  vfs_release(file);
  return n;
}

DEFINE_SYSCALL(fstat, int, fd, gaddr_t, st_ptr)
{
  struct file *file = vfs_acquire(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  struct l_newstat st;
  int n = file->ops->stat(file, &st);
  if (n >= 0) {
    copy_to_user(st_ptr, &st, sizeof st);
  }
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
  vfs_release(file);
  copy_to_user(dirent_ptr, buf, count);
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

struct dir {
  int fd;
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
  if (l_flags & LINUX_AT_EACCESS) {
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

#define LOOKUP_FOLLOW     0x0001
/* #define LOOKUP_DIRECTORY  0x0002 */
/* #define LOOKUP_CONTINUE   0x0004 */
/* #define LOOKUP_AUTOMOUNT  0x0008 */
/* #define LOOKUP_PARENT     0x0010 */
/* #define LOOKUP_REVAL      0x0020 */

int
vfs_grab_dir(int dirfd, const char *path, int flags, struct fs **fs, struct dir **dir, char *subpath)
{
  static struct fs_operations ops = {
    darwinfs_openat,
    darwinfs_symlinkat,
    darwinfs_faccessat,
    darwinfs_renameat,
    darwinfs_linkat,
    darwinfs_unlinkat,
    darwinfs_readlinkat,
  };

  static struct fs darwinfs = {
    .ops = &ops,
  };

  if (flags & ~(LOOKUP_FOLLOW)) {
    return -LINUX_EINVAL;
  }

  *dir = malloc(sizeof *dir);
  if (dirfd == LINUX_AT_FDCWD) {
    (* dir)->fd = AT_FDCWD;
  } else {
    (* dir)->fd = dirfd;
  }
  *fs = &darwinfs;
  if (path[0] == '/') {
    sprintf(subpath, "%s/%s", proc.root, path);
  } else {
    strcpy(subpath, path);
  }
  return 0;
}

void
vfs_ungrab_dir(struct dir *dir)
{
  free(dir);
}

int
do_openat(int dirfd, const char *path, int flags, int mode)
{
  struct fs *fs;
  struct dir *dir;
  char subpath[LINUX_PATH_MAX];

  int r = vfs_grab_dir(dirfd, path, LOOKUP_FOLLOW, &fs, &dir, subpath);
  if (r < 0) {
    return r;
  }
  r = fs->ops->openat(fs, dir, subpath, flags, mode);
  vfs_ungrab_dir(dir);
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

DEFINE_SYSCALL(symlinkat, gstr_t, path1_ptr, int, dirfd, gstr_t, path2_ptr)
{
  char path1[LINUX_PATH_MAX], path2[LINUX_PATH_MAX];

  strncpy_from_user(path1, path1_ptr, sizeof path1);
  strncpy_from_user(path2, path2_ptr, sizeof path2);

  struct fs *fs;
  struct dir *dir;
  char subpath[LINUX_PATH_MAX];

  int r = vfs_grab_dir(dirfd, path2, LOOKUP_FOLLOW, &fs, &dir, subpath);
  if (r < 0) {
    return r;
  }
  r = fs->ops->symlinkat(fs, path1, dir, subpath);
  vfs_ungrab_dir(dir);
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
  int fd = do_openat(dirfd, path, 0, 0); /* TODO: ask for the fs directly */
  if (fd < 0)
    return fd;
  int r = sys_fstat(fd, st_ptr);
  sys_close(fd);
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
do_faccessat(int dirfd, const char *path, int mode)
{
  struct fs *fs;
  struct dir *dir;
  char subpath[LINUX_PATH_MAX];

  int r = vfs_grab_dir(dirfd, path, LOOKUP_FOLLOW, &fs, &dir, subpath);
  if (r < 0) {
    return r;
  }
  r = fs->ops->faccessat(fs, dir, subpath, mode);
  vfs_ungrab_dir(dir);
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
  char oldpath[LINUX_PATH_MAX], newpath[LINUX_PATH_MAX];

  strncpy_from_user(oldpath, oldpath_ptr, sizeof oldpath);
  strncpy_from_user(newpath, newpath_ptr, sizeof newpath);

  struct fs *fs;
  struct dir *olddir, *newdir;
  char oldsubpath[LINUX_PATH_MAX], newsubpath[LINUX_PATH_MAX];

  int r;
  if ((r = vfs_grab_dir(oldfd, oldpath, LOOKUP_FOLLOW, &fs, &olddir, oldsubpath)) < 0) {
    goto out1;
  }
  if ((r = vfs_grab_dir(newfd, newpath, LOOKUP_FOLLOW, &fs, &newdir, newsubpath)) < 0) {
    goto out2;
  }
  r = fs->ops->renameat(fs, olddir, oldsubpath, newdir, newsubpath);
  vfs_ungrab_dir(newdir);
 out2:
  vfs_ungrab_dir(olddir);
 out1:
  return r;
}

DEFINE_SYSCALL(rename, gstr_t, oldpath_ptr, gstr_t, newpath_ptr)
{
  return sys_renameat(LINUX_AT_FDCWD, oldpath_ptr, LINUX_AT_FDCWD, newpath_ptr);
}

DEFINE_SYSCALL(unlinkat, int, dirfd, gstr_t, path_ptr, int, flags)
{
  char path[LINUX_PATH_MAX];
  strncpy_from_user(path, path_ptr, sizeof path);

  struct fs *fs;
  struct dir *dir;
  char subpath[LINUX_PATH_MAX];

  int r;
  if ((r = vfs_grab_dir(dirfd, path, LOOKUP_FOLLOW, &fs, &dir, subpath)) < 0) {
    return r;
  }
  r = fs->ops->unlinkat(fs, dir, subpath, flags);
  vfs_ungrab_dir(dir);
  return r;
}

DEFINE_SYSCALL(unlink, gstr_t, path)
{
  return sys_unlinkat(LINUX_AT_FDCWD, path, 0);
}

DEFINE_SYSCALL(linkat, int, oldfd, gstr_t, oldpath_ptr, int, newfd, gstr_t, newpath_ptr, int, flags)
{
  char oldpath[LINUX_PATH_MAX], newpath[LINUX_PATH_MAX];

  strncpy_from_user(oldpath, oldpath_ptr, sizeof oldpath);
  strncpy_from_user(newpath, newpath_ptr, sizeof newpath);

  struct fs *fs;
  struct dir *olddir, *newdir;
  char oldsubpath[LINUX_PATH_MAX], newsubpath[LINUX_PATH_MAX];

  int r;
  if ((r = vfs_grab_dir(oldfd, oldpath, LOOKUP_FOLLOW, &fs, &olddir, oldsubpath)) < 0) {
    goto out1;
  }
  if ((r = vfs_grab_dir(newfd, newpath, LOOKUP_FOLLOW, &fs, &newdir, newsubpath)) < 0) {
    goto out2;
  }
  r = fs->ops->linkat(fs, olddir, oldsubpath, newdir, newsubpath, flags);
  vfs_ungrab_dir(newdir);
 out2:
  vfs_ungrab_dir(olddir);
 out1:
  return r;
}

DEFINE_SYSCALL(link, gstr_t, oldpath, gstr_t, newpath)
{
  return sys_linkat(LINUX_AT_FDCWD, oldpath, LINUX_AT_FDCWD, newpath, 0);
}

DEFINE_SYSCALL(readlinkat, int, dirfd, gstr_t, path_ptr, gaddr_t, buf_ptr, int, bufsize)
{
  char path[LINUX_PATH_MAX];
  strncpy_from_user(path, path_ptr, sizeof path);

  struct fs *fs;
  struct dir *dir;
  char subpath[LINUX_PATH_MAX];

  int r;
  if ((r = vfs_grab_dir(dirfd, path, LOOKUP_FOLLOW, &fs, &dir, subpath)) < 0) {
    return r;
  }
  char buf[bufsize];
  r = fs->ops->readlinkat(fs, dir, subpath, buf, bufsize);
  vfs_ungrab_dir(dir);
  copy_to_user(buf_ptr, buf, bufsize);
  return r;
}

DEFINE_SYSCALL(readlink, gstr_t, path_ptr, gaddr_t, buf_ptr, int, bufsize)
{
  return sys_readlinkat(LINUX_AT_FDCWD, path_ptr, buf_ptr, bufsize);
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

DEFINE_SYSCALL(pread64, unsigned int, fd, gstr_t, buf, size_t, count, off_t, pos)
{
  return syswrap(pread(fd, guest_to_host(buf), count, pos));
}

DEFINE_SYSCALL(getxattr, gstr_t, path_ptr, gstr_t, name_ptr, gaddr_t, value, size_t, size)
{
  printk("getxattr is unimplemented\n");
  return -LINUX_ENOTSUP;
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
