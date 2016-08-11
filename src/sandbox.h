#ifndef NOAH_SANDBOX_H
#define NOAH_SANDBOX_H

#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>
#include <Hypervisor/hv_arch_vmx.h>

#include "vmem.h"

uint64_t rounddown(uint64_t x, uint64_t y);
uint64_t roundup(uint64_t x, uint64_t y);
void *kalloc(size_t size);
void vm_map(uint64_t vmvaddr, uint64_t vmpaddr, size_t size, page_type_t page_type, int perm);
uint64_t to_vmpa(void *haddr);
void *copy_from_user(const void *vmvaddr);
void create_sandbox(hv_vcpuid_t *vcpuid);
void destroy_sandbox(hv_vcpuid_t vcpuid);
void print_regs(hv_vcpuid_t vcpuid);

#endif
