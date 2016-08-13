#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void do_exec(char *elf_path, int argc, char *argv[], char **envp);

int
main(int argc, char *argv[], char **envp)
{
  if (argc == 1) {
    fprintf(stderr, "usage: %s elf_file ...\n", argv[0]);
    exit(1);
  }

  do_exec(argv[1], argc - 1, argv + 1, envp);

  return 0;
}
