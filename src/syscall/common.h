#include <stdint.h>

/*
 * ``_MAP(f, t0, v0, t1, v1, ...)'' => ``f(t0, v0), f(t1, v1), ...''
 */

#define _MAP(f,...) _DISPATCH(__VA_ARGS__,_MAP7,,_MAP6,,_MAP5,,_MAP4,,_MAP3,,_MAP2,,_MAP1,_MAP0)(f,__VA_ARGS__)
#define _MAP0(f,...)
#define _MAP1(f,t,v)     f(t,v)
#define _MAP2(f,t,v,...) f(t,v), _MAP1(f,__VA_ARGS__)
#define _MAP3(f,t,v,...) f(t,v), _MAP2(f,__VA_ARGS__)
#define _MAP4(f,t,v,...) f(t,v), _MAP3(f,__VA_ARGS__)
#define _MAP5(f,t,v,...) f(t,v), _MAP4(f,__VA_ARGS__)
#define _MAP6(f,t,v,...) f(t,v), _MAP5(f,__VA_ARGS__)
#define _MAP7(f,t,v,...) f(t,v), _MAP6(f,__VA_ARGS__)
#define _DISPATCH(T0,V0,T1,V1,T2,V2,T3,V3,T4,V4,T5,V5,T6,V6,X,...) X

#define MK_DECL(t,v) t v
#define MK_TEMP(t,v) uint64_t temp__##v
#define MK_CAST(t,v) (t) temp__##v

#define DECLARE_SCFUNCT(name, ...)                      \
  uint64_t _sys_##name(_MAP(MK_DECL, __VA_ARGS__));

#define DEFINE_SCWRAPPER(name, ...)                                     \
  uint64_t sys_##name(_MAP(MK_TEMP,__VA_ARGS__)) {                      \
    uint64_t ret = _sys_##name(_MAP(MK_CAST,__VA_ARGS__));              \
    _noah_strace(#name, ret, _MAP(MK_STRACE_CALL, ##__VA_ARGS__, 0, 0)); \
    return ret;                                                         \
  }

#define DEFINE_SCFUNCT(name, ...)                       \
  uint64_t _sys_##name(_MAP(MK_DECL, __VA_ARGS__))

#define DEFINE_SYSCALL(name, ...)               \
  DECLARE_SCFUNCT(name, ##__VA_ARGS__)          \
  DEFINE_SCWRAPPER(name, ##__VA_ARGS__)         \
  DEFINE_SCFUNCT(name, ##__VA_ARGS__)


/*
 * strace related macros
 */

#define MK_STRACE_CALL(t,v) #t, #v, temp__##v
#define temp__0             0  // argument terminator

#ifdef DEBUG_MODE
#define _noah_strace noah_strace
#else
#define _noah_strace(...) 
#endif


/*
 *  Constant conversion macros.
 */

#define DECL_LINUX_linux_to_darwin(linux, val, darwin, ...) case linux: return (darwin);
#define DECL_ALIAS_linux_to_darwin(linux, darwin) 
#define FROM_DARWN_linux_to_darwin(linux, darwin)           case linux: return (dawrin);

#define DECL_LINUX_darwin_to_linux(linux, val, darwin, ...) case darwin: return (linux);
#define DECL_ALIAS_darwin_to_linux(linux, darwin) 
#define FROM_DARWN_darwin_to_linux(linux, darwin)           case darwin: return (linux);

#define DECL_LINUX_constant(const_name, val, ...) const_name = val,
#define DECL_ALIAS_constant(const_name, val)      const_name = val,
#define FROM_DARWN_constant(const_name, val) 

#define DECL_LINUX_strtable(const_name, val, ...) case val: return #const_name;
#define DECL_ALIAS_strtable(const_name, val)
#define FROM_DARWN_strtable(const_name, val)

#define DECL_LINUX(tag, const_name, val, ...) DECL_LINUX_ ## tag (LINUX_ ## const_name, val, ##__VA_ARGS__, const_name)
#define DECL_ALIAS(tag, const_name, val)      DECL_ALIAS_ ## tag (LINUX_ ## const_name, val)
#define FROM_DARWN(tag, const_name, val)      FROM_DARWN_ ## tag (LINUX_ ## const_name, val)

#define LINUX_SPECIFIC (-10 -__COUNTER__)  // Unique value that does not conflict with any linux constants

#define DECLARE_CSTR_FUNC(const_id, const_list) \
  static inline char * linux_##const_id##_##str(int val) {\
    switch (val) { \
      const_list(strtable)\
    }\
    return "(No " #const_id " Matched)";\
  }


#define DECLARE_CMAP_FUNC(tag, const_id, const_list)  \
  static inline int tag ## _ ## const_id (int val) {  \
    switch (val) {                                         \
      const_list(tag)                                \
    }                                                      \
    return -1;                                             \
  }

#define DECLARE_CENUM(const_id, const_list) \
  enum linux_##const_id { \
    const_list(constant)\
  };

#include "linux/errno.h"
