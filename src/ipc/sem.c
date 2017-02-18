#include "common.h"
#include "noah.h"
#include "mm.h"
#include "linux/common.h"
#include "linux/futex.h"
#include "linux/time.h"
#include "linux/ipc.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int
linux_to_darwin_semflg(int l_semflg)
{
  int d_semflg = 0;
  if (l_semflg & LINUX_IPC_CREAT) {
    l_semflg &= ~LINUX_IPC_CREAT;
    d_semflg |= IPC_CREAT;
  }
  if (l_semflg & LINUX_IPC_EXCL) {
    l_semflg &= ~LINUX_IPC_EXCL;
    d_semflg |= IPC_EXCL;
  }
  if (l_semflg & LINUX_IPC_NOWAIT) {
    l_semflg &= ~LINUX_IPC_NOWAIT;
    d_semflg |= IPC_NOWAIT;
  }
  assert(l_semflg == 0);
  return d_semflg;
}

DEFINE_SYSCALL(semget, l_key_t, key, int, nsems, int, semflg)
{
  return syswrap(semget(key | IPC_PRIVATE, nsems, linux_to_darwin_semflg(semflg)));
}

DEFINE_SYSCALL(semop, int, semid, gaddr_t, tsops_ptr, unsigned, nsops)
{
  struct l_sembuf *l_tsops = malloc(sizeof l_tsops[0] * nsops);
  struct sembuf *tsops = malloc(sizeof tsops[0] * nsops);
  int r = 0;
  if (copy_from_user(&l_tsops, tsops_ptr, sizeof l_tsops[0] * nsops)) {
    r = -LINUX_EFAULT;
    goto out;
  }
  for (uint i = 0; i < nsops; ++i) {
    tsops[i].sem_num = l_tsops[i].sem_num;
    tsops[i].sem_op = l_tsops[i].sem_op;
    tsops[i].sem_flg = 0;
    if (l_tsops[i].sem_flg & LINUX_IPC_NOWAIT)
      tsops[i].sem_flg |= IPC_NOWAIT;
    if (l_tsops[i].sem_flg & LINUX_SEM_UNDO)
      tsops[i].sem_flg |= SEM_UNDO;
  }
  r = syswrap(semop(semid, tsops, nsops));
 out:
  free(l_tsops);
  free(tsops);
  return r;
}

DEFINE_SYSCALL(semctl, int, semid, int, semnum, int, cmd, union l_semun, arg)
{
  warnk("semctl: unsupported command: 0x%x\n", cmd);
  return -LINUX_ENOSYS;
}
