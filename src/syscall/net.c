#include "noah.h"
#include "common.h"

#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

DEFINE_SYSCALL(socket, int, family, int, type, int, protocol)
{
  int nfamily;
  switch (family) {
  case LINUX_AF_UNIX: nfamily = AF_UNIX; break;
  case LINUX_AF_INET: nfamily = AF_INET; break;
  case LINUX_AF_INET6: nfamily = AF_INET6; break;
  default:
    return -1;
  }

  /* FIXME */
  type &= ~LINUX_SOCK_NONBLOCK;
  type &= ~LINUX_SOCK_CLOEXEC;

  return socket(nfamily, type, protocol);
}

DEFINE_SYSCALL(connect, int, sockfd, gaddr_t, addr, uint64_t, addrlen)
{
  char buf[addrlen];
  struct sockaddr *naddr = (void *) &buf;

  memcpy(buf, guest_to_host(addr), addrlen);

  switch (naddr->sa_family) {
  case LINUX_AF_UNIX: naddr->sa_family = AF_UNIX; break;
  case LINUX_AF_INET: naddr->sa_family = AF_INET; break;
  case LINUX_AF_INET6: naddr->sa_family = AF_INET6; break;
  default:
    return -1;
  }

  errno = 0;
  int fd = connect(sockfd, naddr, addrlen);
  perror("hoge");
  return fd;
}

DEFINE_SYSCALL(setsockopt, int, fd, int, level, int, optname, gaddr_t, optval, int, option)
{
  return -1;
}

DEFINE_SYSCALL(getsockopt, int, fd, int, level, int, optname, gaddr_t, optval, gaddr_t, option)
{
  return -1;
}
