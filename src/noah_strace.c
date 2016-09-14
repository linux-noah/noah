#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <pthread.h>

#include "syscall/common.h"
#include "noah.h"

static FILE *strace_sink;
pthread_mutex_t strace_sync = PTHREAD_MUTEX_INITIALIZER;

void
noah_strace(char *syscall_name, ...)
{
  static int is_initialized = false;
  if (!is_initialized) {
    init_debug_sink("strace", &strace_sink, "strace");
    is_initialized = true;
  }

  va_list ap;
  va_start(ap, syscall_name);

  uint64_t tid;
  pthread_threadid_np(NULL, &tid);

  pthread_mutex_lock(&strace_sync);
  fprintf(strace_sink, "[%d:%lld] strace: %s(", getpid(), tid, syscall_name);
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
      fprintf(strace_sink, ", ");
    }
    fprintf(strace_sink, "%s: ", arg_name);
    if (strcmp(type_name, "gstr_t") == 0) {
      fprintf(strace_sink, "\"");
      for (int i = 0; i < 100; i++) {
        char c = *((char*)guest_to_host(val) + i);
        if (c == '\0') {
          break;
        } else if (c == '\n') {
          fprintf(strace_sink, "\\n");
        } else if (!isprint(c)) {
          fprintf(strace_sink, "\\x%02x", c);
        } else {
          fprintf(strace_sink, "%c", c);
        }
      }
      fprintf(strace_sink, "\"");
    } else if (strcmp(type_name, "gaddr_t") == 0) {
      fprintf(strace_sink, "0x%016llx [host: 0x%016llx]", val, (uint64_t)guest_to_host(val));
    } else if (strcmp(type_name, "int") == 0) {
      fprintf(strace_sink, "%lld", val);
    } else {
      fprintf(strace_sink, "0x%llx", val);
    }
  }
  fprintf(strace_sink, ")");
  fflush(strace_sink);
  pthread_mutex_unlock(&strace_sync);

  va_end(ap);
}

void
noah_strace_ret(char *syscall_name, uint64_t ret)
{
  fprintf(strace_sink, ": ret = 0x%llx", ret);
  if ((int64_t)ret < 0) {
    fprintf(strace_sink, "[%s]", linux_errno_str(-ret));
  }
  fprintf(strace_sink, "\n");
  fflush(strace_sink);
}
