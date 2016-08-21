#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include "common.h"
#include "noah.h"

DEFINE_SYSCALL(getpid)
{
  return getpid();
}

DEFINE_SYSCALL(geteuid)
{
  return geteuid();
}

DEFINE_SYSCALL(getppid)
{
  return getppid();
}
}

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

DEFINE_SYSCALL(arch_prctl, int, code, gaddr_t, addr)
{
  switch (code) {
  case ARCH_SET_GS:
    if (hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS_BASE, addr) != HV_SUCCESS) {
      return -1;
    }
    return 0;
  case ARCH_SET_FS:
    if (hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS_BASE, addr) != HV_SUCCESS) {
      return -1;
    }
    return 0;
  case ARCH_GET_FS:
    if (hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_FS_BASE, guest_to_host(addr)) != HV_SUCCESS) {
      return -1;
    }
    return 0;
  case ARCH_GET_GS:
    if (hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_GS_BASE, guest_to_host(addr)) != HV_SUCCESS) {
      return -1;
    }
    return 0;
  default:
    return -1;
  }
}

DEFINE_SYSCALL(set_tid_address, int *, tidptr)
{
  return 0;
}
