#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void do_exec(char *elf_path, int argc, char *argv[]);

int
main(int argc, char *argv[])
{
  if (argc == 1) {
    fprintf(stderr, "usage: %s elf_file ...\n", argv[0]);
    exit(1);
  }

  do_exec(argv[1], argc - 1, argv + 1);

  return 0;
}
