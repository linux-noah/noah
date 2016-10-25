#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include "test_assert.h"

int global_data = 0xbeef;

int main(int argc, char *argv[], char *envp[])
{
  if (argc <= 1) {
    nr_tests(0); // This file is intended to be excuted by test_execve
    return 0;
  }

  // Test this file is executed successfully
  assert_true(global_data == 0xbeef);
}

