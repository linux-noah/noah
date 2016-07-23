#include <stdint.h>

int fib(int n)
{
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fib(n - 2) + fib(n - 1);
  }
}

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
  int fib10 = fib(10);
  syscall(60, fib10,  0, 0); // exit
}
  
