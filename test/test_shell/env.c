#include "noah.h"

int main(int argc, char *argv[], char **envp)
{
  for (; *envp; ++envp) {
    if (strcmp(*envp, "NOAH=OK") == 0)
      return 0;
  }
  return 1;
}
