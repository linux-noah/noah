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
to_host_path(const char *path)
{
  if (path[0] == '/') {
    int len = snprintf(NULL, 0, "%s/%s", proc.root, path);
    char *mnt_path = malloc(len + 1);
    snprintf(mnt_path, len + 1, "%s/%s", proc.root, path);
    //if (access(mnt_path, F_OK) == 0) {
      return mnt_path;
    //}
    //free(mnt_path);
  }
  return strdup(path);
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

int
linux_to_darwin_o_flags(int l_flags)
{
  int ret = 0;
  switch (l_flags & LINUX_O_ACCMODE) {
  case LINUX_O_WRONLY:
    ret |= O_WRONLY;
    break;
  case LINUX_O_RDWR:
    ret |= O_RDWR;
    break;
  default:                      /* Note: LINUX_O_RDONLY == 0 */
    ret |= O_RDONLY;
  }
  if (l_flags & LINUX_O_NDELAY)
    ret |= O_NONBLOCK;
  if (l_flags & LINUX_O_APPEND)
    ret |= O_APPEND;
  if (l_flags & LINUX_O_SYNC)
    ret |= O_FSYNC;
  if (l_flags & LINUX_O_NONBLOCK)
    ret |= O_NONBLOCK;
  if (l_flags & LINUX_FASYNC)
    ret |= O_ASYNC;
  if (l_flags & LINUX_O_CREAT)
    ret |= O_CREAT;
  if (l_flags & LINUX_O_TRUNC)
    ret |= O_TRUNC;
  if (l_flags & LINUX_O_EXCL)
    ret |= O_EXCL;
  if (l_flags & LINUX_O_NOCTTY)
    ret |= O_NOCTTY;
  /* if (l_flags & LINUX_O_DIRECT) */
  /*   ret |= O_DIRECT; */
  if (l_flags & LINUX_O_NOFOLLOW)
    ret |= O_NOFOLLOW;
  if (l_flags & LINUX_O_DIRECTORY)
    ret |= O_DIRECTORY;

  return ret;
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

// Linux implementation of faccessat actually does not have "flags"
DEFINE_SYSCALL(faccessat, int, dirfd, gstr_t, path, int, mode)
{
  char *host_path = to_host_path(guest_to_host(path));

  int ret = syswrap(faccessat(dirfd, host_path, mode, 0));
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

/*
 * termio related ioctls
 */

struct linux_termio {
	unsigned short c_iflag;
	unsigned short c_oflag;
	unsigned short c_cflag;
	unsigned short c_lflag;
	unsigned char c_line;
	unsigned char c_cc[LINUX_NCC];
};

struct linux_termios {
	unsigned int c_iflag;
	unsigned int c_oflag;
	unsigned int c_cflag;
	unsigned int c_lflag;
	unsigned char c_line;
	unsigned char c_cc[LINUX_NCCS];
};

struct linux_winsize {
	unsigned short ws_row, ws_col;
	unsigned short ws_xpixel, ws_ypixel;
};

struct speedtab {
	int sp_speed;			/* Speed. */
	int sp_code;			/* Code. */
};

static struct speedtab sptab[] = {
	{ B0, LINUX_B0 }, { B50, LINUX_B50 },
	{ B75, LINUX_B75 }, { B110, LINUX_B110 },
	{ B134, LINUX_B134 }, { B150, LINUX_B150 },
	{ B200, LINUX_B200 }, { B300, LINUX_B300 },
	{ B600, LINUX_B600 }, { B1200, LINUX_B1200 },
	{ B1800, LINUX_B1800 }, { B2400, LINUX_B2400 },
	{ B4800, LINUX_B4800 }, { B9600, LINUX_B9600 },
	{ B19200, LINUX_B19200 }, { B38400, LINUX_B38400 },
	{ B57600, LINUX_B57600 }, { B115200, LINUX_B115200 },
	{-1, -1 }
};

static int
darwin_to_linux_speed(int speed, struct speedtab *table)
{
	for ( ; table->sp_speed != -1; table++)
		if (table->sp_speed == speed)
			return (table->sp_code);
	return -1;
}

void
darwin_to_linux_termios(struct termios *bios, struct linux_termios *lios)
{
	int i;

	lios->c_iflag = 0;
	if (bios->c_iflag & IGNBRK)
		lios->c_iflag |= LINUX_IGNBRK;
	if (bios->c_iflag & BRKINT)
		lios->c_iflag |= LINUX_BRKINT;
	if (bios->c_iflag & IGNPAR)
		lios->c_iflag |= LINUX_IGNPAR;
	if (bios->c_iflag & PARMRK)
		lios->c_iflag |= LINUX_PARMRK;
	if (bios->c_iflag & INPCK)
		lios->c_iflag |= LINUX_INPCK;
	if (bios->c_iflag & ISTRIP)
		lios->c_iflag |= LINUX_ISTRIP;
	if (bios->c_iflag & INLCR)
		lios->c_iflag |= LINUX_INLCR;
	if (bios->c_iflag & IGNCR)
		lios->c_iflag |= LINUX_IGNCR;
	if (bios->c_iflag & ICRNL)
		lios->c_iflag |= LINUX_ICRNL;
	if (bios->c_iflag & IXON)
		lios->c_iflag |= LINUX_IXON;
	if (bios->c_iflag & IXANY)
		lios->c_iflag |= LINUX_IXANY;
	if (bios->c_iflag & IXOFF)
		lios->c_iflag |= LINUX_IXOFF;
	if (bios->c_iflag & IMAXBEL)
		lios->c_iflag |= LINUX_IMAXBEL;

	lios->c_oflag = 0;
	if (bios->c_oflag & OPOST)
		lios->c_oflag |= LINUX_OPOST;
	if (bios->c_oflag & ONLCR)
		lios->c_oflag |= LINUX_ONLCR;
	if (bios->c_oflag & TAB3)
		lios->c_oflag |= LINUX_XTABS;

	lios->c_cflag = darwin_to_linux_speed(bios->c_ispeed, sptab);
	lios->c_cflag |= (bios->c_cflag & CSIZE) >> 4;
	if (bios->c_cflag & CSTOPB)
		lios->c_cflag |= LINUX_CSTOPB;
	if (bios->c_cflag & CREAD)
		lios->c_cflag |= LINUX_CREAD;
	if (bios->c_cflag & PARENB)
		lios->c_cflag |= LINUX_PARENB;
	if (bios->c_cflag & PARODD)
		lios->c_cflag |= LINUX_PARODD;
	if (bios->c_cflag & HUPCL)
		lios->c_cflag |= LINUX_HUPCL;
	if (bios->c_cflag & CLOCAL)
		lios->c_cflag |= LINUX_CLOCAL;
	if (bios->c_cflag & CRTSCTS)
		lios->c_cflag |= LINUX_CRTSCTS;

	lios->c_lflag = 0;
	if (bios->c_lflag & ISIG)
		lios->c_lflag |= LINUX_ISIG;
	if (bios->c_lflag & ICANON)
		lios->c_lflag |= LINUX_ICANON;
	if (bios->c_lflag & ECHO)
		lios->c_lflag |= LINUX_ECHO;
	if (bios->c_lflag & ECHOE)
		lios->c_lflag |= LINUX_ECHOE;
	if (bios->c_lflag & ECHOK)
		lios->c_lflag |= LINUX_ECHOK;
	if (bios->c_lflag & ECHONL)
		lios->c_lflag |= LINUX_ECHONL;
	if (bios->c_lflag & NOFLSH)
		lios->c_lflag |= LINUX_NOFLSH;
	if (bios->c_lflag & TOSTOP)
		lios->c_lflag |= LINUX_TOSTOP;
	if (bios->c_lflag & ECHOCTL)
		lios->c_lflag |= LINUX_ECHOCTL;
	if (bios->c_lflag & ECHOPRT)
		lios->c_lflag |= LINUX_ECHOPRT;
	if (bios->c_lflag & ECHOKE)
		lios->c_lflag |= LINUX_ECHOKE;
	if (bios->c_lflag & FLUSHO)
		lios->c_lflag |= LINUX_FLUSHO;
	if (bios->c_lflag & PENDIN)
		lios->c_lflag |= LINUX_PENDIN;
	if (bios->c_lflag & IEXTEN)
		lios->c_lflag |= LINUX_IEXTEN;

	for (i=0; i<LINUX_NCCS; i++)
		lios->c_cc[i] = LINUX_POSIX_VDISABLE;
	lios->c_cc[LINUX_VINTR] = bios->c_cc[VINTR];
	lios->c_cc[LINUX_VQUIT] = bios->c_cc[VQUIT];
	lios->c_cc[LINUX_VERASE] = bios->c_cc[VERASE];
	lios->c_cc[LINUX_VKILL] = bios->c_cc[VKILL];
	lios->c_cc[LINUX_VEOF] = bios->c_cc[VEOF];
	lios->c_cc[LINUX_VEOL] = bios->c_cc[VEOL];
	lios->c_cc[LINUX_VMIN] = bios->c_cc[VMIN];
	lios->c_cc[LINUX_VTIME] = bios->c_cc[VTIME];
	lios->c_cc[LINUX_VEOL2] = bios->c_cc[VEOL2];
	lios->c_cc[LINUX_VSUSP] = bios->c_cc[VSUSP];
	lios->c_cc[LINUX_VSTART] = bios->c_cc[VSTART];
	lios->c_cc[LINUX_VSTOP] = bios->c_cc[VSTOP];
	lios->c_cc[LINUX_VREPRINT] = bios->c_cc[VREPRINT];
	lios->c_cc[LINUX_VDISCARD] = bios->c_cc[VDISCARD];
	lios->c_cc[LINUX_VWERASE] = bios->c_cc[VWERASE];
	lios->c_cc[LINUX_VLNEXT] = bios->c_cc[VLNEXT];

	for (i=0; i<LINUX_NCCS; i++) {
		if (i != LINUX_VMIN && i != LINUX_VTIME &&
		    lios->c_cc[i] == _POSIX_VDISABLE)
			lios->c_cc[i] = LINUX_POSIX_VDISABLE;
	}
	lios->c_line = 0;
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
