#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include "malloc.h"

struct header {
  struct header *next;
  size_t size;
};

typedef struct header Header;

/* 1GB should suffice, I guess? */
#define MEMORY_ARENA_SIZE (1 * 1024 * 1024 * 1024)

void *arena_start;              /* never changed after the boot sequence completed */

struct malloc_data {
  pthread_rwlock_t lock;
  Header base;
  Header *freep;
  char *brkp;
  char brk_start[0];
};

#define brkp (((struct malloc_data *) arena_start)->brkp)
#define lock (((struct malloc_data *) arena_start)->lock)
#define base (((struct malloc_data *) arena_start)->base)
#define freep (((struct malloc_data *) arena_start)->freep)
#define brk_start (((struct malloc_data *) arena_start)->brk_start)

void
init_shm_malloc(void)
{
  /* this function is part of the "boot" sequence */

  arena_start = mmap(NULL, MEMORY_ARENA_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_HASSEMAPHORE | MAP_SHARED, -1, 0);
  if (arena_start == MAP_FAILED) {
    perror("init_malloc");
    exit(1);
  }

  pthread_rwlock_init(&lock, NULL);
  bzero(&base, sizeof base);
  bzero(&freep, sizeof freep);
  brkp = brk_start;
}

static void *__shm_sbrk(size_t s)
{
  /* we must be in the critical section in shm_malloc so don't get the lock here... */
  if (brkp + s >= (char *) arena_start + MEMORY_ARENA_SIZE)
    return NULL;
  brkp += s;
  return brkp - s;
}

static Header *morecore(size_t);

static void *__shm_malloc(size_t nbytes)
{
  Header *p, *prevp;
  size_t nunits;

  nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
  if (! (prevp = freep)) {  /* no free list yet */
    base.next = freep = prevp = &base;
    base.size = 0;
  }
  for (p = prevp->next; ; prevp = p, p = p->next) {
    if (p->size >= nunits) {  /* big enough */
      if (p->size == nunits) {  /* exactly */
        prevp->next = p->next;
      } else {  /* allocate tail end */
        p->size -= nunits;
        p += p->size;
        p->size = nunits;
      }
      freep = prevp;
      return (void *)(p + 1);
    }
    if (p == freep)
      if (! (p = morecore(nunits)))
        return NULL;
  }
}

static void __shm_free(void *ap)
{
  Header *bp, *p;

  if (! ap)
    return;

  bp = (Header *)ap - 1;
  for (p = freep; ! (p < bp && bp < p->next); p = p->next)
    if (p->next <= p && (p < bp || bp < p->next))
      break;

  if (bp + bp->size == p->next) {
    bp->size += p->next->size;
    bp->next = p->next->next;
  } else {
    bp->next = p->next;
  }

  if (p + p->size == bp) {
    p->size += bp->size;
    p->next = bp->next;
  } else {
    p->next = bp;
  }

  freep = p;
}

#define NALLOC 1024

static Header *morecore(size_t nunits)
{
  Header *p;

  nunits = (nunits + NALLOC - 1) / NALLOC * NALLOC;
  p = (Header *)__shm_sbrk(nunits * sizeof(Header));
  if (! p)
    return NULL;
  p->size = nunits;
  __shm_free(p + 1);
  return freep;
}


// ----

void *shm_malloc(size_t nbytes)
{
  void *ptr;

  pthread_rwlock_wrlock(&lock);
  ptr = __shm_malloc(nbytes);
  pthread_rwlock_unlock(&lock);
  return ptr;
}

void shm_free(void *ptr)
{
  pthread_rwlock_wrlock(&lock);
  __shm_free(ptr);
  pthread_rwlock_unlock(&lock);
}
