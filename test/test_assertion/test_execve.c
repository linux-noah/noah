#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include "test_assert.h"

int global_data = 1;
int global_bss;

void test_execve_twice(int argc, char *argv[], char *envp[])
{
  // Test global_data and global_bss are re-initialized again;
  assert_true(global_data == 1);
  assert_true(global_bss == 0);

  char *path = malloc(strlen(argv[0]) + 2);
  strcpy(path, argv[0]);
  strcat(path, "2");
  char *e_argv[] = {path, "test_execve2", NULL};
  // Execute test_execve2, which has 1 test
  execve(path, e_argv, envp);
}

void test_data_area(int argc, char *argv[], char *envp[])
{
  // Test global_data and global_bss are re-initialized;
  assert_true(global_data == 1);
  assert_true(global_bss == 0);

  global_data = 0xbeef;
  global_data = 0xface;
  
  char *e_argv[] = {argv[0], "test_execve_twice", NULL};
  execve(argv[0], e_argv, envp);
}

int main(int argc, char *argv[], char *envp[])
{
  if (argc > 1) {
    if (strcmp("test_data_area", argv[1]) == 0) {
      test_data_area(argc, argv, envp);
    }
    if (strcmp("test_execve_twice", argv[1]) == 0) {
      test_execve_twice(argc, argv, envp);
    }
  }

  nr_tests(6);

  // Test execve fails
  char *dummy_argv[] = {argv[0], "", NULL};
  int err = execve("/dev/null", dummy_argv, envp);
  assert_true(err == -1);

  // Normal cases
  global_data = 2; // Modify global variables
  global_bss = 1;
  char *e_argv[] = {argv[0], "test_data_area", NULL};
  execve(argv[0], e_argv, envp);
}

