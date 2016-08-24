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

#include "x86/page.h"

extern hv_vcpuid_t vcpuid;

void vmm_create(void);
void vmm_snapshot(void);
void vmm_reentry(void);
void vmm_destroy(void);

typedef uint64_t gaddr_t;

gaddr_t host_to_guest(void *);
void *guest_to_host(gaddr_t);

/* prot is obtained by or'ing HV_MEMORY_READ, HV_MEMORY_EXEC, HV_MEMORY_WRITE */
void vmm_mmap(gaddr_t addr, size_t len, int prot, void *ptr);

/* linux emulation */

struct task {
  gaddr_t set_child_tid, clear_child_tid;
};

extern struct task task;

int do_exec(const char *elf_path, int argc, char *argv[], char **envp);
gaddr_t do_mmap(gaddr_t addr, size_t len, int prot, int flags, int fd, off_t offset);
int do_open(const char *path, int flags, int mode);


#define LINUX_RELEASE "4.6.4"
#define LINUX_VERSION "#1 SMP PREEMPT Mon Jul 11 19:12:32 CEST 2016" /* FIXME */

#define LINUX_PATH_MAX 4096         /* including null */

#define LINUX_PROT_NONE  0x0
#define LINUX_PROT_READ  0x1
#define LINUX_PROT_WRITE 0x2
#define LINUX_PROT_EXEC  0x4

#define LINUX_MAP_FILE       0
#define LINUX_MAP_SHARED     0x1
#define LINUX_MAP_PRIVATE    0x2
#define LINUX_MAP_TYPE       0xf
#define LINUX_MAP_FIXED      0x10
#define LINUX_MAP_ANON       0x20
#define LINUX_MAP_ANONYMOUS  LINUX_MAP_ANON
#define LINUX_MAP_GROWSDOWN  0x0100
#define LINUX_MAP_DENYWRITE  0x0800
#define LINUX_MAP_EXECUTABLE 0x1000
#define LINUX_MAP_LOCKED     0x2000
#define LINUX_MAP_NORESERVE  0x4000
#define LINUX_MAP_POPULATE   0x8000
#define LINUX_MAP_NONBLOCK   0x10000
#define LINUX_MAP_STACK      0x20000
#define LINUX_MAP_HUGETLB    0x40000

#define LINUX_SOCK_STREAM    1
#define LINUX_SOCK_DGRAM     2
#define LINUX_SOCK_RAW       3
#define LINUX_SOCK_RDM       4
#define LINUX_SOCK_SEQPACKET 5
#define LINUX_SOCK_DCCP      6
#define LINUX_SOCK_PACKET    10

#define LINUX_SOCK_NONBLOCK  0x800
#define LINUX_SOCK_CLOEXEC   0x80000


#define LINUX_AF_UNSPEC     0
#define LINUX_AF_LOCAL      1
#define LINUX_AF_UNIX       LINUX_AF_LOCAL
#define LINUX_AF_FILE       LINUX_AF_LOCAL
#define LINUX_AF_INET       2
#define LINUX_AF_AX25       3
#define LINUX_AF_IPX        4
#define LINUX_AF_APPLETALK  5
#define LINUX_AF_NETROM     6
#define LINUX_AF_BRIDGE     7
#define LINUX_AF_ATMPVC     8
#define LINUX_AF_X25        9
#define LINUX_AF_INET6      10
#define LINUX_AF_ROSE       11
#define LINUX_AF_DECnet     12
#define LINUX_AF_NETBEUI    13
#define LINUX_AF_SECURITY   14
#define LINUX_AF_KEY        15
#define LINUX_AF_NETLINK    16
#define LINUX_AF_ROUTE      LINUX_AF_NETLINK
#define LINUX_AF_PACKET     17
#define LINUX_AF_ASH        18
#define LINUX_AF_ECONET     19
#define LINUX_AF_ATMSVC     20
#define LINUX_AF_RDS        21
#define LINUX_AF_SNA        22
#define LINUX_AF_IRDA       23
#define LINUX_AF_PPPOX      24
#define LINUX_AF_WANPIPE    25
#define LINUX_AF_LLC        26
#define LINUX_AF_IB         27
#define LINUX_AF_MPLS       28
#define LINUX_AF_CAN        29
#define LINUX_AF_TIPC       30
#define LINUX_AF_BLUETOOTH  31
#define LINUX_AF_IUCV       32
#define LINUX_AF_RXRPC      33
#define LINUX_AF_ISDN       34
#define LINUX_AF_PHONET     35
#define LINUX_AF_IEEE802154 36
#define LINUX_AF_CAIF       37
#define LINUX_AF_ALG        38
#define LINUX_AF_NFC        39
#define LINUX_AF_VSOCK      40
#define LINUX_AF_KCM        41
#define LINUX_AF_MAX        42

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
