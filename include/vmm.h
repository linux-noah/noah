#ifndef NOAH_VMM_H
#define NOAH_VMM_H

#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>
#include <Hypervisor/hv_arch_vmx.h>

#include "types.h"
#include "noah.h"
#include "x86/vmx.h"

struct vcpu_snapshot {
  uint64_t vcpu_reg[NR_X86_REG_LIST];
  uint64_t vmcs[NR_VMCS_FIELD];
};

struct vmm_snapshot {
  struct vcpu_snapshot first_vcpu_snapshot;
};

void vmm_create(void);
void vmm_destroy(void);
void vmm_snapshot(struct vmm_snapshot*);
void vmm_reentry(struct vmm_snapshot*);
void vmm_snapshot_vcpu(struct vcpu_snapshot*);
void vmm_restore_vcpu(struct vcpu_snapshot*);
void vmm_create_vcpu(struct vcpu_snapshot *);

/* prot is obtained by or'ing HV_MEMORY_READ, HV_MEMORY_EXEC, HV_MEMORY_WRITE */
void vmm_mmap(gaddr_t addr, size_t len, int prot, void *ptr);
struct mm_region *find_region(gaddr_t gaddr, struct mm *mm);
struct mm_region *record_region(void *haddr, gaddr_t gaddr, size_t size, int prot, int mm_flags, int mm_fd, int pgoff);
void split_region(struct mm_region *region, gaddr_t gaddr);

#endif
