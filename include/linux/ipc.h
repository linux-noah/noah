/*-
 * Copyright (c) 2016 Yuichi Nishiwaki
 * Copyright (c) 2000 Marcel Moolenaar
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
 *    derived from this software without specific prior written permission.
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

#ifndef _LINUX_IPC_H_
#define _LINUX_IPC_H_

/*
 * SystemV IPC defines
 */
#define	LINUX_SEMOP		1
#define	LINUX_SEMGET		2
#define	LINUX_SEMCTL		3
#define	LINUX_MSGSND		11
#define	LINUX_MSGRCV		12
#define	LINUX_MSGGET		13
#define	LINUX_MSGCTL		14
#define	LINUX_SHMAT		21
#define	LINUX_SHMDT		22
#define	LINUX_SHMGET		23
#define	LINUX_SHMCTL		24

#define	LINUX_IPC_RMID		0
#define	LINUX_IPC_SET		1
#define	LINUX_IPC_STAT		2
#define	LINUX_IPC_INFO		3

#define	LINUX_MSG_INFO	12

#define	LINUX_SHM_LOCK		11
#define	LINUX_SHM_UNLOCK	12
#define	LINUX_SHM_STAT		13
#define	LINUX_SHM_INFO		14

#define	LINUX_SHM_RDONLY	0x1000
#define	LINUX_SHM_RND		0x2000
#define	LINUX_SHM_REMAP		0x4000

/* semctl commands */
#define	LINUX_GETPID		11
#define	LINUX_GETVAL		12
#define	LINUX_GETALL		13
#define	LINUX_GETNCNT		14
#define	LINUX_GETZCNT		15
#define	LINUX_SETVAL		16
#define	LINUX_SETALL		17
#define	LINUX_SEM_STAT		18
#define	LINUX_SEM_INFO		19

/*
 * Version flags for semctl, msgctl, and shmctl commands
 * These are passed as bitflags or-ed with the actual command
 */
#define	LINUX_IPC_OLD	0	/* Old version (no 32-bit UID support on many
				   architectures) */
#define	LINUX_IPC_64	0x0100	/* New version (support 32-bit UIDs, bigger
				   message sizes, etc. */

union l_semun {
	l_int		val;
	l_uintptr_t	buf;
	l_uintptr_t	array;
	l_uintptr_t	__buf;
	l_uintptr_t	__pad;
};

struct l_ipc_perm {
	l_key_t		key;
	l_uid_t		uid;
	l_gid_t		gid;
	l_uid_t		cuid;
	l_gid_t		cgid;
	l_ushort	mode;
	l_ushort	seq;
};

#endif /* _LINUX_IPC_H_ */
