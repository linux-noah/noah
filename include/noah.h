#ifndef NOAH_H
#define NOAH_H

#include <stdint.h>

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

static inline uint64_t rounddown(uint64_t x, uint64_t y) {
  return x / y * y;
}

static inline uint64_t roundup(uint64_t x, uint64_t y) {
  return (x + y - 1) / y * y;
}


/* hypervisor */

#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>
#include <Hypervisor/hv_arch_vmx.h>

extern hv_vcpuid_t vcpuid;

void vmm_create(void);
void vmm_destroy(void);

typedef uint64_t gaddr_t;

gaddr_t host_to_guest(void *);
void *guest_to_host(gaddr_t);

void vmm_mmap(gaddr_t addr, size_t len, int prot, void *ptr);

/* linux emulation */

void do_exec(const char *elf_path, int argc, char *argv[], char **envp);
gaddr_t do_mmap(gaddr_t addr, size_t len, int prot, int flags, int fd, off_t offset);

#define STACK_SIZE (1 << 21)
#define STACK_TOP  0x0000007fc0000000ULL


/* debug */

#if DEBUG_MODE
#define PUTS(...) puts(__VA_ARGS__)
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PUTS(...) 0
#define PRINTF(...) 0
#endif

void print_regs(void);

#endif
