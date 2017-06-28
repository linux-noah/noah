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
#include <stdbool.h>
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
  int (*ioctl)(struct file *f, int cmd, uint64_t val0);
  int (*lseek)(struct file *f, l_off_t offset, int whence);
  int (*getdents)(struct file *f, char *buf, uint count, bool is64);
  int (*fcntl)(struct file *f, unsigned int cmd, unsigned long arg);
  int (*fsync)(struct file *f);
  /* inode operations */
  int (*fstat)(struct file *f, struct l_newstat *stat);
  int (*fstatfs)(struct file *f, struct l_statfs *buf);
  int (*fchown)(struct file *f, l_uid_t uid, l_gid_t gid);
  int (*fchmod)(struct file *f, l_mode_t mode);
};

static inline bool in_userfd(int fd);
static const int vkern_fdtable_maxsize = 64;

static inline void set_fdbit(struct fdtable *table, uint64_t *fdbits, int fd);
static inline void clear_fdbit(struct fdtable *table, uint64_t *fdbits, int fd);

void
init_fileinfo(int rootfd)
{
  struct rlimit limit;
  struct fileinfo *fileinfo = &proc.fileinfo;

  getrlimit(RLIMIT_NOFILE, &limit);
  fileinfo->vkern_fdtable = (struct fdtable) {
    .start = limit.rlim_cur - 64,
    .size = 64,
    .files = malloc(sizeof(struct file) * 64),
    .open_fds = malloc(sizeof(uint64_t)),
    .cloexec_fds = malloc(sizeof(uint64_t))
  };
  fileinfo->vkern_fdtable.open_fds[0] = 0;
  fileinfo->vkern_fdtable.cloexec_fds[0] = 0;
  fileinfo->fdtable = (struct fdtable) {
    .start = 0,
    .size = vkern_fdtable_maxsize,
    .files = malloc(sizeof(struct file) * vkern_fdtable_maxsize),
    .open_fds = malloc(sizeof(uint64_t)),
    .cloexec_fds = malloc(sizeof(uint64_t))
  };
  fileinfo->fdtable.open_fds[0] = 0;
  fileinfo->fdtable.cloexec_fds[0] = 0;

  for (int i = 0; i < (int) limit.rlim_cur; i++) {
    if (i == rootfd) {
      continue;
    }
    int flag = fcntl(i, F_GETFD);
    if (flag < 0) {
      continue;
    }
    if (in_userfd(i)) {
      register_fd(i, flag & FD_CLOEXEC);
    } else {
      warnk("closing a file whose fd overlaps with vkern_fdtable, fd: %d\n", i);
      fprintf(stderr, "Noah uses high file descriptor numbers as the system file descriptors. fd[%d] is closed because it overlaps with the system area.\n", i);
      close(i);
    }
  }
  fileinfo->rootfd = vkern_dup_fd(rootfd, false);
}

void
darwin_to_linux_rlimit_nofile(struct rlimit *darwin_rlimit, struct l_rlimit *linux_rlimit)
{
  linux_rlimit->rlim_cur = darwin_rlimit->rlim_cur;
  linux_rlimit->rlim_max = darwin_rlimit->rlim_max - vkern_fdtable_maxsize;
}

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
darwinfs_ioctl(struct file *file, int cmd, uint64_t val0)
{
  uint64_t sys_fcntl(unsigned int fd, unsigned int cmd, unsigned long arg);
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
  case LINUX_TIOCSPGRP: {
    l_pid_t pgrp;
    if (copy_from_user(&pgrp, val0, sizeof pgrp)) {
      return -LINUX_EFAULT;
    }
    if ((r = syswrap(ioctl(fd, TIOCSPGRP, &pgrp))) < 0) {
      return r;
    }
    return 0;
  }
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
  case LINUX_FIOCLEX: {
    pthread_rwlock_wrlock(&proc.fileinfo.fdtable_lock);
    int r = -1; //sys_fcntl(fd, LINUX_F_SETFD, 1);
    if (r >= 0) {
      set_fdbit(&proc.fileinfo.fdtable, proc.fileinfo.fdtable.cloexec_fds, fd);
    }
    pthread_rwlock_unlock(&proc.fileinfo.fdtable_lock);
    return r;
  }
  default:
    warnk("unhandled darwinfs ioctl (fd = %08x, cmd = 0x%08x)\n", fd, cmd);
    return -LINUX_EPERM;
  }
}

int
darwinfs_lseek(struct file *file, l_off_t offset, int whence)
{
  return syswrap(lseek(file->fd, offset, whence));
}

ssize_t
darwin_to_linux_dent(struct dirent *d_dent, void *l_dent, size_t buflen, int is64)
{
  unsigned reclen = roundup(is64 ? offsetof(struct l_dirent64, d_name) : offsetof(struct l_dirent, d_name) + d_dent->d_namlen + 2, 8);
  if (reclen > buflen) {
    return -1;
  }
  /* fill dirent buffer */
  if (is64) {
    struct l_dirent64 *dp = (struct l_dirent64 *) l_dent;
    dp->d_reclen = reclen;
    dp->d_ino = d_dent->d_ino;
    dp->d_off = d_dent->d_seekoff;
    dp->d_type = d_dent->d_type;
    memcpy(dp->d_name, d_dent->d_name, d_dent->d_namlen + 1);
  } else {
    struct l_dirent *dp = (struct l_dirent *) l_dent;
    dp->d_reclen = reclen;
    dp->d_ino = d_dent->d_ino;
    dp->d_off = d_dent->d_seekoff;
    memcpy(dp->d_name, d_dent->d_name, d_dent->d_namlen + 1);
    ((char *) dp)[reclen - 1] = d_dent->d_type;
  }
  return reclen;
}

int
darwinfs_getdents(struct file *file, char *direntp, unsigned count, bool is64)
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
    ssize_t reclen = darwin_to_linux_dent(dent, direntp + pos, count - pos, is64);
    if (reclen < 0) {
      seekdir(dir, loc);
      goto end;
    }
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

void linux_to_darwin_flock(struct l_flock *linux_flock, struct flock *darwin_flock);

void darwin_to_linux_flock(struct flock *darwin_flock, struct l_flock *linux_flock);

int
darwinfs_fcntl(struct file *file, unsigned int cmd, unsigned long arg)
{
  int r;
  struct l_flock lflock;
  struct flock dflock;

  switch (cmd) {
  case LINUX_F_DUPFD:
    pthread_rwlock_wrlock(&proc.fileinfo.fdtable_lock);
    r = syswrap(fcntl(file->fd, F_DUPFD, arg)); /* FIXME */
    if (r >= 0) {
      int err = register_fd(r, false);
      if (err < 0) {
        close(r);
        r = err;
      }
    }
    pthread_rwlock_unlock(&proc.fileinfo.fdtable_lock);
    return r;
  case LINUX_F_DUPFD_CLOEXEC:
    pthread_rwlock_wrlock(&proc.fileinfo.fdtable_lock);
    r = syswrap(fcntl(file->fd, F_DUPFD_CLOEXEC, arg));
    if (r >= 0) {
      int err = register_fd(r, true);
      if (err < 0) {
        close(r);
        r = err;
      }
    }
    pthread_rwlock_unlock(&proc.fileinfo.fdtable_lock);
    return r;
    /* no translation required for fd flags (i.e. CLOEXEC==1 */
  case LINUX_F_GETFD:
    return syswrap(fcntl(file->fd, F_GETFD));
  case LINUX_F_SETFD:
    pthread_rwlock_wrlock(&proc.fileinfo.fdtable_lock);
    r = syswrap(fcntl(file->fd, F_SETFD, arg));
    if (r >= 0) {
      if (arg & FD_CLOEXEC) {
        set_fdbit(&proc.fileinfo.fdtable, proc.fileinfo.fdtable.cloexec_fds, file->fd);
      } else {
        clear_fdbit(&proc.fileinfo.fdtable, proc.fileinfo.fdtable.cloexec_fds, file->fd);
      }
    }
    pthread_rwlock_unlock(&proc.fileinfo.fdtable_lock);
    return r;
  case LINUX_F_GETFL:
    r = syswrap(fcntl(file->fd, F_GETFL));
    if (r < 0)
      return r;
    return darwin_to_linux_o_flags(r);
  case LINUX_F_SETFL:
    return syswrap(fcntl(file->fd, F_SETFL, linux_to_darwin_o_flags(arg)));
  case LINUX_F_GETLK:
    if (copy_from_user(&lflock, arg, sizeof lflock)) {
      return -LINUX_EFAULT;
    }
    linux_to_darwin_flock(&lflock, &dflock);
    r = syswrap(fcntl(file->fd, F_GETLK, &dflock));
    if (r < 0) {
      return r;
    }
    darwin_to_linux_flock(&dflock, &lflock);
    if (copy_to_user(arg, &lflock, sizeof lflock)) {
      return -LINUX_EFAULT;
    }
    return 0;
  case LINUX_F_SETLK: case LINUX_F_SETLKW:
    if (copy_from_user(&lflock, arg, sizeof lflock)) {
      return -LINUX_EFAULT;
    }
    linux_to_darwin_flock(&lflock, &dflock);
    return syswrap(fcntl(file->fd, (cmd == LINUX_F_SETLK) ? F_SETLK : F_SETLKW, &dflock));
  default:
    warnk("unknown fcntl cmd: %d\n", cmd);
    return -LINUX_EINVAL;
  }
}

int
darwinfs_fsync(struct file *file)
{
  return syswrap(fsync(file->fd));
}

int
darwinfs_fstat(struct file *file, struct l_newstat *l_st)
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
darwinfs_fstatfs(struct file *file, struct l_statfs *buf)
{
  struct statfs st;
  int r = syswrap(fstatfs(file->fd, &st));
  if (r < 0)
    return r;
  statfs_darwin_to_linux(&st, buf);
  return r;
}

static inline bool
in_userfd(int fd)
{
  return (fd >= 0 && fd < proc.fileinfo.vkern_fdtable.start);
}

static inline void
set_fdbit(struct fdtable *table, uint64_t *fdbits, int fd)
{
  int idx_table = (fd - table->start) / 64;
  int idx_bit = (fd - table->start) - idx_table * 64;
  fdbits[idx_table] |= (1ULL << (idx_bit));
}

static inline void
clear_fdbit(struct fdtable *table, uint64_t *fdbits, int fd)
{
  int idx_table = (fd - table->start) / 64;
  int idx_bit = (fd - table->start) - idx_table * 64;
  fdbits[idx_table] &= ~(1ULL << (idx_bit));
}

static inline bool
test_fdbit(struct fdtable *table, uint64_t *fdbits, int fd)
{
  int idx_table = (fd - table->start) / 64;
  int idx_bit = (fd - table->start) - idx_table * 64;
  return fdbits[idx_table] & (1ULL << (idx_bit));
}

static void
alloc_file(struct fdtable *table, int fd)
{
  static struct file_operations ops = {
    darwinfs_readv,
    darwinfs_writev,
    darwinfs_close,
    darwinfs_ioctl,
    darwinfs_lseek,
    darwinfs_getdents,
    darwinfs_fcntl,
    darwinfs_fsync,
    darwinfs_fstat,
    darwinfs_fstatfs,
    darwinfs_fchown,
    darwinfs_fchmod,
  };

  struct file *file = table->files + (fd - table->start);
  file->ops = &ops;
  file->fd = fd;
}

/*
 * The caller of register_fd and vkern_dup_fd must acquire the lock properly if necessary
 */

int
register_fd(int fd, bool is_cloexec)
{
  if (fd >= proc.fileinfo.vkern_fdtable.start) {
    // Relocation of vkern_fdtable is not implemented currently
    return -LINUX_EMFILE;
  }
  struct fdtable *fdtable = &proc.fileinfo.fdtable;
  if (proc.fileinfo.fdtable.size <= fd) {
    // Expand table
    int new_size = roundup(fd, sizeof(uint64_t));
    size_t old_nunits = proc.fileinfo.fdtable.size / 64;
    size_t new_nunits = new_size / 64;
    fdtable->files = realloc(fdtable->files, new_size * sizeof(struct file));
    fdtable->open_fds = realloc(fdtable->open_fds, sizeof(uint64_t) * new_nunits);
    fdtable->cloexec_fds = realloc(fdtable->cloexec_fds, sizeof(uint64_t) * new_nunits);
    bzero(fdtable->open_fds + old_nunits, (new_nunits - old_nunits) * sizeof(uint64_t));
    bzero(fdtable->cloexec_fds + old_nunits, (new_nunits - old_nunits) * sizeof(uint64_t));
    fdtable->size = new_size;
  }
  set_fdbit(fdtable, fdtable->open_fds, fd);
  if (is_cloexec) {
    set_fdbit(fdtable, fdtable->cloexec_fds, fd);
  } else {
    clear_fdbit(fdtable, fdtable->cloexec_fds, fd);
  }
  alloc_file(fdtable, fd);
  return 0;
}

static inline int
find_emptyfd(struct fdtable *table)
{
  for (int i = 0; i < table->size / 64; i++) {
    int ret = ffs(~table->open_fds[i]);
    if (ret > 0) {
      return table->start + ret - 1 + i * 64;
    }
  }
  return -1;
}

int
vkern_dup_fd(int fd, bool is_cloexec)
{
  int vkern_fd = find_emptyfd(&proc.fileinfo.vkern_fdtable);
  if (vkern_fd == -1) {
    panic("Too many files opened in the kernel space");
  }
  dup2(fd, vkern_fd);
  set_fdbit(&proc.fileinfo.vkern_fdtable, proc.fileinfo.vkern_fdtable.open_fds, vkern_fd);
  if (is_cloexec) {
    set_fdbit(&proc.fileinfo.vkern_fdtable, proc.fileinfo.vkern_fdtable.cloexec_fds, vkern_fd);
  } else {
    clear_fdbit(&proc.fileinfo.vkern_fdtable, proc.fileinfo.vkern_fdtable.cloexec_fds, vkern_fd);
  }
  alloc_file(&proc.fileinfo.vkern_fdtable, vkern_fd);
  return vkern_fd;
}

struct file *
get_file(int fd)
{
  if (fd < 0 || fd >= proc.fileinfo.fdtable.size) {
    return NULL;
  }

  struct file *ret = NULL;
  pthread_rwlock_rdlock(&proc.fileinfo.fdtable_lock);
  if (!test_fdbit(&proc.fileinfo.fdtable, proc.fileinfo.fdtable.open_fds, fd)) {
    goto out;
  }
  ret = &proc.fileinfo.fdtable.files[fd - proc.fileinfo.fdtable.start];

out:
  pthread_rwlock_unlock(&proc.fileinfo.fdtable_lock);
  return ret;
}

DEFINE_SYSCALL(write, int, fd, gaddr_t, buf_ptr, size_t, size)
{
  int r;
  char *buf = malloc(size);
  if (copy_from_user(buf, buf_ptr, size)) {
    r = -LINUX_EFAULT;
    goto out;
  }
  struct file *file = get_file(fd);
  if (file == NULL) {
    r = -LINUX_EBADF;
    goto out;
  }
  if (file->ops->writev == NULL) {
    r = -LINUX_EBADF;
    goto out;
  }
  struct iovec iov = { buf, size };
  r =  file->ops->writev(file, &iov, 1);
out:
  free(buf);
  return r;
}

DEFINE_SYSCALL(read, int, fd, gaddr_t, buf_ptr, size_t, size)
{
  int r;
  char *buf = malloc(size);
  struct file *file = get_file(fd);
  if (file == NULL) {
    r = -LINUX_EBADF;
    goto out;
  }
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
  free(buf);
  return r;
}

DEFINE_SYSCALL(fstat, int, fd, gaddr_t, st_ptr)
{
  struct file *file = get_file(fd);
  if (file == NULL)
    return -LINUX_EBADF;
  struct l_newstat st;
  int n = file->ops->fstat(file, &st);
  if (n < 0)
    return n;
  if (copy_to_user(st_ptr, &st, sizeof st)) {
    return -LINUX_EFAULT;
  }
  return n;
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
  int (*mkdirat)(struct fs *fs, struct dir *dir, const char *path, int mode);
  /* inode operations */
  int (*fstatat)(struct fs *fs, struct dir *dir, const char *path, struct l_newstat *stat, int flags);
  int (*statfs)(struct fs *fs, struct dir *dir, const char *path, struct l_statfs *buf);
  int (*fchownat)(struct fs *fs, struct dir *dir, const char *path, l_uid_t uid, l_gid_t gid, int flags);
  int (*fchmodat)(struct fs *fs, struct dir *dir, const char *path, l_mode_t mode);
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
  /* You must treat E_ACCESS as E_REMOVEDIR in unlinkat */
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
darwinfs_mkdirat(struct fs *fs, struct dir *dir, const char *path, int mode)
{
  return syswrap(mkdirat(dir->fd, path, mode));
}

int
darwinfs_fstatat(struct fs *fs, struct dir *dir, const char *path, struct l_newstat *l_st, int l_flags)
{
  int flags = linux_to_darwin_at_flags(l_flags);
  struct stat st;
  int ret = syswrap(fstatat(dir->fd, path, &st, flags));
  if (ret < 0) {
    return ret;
  }
  stat_darwin_to_linux(&st, l_st);
  return ret;
}

int
darwinfs_statfs(struct fs *fs, struct dir *dir, const char *path, struct l_statfs *buf)
{
  char full_path[LINUX_PATH_MAX];
  const char *path_to_statfs;

  if (dir->fd != AT_FDCWD) {
    path_to_statfs = full_path;
    char at_path[PATH_MAX];
    assert(fcntl(dir->fd, F_GETPATH, at_path) == 0); // fd must be a regular directory to which fcntl should succeed
    if (snprintf(full_path, PATH_MAX, "%s/%s", at_path, path) >= PATH_MAX) {
      return -LINUX_ENAMETOOLONG;
    }
  } else {
    path_to_statfs = path;
  }

  struct statfs st;
  int r = syswrap(statfs(path_to_statfs, &st));
  if (r < 0)
    return r;
  statfs_darwin_to_linux(&st, buf);
  return r;
}

int
darwinfs_fchownat(struct fs *fs, struct dir *dir, const char *path, l_uid_t uid, l_gid_t gid, int l_flags)
{
  int flags = linux_to_darwin_at_flags(l_flags);
  return syswrap(fchownat(dir->fd, path, uid, gid, flags));
}

int
darwinfs_fchmodat(struct fs *fs, struct dir *dir, const char *path, l_mode_t mode)
{
  return syswrap(fchmodat(dir->fd, path, mode, 0));
}

#define LOOKUP_NOFOLLOW   0x0001
#define LOOKUP_DIRECTORY  0x0002
/* #define LOOKUP_CONTINUE   0x0004 */
/* #define LOOKUP_AUTOMOUNT  0x0008 */
/* #define LOOKUP_PARENT     0x0010 */
/* #define LOOKUP_REVAL      0x0020 */

#define LOOP_MAX 20

int
resolve_path(const struct dir *parent, const char *name, int flags, struct path *path, int loop)
{
  static struct fs_operations ops = {
    darwinfs_openat,
    darwinfs_symlinkat,
    darwinfs_faccessat,
    darwinfs_renameat,
    darwinfs_linkat,
    darwinfs_unlinkat,
    darwinfs_readlinkat,
    darwinfs_mkdirat,
    darwinfs_fstatat,
    darwinfs_statfs,
    darwinfs_fchownat,
    darwinfs_fchmodat,
  };
  static struct fs darwinfs = {
    .ops = &ops,
  };
  struct fs *fs = &darwinfs;

  if (loop > LOOP_MAX)
    return -LINUX_ELOOP;

  struct dir dir = *parent;

  /* resolve mountpoints */
  if (*name == '/') {
    if (name[1] == '\0') {
      dir.fd = proc.fileinfo.rootfd;
      strcpy(path->subpath, ".");
      goto out;
    }
    if (strncmp(name, "/Users", sizeof "/Users" - 1) && strncmp(name, "/Volumes", sizeof "/Volumes" - 1) && strncmp(name, "/dev", sizeof "/dev" - 1) && strncmp(name, "/tmp", sizeof "/tmp" - 1) && strncmp(name, "/private", sizeof "/private" - 1)) {
      dir.fd = proc.fileinfo.rootfd;
      name++;
    }
  }

  /* resolve symlinks */
  char *sp = path->subpath;
  *sp = 0;
  const char *c = name;
  assert(*c);
  while (*c) {
    while (*c && *c != '/') {
      *sp++ = *c++;
    }
    *sp = 0;
    if ((flags & LOOKUP_NOFOLLOW) == 0) {
      char buf[LINUX_PATH_MAX];
      int n;
      if ((n = fs->ops->readlinkat(fs, &dir, path->subpath, buf, sizeof buf)) > 0) {
        strcpy(buf + n, c);
        if (buf[0] == '/') {
          return resolve_path(&dir, buf, flags, path, loop + 1);
        } else {
          /* remove the last component */
          while (sp >= path->subpath && *--sp != '/')
            ;
          *++sp = 0;
          char buf2[LINUX_PATH_MAX];
          strcpy(buf2, path->subpath);
          strcat(buf2, buf);
          return resolve_path(&dir, buf2, flags, path, loop + 1);
        }
      }
    }
    if (*c) {
      *sp++ = *c++;
    }
    *sp = 0;
  }

 out:
  path->fs = fs;
  path->dir = malloc(sizeof(struct dir));
  path->dir->fd = dir.fd;
  return 0;
}

int
vfs_grab_dir(int dirfd, const char *name, int flags, struct path *path)
{
  struct dir dir;

  if (flags & ~(LOOKUP_NOFOLLOW | LOOKUP_DIRECTORY)) {
    return -LINUX_EINVAL;
  }

  if (*name == 0) {
    return -LINUX_ENOENT;
  }

  if (dirfd == LINUX_AT_FDCWD) {
    dir.fd = AT_FDCWD;
  } else {
    dir.fd = dirfd;
    if (!in_userfd(dir.fd)) {
      return -LINUX_EBADF;
    }
  }
  return resolve_path(&dir, name, flags, path, 0);
}

void
vfs_ungrab_dir(struct path *path)
{
  free(path->dir);
}

static int
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

static int
do_open(const char *path, int l_flags, int mode)
{
  return do_openat(LINUX_AT_FDCWD, path, l_flags, mode);
}

int
vkern_openat(int atdirfd, const char *name, int flags, int mode)
{
  int ret;

  pthread_rwlock_wrlock(&proc.fileinfo.fdtable_lock);
  int fd = do_openat(atdirfd, name, flags, mode);
  if (fd < 0) {
    ret = fd;
    goto out;
  }
  ret = vkern_dup_fd(fd, flags & LINUX_O_CLOEXEC);
  close(fd);

out:
  pthread_rwlock_unlock(&proc.fileinfo.fdtable_lock);
  return ret;
}

int
vkern_open(const char *path, int l_flags, int mode)
{
  return vkern_openat(LINUX_AT_FDCWD, path, l_flags, mode);
}

int
user_openat(int atdirfd, const char *name, int flags, int mode)
{
  int fd;
  pthread_rwlock_wrlock(&proc.fileinfo.fdtable_lock);
  fd = do_openat(atdirfd, name, flags, mode);
  if (fd < 0) {
    goto out;
  }
  int err = register_fd(fd, flags & LINUX_O_CLOEXEC);
  if (err < 0) {
    fd = err;
    close(fd);
  }

out:
  pthread_rwlock_unlock(&proc.fileinfo.fdtable_lock);
  return fd;
}

int
user_open(const char *path, int l_flags, int mode)
{
  return user_openat(LINUX_AT_FDCWD, path, l_flags, mode);
}

int
do_close(struct fdtable *table, int fd)
{
  if (fd < table->start || fd >= table->start + table->size) {
    return -LINUX_EBADF;
  }
  if (!test_fdbit(table, table->open_fds, fd)) {
    return -LINUX_EBADF;
  }
  struct file *file = &table->files[fd - table->start];
  assert(file);
  int n = file->ops->close(file);
  clear_fdbit(table, table->open_fds, fd);
  clear_fdbit(table, table->cloexec_fds, fd);
  return n;
}

int
user_close(int fd)
{
  pthread_rwlock_wrlock(&proc.fileinfo.fdtable_lock);
  int ret = do_close(&proc.fileinfo.fdtable, fd);
  pthread_rwlock_unlock(&proc.fileinfo.fdtable_lock);
  return ret;
}

int
vkern_close(int fd)
{
  pthread_rwlock_wrlock(&proc.fileinfo.fdtable_lock);
  int n = do_close(&proc.fileinfo.vkern_fdtable, fd);
  pthread_rwlock_unlock(&proc.fileinfo.fdtable_lock);
  return n;
}

void
close_cloexec()
{
  pthread_rwlock_wrlock(&proc.fileinfo.fdtable_lock);
  struct fdtable *fdtable = &proc.fileinfo.fdtable;
  for (int i = 0; i < fdtable->size / 64; i++) {
    for (int j = 0; j < 64; j++) {
      if (fdtable->cloexec_fds[i] == 0) {
        break;
      }
      if ((fdtable->cloexec_fds[i] >> j) & 1) {
        do_close(fdtable, j + i * 64);
      }
    }
  }
  pthread_rwlock_unlock(&proc.fileinfo.fdtable_lock);
}

DEFINE_SYSCALL(openat, int, dirfd, gstr_t, path_ptr, int, flags, int, mode)
{
  char path[LINUX_PATH_MAX];
  strncpy_from_user(path, path_ptr, sizeof path);
  return user_openat(dirfd, path, flags, mode);
}

DEFINE_SYSCALL(open, gstr_t, path_ptr, int, flags, int, mode)
{
  return sys_openat(LINUX_AT_FDCWD, path_ptr, flags, mode);
}

DEFINE_SYSCALL(close, int, fd)
{
  return user_close(fd);
}

DEFINE_SYSCALL(newfstatat, int, dirfd, gstr_t, path_ptr, gaddr_t, st_ptr, int, flags)
{
  char pathname[LINUX_PATH_MAX];
  strncpy_from_user(pathname, path_ptr, sizeof pathname);
  if (flags & ~(LINUX_AT_SYMLINK_NOFOLLOW)) {
    return -LINUX_EINVAL;
  }
  int grab_flags = flags & LINUX_AT_SYMLINK_NOFOLLOW ? LOOKUP_NOFOLLOW : 0;
  struct path path;
  int r = vfs_grab_dir(dirfd, pathname, grab_flags, &path);
  if (r < 0) {
    return r;
  }
  struct l_newstat st;
  r = path.fs->ops->fstatat(path.fs, path.dir, path.subpath, &st, flags);
  vfs_ungrab_dir(&path);
  if (0 <= r && copy_to_user(st_ptr, &st, sizeof st))
    return -LINUX_EFAULT;
  return r;
}

DEFINE_SYSCALL(stat, gstr_t, path, gaddr_t, st)
{
  return sys_newfstatat(LINUX_AT_FDCWD, path, st, 0);
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
  if (strncpy_from_user(path, path_ptr, sizeof path) < 0)
    return -LINUX_EFAULT;
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
