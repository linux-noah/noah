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

static FILE *printk_sink, *warnk_sink;
pthread_mutex_t printk_sync = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t warnk_sync = PTHREAD_MUTEX_INITIALIZER;

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
print_to_sink(FILE *sink, pthread_mutex_t *sync, va_list ap, const char *fmt)
{
  if (!sink) {
    va_end(ap);
    return;
  }

  uint64_t tid;
  pthread_threadid_np(NULL, &tid);

  pthread_mutex_lock(sync);
  fprintf(sink, "[%d:%lld] ", getpid(), tid);
  vfprintf(sink, fmt, ap);
  fflush(sink);
  pthread_mutex_unlock(sync);

  va_end(ap);
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

  print_to_sink(printk_sink, &printk_sync, ap, fmt);

  va_end(ap);
}

void
init_warnk(const char *fn)
{
  init_sink(fn, &warnk_sink, "warning");
}

void
warnk(const char *fmt, ...)
{
  va_list ap, cp1, cp2;
  va_start(ap, fmt);
  va_copy(cp1, ap);va_copy(cp2, ap);

  char *mes;
  asprintf(&mes, "WARNING: %s", fmt);

  print_to_sink(printk_sink, &printk_sync, cp1, mes);
  print_to_sink(warnk_sink, &printk_sync, cp2, mes);

#ifndef NDEBUG
  const char *magenda = "\x1b[35m", *reset = "\x1b[0m";
  char *colored;
  asprintf(&colored, "%s%s%s", magenda, mes, reset);
  vfprintf(stderr, colored, ap);
  free(colored);
#endif

  free(mes);

  va_end(ap);va_end(cp1);va_end(cp2);
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
