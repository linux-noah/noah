#define _STRINGIFY(x) #x
#define STRINGIFY(x) _STRINGIFY(x)

#define assert_true(val) do \
{  \
  if ((val)) {\
    write(1, ".", 1);\
  } else {\
    char m[] = "Assertion failed, " __FILE__ ":" STRINGIFY(__LINE__) "\n";\
    write(1, "F", 1);\
    write(2, m, sizeof(m) - 1);\
  }\
} while(0)
