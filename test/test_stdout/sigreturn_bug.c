#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

static void handler(int sig) {
  if (sig == SIGCHLD)
    printf("sigchld arrived\n");
}

int main() {
  struct sigaction sa;
  sa.sa_handler = handler;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  sigaction(SIGCHLD, &sa, NULL);

  int pid;
  if ((pid = fork()) > 0) {
    printf("child pid\n");
  again:
    errno = 0;
    int dead_pid = waitpid(-1, 0, 0);
    if (dead_pid < 0 && errno == EINTR) {
      goto again;
    }
    if (dead_pid < 0)
      perror("bug");
    else {
      if (dead_pid == pid)
        printf("dead pid equals pid!\n");
      else
        printf("bug\n");
    }
  } else {
    sleep(1);
    _exit(0);
  }
}
