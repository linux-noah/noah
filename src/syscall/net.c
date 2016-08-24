#include "noah.h"
#include "common.h"

#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stddef.h>
#include <assert.h>

#include "linux/common.h"
#include "linux/socket.h"
#include "linux/misc.h"

int
to_host_sa_family(int family)
{
  switch (family) {
  case LINUX_AF_UNIX:
    return AF_UNIX;
  case LINUX_AF_INET:
    return AF_INET;
  case LINUX_AF_INET6:
    return AF_INET6;
  default:
    return -1;
  }
}

DEFINE_SYSCALL(socket, int, family, int, type, int, protocol)
{
  /* FIXME */
  type &= ~LINUX_SOCK_NONBLOCK;
  type &= ~LINUX_SOCK_CLOEXEC;

  return socket(to_host_sa_family(family), type, protocol);
}

DEFINE_SYSCALL(connect, int, sockfd, gaddr_t, addr, uint64_t, addrlen)
{
  int host_addrlen;
  struct sockaddr *sockaddr = malloc(addrlen);
  struct l_sockaddr *l_sockaddr = guest_to_host(addr);

  memcpy((char*)sockaddr, l_sockaddr, addrlen);
  assert(offsetof(struct sockaddr, sa_data) == offsetof(struct l_sockaddr, sa_data));
  sockaddr->sa_family = l_sockaddr->sa_family;

  switch (sockaddr->sa_family) {
  case AF_UNIX: {
    int slen;
    struct sockaddr_un *sockaddr_un = (struct sockaddr_un*)sockaddr;
    if (sockaddr_un->sun_path[0] == '\0') {
      // Linux abstract namespace starts with NULL, which we do not support yet
      PRINTF("Abstract namespace: %20s\n", &sockaddr_un->sun_path[1]);
      slen = strnlen(&sockaddr_un->sun_path[1], addrlen - offsetof(struct sockaddr_un, sun_path) - 1);
    } else {
      slen = strnlen(sockaddr_un->sun_path, addrlen - offsetof(struct sockaddr_un, sun_path));
    }
    host_addrlen = sizeof(struct sockaddr_un);
    if (host_addrlen < offsetof(struct sockaddr_un, sun_path) + slen) {
      // Name too long
      return -1;
    }
    break;
  }
  case AF_INET:
    host_addrlen = sizeof(struct sockaddr_in);
    break;
  default:
    fprintf(stderr, "Unimplemented sa_family");
    return -1;
  }

  int fd = connect(sockfd, sockaddr, host_addrlen);
  free(sockaddr);
  return fd;
}

int
to_host_sockopt_level(int level)
{
  switch (level) {
  case LINUX_SOL_SOCKET: return SOL_SOCKET;
  default: return level; // Other values are the same as OSX as long as they exist.
  };
}

int
to_host_sockopt_name(int name)
{
  switch (name) {
  case LINUX_SO_DEBUG:
    return SO_DEBUG;
  case LINUX_SO_REUSEADDR:
    return SO_REUSEADDR;
  case LINUX_SO_TYPE:
    return SO_TYPE;
  case LINUX_SO_ERROR:
    return SO_ERROR;
  case LINUX_SO_DONTROUTE:
    return SO_DONTROUTE;
  case LINUX_SO_BROADCAST:
    return SO_BROADCAST;
  case LINUX_SO_SNDBUF:
    return SO_SNDBUF;
  case LINUX_SO_RCVBUF:
    return SO_RCVBUF;
  case LINUX_SO_KEEPALIVE:
    return SO_KEEPALIVE;
  case LINUX_SO_OOBINLINE:
    return SO_OOBINLINE;
  case LINUX_SO_LINGER:
    return SO_LINGER;
  case LINUX_SO_RCVLOWAT:
    return SO_RCVLOWAT;
  case LINUX_SO_SNDLOWAT:
    return SO_SNDLOWAT;
  case LINUX_SO_RCVTIMEO:
    return SO_RCVTIMEO;
  case LINUX_SO_SNDTIMEO:
    return SO_SNDTIMEO;
  case LINUX_SO_TIMESTAMP:
    return SO_TIMESTAMP;
  case LINUX_SO_ACCEPTCONN:
    return SO_ACCEPTCONN;
  default:
    PRINTF("Unsupported sockopt name: 0x%x\n", name);
    return -1;
  }
}

DEFINE_SYSCALL(setsockopt, int, fd, int, level, int, optname, gaddr_t, optval, int, opt_len)
{
  // Darwin's optval is compatible with that of Linux
  return setsockopt(fd, to_host_sockopt_level(level), to_host_sockopt_name(optname), guest_to_host(optval), opt_len);
}

DEFINE_SYSCALL(getsockopt, int, fd, int, level, int, optname, gaddr_t, optval, gaddr_t, opt_len)
{
  // Darwin's optval is compatible with that of Linux
  return getsockopt(fd, to_host_sockopt_level(level), to_host_sockopt_name(optname), guest_to_host(optval), guest_to_host(opt_len));
}
