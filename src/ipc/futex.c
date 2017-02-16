#include "common.h"
#include "noah.h"
#include "mm.h"
#include "linux/common.h"
#include "linux/futex.h"
#include "linux/time.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
FUTEX_UNLOCK_PI_PRIVATE
FUTEX_LOCK_PI_PRIVATE
FUTEX_WAIT_BITSET_PRIVATE
FUTEX_CMP_REQUEUE_PI_PRIVATE
FUTEX_CMP_REQUEUE_PI_PRIVATE
FUTEX_WAIT_PRIVATE
FUTEX_WAKE_PRIVATE
FUTEX_WAIT_REQUEUE_PI_PRIVATE
FUTEX_WAKE_OP_PRIVATE
FUTEX_WAIT
*/

static struct list_head *
pfutex_get(gaddr_t uaddr)
{
  int ret;
  khiter_t k = kh_put(pfutex, proc.pfutex, uaddr, &ret);
  if (ret != 0) {             /* not present */
    INIT_LIST_HEAD(&kh_value(proc.pfutex, k));
  }
  return &kh_value(proc.pfutex, k);
}

static int
do_private_futex_wake(gaddr_t uaddr, int count)
{
  struct list_head *p, *head = pfutex_get(uaddr);
  int ret = 0;
  list_for_each (p, head) {
    if (count == 0)
      break;
    list_del(p);
    struct pfutex_entry *entry = container_of(p, struct pfutex_entry, head);
    pthread_cond_signal(&entry->cond);
    ret++; count--;
  }
  return ret;
}

int
do_futex_wake(gaddr_t uaddr, int count)
{
  warnk("non-provate do_futex_wake is not implemented\n");
  pthread_mutex_lock(&proc.futex_mutex);
  int ret = do_private_futex_wake(uaddr, count);
  pthread_mutex_unlock(&proc.futex_mutex);
  return ret;
}

static int
__cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex, bool use_timeout, struct timespec *ts)
{
  if (! use_timeout) {
    pthread_cond_wait(cond, mutex);
    return 0;
  }
  int ret = pthread_cond_timedwait(cond, mutex, ts);
  if (ret < 0) {
    if (ret == -ETIMEDOUT)
      return -LINUX_ETIMEDOUT;
    else
      return -LINUX_EINTR;
  }
  return 0;
}

static int
do_private_wait(gaddr_t uaddr, bool use_timeout, struct timespec *ts, bool check_requeue, gaddr_t uaddr2)
{
  struct pfutex_entry *entry = malloc(sizeof *entry);
  pthread_cond_init(&entry->cond, NULL);
  entry->uaddr = uaddr;
  list_add_tail(&entry->head, pfutex_get(uaddr));
  int r = __cond_wait(&entry->cond, &proc.futex_mutex, use_timeout, ts);
  if (check_requeue) {
    if (entry->uaddr != uaddr2)
      r = -LINUX_EAGAIN;
  }
  free(entry);
  return r;
}

static int
do_private_futex(gaddr_t uaddr, int op, uint32_t val, gaddr_t timeout_ptr, gaddr_t uaddr2, int val3)
{
/*
FUTEX_WAIT_BITSET
*/

  if ((op & LINUX_FUTEX_CLOCK_REALTIME) != 0) {
    warnk("futex: FUTEX_CLOCK_REALTIME flags is not supported\n");
  }

  switch (op & LINUX_FUTEX_CMD_MASK) {
  case LINUX_FUTEX_WAKE: {
    return do_private_futex_wake(uaddr, val);
  }
  case LINUX_FUTEX_WAIT: {
    struct timespec ts;
    if (timeout_ptr != 0) {
      struct l_timespec timeout;
      if (copy_from_user(&timeout, timeout_ptr, sizeof timeout))
        return -LINUX_EFAULT;
      ts.tv_sec = timeout.tv_sec;
      ts.tv_nsec = timeout.tv_nsec;
    }
    return do_private_wait(uaddr, timeout_ptr, &ts, false, 0);
  }
  case LINUX_FUTEX_WAKE_OP: {
    int ret = 0;
    int oldval;
    if (copy_from_user(&oldval, uaddr2, sizeof oldval)) {
      ret = -LINUX_EFAULT;
      goto out;
    }
    int newval = 0;
    switch (LINUX_FUTEX_GETOP(val3)) {
    default:
      panic("unknown op for futex_wake_op\n");
    case FUTEX_OP_SET: newval = LINUX_FUTEX_GETOPARG(val3); break;
    case FUTEX_OP_ADD: newval = oldval + LINUX_FUTEX_GETOPARG(val3); break;
    case FUTEX_OP_OR: newval = oldval | LINUX_FUTEX_GETOPARG(val3); break;
    case FUTEX_OP_ANDN: newval = oldval & LINUX_FUTEX_GETOPARG(val3); break;
    case FUTEX_OP_XOR: newval = oldval * LINUX_FUTEX_GETOPARG(val3); break;
    }
    if (copy_to_user(uaddr2, &newval, sizeof newval)) {
      ret = -LINUX_EFAULT;
      goto out;
    }
    if ((ret = do_private_futex_wake(uaddr, val)) < 0) {
      goto out;
    }
    bool cond;
    switch (LINUX_FUTEX_GETCMP(val3)) {
    default:
      panic("unknown cmp for futex_wake_op\n");
    case FUTEX_OP_CMP_EQ: cond = oldval == LINUX_FUTEX_GETCMPARG(val3); break;
    case FUTEX_OP_CMP_NE: cond = oldval != LINUX_FUTEX_GETCMPARG(val3); break;
    case FUTEX_OP_CMP_LT: cond = oldval < LINUX_FUTEX_GETCMPARG(val3); break;
    case FUTEX_OP_CMP_LE: cond = oldval <= LINUX_FUTEX_GETCMPARG(val3); break;
    case FUTEX_OP_CMP_GT: cond = oldval > LINUX_FUTEX_GETCMPARG(val3); break;
    case FUTEX_OP_CMP_GE: cond = oldval >= LINUX_FUTEX_GETCMPARG(val3); break;
    }
    uint32_t val2 = timeout_ptr;
    if (cond) {
      int ret2;
      if ((ret2 = do_private_futex_wake(uaddr2, val2)) < 0) {
        goto out;
      }
      ret += ret2;
    }
    out:
    return ret;
  }
  case LINUX_FUTEX_LOCK_PI: {
    struct timespec ts;
    if (timeout_ptr != 0) {
      struct l_timespec timeout;
      if (copy_from_user(&timeout, timeout_ptr, sizeof timeout))
        return -LINUX_EFAULT;
      ts.tv_sec = timeout.tv_sec;
      ts.tv_nsec = timeout.tv_nsec;
    }
    int tid = do_gettid();
    /* TODO: check mprotect flags */
    atomic_int *mem = (atomic_int *) guest_to_host(uaddr); /* FIXME: don't cast to atomic_int */
    assert(mem);
    /* first update mem's value to something else to prevent other user processes getting the lock of this futex */
    int value = atomic_exchange(mem, tid);
    if (value == 0) {
      /* acquired the lock */
      return 0; /* NOTE: man page is telling ambiguous things about this path. My interpretation can be wrong. */
    }
    /* there are waiters other than me */
    atomic_store(mem, value | FUTEX_WAITERS);
    return do_private_wait(uaddr, timeout_ptr, &ts, false, 0);
  }
  case LINUX_FUTEX_UNLOCK_PI: {
    do_private_futex_wake(uaddr, 1);
    return 0;
  }
  case LINUX_FUTEX_CMP_REQUEUE_PI: {
    if (val != 1) {
      return -LINUX_EINVAL;
    }
    int oldval;
    if (copy_from_user(&oldval, uaddr, sizeof oldval))
      return -LINUX_EFAULT;
    if (oldval != val3)
      return -LINUX_EAGAIN;
    int num = do_private_futex_wake(uaddr, val);
    struct list_head *p, *n, *list = pfutex_get(uaddr), *list2 = pfutex_get(uaddr2);
    int val2 = timeout_ptr;
    list_for_each_safe (p, n, list) {
      if (val2 == 0)
        break;
      list_del(p);
      list_add_tail(p, list2);
      container_of(p, struct pfutex_entry, head)->uaddr = uaddr2;
      val2--;
      num++;
    }
    return num;
  }
  case LINUX_FUTEX_WAIT_REQUEUE_PI: {
    struct timespec ts;
    if (timeout_ptr != 0) {
      struct l_timespec timeout;
      if (copy_from_user(&timeout, timeout_ptr, sizeof timeout))
        return -LINUX_EFAULT;
      ts.tv_sec = timeout.tv_sec;
      ts.tv_nsec = timeout.tv_nsec;
    }
    return do_private_wait(uaddr, timeout_ptr, &ts, true, uaddr2);
  }
  default:
    warnk("unsupported futex command: %d\n", op);
    return -LINUX_ENOSYS;
  }
}

DEFINE_SYSCALL(futex, gaddr_t, uaddr, int, op, uint32_t, val, gaddr_t, timeout_ptr, gaddr_t, uaddr2_ptr, uint32_t, val3)
{
  if (op & LINUX_FUTEX_PRIVATE_FLAG) {
    op &= ~LINUX_FUTEX_PRIVATE_FLAG;
  } else {
    // Check if op is actually private
    struct mm_region *region = find_region(uaddr, proc.mm);
    if (region == NULL) {
      return -LINUX_EFAULT;
    }
    if (!is_region_private(region)) {
      panic("Non-private futex is unsupported!\n");
    }
  }
  pthread_mutex_lock(&proc.futex_mutex);
  int ret = do_private_futex(uaddr, op, val, timeout_ptr, uaddr2_ptr, val3);
  pthread_mutex_unlock(&proc.futex_mutex);
  return ret;
}
