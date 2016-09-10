#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <pthread.h>

#include "syscall/common.h"
#include "noah.h"


void
noah_strace(char *syscall_name, ...)
{
  va_list ap;
  va_start(ap, syscall_name);

  uint64_t tid;
  pthread_threadid_np(NULL, &tid);

  fprintf(stderr, "[%d:%lld] strace: %s(", getpid(), tid, syscall_name);
  int first = 1;
  for (;;) {
    char *type_name, *arg_name;
    uint64_t val;

    type_name = va_arg(ap, char*);
    if (type_name[0] == '0') {
      break;
    }
    arg_name = va_arg(ap, char*);
    val = va_arg(ap, uint64_t);
    
    if (first) {
      first = 0;
    } else {
      fprintf(stderr, ", ");
    }
    fprintf(stderr, "%s: ", arg_name);
    if (strcmp(type_name, "gstr_t") == 0) {
      fprintf(stderr, "\"");
      for (int i = 0; i < 100; i++) {
        char c = *((char*)guest_to_host(val) + i);
        if (c == '\0') {
          break;
        } else if (c == '\n') {
          fprintf(stderr, "\\n");
        } else if (!isprint(c)) {
          fprintf(stderr, "\\x%02x", c);
        } else {
          fprintf(stderr, "%c", c);
        }
      }
      fprintf(stderr, "\"");
    } else if (strcmp(type_name, "gaddr_t") == 0) {
      fprintf(stderr, "0x%016llx [host: 0x%016llx]", val, (uint64_t)guest_to_host(val));
    } else if (strcmp(type_name, "int") == 0) {
      fprintf(stderr, "%lld", val);
    } else {
      fprintf(stderr, "0x%llx", val);
    }
  }
  fprintf(stderr, ")");
  fflush(stderr);

  va_end(ap);
}

void
noah_strace_ret(char *syscall_name, uint64_t ret)
{
  fprintf(stderr, ": ret = 0x%llx", ret);
  if ((int64_t)ret < 0) {
    fprintf(stderr, "[%s]", linux_errno_str(-ret));
  }
  fprintf(stderr, "\n");
  fflush(stderr);
}
