#include <stdlib.h>
#include <stdio.h>
#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>
#include <stdarg.h>
#include <time.h>
#include <pthread.h>
#include <execinfo.h>

#include "noah.h"
#include "vmm.h"

static FILE *printk_sink;
pthread_mutex_t printk_sync = PTHREAD_MUTEX_INITIALIZER;

void
init_sink(const char *fn, FILE **sinkp, const char *name)
{
  if (! fn) {
    fn = "/dev/null";
  }
  *sinkp = fopen(fn, "w");

  char buf[1000];
  time_t now = time(0);
  struct tm tm = *gmtime(&now);
  strftime(buf, sizeof buf, "%a, %d %b %Y %H:%M:%S %Z", &tm);
  fprintf(*sinkp, "\n//==================\n");
  fprintf(*sinkp, "%s log started: [%s]\n", name, buf);
}

void
init_printk(const char *fn)
{
  init_sink(fn, &printk_sink, "printk");
}

void
printk(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);

  if (!printk_sink) {
    va_end(ap);
    return;
  }

  uint64_t tid;
  pthread_threadid_np(NULL, &tid);

  pthread_mutex_lock(&printk_sync);
  fprintf(printk_sink, "[%d:%lld] ", getpid(), tid);
  vfprintf(printk_sink, fmt, ap);
  fflush(printk_sink);
  pthread_mutex_unlock(&printk_sync);

  va_end(ap);
}

void
print_bt(void)
{
  void *array[10];
  size_t size;
  char **strings;
  size_t i;
  uint64_t tid;
  pthread_threadid_np(NULL, &tid);

  size = backtrace(array, 10);
  strings = backtrace_symbols(array, size);

  fprintf(stderr, "[%d:%lld] Obtained %zd stack frames.\n", getpid(), tid, size);

  for(i = 0; i < size; i++)
    fprintf(stderr, "%s\n", strings[i]);

  free(strings);
}
