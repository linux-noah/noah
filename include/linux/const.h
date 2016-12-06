#ifndef NOAH_CONST_H
#define NOAH_CONST_H

/*
 *  Constant conversion macros.
 */

#define DECL_LINUX_linux_to_darwin(linux, val, darwin, ...) case linux: return (darwin);
#define DECL_ALIAS_linux_to_darwin(linux, darwin)
#define FROM_DARWN_linux_to_darwin(linux, darwin)

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

void warnk(const char *fmt, ...) __attribute__((format(printf, 1, 2)));

#define DECLARE_CMAP_FUNC(tag, const_id, const_list)  \
  static inline int tag ## _ ## const_id (int val) {  \
    switch (val) {                                         \
      const_list(tag)                                \
    }                                                      \
    warnk("unsupported " #const_id " is converted: 0x%x\n", val);     \
    return -1;                                             \
  }

#define DECLARE_CENUM(const_id, const_list) \
  enum linux_##const_id { \
    const_list(constant)\
  };

#endif
