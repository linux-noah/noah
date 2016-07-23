#include <stdint.h>

int syscall(uint64_t num, uint64_t rdi, uint64_t rsi, uint64_t rdx)
{
  int ret;
  asm("syscall" 
      : "=rax" (ret)
      : "0" (num), "D" (rdi), "S" (rsi), "d" (rdx)
      : "cc", "memory", "r11", "rcx"
      );
  return ret;
}

int _start()
{
  const char str[] = "hello, world!\n";
  syscall(1, 1, (uint64_t)str, sizeof(str) - 1); // write
  syscall(60, 0,  0, 0); // exit
}
  
