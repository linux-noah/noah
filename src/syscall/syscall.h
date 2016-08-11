#include <stdint.h>

typedef uint64_t (*sc_handler_t)(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);

#define KV_SEL(K0,V0,K1,V1,K2,V2,K3,V3,K4,V4,K5,V5,X,...) X

#define MAP_KV(f,...) MAP_KV_HELP(KV_SEL(__VA_ARGS__,MAP_KV6,ERROR,MAP_KV5,ERROR,MAP_KV4,ERROR,MAP_KV3,ERROR,MAP_KV2,ERROR,MAP_KV1,ERROR,MAP_KV0,ERROR),f,__VA_ARGS__)
#define MAP_KV_HELP(MAP_KVN,f,...) MAP_KVN(f,__VA_ARGS__)
#define MAP_KV0(f)
#define MAP_KV1(f,k,v)     f(k,v)
#define MAP_KV2(f,k,v,...) f(k,v), MAP_KV1(f,__VA_ARGS__)
#define MAP_KV3(f,k,v,...) f(k,v), MAP_KV2(f,__VA_ARGS__)
#define MAP_KV4(f,k,v,...) f(k,v), MAP_KV3(f,__VA_ARGS__)
#define MAP_KV5(f,k,v,...) f(k,v), MAP_KV4(f,__VA_ARGS__)
#define MAP_KV6(f,k,v,...) f(k,v), MAP_KV5(f,__VA_ARGS__)

#define MK_DECL(t,v) t v
#define MK_TEMP(t,v) uint64_t temp__##v
#define MK_CAST(t,v) (t) temp__##v

#define DECLARE_SCFUNCT(name, ...)                      \
  uint64_t _sys_##name(MAP_KV(MK_DECL, __VA_ARGS__));

#define DEFINE_SCWRAPPER(name, ...)                     \
  uint64_t sys_##name(MAP_KV(MK_TEMP,__VA_ARGS__)) {    \
    return _sys_##name(MAP_KV(MK_CAST,__VA_ARGS__));    \
  }

#define DEFINE_SCFUNCT(name, ...)                       \
  uint64_t _sys_##name(MAP_KV(MK_DECL, __VA_ARGS__))

#define DEFINE_SYSCALL(name, ...)               \
  DECLARE_SCFUNCT(name, __VA_ARGS__)            \
  DEFINE_SCWRAPPER(name, __VA_ARGS__)           \
  DEFINE_SCFUNCT(name, __VA_ARGS__)

#define SYSCALLS                                \
  SYSCALL(0, read)                              \
  SYSCALL(1, write)                             \
  SYSCALL(2, open)                              \
  SYSCALL(3, close)                             \
  SYSCALL(60, exit)                             \
  /* SYSCALL(5, fstat)                             \ */
  /* SYSCALL(12, brk)                              \ */
  /* SYSCALL(32, access)                           \ */
  /* SYSCALL(59, execve)                           \ */
  /* SYSCALL(63, uname)                            \ */
  /* SYSCALL(89, readlink)                         \ */
  /* SYSCALL(158, arch_prctl)                      \ */
  /* SYSCALL(231, exit_group) */

#define NR_SYSCALLS 256         /* FIXME */

extern sc_handler_t sc_handler_table[NR_SYSCALLS];
