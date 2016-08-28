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
  CMAP_BIDR(_, LINUX_EPERM,              EPERM)               \
  CMAP_BIDR(_, LINUX_ENOENT,             ENOENT)              \
  CMAP_BIDR(_, LINUX_ESRCH,              ESRCH)               \
  CMAP_BIDR(_, LINUX_EINTR,              EINTR)               \
  CMAP_BIDR(_, LINUX_EIO,                EIO)                 \
  CMAP_BIDR(_, LINUX_ENXIO,              ENXIO)               \
  CMAP_BIDR(_, LINUX_E2BIG,              E2BIG)               \
  CMAP_BIDR(_, LINUX_ENOEXEC,            ENOEXEC)             \
  CMAP_BIDR(_, LINUX_EBADF,              EBADF)               \
  CMAP_BIDR(_, LINUX_ECHILD,             ECHILD)              \
  CMAP_BIDR(_, LINUX_EAGAIN,             EAGAIN)              \
  CMAP_BIDR(_, LINUX_ENOMEM,             ENOMEM)              \
  CMAP_BIDR(_, LINUX_EACCES,             EACCES)              \
  CMAP_BIDR(_, LINUX_EFAULT,             EFAULT)              \
  CMAP_BIDR(_, LINUX_ENOTBLK,            ENOTBLK)             \
  CMAP_BIDR(_, LINUX_EBUSY,              EBUSY)               \
  CMAP_BIDR(_, LINUX_EEXIST,             EEXIST)              \
  CMAP_BIDR(_, LINUX_EXDEV,              EXDEV)               \
  CMAP_BIDR(_, LINUX_ENODEV,             ENODEV)              \
  CMAP_BIDR(_, LINUX_ENOTDIR,            ENOTDIR)             \
  CMAP_BIDR(_, LINUX_EISDIR,             EISDIR)              \
  CMAP_BIDR(_, LINUX_EINVAL,             EINVAL)              \
  CMAP_BIDR(_, LINUX_ENFILE,             ENFILE)              \
  CMAP_BIDR(_, LINUX_EMFILE,             EMFILE)              \
  CMAP_BIDR(_, LINUX_ENOTTY,             ENOTTY)              \
  CMAP_BIDR(_, LINUX_ETXTBSY,            ETXTBSY)             \
  CMAP_BIDR(_, LINUX_EFBIG,              EFBIG)               \
  CMAP_BIDR(_, LINUX_ENOSPC,             ENOSPC)              \
  CMAP_BIDR(_, LINUX_ESPIPE,             ESPIPE)              \
  CMAP_BIDR(_, LINUX_EROFS,              EROFS)               \
  CMAP_BIDR(_, LINUX_EMLINK,             EMLINK)              \
  CMAP_BIDR(_, LINUX_EPIPE,              EPIPE)               \
  CMAP_BIDR(_, LINUX_EDOM,               EDOM)                \
  CMAP_BIDR(_, LINUX_ERANGE,             ERANGE)              \
  CMAP_BIDR(_, LINUX_EDEADLK,            EDEADLK)             \
  CMAP_BIDR(_, LINUX_ENAMETOOLONG,       ENAMETOOLONG)        \
  CMAP_BIDR(_, LINUX_ENOLCK,             ENOLCK)              \
  CMAP_BIDR(_, LINUX_ENOSYS,             ENOSYS)              \
  CMAP_BIDR(_, LINUX_ENOTEMPTY,          ENOTEMPTY)           \
  CMAP_BIDR(_, LINUX_ELOOP,              ELOOP)               \
  CMAP_BIDR(_, LINUX_ENOMSG,             ENOMSG)              \
  CMAP_BIDR(_, LINUX_EIDRM,              EIDRM)               \
  CMAP_BIDR(_, LINUX_ENOSTR,             ENOSTR)              \
  CMAP_BIDR(_, LINUX_ENODATA,            ENODATA)             \
  CMAP_BIDR(_, LINUX_ETIME,              ETIME)               \
  CMAP_BIDR(_, LINUX_ENOSR,              ENOSR)               \
  CMAP_BIDR(_, LINUX_EREMOTE,            EREMOTE)             \
  CMAP_BIDR(_, LINUX_ENOLINK,            ENOLINK)             \
  CMAP_BIDR(_, LINUX_EPROTO,             EPROTO)              \
  CMAP_BIDR(_, LINUX_EMULTIHOP,          EMULTIHOP)           \
  CMAP_BIDR(_, LINUX_EBADMSG,            EBADMSG)             \
  CMAP_BIDR(_, LINUX_EOVERFLOW,          EOVERFLOW)           \
  CMAP_BIDR(_, LINUX_EILSEQ,             EILSEQ)              \
  CMAP_BIDR(_, LINUX_EUSERS,             EUSERS)              \
  CMAP_BIDR(_, LINUX_ENOTSOCK,           ENOTSOCK)            \
  CMAP_BIDR(_, LINUX_EDESTADDRREQ,       EDESTADDRREQ)        \
  CMAP_BIDR(_, LINUX_EMSGSIZE,           EMSGSIZE)            \
  CMAP_BIDR(_, LINUX_EPROTOTYPE,         EPROTOTYPE)          \
  CMAP_BIDR(_, LINUX_ENOPROTOOPT,        ENOPROTOOPT)         \
  CMAP_BIDR(_, LINUX_EPROTONOSUPPORT,    EPROTONOSUPPORT)     \
  CMAP_BIDR(_, LINUX_ESOCKTNOSUPPORT,    ESOCKTNOSUPPORT)     \
  CMAP_BIDR(_, LINUX_ENOTSUP,            ENOTSUP)             \
  CMAP_BIDR(_, LINUX_EPFNOSUPPORT,       EPFNOSUPPORT)        \
  CMAP_BIDR(_, LINUX_EAFNOSUPPORT,       EAFNOSUPPORT)        \
  CMAP_BIDR(_, LINUX_EADDRINUSE,         EADDRINUSE)          \
  CMAP_BIDR(_, LINUX_EADDRNOTAVAIL,      EADDRNOTAVAIL)       \
  CMAP_BIDR(_, LINUX_ENETDOWN,           ENETDOWN)            \
  CMAP_BIDR(_, LINUX_ENETUNREACH,        ENETUNREACH)         \
  CMAP_BIDR(_, LINUX_ENETRESET,          ENETRESET)           \
  CMAP_BIDR(_, LINUX_ECONNABORTED,       ECONNABORTED)        \
  CMAP_BIDR(_, LINUX_ECONNRESET,         ECONNRESET)          \
  CMAP_BIDR(_, LINUX_ENOBUFS,            ENOBUFS)             \
  CMAP_BIDR(_, LINUX_EISCONN,            EISCONN)             \
  CMAP_BIDR(_, LINUX_ENOTCONN,           ENOTCONN)            \
  CMAP_BIDR(_, LINUX_ESHUTDOWN,          ESHUTDOWN)           \
  CMAP_BIDR(_, LINUX_ETOOMANYREFS,       ETOOMANYREFS)        \
  CMAP_BIDR(_, LINUX_ETIMEDOUT,          ETIMEDOUT)           \
  CMAP_BIDR(_, LINUX_ECONNREFUSED,       ECONNREFUSED)        \
  CMAP_BIDR(_, LINUX_EHOSTDOWN,          EHOSTDOWN)           \
  CMAP_BIDR(_, LINUX_EHOSTUNREACH,       EHOSTUNREACH)        \
  CMAP_BIDR(_, LINUX_EALREADY,           EALREADY)            \
  CMAP_BIDR(_, LINUX_EINPROGRESS,        EINPROGRESS)         \
  CMAP_BIDR(_, LINUX_ESTALE,             ESTALE)              \
  CMAP_BIDR(_, LINUX_EDQUOT,             EDQUOT)              \
  CMAP_BIDR(_, LINUX_ECANCELED,          ECANCELED)           \
  CMAP_BIDR(_, LINUX_EOWNERDEAD,         EOWNERDEAD)          \
  CMAP_BIDR(_, LINUX_ENOTRECOVERABLE,    ENOTRECOVERABLE)     \
  /* Darwin Specifig errno */                                      \
  CMAP_DTOL(_, EPERM,                    EFTYPE)              \
  CMAP_DTOL(_, EPERM,                    EAUTH)               \
  CMAP_DTOL(_, EPERM,                    ENEEDAUTH)           \
  CMAP_DTOL(_, ENOEXEC,                  EBADEXEC)            \
  CMAP_DTOL(_, ENOEXEC,                  EBADARCH)            \
  CMAP_DTOL(_, ENOEXEC,                  EBADMACHO)           \
  CMAP_DTOL(_, ENODATA,                  ENOATTR)             \
  CMAP_DTOL(_, EPERM,                    ENOPOLICY)           \
  CMAP_DTOL(_, EPERM,                    EBADRPC)             \

DECLARE_CMAP_FUNC(darwin_to_linux, errno, ERRNO_MAP);

#endif
