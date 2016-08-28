#ifndef NOAH_LINUX_ERRNO_H
#define NOAH_LINUX_ERRNO_H

#include <errno.h>

#define LINUX_EPERM           1
#define LINUX_ENOENT          2
#define LINUX_ESRCH           3
#define LINUX_EINTR           4
#define LINUX_EIO             5
#define LINUX_ENXIO           6
#define LINUX_E2BIG           7
#define LINUX_ENOEXEC         8
#define LINUX_EBADF           9
#define LINUX_ECHILD          10
#define LINUX_EAGAIN          11
#define LINUX_ENOMEM          12
#define LINUX_EACCES          13
#define LINUX_EFAULT          14
#define LINUX_ENOTBLK         15
#define LINUX_EBUSY           16
#define LINUX_EEXIST          17
#define LINUX_EXDEV           18
#define LINUX_ENODEV          19
#define LINUX_ENOTDIR         20
#define LINUX_EISDIR          21
#define LINUX_EINVAL          22
#define LINUX_ENFILE          23
#define LINUX_EMFILE          24
#define LINUX_ENOTTY          25
#define LINUX_ETXTBSY         26
#define LINUX_EFBIG           27
#define LINUX_ENOSPC          28
#define LINUX_ESPIPE          29
#define LINUX_EROFS           30
#define LINUX_EMLINK          31
#define LINUX_EPIPE           32
#define LINUX_EDOM            33
#define LINUX_ERANGE          34
#define LINUX_EDEADLK         35
#define LINUX_ENAMETOOLONG    36
#define LINUX_ENOLCK          37
#define LINUX_ENOSYS          38
#define LINUX_ENOTEMPTY       39
#define LINUX_ELOOP           40
#define LINUX_EWOULDBLOCK     LINUX_EAGAIN
#define LINUX_ENOMSG          42
#define LINUX_EIDRM           43
#define LINUX_ECHRNG          44
#define LINUX_EL2NSYNC        45
#define LINUX_EL3HLT          46
#define LINUX_EL3RST          47
#define LINUX_ELNRNG          48
#define LINUX_EUNATCH         49
#define LINUX_ENOCSI          50
#define LINUX_EL2HLT          51
#define LINUX_EBADE           52
#define LINUX_EBADR           53
#define LINUX_EXFULL          54
#define LINUX_ENOANO          55
#define LINUX_EBADRQC         56
#define LINUX_EBADSLT         57
#define LINUX_EDEADLOCK       LINUX_EDEADLK
#define LINUX_EBFONT          59
#define LINUX_ENOSTR          60
#define LINUX_ENODATA         61
#define LINUX_ETIME           62
#define LINUX_ENOSR           63
#define LINUX_ENONET          64
#define LINUX_ENOPKG          65
#define LINUX_EREMOTE         66
#define LINUX_ENOLINK         67
#define LINUX_EADV            68
#define LINUX_ESRMNT          69
#define LINUX_ECOMM           70
#define LINUX_EPROTO          71
#define LINUX_EMULTIHOP       72
#define LINUX_EDOTDOT         73
#define LINUX_EBADMSG         74
#define LINUX_EOVERFLOW       75
#define LINUX_ENOTUNIQ        76
#define LINUX_EBADFD          77
#define LINUX_EREMCHG         78
#define LINUX_ELIBACC         79
#define LINUX_ELIBBAD         80
#define LINUX_ELIBSCN         81
#define LINUX_ELIBMAX         82
#define LINUX_ELIBEXEC        83
#define LINUX_EILSEQ          84
#define LINUX_ERESTART        85
#define LINUX_ESTRPIPE        86
#define LINUX_EUSERS          87
#define LINUX_ENOTSOCK        88
#define LINUX_EDESTADDRREQ    89
#define LINUX_EMSGSIZE        90
#define LINUX_EPROTOTYPE      91
#define LINUX_ENOPROTOOPT     92
#define LINUX_EPROTONOSUPPORT 93
#define LINUX_ESOCKTNOSUPPORT 94
#define LINUX_EOPNOTSUPP      95
#define LINUX_ENOTSUP         LINUX_EOPNOTSUPP
#define LINUX_EPFNOSUPPORT    96
#define LINUX_EAFNOSUPPORT    97
#define LINUX_EADDRINUSE      98
#define LINUX_EADDRNOTAVAIL   99
#define LINUX_ENETDOWN        100
#define LINUX_ENETUNREACH     101
#define LINUX_ENETRESET       102
#define LINUX_ECONNABORTED    103
#define LINUX_ECONNRESET      104
#define LINUX_ENOBUFS         105
#define LINUX_EISCONN         106
#define LINUX_ENOTCONN        107
#define LINUX_ESHUTDOWN       108
#define LINUX_ETOOMANYREFS    109
#define LINUX_ETIMEDOUT       110
#define LINUX_ECONNREFUSED    111
#define LINUX_EHOSTDOWN       112
#define LINUX_EHOSTUNREACH    113
#define LINUX_EALREADY        114
#define LINUX_EINPROGRESS     115
#define LINUX_ESTALE          116
#define LINUX_EUCLEAN         117
#define LINUX_ENOTNAM         118
#define LINUX_ENAVAIL         119
#define LINUX_EISNAM          120
#define LINUX_EREMOTEIO       121
#define LINUX_EDQUOT          122
#define LINUX_ENOMEDIUM       123
#define LINUX_EMEDIUMTYPE     124
#define LINUX_ECANCELED       125
#define LINUX_ENOKEY          126
#define LINUX_EKEYEXPIRED     127
#define LINUX_EKEYREVOKED     128
#define LINUX_EKEYREJECTED    129
#define LINUX_EOWNERDEAD      130
#define LINUX_ENOTRECOVERABLE 131
#define LINUX_ERFKILL         132
#define LINUX_EHWPOISON       133


#define ERRNO_MAP(_) \
  CONST_MAP_BIDR(_, LINUX_EPERM,              EPERM)               \
  CONST_MAP_BIDR(_, LINUX_ENOENT,             ENOENT)              \
  CONST_MAP_BIDR(_, LINUX_ESRCH,              ESRCH)               \
  CONST_MAP_BIDR(_, LINUX_EINTR,              EINTR)               \
  CONST_MAP_BIDR(_, LINUX_EIO,                EIO)                 \
  CONST_MAP_BIDR(_, LINUX_ENXIO,              ENXIO)               \
  CONST_MAP_BIDR(_, LINUX_E2BIG,              E2BIG)               \
  CONST_MAP_BIDR(_, LINUX_ENOEXEC,            ENOEXEC)             \
  CONST_MAP_BIDR(_, LINUX_EBADF,              EBADF)               \
  CONST_MAP_BIDR(_, LINUX_ECHILD,             ECHILD)              \
  CONST_MAP_BIDR(_, LINUX_EAGAIN,             EAGAIN)              \
  CONST_MAP_BIDR(_, LINUX_ENOMEM,             ENOMEM)              \
  CONST_MAP_BIDR(_, LINUX_EACCES,             EACCES)              \
  CONST_MAP_BIDR(_, LINUX_EFAULT,             EFAULT)              \
  CONST_MAP_BIDR(_, LINUX_ENOTBLK,            ENOTBLK)             \
  CONST_MAP_BIDR(_, LINUX_EBUSY,              EBUSY)               \
  CONST_MAP_BIDR(_, LINUX_EEXIST,             EEXIST)              \
  CONST_MAP_BIDR(_, LINUX_EXDEV,              EXDEV)               \
  CONST_MAP_BIDR(_, LINUX_ENODEV,             ENODEV)              \
  CONST_MAP_BIDR(_, LINUX_ENOTDIR,            ENOTDIR)             \
  CONST_MAP_BIDR(_, LINUX_EISDIR,             EISDIR)              \
  CONST_MAP_BIDR(_, LINUX_EINVAL,             EINVAL)              \
  CONST_MAP_BIDR(_, LINUX_ENFILE,             ENFILE)              \
  CONST_MAP_BIDR(_, LINUX_EMFILE,             EMFILE)              \
  CONST_MAP_BIDR(_, LINUX_ENOTTY,             ENOTTY)              \
  CONST_MAP_BIDR(_, LINUX_ETXTBSY,            ETXTBSY)             \
  CONST_MAP_BIDR(_, LINUX_EFBIG,              EFBIG)               \
  CONST_MAP_BIDR(_, LINUX_ENOSPC,             ENOSPC)              \
  CONST_MAP_BIDR(_, LINUX_ESPIPE,             ESPIPE)              \
  CONST_MAP_BIDR(_, LINUX_EROFS,              EROFS)               \
  CONST_MAP_BIDR(_, LINUX_EMLINK,             EMLINK)              \
  CONST_MAP_BIDR(_, LINUX_EPIPE,              EPIPE)               \
  CONST_MAP_BIDR(_, LINUX_EDOM,               EDOM)                \
  CONST_MAP_BIDR(_, LINUX_ERANGE,             ERANGE)              \
  CONST_MAP_BIDR(_, LINUX_EDEADLK,            EDEADLK)             \
  CONST_MAP_BIDR(_, LINUX_ENAMETOOLONG,       ENAMETOOLONG)        \
  CONST_MAP_BIDR(_, LINUX_ENOLCK,             ENOLCK)              \
  CONST_MAP_BIDR(_, LINUX_ENOSYS,             ENOSYS)              \
  CONST_MAP_BIDR(_, LINUX_ENOTEMPTY,          ENOTEMPTY)           \
  CONST_MAP_BIDR(_, LINUX_ELOOP,              ELOOP)               \
  CONST_MAP_BIDR(_, LINUX_ENOMSG,             ENOMSG)              \
  CONST_MAP_BIDR(_, LINUX_EIDRM,              EIDRM)               \
  CONST_MAP_BIDR(_, LINUX_ENOSTR,             ENOSTR)              \
  CONST_MAP_BIDR(_, LINUX_ENODATA,            ENODATA)             \
  CONST_MAP_BIDR(_, LINUX_ETIME,              ETIME)               \
  CONST_MAP_BIDR(_, LINUX_ENOSR,              ENOSR)               \
  CONST_MAP_BIDR(_, LINUX_EREMOTE,            EREMOTE)             \
  CONST_MAP_BIDR(_, LINUX_ENOLINK,            ENOLINK)             \
  CONST_MAP_BIDR(_, LINUX_EPROTO,             EPROTO)              \
  CONST_MAP_BIDR(_, LINUX_EMULTIHOP,          EMULTIHOP)           \
  CONST_MAP_BIDR(_, LINUX_EBADMSG,            EBADMSG)             \
  CONST_MAP_BIDR(_, LINUX_EOVERFLOW,          EOVERFLOW)           \
  CONST_MAP_BIDR(_, LINUX_EILSEQ,             EILSEQ)              \
  CONST_MAP_BIDR(_, LINUX_EUSERS,             EUSERS)              \
  CONST_MAP_BIDR(_, LINUX_ENOTSOCK,           ENOTSOCK)            \
  CONST_MAP_BIDR(_, LINUX_EDESTADDRREQ,       EDESTADDRREQ)        \
  CONST_MAP_BIDR(_, LINUX_EMSGSIZE,           EMSGSIZE)            \
  CONST_MAP_BIDR(_, LINUX_EPROTOTYPE,         EPROTOTYPE)          \
  CONST_MAP_BIDR(_, LINUX_ENOPROTOOPT,        ENOPROTOOPT)         \
  CONST_MAP_BIDR(_, LINUX_EPROTONOSUPPORT,    EPROTONOSUPPORT)     \
  CONST_MAP_BIDR(_, LINUX_ESOCKTNOSUPPORT,    ESOCKTNOSUPPORT)     \
  CONST_MAP_BIDR(_, LINUX_ENOTSUP,            ENOTSUP)             \
  CONST_MAP_BIDR(_, LINUX_EPFNOSUPPORT,       EPFNOSUPPORT)        \
  CONST_MAP_BIDR(_, LINUX_EAFNOSUPPORT,       EAFNOSUPPORT)        \
  CONST_MAP_BIDR(_, LINUX_EADDRINUSE,         EADDRINUSE)          \
  CONST_MAP_BIDR(_, LINUX_EADDRNOTAVAIL,      EADDRNOTAVAIL)       \
  CONST_MAP_BIDR(_, LINUX_ENETDOWN,           ENETDOWN)            \
  CONST_MAP_BIDR(_, LINUX_ENETUNREACH,        ENETUNREACH)         \
  CONST_MAP_BIDR(_, LINUX_ENETRESET,          ENETRESET)           \
  CONST_MAP_BIDR(_, LINUX_ECONNABORTED,       ECONNABORTED)        \
  CONST_MAP_BIDR(_, LINUX_ECONNRESET,         ECONNRESET)          \
  CONST_MAP_BIDR(_, LINUX_ENOBUFS,            ENOBUFS)             \
  CONST_MAP_BIDR(_, LINUX_EISCONN,            EISCONN)             \
  CONST_MAP_BIDR(_, LINUX_ENOTCONN,           ENOTCONN)            \
  CONST_MAP_BIDR(_, LINUX_ESHUTDOWN,          ESHUTDOWN)           \
  CONST_MAP_BIDR(_, LINUX_ETOOMANYREFS,       ETOOMANYREFS)        \
  CONST_MAP_BIDR(_, LINUX_ETIMEDOUT,          ETIMEDOUT)           \
  CONST_MAP_BIDR(_, LINUX_ECONNREFUSED,       ECONNREFUSED)        \
  CONST_MAP_BIDR(_, LINUX_EHOSTDOWN,          EHOSTDOWN)           \
  CONST_MAP_BIDR(_, LINUX_EHOSTUNREACH,       EHOSTUNREACH)        \
  CONST_MAP_BIDR(_, LINUX_EALREADY,           EALREADY)            \
  CONST_MAP_BIDR(_, LINUX_EINPROGRESS,        EINPROGRESS)         \
  CONST_MAP_BIDR(_, LINUX_ESTALE,             ESTALE)              \
  CONST_MAP_BIDR(_, LINUX_EDQUOT,             EDQUOT)              \
  CONST_MAP_BIDR(_, LINUX_ECANCELED,          ECANCELED)           \
  CONST_MAP_BIDR(_, LINUX_EOWNERDEAD,         EOWNERDEAD)          \
  CONST_MAP_BIDR(_, LINUX_ENOTRECOVERABLE,    ENOTRECOVERABLE)     \
  /* Darwin Specifig errno */                                      \
  CONST_MAP_RTOL(_, EPERM,                    EFTYPE)              \
  CONST_MAP_RTOL(_, EPERM,                    EAUTH)               \
  CONST_MAP_RTOL(_, EPERM,                    ENEEDAUTH)           \
  CONST_MAP_RTOL(_, ENOEXEC,                  EBADEXEC)            \
  CONST_MAP_RTOL(_, ENOEXEC,                  EBADARCH)            \
  CONST_MAP_RTOL(_, ENOEXEC,                  EBADMACHO)           \
  CONST_MAP_RTOL(_, ENODATA,                  ENOATTR)             \
  CONST_MAP_RTOL(_, EPERM,                    ENOPOLICY)           \
  CONST_MAP_RTOL(_, EPERM,                    EBADRPC)             \

DECLARE_MAP_FUNC(darwin_to_linux, errno, ERRNO_MAP);

#endif
