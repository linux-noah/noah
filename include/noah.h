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

/* prot is obtained by or'ing HV_MEMORY_READ, HV_MEMORY_EXEC, HV_MEMORY_WRITE */
void vmm_mmap(gaddr_t addr, size_t len, int prot, void *ptr);

/* linux emulation */

void do_exec(const char *elf_path, int argc, char *argv[], char **envp);
gaddr_t do_mmap(gaddr_t addr, size_t len, int prot, int flags, int fd, off_t offset);
int do_open(const char *path, int flags, int mode);

#define STACK_SIZE (1 << 21)
#define STACK_TOP  0x0000007fc0000000ULL

#define LINUX_RELEASE "4.6.4"
#define LINUX_VERSION "#1 SMP PREEMPT Mon Jul 11 19:12:32 CEST 2016" /* FIXME */

#define L_PATH_MAX 4096         /* including null */

#define L_PROT_NONE  0x0
#define L_PROT_READ  0x1
#define L_PROT_WRITE 0x2
#define L_PROT_EXEC  0x4

#define L_MAP_FILE       0
#define L_MAP_SHARED     0x01
#define L_MAP_PRIVATE    0x02
#define L_MAP_TYPE       0x0f
#define L_MAP_FIXED      0x10
#define L_MAP_ANON       0x20
#define L_MAP_ANONYMOUS  MAP_ANON
#define L_MAP_NORESERVE  0x4000
#define L_MAP_GROWSDOWN  0x0100
#define L_MAP_DENYWRITE  0x0800
#define L_MAP_EXECUTABLE 0x1000
#define L_MAP_LOCKED     0x2000
#define L_MAP_POPULATE   0x8000
#define L_MAP_NONBLOCK   0x10000
#define L_MAP_STACK      0x20000
#define L_MAP_HUGETLB    0x40000

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
