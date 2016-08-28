#include <stdint.h>

/*
 * ``_MAP(f, t0, v0, t1, v1, ...)'' => ``f(t0, v0), f(t1, v1), ...''
 */

#define _MAP(f,...) _DISPATCH(__VA_ARGS__,_MAP6,,_MAP5,,_MAP4,,_MAP3,,_MAP2,,_MAP1,_MAP0)(f,__VA_ARGS__)
#define _MAP0(f,...)
#define _MAP1(f,t,v)     f(t,v)
#define _MAP2(f,t,v,...) f(t,v), _MAP1(f,__VA_ARGS__)
#define _MAP3(f,t,v,...) f(t,v), _MAP2(f,__VA_ARGS__)
#define _MAP4(f,t,v,...) f(t,v), _MAP3(f,__VA_ARGS__)
#define _MAP5(f,t,v,...) f(t,v), _MAP4(f,__VA_ARGS__)
#define _MAP6(f,t,v,...) f(t,v), _MAP5(f,__VA_ARGS__)
#define _DISPATCH(T0,V0,T1,V1,T2,V2,T3,V3,T4,V4,T5,V5,X,...) X

#define MK_DECL(t,v) t v
#define MK_TEMP(t,v) uint64_t temp__##v
#define MK_CAST(t,v) (t) temp__##v

#define DECLARE_SCFUNCT(name, ...)                      \
  uint64_t _sys_##name(_MAP(MK_DECL, __VA_ARGS__));

#define DEFINE_SCWRAPPER(name, ...)                     \
  uint64_t sys_##name(_MAP(MK_TEMP,__VA_ARGS__)) {    \
    return _sys_##name(_MAP(MK_CAST,__VA_ARGS__));    \
  }

#define DEFINE_SCFUNCT(name, ...)                       \
  uint64_t _sys_##name(_MAP(MK_DECL, __VA_ARGS__))

#define DEFINE_SYSCALL(name, ...)               \
  DECLARE_SCFUNCT(name, __VA_ARGS__)            \
  DEFINE_SCWRAPPER(name, __VA_ARGS__)           \
  DEFINE_SCFUNCT(name, __VA_ARGS__)


/*
 *  Constant conversion macros.
 */

#define _CMAP_BIDR_darwin_to_linux(linux, darwin) case darwin: return (linux);
#define _CMAP_BIDR_linux_to_darwin(linux, darwin) case linux: return (darwin);
#define _CMAP_LTOR_darwin_to_linux(linux, darwin) 
#define _CMAP_LTOR_linux_to_darwin(linux, darwin) case linux: return (darwin);
#define _CMAP_RTOL_darwin_to_linux(linux, darwin) case darwin: return (linux);
#define _CMAP_RTOL_linux_to_darwin(linux, darwin) 

#define CMAP_BIDR(direction, linux, darwin) _CMAP_BIDR_ ## direction (linux, darwin)
#define CMAP_LTOD(direction, linux, darwin) _CMAP_LTOR_ ## direction (linux, darwin)
#define CMAP_DTOL(direction, linux, darwin) _CMAP_RTOL_ ## direction (linux, darwin)

#define DECLARE_CMAP_FUNC(direction, const_id, const_list)  \
  static inline int direction ## _ ## const_id (int val) {  \
    switch (val) {                                         \
      const_list(direction)                                \
    }                                                      \
    return -1;                                             \
  }

