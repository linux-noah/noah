#include "common.h"
#include "noah.h"
#include "vmm.h"
#include "mm.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "linux/errno.h"

bool
addr_ok(gaddr_t addr, int access)
{
  if (addr >= user_addr_max) {
    return false;
  }
  struct mm_region *region = find_region(addr, proc.mm);
  if (!region) {
    return false;
  }
  if (access & ~region->prot) {
    return false;
  }

  return true;
}

size_t
copy_from_user(void *to, gaddr_t src_ptr, size_t n)
{
  while (n > 0) {
    const void *src = guest_to_host(src_ptr);
    if (src == NULL) {
      return n;
    }
    size_t size = MIN(rounddown(src_ptr + 4096, 4096) - src_ptr, n);
    memcpy(to, src, size);
    to = (char *) to + size;
    src_ptr += size;
    n -= size;
  }
  return 0;
}

// On success, returns the length of the string (not including the trailing NUL).
// If access to userspace fails, returns -EFAULT
ssize_t
strncpy_from_user(void *to, gaddr_t src_ptr, size_t n)
{
  size_t len = strnlen_user(src_ptr, n);
  if (len == 0) {
    return -LINUX_EFAULT;
  } else if (n < len) {
    if (copy_from_user(to, src_ptr, n)) {
      return -LINUX_EFAULT;
    }
    return n;
  }
  if (copy_from_user(to, src_ptr, len)) {
    return -LINUX_EFAULT;
  }
  return len - 1;
}

// Get the size of a user string INCLUDING trailing NULL
// On exception, it returns 0. For too long strings, returns a number greater than n.
ssize_t
strnlen_user(gaddr_t src_ptr, size_t n)
{
  int len = 0;
  while ((ssize_t) n > 0) {
    const void *str = guest_to_host(src_ptr);
    if (str == NULL) {
      return 0;
    }
    size_t size = MIN(rounddown(src_ptr + 4096, 4096) - src_ptr, n);
    size_t i = strnlen(str, size);
    if (i < size) {
      return len + i + 1;
    }
    assert(i == size);
    len += size;
    src_ptr += size;
    n -= size;
  }
  return len + 1;
}

size_t
copy_to_user(gaddr_t to_ptr, const void *src, size_t n)
{
  while (n > 0) {
    void *to = guest_to_host(to_ptr);
    if (to == NULL) {
      return n;
    }
    size_t size = MIN(rounddown(to_ptr + 4096, 4096) - to_ptr, n);
    memcpy(to, src, size);
    to_ptr += size;
    src = (char *) src + size;
    n -= size;
  }
  return 0;
}

DEFINE_SYSCALL(unimplemented)
{
  uint64_t rax;

  vmm_read_register(HV_X86_RAX, &rax);

  warnk("unimplemented syscall: %lld\n", rax);
  return -LINUX_ENOSYS;
}

#include "syscall.h"

#define sys_unimplemented __ignore_me__
#define SYSCALL(n, name) uint64_t _sys_##name(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);
SYSCALLS
#undef SYSCALL
#undef sys_unimplemented

sc_handler_t sc_handler_table[NR_SYSCALLS] = {
#define SYSCALL(n, name) [n] = ((sc_handler_t) _sys_##name),
  SYSCALLS
#undef SYSCALL
};

char *sc_name_table[NR_SYSCALLS] = {
#define SYSCALL(n, name) [n] = #name,
  SYSCALLS
#undef SYSCALL
};

#define DEFINE_NOT_IMPLEMENTED_SYSCALL(name)      \
  DEFINE_SYSCALL(name)                            \
  {                                               \
    return -LINUX_ENOSYS;                         \
  }

DEFINE_NOT_IMPLEMENTED_SYSCALL(vserver)
DEFINE_NOT_IMPLEMENTED_SYSCALL(uselib)
DEFINE_NOT_IMPLEMENTED_SYSCALL(epoll_ctl_old)
DEFINE_NOT_IMPLEMENTED_SYSCALL(epoll_wait_old)
DEFINE_NOT_IMPLEMENTED_SYSCALL(getpmsg)
DEFINE_NOT_IMPLEMENTED_SYSCALL(putpmsg)
DEFINE_NOT_IMPLEMENTED_SYSCALL(nfsservctl)
DEFINE_NOT_IMPLEMENTED_SYSCALL(security)
DEFINE_NOT_IMPLEMENTED_SYSCALL(set_thread_area)
DEFINE_NOT_IMPLEMENTED_SYSCALL(get_thread_area)
DEFINE_NOT_IMPLEMENTED_SYSCALL(tuxcall)
DEFINE_NOT_IMPLEMENTED_SYSCALL(afs_syscall)
