typedef unsigned long uint64_t;
typedef unsigned long size_t;
typedef long ssize_t;

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

#define SYS_write 1
#define SYS_exit 60

void write(int fd, const void *buf, size_t count)
{
  syscall(SYS_write, fd, (uint64_t)buf, count);
}

void _exit(int status)
{
  syscall(SYS_exit, status, 0, 0);
}
