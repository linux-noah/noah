typedef unsigned long uint64_t;
typedef unsigned long size_t;
typedef long ssize_t;

uint64_t syscall(uint64_t num, uint64_t rdi, uint64_t rsi, uint64_t rdx)
{
  uint64_t ret;
  asm("syscall"
      : "=rax" (ret)
      : "0" (num), "D" (rdi), "S" (rsi), "d" (rdx)
      : "cc", "memory", "r11", "rcx"
      );
  return ret;
}

#define SYS_read 0
#define SYS_write 1
#define SYS_exit 60

ssize_t read(int fd, void *buf, size_t count)
{
  return syscall(SYS_read, fd, (uint64_t)buf, count);
}

ssize_t write(int fd, const void *buf, size_t count)
{
  return syscall(SYS_write, fd, (uint64_t)buf, count);
}

void _exit(int status)
{
  syscall(SYS_exit, status, 0, 0);
  __builtin_unreachable();
}
