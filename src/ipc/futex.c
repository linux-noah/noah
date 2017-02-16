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

static struct pfutex_entry *
pfutex_get(gaddr_t uaddr)
{
  struct pfutex_entry *entry;
  pthread_rwlock_wrlock(&proc.futex_lock);
  int ret;
  khiter_t k = kh_put(pfutex, proc.pfutex, uaddr, &ret);
  if (ret != 0) {             /* not present */
    struct pfutex_entry *e = malloc(sizeof *e);
    e->nr_waiters = 0;
    pthread_cond_init(&e->cond, NULL);
    pthread_mutex_init(&e->mutex, NULL);
    kh_value(proc.pfutex, k) = e;
  }
  entry = kh_value(proc.pfutex, k);
  pthread_rwlock_unlock(&proc.futex_lock);
  return entry;
}

static int
do_private_futex_wake_no_lock(struct pfutex_entry *entry, int count)
{
  int ret;
  if (entry->nr_waiters < count) {
    ret = entry->nr_waiters;
    entry->nr_waiters = 0;
    pthread_cond_broadcast(&entry->cond);
  } else {
    ret = count;
    entry->nr_waiters -= count;
    for (int i = 0; i < count; ++i) {
      pthread_cond_signal(&entry->cond);
    }
  }
  return ret;
}

int
do_futex_wake(gaddr_t uaddr, int count)
{
  warnk("non-provate do_futex_wake is not implemented\n");
  struct pfutex_entry *entry = pfutex_get(uaddr);
  pthread_mutex_lock(&entry->mutex);
  int ret = do_private_futex_wake_no_lock(entry, count);
  pthread_mutex_unlock(&entry->mutex);
  return ret;
}

static int
do_private_futex(gaddr_t uaddr, int op, uint32_t val, gaddr_t timeout_ptr, gaddr_t uaddr2, uint32_t val3)
{
/*
FUTEX_UNLOCK_PI
FUTEX_LOCK_PI
FUTEX_CMP_REQUEUE_PI
FUTEX_CMP_REQUEUE_PI
FUTEX_WAIT_REQUEUE_PI
FUTEX_WAIT_BITSET
*/

  switch (op & LINUX_FUTEX_CMD_MASK) {
  case LINUX_FUTEX_WAKE: {
    int count = val;
    struct pfutex_entry *entry = pfutex_get(uaddr);
    pthread_mutex_lock(&entry->mutex);
    int ret = do_private_futex_wake_no_lock(entry, count);
    pthread_mutex_unlock(&entry->mutex);
    return ret;
  }
  case LINUX_FUTEX_WAIT: {
    if ((op & LINUX_FUTEX_CLOCK_REALTIME) != 0) {
      warnk("futex: FUTEX_CLOCK_REALTIME flags is not supported\n");
    }
    if (timeout_ptr == 0) {
      struct pfutex_entry *entry = pfutex_get(uaddr);
      pthread_mutex_lock(&entry->mutex);
      entry->nr_waiters++;
      pthread_cond_wait(&entry->cond, &entry->mutex);
      pthread_mutex_unlock(&entry->mutex);
      return 0;
    }
    struct l_timespec timeout;
    if (copy_from_user(&timeout, timeout_ptr, sizeof timeout))
      return -LINUX_EFAULT;
    struct timespec ts;
    ts.tv_sec = timeout.tv_sec;
    ts.tv_nsec = timeout.tv_nsec;
    struct pfutex_entry *entry = pfutex_get(uaddr);
    pthread_mutex_lock(&entry->mutex);
    entry->nr_waiters++;
    int ret = pthread_cond_timedwait(&entry->cond, &entry->mutex, &ts);
    pthread_mutex_unlock(&entry->mutex);
    if (ret < 0) {
      if (ret == -ETIMEDOUT)
        return -LINUX_ETIMEDOUT;
      else
        return -LINUX_EINTR;
    }
    return 0;
  }
  case LINUX_FUTEX_WAKE_OP: {
    int ret = 0;
    struct pfutex_entry *entry1, *entry2;
    entry1 = pfutex_get(uaddr);
    entry2 = pfutex_get(uaddr2);
    pthread_mutex_lock(&entry1->mutex);
    pthread_mutex_lock(&entry2->mutex); /* not sure this does not cause race condition */
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
    if ((ret = do_private_futex_wake_no_lock(entry1, val)) < 0) {
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
      if ((ret = do_private_futex_wake_no_lock(entry2, val2)) < 0) {
        goto out;
      }
    }
    out:
    pthread_mutex_unlock(&entry2->mutex);
    pthread_mutex_unlock(&entry1->mutex);
    return ret;
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
  return do_private_futex(uaddr, op, val, timeout_ptr, uaddr2_ptr, val3);
}
