/* npth.h - a lightweight implementation of pth over pthread.
            Configured for: x86_64-unknown-linux-gnu.
   Copyright (C) 2011, 2012, 2015 g10 Code GmbH

   This file is part of NPTH.

   NPTH is free software; you can redistribute it and/or modify it
   under the terms of either

   - the GNU Lesser General Public License as published by the Free
   Software Foundation; either version 3 of the License, or (at
   your option) any later version.

   or

   - the GNU General Public License as published by the Free
   Software Foundation; either version 2 of the License, or (at
   your option) any later version.

   or both in parallel, as here.

   NPTH is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copies of the GNU General Public License
   and the GNU Lesser General Public License along with this program;
   if not, see <http://www.gnu.org/licenses/>.  */

/* Changes to Pth:

   Return value and arguments follow strictly the pthread format:

   * Return the error number instead of setting errno,

   * have timedlock function instead of extra event argument,

   * have trylock function instead of extra event argument.  Can't mix
   timed and try.

   * No _new functions.  Use _init functions instead.

   * Attributes are set by specific instead of generic getter/setter
   functions.

   Offers replacement functions for sendmsg and recvmsg.  */

#ifndef _NPTH_H
#define _NPTH_H

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>
#include <sys/socket.h>
#define _npth_socklen_t socklen_t
#include <sys/select.h>
#include <signal.h>

#include <pthread.h>

#ifdef __ANDROID__
#include <android/api-level.h>
#if __ANDROID_API__ < 9
/* Android 8 and earlier are missing rwlocks.  We punt to mutexes in
   that case.  */
#define _NPTH_NO_RWLOCK 1
#endif
#endif

#ifdef __cplusplus
extern "C" {
#if 0 /* (Keep Emacsens' auto-indent happy.) */
}
#endif
#endif



/* Global Library Management */

#define npth_t pthread_t

/* Initialize the library and convert current thread to main thread.
   Must be first npth function called in a process.  Returns error
   number on error and 0 on success.  */

int npth_init(void);

/* Not needed.  */
/* pth_kill, pth_ctrl, pth_version */


/* Thread Attribute Handling */

/* Can't do that.  */
/* pth_attr_of */

#define npth_attr_t pthread_attr_t
#define npth_attr_init pthread_attr_init
#define npth_attr_destroy pthread_attr_destroy
#define NPTH_CREATE_JOINABLE PTHREAD_CREATE_JOINABLE
#define NPTH_CREATE_DETACHED PTHREAD_CREATE_DETACHED
#define npth_attr_getdetachstate pthread_attr_getdetachstate
#define npth_attr_setdetachstate pthread_attr_setdetachstate
int npth_getname_np (npth_t target_thread, char *buf, size_t buflen);
int npth_setname_np (npth_t target_thread, const char *name);


/* Thread Control */
int npth_create(npth_t *thread, const npth_attr_t *attr,
		void *(*start_routine) (void *), void *arg);


/* The Pth version of pth_once supports passing an argument, the
   pthread version does not.  We would have to reimplement the whole
   feature with a global table.  Not needed.  */
/* pth_once */

#define npth_self pthread_self

/* No can do! */
/* pth_suspend, pth_resume */

/* Yield is considered harmful and should never be used in high-level
   applications.  Use a condition instead to wait for a specific event
   to happen, or, as a last resort, use npth_usleep to back off a hard
   busy wait.  */
/* pth_yield */

/* Not needed.  */
/* pth_nap */

/* pth_wait, pth_cancel, pth_abort, pth_raise */

int npth_join(npth_t thread, void **retval);
#define npth_detach pthread_detach

void npth_exit(void *retval);


/* Utilities */

/* pth_fdmode, pth_time, pth_timeout, pth_sfiodisc */


/* Cancellation Management */

/* Not needed.  */
/* pth_cancel_state. npth_cancel_point */


/* Event Handling */

/* No equivalent in pthread.  */
/* pth_event, pth_event_typeof, pth_event_extract, pth_event_concat, pth_event_isolate,
   pth_event_walk, pth_event_status, pth_event_free */


/* Key-Based Storage */

#define npth_key_t pthread_key_t
#define npth_key_create pthread_key_create
#define npth_key_delete pthread_key_delete
#define npth_setspecific pthread_setspecific
#define npth_getspecific pthread_getspecific


/* Message Port Communication */

/* No equivalent in pthread.  */
/* pth_msgport_create, pth_msgport_destroy, pth_msgport_find,
   pth_msgport_pending, pth_msgport_put, pth_msgport_get,
   pth_msgport_reply. */


/* Thread Cleanups */

/* Not needed.  */
/* pth_cleanup_push, pth_cleanup_pop */


/* Process Forking */

/* POSIX only supports a global atfork handler.  So, to implement
   per-thread handlers like in Pth, we would need to keep the data in
   thread local storage.  But, neither pthread_self nor
   pthread_getspecific are standardized as async-signal-safe (what a
   joke!), and __thread is an ELF extension.  Still, using
   pthread_self and pthread_getspecific is probably portable
   enough to implement the atfork handlers, if required.

   pth_fork is only required because fork() is not pth aware.  fork()
   is pthread aware though, and already only creates a single thread
   in the child process.  */
/* pth_atfork_push, pth_atfork_pop, pth_fork */


/* Synchronization */

#define npth_mutexattr_t pthread_mutexattr_t
#define npth_mutexattr_init pthread_mutexattr_init
#define npth_mutexattr_destroy pthread_mutexattr_destroy
#define npth_mutexattr_settype pthread_mutexattr_settype
#define npth_mutexattr_gettype pthread_mutexattr_gettype
#define NPTH_MUTEX_NORMAL PTHREAD_MUTEX_NORMAL
#define NPTH_MUTEX_RECURSIVE PTHREAD_MUTEX_RECURSIVE
#define NPTH_MUTEX_ERRORCHECK PTHREAD_MUTEX_ERRORCHECK
#define NPTH_MUTEX_DEFAULT PTHREAD_MUTEX_DEFAULT

#define npth_mutex_t pthread_mutex_t
#define NPTH_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
#define NPTH_RECURSIVE_MUTEX_INITIALIZER_NP \
  PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
#define NPTH_ERRORCHECK_MUTEX_INITIALIZER_NP \
  PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP
#define npth_mutex_init pthread_mutex_init
#define npth_mutex_destroy pthread_mutex_destroy
#define npth_mutex_trylock pthread_mutex_trylock

int npth_mutex_lock(npth_mutex_t *mutex);
int npth_mutex_timedlock(npth_mutex_t *mutex, const struct timespec *abstime);

#define npth_mutex_unlock pthread_mutex_unlock

#ifdef _NPTH_NO_RWLOCK

typedef int npth_rwlockattr_t;
#define npth_rwlockattr_init(attr)
#define npth_rwlockattr_destroy(attr)
#define npth_rwlockattr_gettype_np(attr,kind)
#define npth_rwlockattr_settype_np(attr,kind)
#define NPTH_RWLOCK_PREFER_READER_NP 0
#define NPTH_RWLOCK_PREFER_WRITER_NP 0
#define NPTH_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP 0
#define NPTH_RWLOCK_DEFAULT_NP 0
#define NPTH_RWLOCK_INITIALIZER NPTH_MUTEX_INITIALIZER
#define NPTH_RWLOCK_WRITER_NONRECURSIVE_INITIALIZER_NP NPTH_MUTEX_INITIALIZER
typedef npth_mutex_t npth_rwlock_t;
#define npth_rwlock_init(rwlock,attr) npth_mutex_init(rwlock,0)
#define npth_rwlock_destroy npth_mutex_destroy
#define npth_rwlock_tryrdlock npth_mutex_trylock
#define npth_rwlock_rdlock npth_mutex_lock
#define npth_rwlock_trywrlock npth_mutex_trylock
#define npth_rwlock_timedrdlock npth_mutex_timedlock
#define npth_rwlock_wrlock npth_mutex_lock
#define npth_rwlock_rdlock npth_mutex_lock
#define npth_rwlock_timedwrlock npth_mutex_timedlock
#define npth_rwlock_unlock npth_mutex_unlock

#else /* _NPTH_NO_RWLOCK */

#define npth_rwlockattr_t pthread_rwlockattr_t
#define npth_rwlockattr_init pthread_rwlockattr_init
#define npth_rwlockattr_destroy pthread_rwlockattr_destroy
#define npth_rwlockattr_gettype_np pthread_rwlockattr_gettype_np
#define npth_rwlockattr_settype_np pthread_rwlockattr_settype_np
#define NPTH_RWLOCK_PREFER_READER_NP PTHREAD_RWLOCK_PREFER_READER_NP
/* Note: The prefer-writer setting is ineffective and the same as
   prefer-reader.  This is because reader locks are specified to be
   recursive, but for efficiency reasons we do not keep track of which
   threads already hold a reader lock.  For this reason, we can not
   prefer some reader locks over others, and thus a recursive reader
   lock could be stalled by a pending writer, leading to a dead
   lock.  */
#define NPTH_RWLOCK_PREFER_WRITER_NP PTHREAD_RWLOCK_PREFER_WRITER_NP
/* The non-recursive choise is a promise by the application that it
   does not lock the rwlock for reading recursively.  In this setting,
   writers are preferred, but note that recursive reader locking is
   prone to deadlocks in that case.  */
#define NPTH_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP \
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP
#define NPTH_RWLOCK_DEFAULT_NP PTHREAD_RWLOCK_DEFAULT_NP
#define NPTH_RWLOCK_INITIALIZER PTHREAD_RWLOCK_INITIALIZER
#define NPTH_RWLOCK_WRITER_NONRECURSIVE_INITIALIZER_NP \
  PTHREAD_RWLOCK_WRITER_NONRECURSIVE_INITIALIZER_NP

typedef pthread_rwlock_t npth_rwlock_t;
#define npth_rwlock_init pthread_rwlock_init
#define npth_rwlock_destroy pthread_rwlock_destroy
#define npth_rwlock_tryrdlock pthread_rwlock_tryrdlock

int npth_rwlock_rdlock (npth_rwlock_t *rwlock);

int npth_rwlock_timedrdlock (npth_rwlock_t *rwlock,
			     const struct timespec *abstime);

#define npth_rwlock_trywrlock pthread_rwlock_trywrlock
int npth_rwlock_wrlock (npth_rwlock_t *rwlock);
int npth_rwlock_timedwrlock (npth_rwlock_t *rwlock,
			     const struct timespec *abstime);
#define npth_rwlock_unlock  pthread_rwlock_unlock

#endif /* !_NPTH_NO_RWLOCK */


typedef pthread_cond_t npth_cond_t;
#define NPTH_COND_INITIALIZER PTHREAD_COND_INITIALIZER
/* For now, we don't support any cond attributes.  */
#define npth_cond_init pthread_cond_init
#define npth_cond_broadcast pthread_cond_broadcast
#define npth_cond_signal pthread_cond_signal
#define npth_cond_destroy pthread_cond_destroy
int npth_cond_wait(npth_cond_t *cond, npth_mutex_t *mutex);
int npth_cond_timedwait(npth_cond_t *cond, npth_mutex_t *mutex,
			const struct timespec *abstime);

/* Not needed.  */

/* pth_barrier_t, pth_barrier_init, pth_barrier_reach */


/* User-Space Context */

/* Can not be implemented.  */
/* pth_uctx_create, pth_uctx_make, pth_uctx_switch, pth_uctx_destroy */


/* Generalized POSIX Replacement API */

/* In general, we can not support these easily.  */
/* pth_sigwait_ev, pth_accept_ev, pth_connect_ev, pth_select_ev,
   pth_poll_ev, pth_read_ev, pth_readv_ev, pth_write_ev,
   pth_writev_ev, pth_recv_ev, pth_recvfrom_ev, pth_send_ev,
   pth_sendto_ev */


/* Standard POSIX Replacement API */

/* We will provide a more specific way to handle signals.  */
/* pth_sigmask, pth_sigwait */

/* Not needed.  */
/* pth_nanosleep, pth_system, pth_readv, pth_writev, pth_poll,
   pth_recv, pth_send, pth_recvfrom, pth_sendto */

int npth_usleep(unsigned int usec);
unsigned int npth_sleep(unsigned int sec);

pid_t npth_waitpid(pid_t pid, int *status, int options);
int npth_system(const char *cmd);
#define npth_sigmask pthread_sigmask
int npth_sigwait(const sigset_t *set, int *sig);

int npth_connect(int s, const struct sockaddr *addr, _npth_socklen_t addrlen);
int npth_accept(int s, struct sockaddr *addr, _npth_socklen_t *addrlen);
int npth_select(int nfd, fd_set *rfds, fd_set *wfds, fd_set *efds,
		struct timeval *timeout);
int npth_pselect(int nfd, fd_set *rfds, fd_set *wfds, fd_set *efds,
		 const struct timespec *timeout, const sigset_t *sigmask);
ssize_t npth_read(int fd, void *buf, size_t nbytes);
ssize_t npth_write(int fd, const void *buf, size_t nbytes);
int npth_recvmsg (int fd, struct msghdr *msg, int flags);
int npth_sendmsg (int fd, const struct msghdr *msg, int flags);

/* For anything not covered here, you can enter/leave manually at your
   own risk.  */
void npth_unprotect (void);
void npth_protect (void);


/* Because the timed functions work on timespec, we provide a clock
   interface for convenience and portability.  */
int npth_clock_gettime (struct timespec *tp);

/* CMP may be ==, < or >.  Do not use <= or >=.  */
#define npth_timercmp(t1, t2, cmp)					\
  (((t1)->tv_sec == (t2)->tv_sec) ?					\
   ((t1)->tv_nsec cmp (t2)->tv_nsec) :					\
   ((t1)->tv_sec cmp (t2)->tv_sec))
#define npth_timeradd(t1, t2, result)					\
  do {									\
    (result)->tv_sec = (t1)->tv_sec + (t2)->tv_sec;			\
    (result)->tv_nsec = (t1)->tv_nsec + (t2)->tv_nsec;			\
    if ((result)->tv_nsec >= 1000000000)				\
      {									\
	++(result)->tv_sec;						\
	(result)->tv_nsec -= 1000000000;				\
      }									\
  } while (0)
#define npth_timersub(t1, t2, result)					\
  do {									\
    (result)->tv_sec = (t1)->tv_sec - (t2)->tv_sec;			\
    (result)->tv_nsec = (t1)->tv_nsec - (t2)->tv_nsec;			\
    if ((result)->tv_nsec < 0) {					\
      --(result)->tv_sec;						\
      (result)->tv_nsec += 1000000000;					\
    }									\
  } while (0)


/* This is a support interface to make it easier to handle signals.

   The interfaces here support one (and only one) thread (here called
   "main thread") in the application to monitor several signals while
   selecting on filedescriptors.

   First, the main thread should call npth_sigev_init.  This
   initializes some global data structures used to record interesting
   and pending signals.

   Then, the main thread should call npth_sigev_add for every signal
   it is interested in observing, and finally npth_sigev_fini.  This
   will block the signal in the main threads sigmask.  Note that these
   signals should also be blocked in all other threads.  Since they
   are blocked in the main thread after calling npth_sigev_add, it is
   recommended to call npth_sigev_add in the main thread before
   creating any threads.

   The function npth_sigev_sigmask is a convenient function that
   returns the sigmask of the thread at time of npth_sigev_init, but
   with all registered signals unblocked.  It is recommended to do all
   other changes to the main thread's sigmask before calling
   npth_sigev_init, so that the return value of npth_sigev_sigmask can
   be used in the npth_pselect invocation.

   In any case, the main thread should invoke npth_pselect with a
   sigmask that has all signals that should be monitored unblocked.

   After npth_pselect returns, npth_sigev_get_pending can be called in
   a loop until it returns 0 to iterate over the list of pending
   signals.  Each time a signal is returned by that function, its
   status is reset to non-pending.  */

/* Start setting up signal event handling.  */
void npth_sigev_init (void);

/* Add signal SIGNUM to the list of watched signals.  */
void npth_sigev_add (int signum);

/* Finish the list of watched signals.  This starts to block them,
   too.  */
void npth_sigev_fini (void);

/* Get the sigmask as needed for pselect.  */
sigset_t *npth_sigev_sigmask (void);

/* Return the next signal event that occured.  Returns if none are
   left, 1 on success.  */
int npth_sigev_get_pending (int *r_signum);


#if 0 /* (Keep Emacsens' auto-indent happy.) */
{
#endif
#ifdef __cplusplus
}
#endif
#endif /*_NPTH_H*/
/*
Local Variables:
buffer-read-only: t
End:
*/
