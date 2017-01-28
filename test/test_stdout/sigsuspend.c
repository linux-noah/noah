#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

void do_nothing(int sig)
{
  printf("%d\n", sig);
}

int main() {
struct sigaction sa;
sa.sa_handler = do_nothing;
sa.sa_flags = 0;
sigemptyset(&sa.sa_mask);
sigaction(SIGALRM, &sa, NULL);
//sigaction(SIGTSTP, &sa, NULL);
      
alarm(1);	
	
  sigset_t set;
  sigemptyset(&set);
//  while (1) {
    printf("waiting for a signal...\n");
    sigsuspend(&set);
//  }
}
