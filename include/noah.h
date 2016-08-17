#ifndef NOAH_H
#define NOAH_H

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>
#include <Hypervisor/hv_arch_vmx.h>

#include "vmem.h"

extern hv_vcpuid_t vcpuid;

uint64_t rounddown(uint64_t x, uint64_t y);
uint64_t roundup(uint64_t x, uint64_t y);
void *kalloc(size_t size);
void vm_map(uint64_t vmvaddr, uint64_t vmpaddr, size_t size, page_type_t page_type, int perm);
uint64_t to_vmpa(void *haddr);
void *copy_from_user(const void *vmvaddr);
void create_sandbox(void);
void destroy_sandbox(void);
void print_regs(void);

/* debug */

#if DEBUG_MODE
#define PUTS(...) puts(__VA_ARGS__)
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PUTS(...) 0
#define PRINTF(...) 0
#endif

#endif
