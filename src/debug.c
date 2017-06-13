#include <stdlib.h>
#include <stdio.h>
#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>
#include <stdarg.h>
#include <time.h>
#include <pthread.h>
#include <execinfo.h>
#include <stdnoreturn.h>
#include <errno.h>
#include <string.h>

#include "noah.h"
#include "vmm.h"
#include "linux/time.h"
#include "linux/fs.h"

static FILE *printk_sink, *warnk_sink;
pthread_mutex_t printk_sync = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t warnk_sync = PTHREAD_MUTEX_INITIALIZER;

void
init_sink(const char *fn, FILE **sinkp, const char *name)
{
  if (! fn) {
    fn = "/dev/null";
  }
  int fd = open(fn, O_RDWR | O_CREAT, 0644);
  *sinkp = fdopen(vkern_dup_fd(fd, false), "w");
  close(fd);

  char buf[1000];
  time_t now = time(0);
  struct tm tm = *gmtime(&now);
  strftime(buf, sizeof buf, "%a, %d %b %Y %H:%M:%S %Z", &tm);
  fprintf(*sinkp, "\n//==================\n");
  fprintf(*sinkp, "%s log started: [%s]\n", name, buf);
  fflush(*sinkp);
}

void
print_to_sink(FILE *sink, pthread_mutex_t *sync, const char *mes)
{
  if (!sink) {
    return;
  }

  uint64_t tid;
  pthread_threadid_np(NULL, &tid);

  if (sync) {
    pthread_mutex_lock(sync);
  }
  fprintf(sink, "[%d:%lld] %s", getpid(), tid, mes);
  fflush(sink);
  if (sync) {
    pthread_mutex_unlock(sync);
  }
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
  char *mes;

  if (!printk_sink) {
    va_end(ap);
    return;
  }

  vasprintf(&mes, fmt, ap);
  print_to_sink(printk_sink, &printk_sync, mes);

  free(mes);
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
  va_list ap;
  va_start(ap, fmt);
  char *mes;

  vasprintf(&mes, fmt, ap);

  printk("WARNING: %s", mes);
  print_to_sink(warnk_sink, &printk_sync, mes);

#ifndef NDEBUG
  //const char *magenda = "\x1b[35m", *reset = "\x1b[0m";
  //fprintf(stderr, "%sNoah WARNING: %s%s", magenda, mes, reset);
#endif

  free(mes);
  va_end(ap);
}

static void
printbt_to_sink(FILE *sink, pthread_mutex_t *sync)
{
  if (!sink) {
    return;
  }

  void *array[10];
  size_t size;
  char **strings;
  size_t i;
  uint64_t tid;

  pthread_threadid_np(NULL, &tid);
  size = backtrace(array, 10);
  strings = backtrace_symbols(array, size);

  if (sync) {
    pthread_mutex_lock(sync);
  }
  fprintf(sink, "[%d:%lld] Obtained %zd stack frames.\n", getpid(), tid, size);
  for(i = 0; i < size; i++)
    fprintf(sink, "%s\n", strings[i]);
  fflush(sink);
  if (sync) {
    pthread_mutex_unlock(sync);
  }

  free(strings);
}

noreturn void
panic(const char *fmt, ...)
{
  int err = errno;
  va_list ap, cp;
  va_start(ap, fmt);
  va_copy(cp, ap);
  char *given, *mes;

  vasprintf(&given, fmt, ap);
  asprintf(&mes, "!!PANIC!!\nperror is \"%s\" if it is valid\n%s\n", strerror(err), given);

  printk("!!PANIC!!%s", mes);
  printbt_to_sink(printk_sink, &printk_sync);

  print_to_sink(warnk_sink, &warnk_sync, mes);
  printbt_to_sink(warnk_sink, &warnk_sync);

  const char *magenda = "\x1b[35m", *reset = "\x1b[0m";
  fprintf(stderr, "%s%s", magenda, mes);
  printbt_to_sink(stderr, NULL);
  fprintf(stderr, "%s\n", reset);

  free(given);
  free(mes);

  struct rlimit lim;
  getrlimit(RLIMIT_CORE, &lim);
  if (lim.rlim_cur == 0) {
    fprintf(stderr, "%sSet the ulimit value to unlimited to generate the coredump? [Y/n] %s", magenda, reset);
    char ans = getchar();
    if (ans == '\n' || ans == '\r' || ans == 'Y' || ans == 'y') {
      lim.rlim_cur = RLIM_INFINITY;
      lim.rlim_max = RLIM_INFINITY;
      setrlimit(RLIMIT_CORE, &lim);
    }
  }
  
  fprintf(stderr, "%saborting..%s\n", magenda, reset);
  die_with_forcedsig(LINUX_SIGABRT);
}
