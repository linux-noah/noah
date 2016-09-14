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
#include <limits.h>

#include "linux/common.h"
#include "linux/socket.h"
#include "linux/misc.h"

DEFINE_SYSCALL(socket, int, family, int, type, int, protocol)
{
  /* FIXME */
  type &= ~LINUX_SOCK_NONBLOCK;
  type &= ~LINUX_SOCK_CLOEXEC;

  return syswrap(socket(linux_to_darwin_sa_family(family), type, protocol));
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

  case AF_INET6:
    assert(l_sockaddr_len != sizeof(struct sockaddr_in6) - sizeof(uint32_t));
    (*sockaddr)->sa_len = l_sockaddr_len;
    break;

  default:
    fprintf(stderr, "Unimplemented sa_family: 0x%x(%s)\n", linux_to_darwin_sa_family(l_sockaddr->sa_family), linux_sa_family_str(l_sockaddr->sa_family));
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
  return syswrap(setsockopt(fd, to_host_sockopt_level(level), to_host_sockopt_name(optname), guest_to_host(optval), opt_len));
}

DEFINE_SYSCALL(getsockopt, int, fd, int, level, int, optname, gaddr_t, optval, gaddr_t, opt_len)
{
  // Darwin's optval is compatible with that of Linux
  return syswrap(getsockopt(fd, to_host_sockopt_level(level), to_host_sockopt_name(optname), guest_to_host(optval), guest_to_host(opt_len)));
}

DEFINE_SYSCALL(shutdown, int, socket, int, how)
{
  return syswrap(shutdown(socket, how));
}

DEFINE_SYSCALL(sendto, int, socket, gaddr_t, buf, int, length, int, flags, gaddr_t, dest_addr, socklen_t, dest_len)
{
  return syswrap(sendto(socket, guest_to_host(buf), length, flags, NULL, 0));
}

int
linux_to_darwin_msg_flags(l_int flags)
{
  int ret = 0;
  if (flags & LINUX_MSG_OOB) {
    ret |= MSG_OOB;
    flags &= ~LINUX_MSG_OOB;
  }
  if (flags & LINUX_MSG_PEEK) {
    ret |= MSG_PEEK;
    flags &= ~LINUX_MSG_PEEK;
  }
  if (flags & LINUX_MSG_DONTROUTE) {
    ret |= MSG_DONTROUTE;
    flags &= ~LINUX_MSG_DONTROUTE;
  }
  if (flags & LINUX_MSG_EOR) {
    ret |= MSG_EOR;
    flags &= ~LINUX_MSG_EOR;
  }
  if (flags & LINUX_MSG_TRUNC) {
    ret |= MSG_TRUNC;
    flags &= ~LINUX_MSG_TRUNC;
  }
  if (flags & LINUX_MSG_CTRUNC) {
    ret |= MSG_CTRUNC;
    flags &= ~LINUX_MSG_CTRUNC;
  }
  if (flags & LINUX_MSG_WAITALL) {
    ret |= MSG_WAITALL;
    flags &= ~LINUX_MSG_WAITALL;
  }
  if (flags & LINUX_MSG_DONTWAIT) {
    ret |= MSG_DONTWAIT;
    flags &= ~LINUX_MSG_DONTWAIT;
  }

  if (flags) {
    printk("unsupported msg_flags: 0x%x", flags);
    return -LINUX_EOPNOTSUPP;
  }

  return ret;
}

void
linux_to_darwin_msg_iovec(struct l_iovec *liovec, struct iovec *diovec)
{
  diovec->iov_base = guest_to_host(liovec->iov_base);
  diovec->iov_len = liovec->iov_len;
}

int
linux_to_darwin_msghdr(const struct l_msghdr *lhdr, struct iovec *diovec, struct msghdr *dhdr)
{
  if (lhdr->msg_controllen > INT_MAX) {
    return -LINUX_ENOBUFS;
  }

  dhdr->msg_name = guest_to_host(lhdr->msg_name);
  dhdr->msg_namelen = lhdr->msg_namelen;
  linux_to_darwin_msg_iovec(guest_to_host(lhdr->msg_iov), diovec);
  dhdr->msg_iov = diovec;
  dhdr->msg_iovlen = lhdr->msg_iovlen;
  dhdr->msg_control = guest_to_host(lhdr->msg_control);
  dhdr->msg_flags = linux_to_darwin_msg_flags(lhdr->msg_flags);

  if (dhdr->msg_flags < 0) {
    // unsupported flags found
    return dhdr->msg_flags;
  }

  if (LINUX_CMSG_FIRSTHDR(lhdr) != NULL) {
    printk("we do not support ancillary data yet\n");
    return -LINUX_EINVAL;
  }
  dhdr->msg_controllen = 0;

  return 0;
}

DEFINE_SYSCALL(recvfrom, int, socket, gaddr_t, buf, int, length, int, flags, gaddr_t, addr, gaddr_t, addrlen)
{
  int ret;
  socklen_t *socklen = guest_to_host(addrlen);
  struct l_sockaddr *sockaddr = guest_to_host(addr);

  ret = syswrap(recvfrom(socket, guest_to_host(buf), length, flags, (void*)sockaddr, socklen));
  to_linux_sockaddr(sockaddr, (struct sockaddr*)sockaddr, socklen);

  return ret;
}

int
do_sendmsg(int sockfd, struct l_msghdr *msg, int flags)
{
  struct msghdr dhdr;
  struct iovec diovec;
  
  int err = linux_to_darwin_msghdr(msg, &diovec, &dhdr);
  if (err < 0) {
    return err;
  }

  return syswrap(sendmsg(sockfd, &dhdr, flags));
}

DEFINE_SYSCALL(sendmsg, int, sockfd, gaddr_t, msg, int, flags)
{
  return do_sendmsg(sockfd, (struct l_msghdr*)msg, flags);
}

DEFINE_SYSCALL(sendmmsg, int, sockfd, gaddr_t, msgvec, unsigned int, vlen, unsigned int, flags)
{
  struct l_mmsghdr *msg = guest_to_host(msgvec);
  int i = 0;

  while (i < vlen) {
    int err = do_sendmsg(sockfd, &msg->msg_hdr, flags);
    if (err < 0) {
      return err;
    }
    msg->msg_len = err;

    i++;
    msg++;
  }

  return i;
}

DEFINE_SYSCALL(listen, int, socket, int, backlog)
{
  return syswrap(listen(socket, backlog));
}

DEFINE_SYSCALL(accept, int, sockfd, gaddr_t, addr, gaddr_t, addrlen)
{
  int ret;
  socklen_t *socklen = guest_to_host(addrlen);
  struct l_sockaddr *sockaddr = guest_to_host(addr);

  ret = syswrap(accept(sockfd, (void*)sockaddr, socklen));
  to_linux_sockaddr(sockaddr, (struct sockaddr*)sockaddr, socklen);

  return ret;
}

DEFINE_SYSCALL(bind, int, sockfd, gaddr_t, addr, int, addrlen)
{
  int ret;
  struct sockaddr *sockaddr;

  if (to_host_sockaddr(&sockaddr, guest_to_host(addr), addrlen) < 0) {
    return -LINUX_EINVAL;
  }
  ret = syswrap(bind(sockfd, sockaddr, addrlen));

  free(sockaddr);
  return ret;
}

DEFINE_SYSCALL(getsockname, int, sockfd, gaddr_t, addr, gaddr_t, addrlen)
{
  int ret;
  socklen_t *socklen = guest_to_host(addrlen);
  struct l_sockaddr *sockaddr = guest_to_host(addr);

  ret = syswrap(getsockname(sockfd, (void*)sockaddr, socklen));
  to_linux_sockaddr(sockaddr, (struct sockaddr*)sockaddr, socklen);

  return ret;
}

DEFINE_SYSCALL(getpeername, int, sockfd, gaddr_t, addr, gaddr_t, addrlen)
{
  int ret;
  socklen_t *socklen = guest_to_host(addrlen);
  struct l_sockaddr *sockaddr = guest_to_host(addr);

  ret = syswrap(getpeername(sockfd, (void*)sockaddr, socklen));
  to_linux_sockaddr(sockaddr, (struct sockaddr*)sockaddr, socklen);

  return ret;
}
