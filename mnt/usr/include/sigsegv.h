/* Page fault handling library.
   Copyright (C) 1998-1999, 2002, 2004-2011  Bruno Haible <bruno@clisp.org>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

#ifndef _SIGSEGV_H
#define _SIGSEGV_H

#include <ucontext.h>

/* HAVE_SIGSEGV_RECOVERY
   is defined if the system supports catching SIGSEGV.  */
#if 1
# define HAVE_SIGSEGV_RECOVERY 1
#endif

/* HAVE_STACK_OVERFLOW_RECOVERY
   is defined if stack overflow can be caught.  */
#if 1
# define HAVE_STACK_OVERFLOW_RECOVERY 1
#endif


#ifdef __cplusplus
extern "C" {
#endif

#define LIBSIGSEGV_VERSION 0x020A    /* version number: (major<<8) + minor */
extern int libsigsegv_version;       /* Likewise */

/* -------------------------------------------------------------------------- */

/*
 * The mask of bits that are set to zero in a fault address that gets passed
 * to a global SIGSEGV handler.
 * On some platforms, the precise fault address is not known, only the memory
 * page into which the fault address falls. On these platforms,
 * SIGSEGV_FAULT_ADDRESS_ALIGNMENT is greater than 1.
 */
#if defined __linux__ && (defined __s390__ || defined __s390x__)
# define SIGSEGV_FAULT_ADDRESS_ALIGNMENT 0x1000UL
#else
# define SIGSEGV_FAULT_ADDRESS_ALIGNMENT 1UL
#endif

/*
 * The type of a global SIGSEGV handler.
 * The fault address, with the bits (SIGSEGV_FAULT_ADDRESS_ALIGNMENT - 1)
 * cleared, is passed as argument.
 * The access type (read access or write access) is not passed; your handler
 * has to know itself how to distinguish these two cases.
 * The second argument is 0, meaning it could also be a stack overflow, or 1,
 * meaning the handler should seriously try to fix the fault.
 * The return value should be nonzero if the handler has done its job
 * and no other handler should be called, or 0 if the handler declines
 * responsibility for the given address.
 *
 * The handler is run at a moment when nothing about the global state of the
 * program is known. Therefore it cannot use facilities that manipulate global
 * variables or locks. In particular, it cannot use malloc(); use mmap()
 * instead. It cannot use fopen(); use open() instead. Etc. All global
 * variables that are accessed by the handler should be marked 'volatile'.
 */
typedef int (*sigsegv_handler_t) (void* fault_address, int serious);

/*
 * Installs a global SIGSEGV handler.
 * This should be called once only, and it ignores any previously installed
 * SIGSEGV handler.
 * Returns 0 on success, or -1 if the system doesn't support catching SIGSEGV.
 */
extern int sigsegv_install_handler (sigsegv_handler_t handler);

/*
 * Deinstalls the global SIGSEGV handler.
 * This goes back to the state where no SIGSEGV handler is installed.
 */
extern void sigsegv_deinstall_handler (void);

#if LIBSIGSEGV_VERSION >= 0x0206
/*
 * Prepares leaving a SIGSEGV handler (through longjmp or similar means).
 * Control is transferred by calling CONTINUATION with CONT_ARG1, CONT_ARG2,
 * CONT_ARG3 as arguments.
 * CONTINUATION must not return.
 * The sigsegv_leave_handler function may return if called from a SIGSEGV
 * handler; its return value should be used as the handler's return value.
 * The sigsegv_leave_handler function does not return if called from a
 * stack overflow handler.
 */
extern int sigsegv_leave_handler (void (*continuation) (void*, void*, void*), void* cont_arg1, void* cont_arg2, void* cont_arg3);
#else /* older versions of libsigsegv */
/*
 * Prepares leaving a SIGSEGV handler (through longjmp or similar means).
 * Limitation: This function could only be called once on MacOS X.
 */
extern void sigsegv_leave_handler (void);
#endif

/*
 * The type of a context passed to a stack overflow handler.
 * This type is system dependent; on some platforms it is an 'ucontext_t *',
 * on some platforms it is a 'struct sigcontext *', on others merely an
 * opaque 'void *'.
 */
typedef ucontext_t *stackoverflow_context_t;

/*
 * The type of a stack overflow handler.
 * Such a handler should perform a longjmp call in order to reduce the amount
 * of stack needed. It must not return.
 * The emergency argument is 0 when the stack could be repared, or 1 if the
 * application should better save its state and exit now.
 *
 * The handler is run at a moment when nothing about the global state of the
 * program is known. Therefore it cannot use facilities that manipulate global
 * variables or locks. In particular, it cannot use malloc(); use mmap()
 * instead. It cannot use fopen(); use open() instead. Etc. All global
 * variables that are accessed by the handler should be marked 'volatile'.
 */
typedef void (*stackoverflow_handler_t) (int emergency, stackoverflow_context_t scp);

/*
 * Installs a stack overflow handler.
 * The extra_stack argument is a pointer to a pre-allocated area used as a
 * stack for executing the handler. It typically comes from a static variable
 * or from heap-allocated memoty; placing it on the main stack may fail on
 * some operating systems.
 * Its size, passed in extra_stack_size, should be sufficiently large.  The
 * following code determines an appropriate size:
 *   #include <signal.h>
 *   #ifndef SIGSTKSZ         / * glibc defines SIGSTKSZ for this purpose * /
 *   # define SIGSTKSZ 16384  / * on most platforms, 16 KB are sufficient * /
 *   #endif
 * Returns 0 on success, or -1 if the system doesn't support catching stack
 * overflow.
 */
extern int stackoverflow_install_handler (stackoverflow_handler_t handler,
                                          void* extra_stack, unsigned long extra_stack_size);

/*
 * Deinstalls the stack overflow handler.
 */
extern void stackoverflow_deinstall_handler (void);

/* -------------------------------------------------------------------------- */

/*
 * The following structure and functions permit to define different SIGSEGV
 * policies on different address ranges.
 */

/*
 * The type of a local SIGSEGV handler.
 * The fault address is passed as argument.
 * The second argument is fixed arbitrary user data.
 * The return value should be nonzero if the handler has done its job
 * and no other handler should be called, or 0 if the handler declines
 * responsibility for the given address.
 */
typedef int (*sigsegv_area_handler_t) (void* fault_address, void* user_arg);

/*
 * This structure represents a table of memory areas (address range intervals),
 * with an local SIGSEGV handler for each.
 */
typedef
struct sigsegv_dispatcher {
  void* tree;
}
sigsegv_dispatcher;

/*
 * Initializes a sigsegv_dispatcher structure.
 */
extern void sigsegv_init (sigsegv_dispatcher* dispatcher);

/*
 * Adds a local SIGSEGV handler to a sigsegv_dispatcher structure.
 * It will cover the interval [address..address+len-1].
 * The address and len arguments must be multiples of
 * SIGSEGV_FAULT_ADDRESS_ALIGNMENT.
 * Returns a "ticket" that can be used to remove the handler later.
 */
extern void* sigsegv_register (sigsegv_dispatcher* dispatcher,
                               void* address, unsigned long len,
                               sigsegv_area_handler_t handler, void* handler_arg);

/*
 * Removes a local SIGSEGV handler.
 */
extern void sigsegv_unregister (sigsegv_dispatcher* dispatcher, void* ticket);

/*
 * Call the local SIGSEGV handler responsible for the given fault address.
 * Return the handler's return value. 0 means that no handler has been found,
 * or that a handler was found but declined responsibility.
 */
extern int sigsegv_dispatch (sigsegv_dispatcher* dispatcher, void* fault_address);

/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif /* _SIGSEGV_H */
