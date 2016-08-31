#ifndef NOAH_LINUX_ERRNO_H
#define NOAH_LINUX_ERRNO_H

#include <errno.h>

#define LINUX_ERRNO(_) \
  DECL_LINUX(_,EPERM,           1)                                  \
  DECL_LINUX(_,ENOENT,          2)                                  \
  DECL_LINUX(_,ESRCH,           3)                                  \
  DECL_LINUX(_,EINTR,           4)                                  \
  DECL_LINUX(_,EIO,             5)                                  \
  DECL_LINUX(_,ENXIO,           6)                                  \
  DECL_LINUX(_,E2BIG,           7)                                  \
  DECL_LINUX(_,ENOEXEC,         8)                                  \
  DECL_LINUX(_,EBADF,           9)                                  \
  DECL_LINUX(_,ECHILD,          10)                                 \
  DECL_LINUX(_,EAGAIN,          11)                                 \
  DECL_LINUX(_,ENOMEM,          12)                                 \
  DECL_LINUX(_,EACCES,          13)                                 \
  DECL_LINUX(_,EFAULT,          14)                                 \
  DECL_LINUX(_,ENOTBLK,         15)                                 \
  DECL_LINUX(_,EBUSY,           16)                                 \
  DECL_LINUX(_,EEXIST,          17)                                 \
  DECL_LINUX(_,EXDEV,           18)                                 \
  DECL_LINUX(_,ENODEV,          19)                                 \
  DECL_LINUX(_,ENOTDIR,         20)                                 \
  DECL_LINUX(_,EISDIR,          21)                                 \
  DECL_LINUX(_,EINVAL,          22)                                 \
  DECL_LINUX(_,ENFILE,          23)                                 \
  DECL_LINUX(_,EMFILE,          24)                                 \
  DECL_LINUX(_,ENOTTY,          25)                                 \
  DECL_LINUX(_,ETXTBSY,         26)                                 \
  DECL_LINUX(_,EFBIG,           27)                                 \
  DECL_LINUX(_,ENOSPC,          28)                                 \
  DECL_LINUX(_,ESPIPE,          29)                                 \
  DECL_LINUX(_,EROFS,           30)                                 \
  DECL_LINUX(_,EMLINK,          31)                                 \
  DECL_LINUX(_,EPIPE,           32)                                 \
  DECL_LINUX(_,EDOM,            33)                                 \
  DECL_LINUX(_,ERANGE,          34)                                 \
  DECL_LINUX(_,EDEADLK,         35)                                 \
  DECL_LINUX(_,ENAMETOOLONG,    36)                                 \
  DECL_LINUX(_,ENOLCK,          37)                                 \
  DECL_LINUX(_,ENOSYS,          38)                                 \
  DECL_LINUX(_,ENOTEMPTY,       39)                                 \
  DECL_LINUX(_,ELOOP,           40)                                 \
  DECL_ALIAS(_,EWOULDBLOCK,     LINUX_EAGAIN)                       \
  DECL_LINUX(_,ENOMSG,          42)                                 \
  DECL_LINUX(_,EIDRM,           43)                                 \
  DECL_LINUX(_,ECHRNG,          44,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EL2NSYNC,        45,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EL3HLT,          46,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EL3RST,          47,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,ELNRNG,          48,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EUNATCH,         49,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,ENOCSI,          50,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EL2HLT,          51,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EBADE,           52,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EBADR,           53,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EXFULL,          54,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,ENOANO,          55,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EBADRQC,         56,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EBADSLT,         57,               LINUX_SPECIFIC)   \
  DECL_ALIAS(_,EDEADLOCK,       LINUX_EDEADLK)                      \
  DECL_LINUX(_,EBFONT,          59,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,ENOSTR,          60)                                 \
  DECL_LINUX(_,ENODATA,         61)                                 \
  DECL_LINUX(_,ETIME,           62)                                 \
  DECL_LINUX(_,ENOSR,           63)                                 \
  DECL_LINUX(_,ENONET,          64,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,ENOPKG,          65,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EREMOTE,         66)                                 \
  DECL_LINUX(_,ENOLINK,         67)                                 \
  DECL_LINUX(_,EADV,            68,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,ESRMNT,          69,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,ECOMM,           70,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EPROTO,          71)                                 \
  DECL_LINUX(_,EMULTIHOP,       72)                                 \
  DECL_LINUX(_,EDOTDOT,         73,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EBADMSG,         74)                                 \
  DECL_LINUX(_,EOVERFLOW,       75)                                 \
  DECL_LINUX(_,ENOTUNIQ,        76,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EBADFD,          77,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EREMCHG,         78,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,ELIBACC,         79,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,ELIBBAD,         80,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,ELIBSCN,         81,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,ELIBMAX,         82,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,ELIBEXEC,        83,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EILSEQ,          84)                                 \
  DECL_LINUX(_,ERESTART,        85,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,ESTRPIPE,        86,               LINUX_SPECIFIC)   \
  DECL_LINUX(_,EUSERS,          87)                                 \
  DECL_LINUX(_,ENOTSOCK,        88)                                 \
  DECL_LINUX(_,EDESTADDRREQ,    89)                                 \
  DECL_LINUX(_,EMSGSIZE,        90)                                 \
  DECL_LINUX(_,EPROTOTYPE,      91)                                 \
  DECL_LINUX(_,ENOPROTOOPT,     92)                                 \
  DECL_LINUX(_,EPROTONOSUPPORT, 93)                                 \
  DECL_LINUX(_,ESOCKTNOSUPPORT, 94)                                 \
  DECL_LINUX(_,EOPNOTSUPP,      95)                                 \
  DECL_ALIAS(_,ENOTSUP,         LINUX_EOPNOTSUPP)                   \
  DECL_LINUX(_,EPFNOSUPPORT,    96)                                 \
  DECL_LINUX(_,EAFNOSUPPORT,    97)                                 \
  DECL_LINUX(_,EADDRINUSE,      98)                                 \
  DECL_LINUX(_,EADDRNOTAVAIL,   99)                                 \
  DECL_LINUX(_,ENETDOWN,        100)                                \
  DECL_LINUX(_,ENETUNREACH,     101)                                \
  DECL_LINUX(_,ENETRESET,       102)                                \
  DECL_LINUX(_,ECONNABORTED,    103)                                \
  DECL_LINUX(_,ECONNRESET,      104)                                \
  DECL_LINUX(_,ENOBUFS,         105)                                \
  DECL_LINUX(_,EISCONN,         106)                                \
  DECL_LINUX(_,ENOTCONN,        107)                                \
  DECL_LINUX(_,ESHUTDOWN,       108)                                \
  DECL_LINUX(_,ETOOMANYREFS,    109)                                \
  DECL_LINUX(_,ETIMEDOUT,       110)                                \
  DECL_LINUX(_,ECONNREFUSED,    111)                                \
  DECL_LINUX(_,EHOSTDOWN,       112)                                \
  DECL_LINUX(_,EHOSTUNREACH,    113)                                \
  DECL_LINUX(_,EALREADY,        114)                                \
  DECL_LINUX(_,EINPROGRESS,     115)                                \
  DECL_LINUX(_,ESTALE,          116)                                \
  DECL_LINUX(_,EUCLEAN,         117,              LINUX_SPECIFIC)   \
  DECL_LINUX(_,ENOTNAM,         118,              LINUX_SPECIFIC)   \
  DECL_LINUX(_,ENAVAIL,         119,              LINUX_SPECIFIC)   \
  DECL_LINUX(_,EISNAM,          120,              LINUX_SPECIFIC)   \
  DECL_LINUX(_,EREMOTEIO,       121,              LINUX_SPECIFIC)   \
  DECL_LINUX(_,EDQUOT,          122)                                \
  DECL_LINUX(_,ENOMEDIUM,       123,              LINUX_SPECIFIC)   \
  DECL_LINUX(_,EMEDIUMTYPE,     124,              LINUX_SPECIFIC)   \
  DECL_LINUX(_,ECANCELED,       125)                                \
  DECL_LINUX(_,ENOKEY,          126,              LINUX_SPECIFIC)   \
  DECL_LINUX(_,EKEYEXPIRED,     127,              LINUX_SPECIFIC)   \
  DECL_LINUX(_,EKEYREVOKED,     128,              LINUX_SPECIFIC)   \
  DECL_LINUX(_,EKEYREJECTED,    129,              LINUX_SPECIFIC)   \
  DECL_LINUX(_,EOWNERDEAD,      130)                                \
  DECL_LINUX(_,ENOTRECOVERABLE, 131)                                \
  DECL_LINUX(_,ERFKILL,         132,              LINUX_SPECIFIC)   \
  DECL_LINUX(_,EHWPOISON,       133,              LINUX_SPECIFIC)   \
  FROM_DARWN(_,EPERM,           EFTYPE)                             \
  FROM_DARWN(_,EPERM,           EAUTH)                              \
  FROM_DARWN(_,EPERM,           ENEEDAUTH)                          \
  FROM_DARWN(_,ENOEXEC,         EBADEXEC)                           \
  FROM_DARWN(_,ENOEXEC,         EBADARCH)                           \
  FROM_DARWN(_,ENOEXEC,         EBADMACHO)                          \
  FROM_DARWN(_,ENODATA,         ENOATTR)                            \
  FROM_DARWN(_,EPERM,           ENOPOLICY)                          \
  FROM_DARWN(_,EPERM,           EBADRPC)                            \

DECLARE_CENUM(errno, LINUX_ERRNO);
DECLARE_CSTR_FUNC(errno, LINUX_ERRNO);
DECLARE_CMAP_FUNC(darwin_to_linux, errno, LINUX_ERRNO);

static inline int or_errno(int sys_ret) {
  return (sys_ret < 0 && errno != 0) ? -errno : sys_ret ;
}

#endif
