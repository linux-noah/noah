/*-
 * Copyright (c) 2016 Yuichi Nishiwaki
 * Copyright (c) 2015 Dmitry Chagin
 * Copyright (c) 2013 Dmitry Chagin
 * Copyright (c) 2002 Doug Rabson
 * Copyright (c) 1994-1996 Søren Schmidt
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
 *
 * $FreeBSD$
 */

#ifndef NOAH_LINUX_COMMON_H
#define NOAH_LINUX_COMMON_H

#include <stdint.h>

#define __packed __attribute__((packed))

typedef unsigned char u_char;
typedef uint16_t u_int16_t;
typedef uint32_t u_int32_t;
typedef uint64_t u_int64_t;

/*
 * Provide a separate set of types for the Linux types.
 */
typedef int32_t		l_int;
typedef int64_t		l_long;
typedef int16_t		l_short;
typedef uint32_t	l_uint;
typedef uint64_t	l_ulong;
typedef uint16_t	l_ushort;

typedef l_ulong		l_uintptr_t;
typedef l_ulong		l_ucharptr_t;

/**
// The following typedefs are generated automatially by:
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <mqueue.h>
#include <stdio.h>

#define ISUNSIGNED(type) ((type)0 - 1 > 0)
#define P(type) do {                                    \
  char *ty = 0;                                         \
  switch (sizeof(type)) {                               \
  case 2: ty = "short"; break;                          \
  case 4: ty = "int"; break;                            \
  case 8: ty = "long"; break;                           \
  }                                                     \
  printf("typedef l_%s%s\t\tl_%s;\n", (ISUNSIGNED(type) ? "u" : ""), ty, #type);  \
} while (0)

int main() {
  P(clock_t);
  P(daddr_t);
  P(dev_t);
  P(gid_t);
  P(uid_t);
  P(ino_t);
  P(key_t);
  P(loff_t);
  P(mode_t);
  P(off_t);
  P(pid_t);
  P(size_t);
  P(ssize_t);
  P(suseconds_t);
  P(time_t);
  P(timer_t);
  P(mqd_t);
  P(socklen_t);
  P(fd_mask);
}
 */
typedef l_long		l_clock_t;
typedef l_int		l_daddr_t;
typedef l_ulong		l_dev_t;
typedef l_uint		l_gid_t;
typedef l_uint		l_uid_t;
typedef l_ulong		l_ino_t;
typedef l_int		l_key_t;
typedef l_long		l_loff_t;
typedef l_uint		l_mode_t;
typedef l_long		l_off_t;
typedef l_int		l_pid_t;
typedef l_ulong		l_size_t;
typedef l_long		l_ssize_t;
typedef l_long		l_suseconds_t;
typedef l_long		l_time_t;
typedef l_ulong		l_timer_t;
typedef l_int		l_mqd_t;
typedef l_uint		l_socklen_t;
typedef l_long		l_fd_mask;

#define	LINUX_NAME_MAX		255

#endif
