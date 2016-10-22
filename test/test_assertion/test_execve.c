#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include "test_assert.h"

int global_data = 1;
int global_bss;

void __attribute__((noreturn)) test_data_area(int argc, char *argv[])
{
  // Test global_data and global_bss are re-initialized;
  assert_true(global_data == 1);
  assert_true(global_bss == 0);
  
  exit(0);
}

int main(int argc, char *argv[], char *envp[])
{
  if (argc > 1) {
    if (strcmp("test_data_area", argv[1]) == 0) {
      test_data_area(argc, argv);
    }
  }

  nr_tests(3);

  // Test execve fails
  char *dummy_argv[] = {argv[0], ""};
  int err = execve("/dev/null", dummy_argv, envp);
  assert_true(err == -1);

  // Normal cases
  global_data = 2; // Modify global variables
  global_bss = 1;
  char *e_argv[] = {argv[0], "test_data_area"};
  execve(argv[0], e_argv, envp);
}

