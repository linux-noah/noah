/*-
 * Copyright (c) 2016 Yuichi Nishiwaki, Takaya Saeki
 * Copyright (c) 2015 Dmitry Chagin
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef NOAH_LINUX_SIGNAL_H
#define NOAH_LINUX_SIGNAL_H

#include "linux/common.h"
#include "linux/const.h"
#include "types.h"
#include <signal.h>

/* signaling */
#define LINUX_STSIGNUM(_)\
	DECL_LINUX(_,SIGHUP,		1)\
	DECL_LINUX(_,SIGINT,		2)\
	DECL_LINUX(_,SIGQUIT,		3)\
	DECL_LINUX(_,SIGILL,		4)\
	DECL_LINUX(_,SIGTRAP,		5)\
	DECL_LINUX(_,SIGABRT,		6)\
	DECL_ALIAS(_,SIGIOT,		LINUX_SIGABRT)\
	DECL_LINUX(_,SIGBUS,		7)\
	DECL_LINUX(_,SIGFPE,		8)\
	DECL_LINUX(_,SIGKILL,		9)\
	DECL_LINUX(_,SIGUSR1,		10)\
	DECL_LINUX(_,SIGSEGV,		11)\
	DECL_LINUX(_,SIGUSR2,		12)\
	DECL_LINUX(_,SIGPIPE,		13)\
	DECL_LINUX(_,SIGALRM,		14)\
	DECL_LINUX(_,SIGTERM,		15)\
	DECL_LINUX(_,SIGSTKFLT,		16, LINUX_SPECIFIC)/* On x86, SIGSTKFLT is never used */\
	DECL_LINUX(_,SIGCHLD,		17)\
	DECL_LINUX(_,SIGCONT,		18)\
	DECL_LINUX(_,SIGSTOP,		19)\
	DECL_LINUX(_,SIGTSTP,		20)\
	DECL_LINUX(_,SIGTTIN,		21)\
	DECL_LINUX(_,SIGTTOU,		22)\
	DECL_LINUX(_,SIGURG,		23)\
	DECL_LINUX(_,SIGXCPU,		24)\
	DECL_LINUX(_,SIGXFSZ,		25)\
	DECL_LINUX(_,SIGVTALRM,		26)\
	DECL_LINUX(_,SIGPROF,		27)\
	DECL_LINUX(_,SIGWINCH,		28)\
	DECL_LINUX(_,SIGIO,		29)\
	DECL_ALIAS(_,SIGPOLL,		LINUX_SIGIO)\
	DECL_LINUX(_,SIGPWR,		30, LINUX_SPECIFIC) /* Noah vkernel wll never send SIGPWR */ \
	DECL_LINUX(_,SIGSYS,		31)\

#define LINUX_SIGTBLSZ 31
#define LINUX_SIGRTMIN 32
#define LINUX_SIGRTMAX 64

DECLARE_CENUM(signum, LINUX_STSIGNUM);
DECLARE_CMAP_FUNC(darwin_to_linux, signum, LINUX_STSIGNUM);
DECLARE_CMAP_FUNC(linux_to_darwin, signum, LINUX_STSIGNUM);
DECLARE_CSTR_FUNC(signum, LINUX_STSIGNUM);


#define LINUX_NSIG              64

/* sigaction flags */
#define	LINUX_SA_NOCLDSTOP	0x00000001
#define	LINUX_SA_NOCLDWAIT	0x00000002
#define	LINUX_SA_SIGINFO	0x00000004
#define	LINUX_SA_RESTORER	0x04000000
#define	LINUX_SA_ONSTACK	0x08000000
#define	LINUX_SA_RESTART	0x10000000
#define	LINUX_SA_INTERRUPT	0x20000000
#define	LINUX_SA_NOMASK		0x40000000
#define	LINUX_SA_ONESHOT	0x80000000

/* sigset */
typedef struct {
  uint64_t	__mask;
} l_sigset_t;

void linux_to_darwin_sigset(l_sigset_t *, sigset_t *);
void darwin_to_linux_sigset(sigset_t *, l_sigset_t *);

/* primitives to manipulate sigset_t */
#define	LINUX_SIGEMPTYSET(setp)		((setp)->__mask = 0)
#define	LINUX_SIGISMEMBER(setp, sig)	(1UL & ((setp)->__mask >> ((sig) - 1)))
#define	LINUX_SIGADDSET(setp, sig)	((setp)->__mask |= (1UL << ((sig) - 1)))
#define	LINUX_SIGDELSET(setp, sig)	((setp)->__mask &= ~(1UL << ((sig) - 1)))

#define	LINUX_SIGSET_ADD(setp, masksetp)	((setp)->__mask |= ((masksetp)->__mask))
#define	LINUX_SIGSET_DEL(setp, masksetp)	((setp)->__mask &= ~((masksetp)->__mask))
#define	LINUX_SIGSET_SET(setp, masksetp)	((setp)->__mask = (masksetp)->__mask)

#define LINUX_SIGSET_TO_UI64(setp)      ((setp)->__mask)

/* sigprocmask actions */
#define	LINUX_SIG_BLOCK		0
#define	LINUX_SIG_UNBLOCK	1
#define	LINUX_SIG_SETMASK	2

/* sigaltstack */
#define	LINUX_MINSIGSTKSZ	2048

typedef gaddr_t	l_handler_t;

typedef struct {
  l_handler_t	lsa_handler;
  l_ulong	lsa_flags;
  l_uintptr_t	lsa_restorer;
  l_sigset_t	lsa_mask;
} l_sigaction_t;

#define LINUX_SIG_DFL ((l_handler_t)0)
#define LINUX_SIG_IGN ((l_handler_t)1)
#define LINUX_SIG_ERR ((l_handler_t)-1)

void linux_to_darwin_sigaction(l_sigaction_t *, struct sigaction *, void *);
void darwin_to_linux_sigaction(struct sigaction *, l_sigaction_t *, gaddr_t);

typedef struct {
  l_uintptr_t	ss_sp;
  l_int		ss_flags;
  l_size_t	ss_size;
} l_stack_t;

#define LINUX_SS_ONSTACK      1
#define LINUX_SS_DISABLE      2
#define LINUX_SS_AUTODISARM   (1U << 31)

struct l_fpstate {
  u_int16_t cwd;
  u_int16_t swd;
  u_int16_t twd;
  u_int16_t fop;
  u_int64_t rip;
  u_int64_t rdp;
  u_int32_t mxcsr;
  u_int32_t mxcsr_mask;
  u_int32_t st_space[32];
  u_int32_t xmm_space[64];
  u_int32_t reserved2[24];
};

struct l_sigcontext {
  l_ulong		sc_r8;
  l_ulong		sc_r9;
  l_ulong		sc_r10;
  l_ulong		sc_r11;
  l_ulong		sc_r12;
  l_ulong		sc_r13;
  l_ulong		sc_r14;
  l_ulong		sc_r15;
  l_ulong		sc_rdi;
  l_ulong		sc_rsi;
  l_ulong		sc_rbp;
  l_ulong		sc_rbx;
  l_ulong		sc_rdx;
  l_ulong		sc_rax;
  l_ulong		sc_rcx;
  l_ulong		sc_rsp;
  l_ulong		sc_rip;
  l_ulong		sc_rflags;
  l_ushort		sc_cs;
  l_ushort		sc_gs;
  l_ushort		sc_fs;
  union {
    l_ushort		sc_ss;
    l_ushort		sc___pad0;
  };
  l_ulong		sc_err;
  l_ulong		sc_trapno;
  l_sigset_t		sc_mask;
  l_ulong		sc_cr2;
  struct l_fpstate	*sc_fpstate;
  l_ulong		sc_reserved1[8];
};

struct l_ucontext {
  l_ulong	uc_flags;
  l_uintptr_t	uc_link;
  l_stack_t	uc_stack;
  struct l_sigcontext	uc_mcontext;
  l_sigset_t	uc_sigmask;
};

#define LINUX_UC_FP_XSTATE	0x1
#define LINUX_UC_SIGCONTEXT_SS	0x2
#define LINUX_UC_STRICT_RESTORE_SS	0x4

#define LINUX_SI_PREAMBLE_SIZE	(4 * sizeof(int))
#define	LINUX_SI_MAX_SIZE	128
#define	LINUX_SI_PAD_SIZE	((LINUX_SI_MAX_SIZE - \
				    LINUX_SI_PREAMBLE_SIZE) / sizeof(l_int))
typedef union l_sigval {
  l_int		sival_int;
  l_uintptr_t	sival_ptr;
} l_sigval_t;

typedef struct l_siginfo {
  l_int		lsi_signo;
  l_int		lsi_errno;
  l_int		lsi_code;
  union {
    l_int	_pad[LINUX_SI_PAD_SIZE];

    struct {
      l_pid_t		_pid;
      l_uid_t		_uid;
    } _kill;

    struct {
      l_timer_t	_tid;
      l_int		_overrun;
      char		_pad[sizeof(l_uid_t) - sizeof(int)];
      union l_sigval	_sigval;
      l_uint		_sys_private;
    } _timer;

    struct {
      l_pid_t		_pid;		/* sender's pid */
      l_uid_t		_uid;		/* sender's uid */
      union l_sigval	_sigval;
    } _rt;

    struct {
      l_pid_t		_pid;		/* which child */
      l_uid_t		_uid;		/* sender's uid */
      l_int		_status;	/* exit code */
      l_clock_t	_utime;
      l_clock_t	_stime;
    } _sigchld;

    struct {
      l_uintptr_t	_addr;	/* Faulting insn/memory ref. */
    } _sigfault;

    struct {
      l_long		_band;	/* POLL_IN,POLL_OUT,POLL_MSG */
      l_int		_fd;
    } _sigpoll;
  } _sifields;
} l_siginfo_t;

#define	lsi_pid		_sifields._kill._pid
#define	lsi_uid		_sifields._kill._uid
#define	lsi_tid		_sifields._timer._tid
#define	lsi_overrun	_sifields._timer._overrun
#define	lsi_sys_private	_sifields._timer._sys_private
#define	lsi_status	_sifields._sigchld._status
#define	lsi_utime	_sifields._sigchld._utime
#define	lsi_stime	_sifields._sigchld._stime
#define	lsi_value	_sifields._rt._sigval
#define	lsi_int		_sifields._rt._sigval.sival_int
#define	lsi_ptr		_sifields._rt._sigval.sival_ptr
#define	lsi_addr	_sifields._sigfault._addr
#define	lsi_band	_sifields._sigpoll._band
#define	lsi_fd		_sifields._sigpoll._fd

/*
 * We make l_rt_sigframe exactly the same as that of Linux.
 * This is a different choice of FreeBSD's Linuxulator.
 */

struct l_rt_sigframe {
  l_ucharptr_t sf_pretcode;
  struct l_ucontext	sf_sc;
  struct l_siginfo	sf_si;
  /* fp state should follow */
};

#endif
