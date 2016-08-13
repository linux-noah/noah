#include "common.h"

#include "../sandbox.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

DEFINE_SYSCALL(exit, int, reason)
{
  _exit(reason);
}

DEFINE_SYSCALL(exit_group, int, reason)
{
  _exit(reason);
}

#define ARCH_SET_GS 0x1001
#define ARCH_SET_FS 0x1002
#define ARCH_GET_FS 0x1003
#define ARCH_GET_GS 0x1004

DEFINE_SYSCALL(arch_prctl, int, code, uint64_t, addr)
{
  switch (code) {
  case ARCH_SET_GS:
    hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS_BASE, addr);
    return 0;
  case ARCH_SET_FS:
    hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS_BASE, addr);
    return 0;
  case ARCH_GET_FS:
  case ARCH_GET_GS:
  default:
    return -1;
  }
}

DEFINE_SYSCALL(set_tid_address, int *, tidptr)
{
  return 0;
}
