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

typedef struct vm_snapshot *vm_snapshot_t;
extern hv_vcpuid_t vcpuid;

void vmm_create(void);
void vmm_clone(vm_snapshot_t snapshot);
void vmm_snapshot(vm_snapshot_t *snapshot);
void vmm_snapshot_destroy(vm_snapshot_t snapshot);
void vmm_destroy(void);

typedef uint64_t gaddr_t;

gaddr_t host_to_guest(void *);
void *guest_to_host(gaddr_t);

/* prot is obtained by or'ing HV_MEMORY_READ, HV_MEMORY_EXEC, HV_MEMORY_WRITE */
void vmm_mmap(gaddr_t addr, size_t len, int prot, void *ptr);

/* linux emulation */

int do_exec(const char *elf_path, int argc, char *argv[], char **envp);
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
#define L_MAP_SHARED     0x1
#define L_MAP_PRIVATE    0x2
#define L_MAP_TYPE       0xf
#define L_MAP_FIXED      0x10
#define L_MAP_ANON       0x20
#define L_MAP_ANONYMOUS  L_MAP_ANON
#define L_MAP_GROWSDOWN  0x0100
#define L_MAP_DENYWRITE  0x0800
#define L_MAP_EXECUTABLE 0x1000
#define L_MAP_LOCKED     0x2000
#define L_MAP_NORESERVE  0x4000
#define L_MAP_POPULATE   0x8000
#define L_MAP_NONBLOCK   0x10000
#define L_MAP_STACK      0x20000
#define L_MAP_HUGETLB    0x40000

#define L_SOCK_STREAM    1
#define L_SOCK_DGRAM     2
#define L_SOCK_RAW       3
#define L_SOCK_RDM       4
#define L_SOCK_SEQPACKET 5
#define L_SOCK_DCCP      6
#define L_SOCK_PACKET    10

#define L_SOCK_NONBLOCK  0x800
#define L_SOCK_CLOEXEC   0x80000


#define L_AF_UNSPEC     0
#define L_AF_LOCAL      1
#define L_AF_UNIX       L_AF_LOCAL
#define L_AF_FILE       L_AF_LOCAL
#define L_AF_INET       2
#define L_AF_AX25       3
#define L_AF_IPX        4
#define L_AF_APPLETALK  5
#define L_AF_NETROM     6
#define L_AF_BRIDGE     7
#define L_AF_ATMPVC     8
#define L_AF_X25        9
#define L_AF_INET6      10
#define L_AF_ROSE       11
#define L_AF_DECnet     12
#define L_AF_NETBEUI    13
#define L_AF_SECURITY   14
#define L_AF_KEY        15
#define L_AF_NETLINK    16
#define L_AF_ROUTE      L_AF_NETLINK
#define L_AF_PACKET     17
#define L_AF_ASH        18
#define L_AF_ECONET     19
#define L_AF_ATMSVC     20
#define L_AF_RDS        21
#define L_AF_SNA        22
#define L_AF_IRDA       23
#define L_AF_PPPOX      24
#define L_AF_WANPIPE    25
#define L_AF_LLC        26
#define L_AF_IB         27
#define L_AF_MPLS       28
#define L_AF_CAN        29
#define L_AF_TIPC       30
#define L_AF_BLUETOOTH  31
#define L_AF_IUCV       32
#define L_AF_RXRPC      33
#define L_AF_ISDN       34
#define L_AF_PHONET     35
#define L_AF_IEEE802154 36
#define L_AF_CAIF       37
#define L_AF_ALG        38
#define L_AF_NFC        39
#define L_AF_VSOCK      40
#define L_AF_KCM        41
#define L_AF_MAX        42

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
