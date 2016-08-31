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

DEFINE_SYSCALL(socket, int, family, int, type, int, protocol)
{
  /* FIXME */
  type &= ~LINUX_SOCK_NONBLOCK;
  type &= ~LINUX_SOCK_CLOEXEC;

  return or_errno(socket(linux_to_darwin_sa_family(family), type, protocol));
}

int
to_host_sockaddr(struct sockaddr **sockaddr, struct l_sockaddr *l_sockaddr, size_t l_sockaddr_len)
{
  if (l_sockaddr == NULL) {
    return -1;
  }

  *sockaddr = malloc(l_sockaddr_len);

  memcpy(*sockaddr, l_sockaddr, l_sockaddr_len);
  assert(offsetof(struct sockaddr, sa_data) == offsetof(struct l_sockaddr, sa_data));
  (*sockaddr)->sa_family = l_sockaddr->sa_family;

  switch (linux_to_darwin_sa_family(l_sockaddr->sa_family)) {
  case AF_UNIX: {
    int slen;
    struct sockaddr_un *sockaddr_un = (struct sockaddr_un*)*sockaddr;
    if (sockaddr_un->sun_path[0] == '\0') {
      // Linux abstract namespace starts with NULL, which we do not support yet
      printk("Abstract namespace: %20s\n", &sockaddr_un->sun_path[1]);
      slen = strnlen(&sockaddr_un->sun_path[1], l_sockaddr_len - offsetof(struct sockaddr_un, sun_path) - 1);
    } else {
      slen = strnlen(sockaddr_un->sun_path, l_sockaddr_len - offsetof(struct sockaddr_un, sun_path));
    }
    (*sockaddr)->sa_len = sizeof(struct sockaddr_un);
    if ((*sockaddr)->sa_len < offsetof(struct sockaddr_un, sun_path) + slen) {
      // Name too long
      goto err;
    }
    break;
  }
  case AF_INET:
    (*sockaddr)->sa_len = sizeof(struct sockaddr_in);
    break;
  default:
    fprintf(stderr, "Unimplemented sa_family");
    goto err;
  }

  return 0;

err:
  free(*sockaddr);
  return -1;
}

void
to_linux_sockaddr(struct l_sockaddr *l_sockaddr, struct sockaddr *sockaddr, socklen_t *l_sockaddr_len)
{
  if (sockaddr == NULL || l_sockaddr == NULL || *l_sockaddr_len < sizeof(struct sockaddr)) {
    return;
  }

  if ((void*)l_sockaddr != (void*)sockaddr) {
    memmove(l_sockaddr, sockaddr, MIN(*l_sockaddr_len, sockaddr->sa_len));
  }

  int family = sockaddr->sa_family;
  l_sockaddr->sa_family = darwin_to_linux_sa_family(family);
}

DEFINE_SYSCALL(connect, int, sockfd, gaddr_t, addr, uint64_t, addrlen)
{
  struct sockaddr *sockaddr;
  if (to_host_sockaddr(&sockaddr, guest_to_host(addr), addrlen) < 0) {
    return -1;
  }

  int fd = connect(sockfd, sockaddr, sockaddr->sa_len);
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
    printk("Unsupported sockopt name: 0x%x\n", name);
    return -1;
  }
}

DEFINE_SYSCALL(setsockopt, int, fd, int, level, int, optname, gaddr_t, optval, uint, opt_len)
{
  // Darwin's optval is compatible with that of Linux
  return or_errno(setsockopt(fd, to_host_sockopt_level(level), to_host_sockopt_name(optname), guest_to_host(optval), opt_len));
}

DEFINE_SYSCALL(getsockopt, int, fd, int, level, int, optname, gaddr_t, optval, gaddr_t, opt_len)
{
  // Darwin's optval is compatible with that of Linux
  return or_errno(getsockopt(fd, to_host_sockopt_level(level), to_host_sockopt_name(optname), guest_to_host(optval), guest_to_host(opt_len)));
}

DEFINE_SYSCALL(shutdown, int, socket, int, how)
{
  return or_errno(shutdown(socket, how));
}

DEFINE_SYSCALL(sendto, int, socket, gaddr_t, buf, int, length, int, flags, gaddr_t, dest_addr, socklen_t, dest_len)
{
  return or_errno(sendto(socket, guest_to_host(buf), length, flags, NULL, 0));
}

DEFINE_SYSCALL(recvfrom, int, socket, gaddr_t, buf, int, length, int, flags, gaddr_t, addr, gaddr_t, addrlen)
{
  int ret;
  socklen_t *socklen = guest_to_host(addrlen);
  struct l_sockaddr *sockaddr = guest_to_host(addr);

  ret = or_errno(recvfrom(socket, guest_to_host(buf), length, flags, (void*)sockaddr, socklen));
  to_linux_sockaddr(sockaddr, (struct sockaddr*)sockaddr, socklen);

  return ret;
}

DEFINE_SYSCALL(listen, int, socket, int, backlog)
{
  return or_errno(listen(socket, backlog));
}

DEFINE_SYSCALL(accept, int, sockfd, gaddr_t, addr, gaddr_t, addrlen)
{
  int ret;
  socklen_t *socklen = guest_to_host(addrlen);
  struct l_sockaddr *sockaddr = guest_to_host(addr);

  ret = or_errno(accept(sockfd, (void*)sockaddr, socklen));
  to_linux_sockaddr(sockaddr, (struct sockaddr*)sockaddr, socklen);

  return ret;
}

DEFINE_SYSCALL(bind, int, sockfd, gaddr_t, addr, int, addrlen)
{
  int ret;
  struct sockaddr *sockaddr;

  if (to_host_sockaddr(&sockaddr, guest_to_host(addr), addrlen) < 0) {
    return -EINVAL;
  }
  ret = or_errno(bind(sockfd, sockaddr, addrlen));

  free(sockaddr);
  return ret;
}

DEFINE_SYSCALL(getsockname, int, sockfd, gaddr_t, addr, gaddr_t, addrlen)
{
  int ret;
  socklen_t *socklen = guest_to_host(addrlen);
  struct l_sockaddr *sockaddr = guest_to_host(addr);

  ret = or_errno(getsockname(sockfd, (void*)sockaddr, socklen));
  to_linux_sockaddr(sockaddr, (struct sockaddr*)sockaddr, socklen);

  return ret;
}

DEFINE_SYSCALL(getpeername, int, sockfd, gaddr_t, addr, gaddr_t, addrlen)
{
  int ret;
  socklen_t *socklen = guest_to_host(addrlen);
  struct l_sockaddr *sockaddr = guest_to_host(addr);

  ret = or_errno(getpeername(sockfd, (void*)sockaddr, socklen));
  to_linux_sockaddr(sockaddr, (struct sockaddr*)sockaddr, socklen);

  return ret;
}
