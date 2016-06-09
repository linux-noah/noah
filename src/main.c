#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>

/*
 mov rax, rbx
 vmcall
 */
/* const unsigned char text[] = "\x48\x89\xd8\x0f\x01\xc1"; */
/*
 mov ax, bx
 vmcall
 */
/* const unsigned char text[] = "\x66\x89\xd8\x0f\x01\xc1"; */
/* const unsigned char text[] = "\x0f\x01\xc1"; */
const unsigned char text[] = "\x66\xb8\x00\x00\x0f\x01\xc1";

void
init_cpu(hv_vcpuid_t vcpuid)
{
  uint64_t vmx_cap_pinbased, vmx_cap_procbased, vmx_cap_procbased2, vmx_cap_entry;

  hv_vmx_read_capability(HV_VMX_CAP_PINBASED, &vmx_cap_pinbased);
  hv_vmx_read_capability(HV_VMX_CAP_PROCBASED, &vmx_cap_procbased);
  hv_vmx_read_capability(HV_VMX_CAP_PROCBASED2, &vmx_cap_procbased2);
  hv_vmx_read_capability(HV_VMX_CAP_ENTRY, &vmx_cap_entry);

  /* set up vmcs */

#define VMCS_PRI_PROC_BASED_CTLS_HLT           (1 << 7)
#define VMCS_PRI_PROC_BASED_CTLS_CR8_LOAD      (1 << 19)
#define VMCS_PRI_PROC_BASED_CTLS_CR8_STORE     (1 << 20)

#define cap2ctrl(cap,ctrl) ((ctrl | (cap & 0xffffffff)) & (cap >> 32))

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_PIN_BASED, cap2ctrl(vmx_cap_pinbased, 0));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CPU_BASED, cap2ctrl(vmx_cap_procbased,
                                                 VMCS_PRI_PROC_BASED_CTLS_HLT |
                                                 VMCS_PRI_PROC_BASED_CTLS_CR8_LOAD |
                                                 VMCS_PRI_PROC_BASED_CTLS_CR8_STORE));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CPU_BASED2, cap2ctrl(vmx_cap_procbased2, 0));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_VMENTRY_CONTROLS, cap2ctrl(vmx_cap_entry, 0));
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_EXC_BITMAP, 0xffffffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CR0_MASK, 0x60000000);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CR0_SHADOW, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CR4_MASK, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_CTRL_CR4_SHADOW, 0);

  /* set up cpu regs */

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CS, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CS_LIMIT, 0xffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CS_AR, 0x9b);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_DS, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_DS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_DS_LIMIT, 0xffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_DS_AR, 0x93);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_ES, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_ES_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_ES_LIMIT, 0xffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_ES_AR, 0x93);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS_LIMIT, 0xffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_FS_AR, 0x93);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS_LIMIT, 0xffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GS_AR, 0x93);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_SS, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_SS_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_SS_LIMIT, 0xffff);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_SS_AR, 0x93);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_LDTR, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_LDTR_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_LDTR_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_LDTR_AR, 0x10000);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_TR, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_TR_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_TR_LIMIT, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_TR_AR, 0x83);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GDTR_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_GDTR_LIMIT, 0);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_IDTR_BASE, 0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_IDTR_LIMIT, 0);

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CR0, 0x20);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CR3, 0x0);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_CR4, 0x2000);

  hv_vcpu_write_register(vcpuid, HV_X86_RFLAGS, 0x2);
  hv_vcpu_write_register(vcpuid, HV_X86_RSP, 0x0);
}

void
print_regs(hv_vcpuid_t vcpuid)
{
  uint64_t value;

  hv_vcpu_read_register(vcpuid, HV_X86_RAX, &value);
  printf("rax = %llx\n", value);
  hv_vcpu_read_register(vcpuid, HV_X86_RBX, &value);
  printf("rbx = %llx\n", value);
}

void
run(void)
{
  hv_return_t ret;
  hv_vcpuid_t vcpuid;
  void *mem;
  uint64_t value;

  ret = hv_vm_create(HV_VM_DEFAULT);
  if (ret != HV_SUCCESS) {
    printf("could not create the vm: error code %x", ret);
    return;
  }

  puts("successfully created the vm");

  ret = hv_vcpu_create(&vcpuid, HV_VCPU_DEFAULT);
  if (ret != HV_SUCCESS) {
    printf("could not create a vcpu: error code %x", ret);
    return;
  }

  puts("successfully created a vcpu");

  mem = valloc(1 * 1024 * 1024);
  assert(mem);
  memcpy((char *)mem + 0x100, text, sizeof text);

  assert(((char *)mem)[0x100] == text[0]);

  ret = hv_vm_map(mem, 0, 1 * 1024 * 1024, HV_MEMORY_READ | HV_MEMORY_WRITE | HV_MEMORY_EXEC);
  if (ret != HV_SUCCESS) {
    printf("could not map a memory region: error code %x", ret);
    return;
  }

  puts("successfully created a memory mapping");

  init_cpu(vcpuid);

  hv_vcpu_write_register(vcpuid, HV_X86_RIP, 0x100);

  puts("successfully set regs");

  /* now vm is ready */

  puts("now vm is ready");

  hv_vcpu_write_register(vcpuid, HV_X86_RAX, 42);
  hv_vcpu_write_register(vcpuid, HV_X86_RBX, 0);

  print_regs(vcpuid);

  ret = hv_vcpu_run(vcpuid);
  if (ret != HV_SUCCESS) {
    puts("oops");
    return;
  }

  hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_EXIT_REASON, &value);
  printf("exit reason = 0x%llx\n", value);

  hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_EXIT_QUALIFIC, &value);
  printf("exit qualification = 0x%llx\n", value);

  hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_PHYSICAL_ADDRESS, &value);
  printf("guest-physical address = 0x%llx\n", value);

  print_regs(vcpuid);

  puts("exit...");

  /* exit... */

  ret = hv_vcpu_destroy(vcpuid);
  if (ret != HV_SUCCESS) {
    printf("could not destroy the vcpu: error code %x", ret);
    return;
  }

  puts("successfully destroyed the vcpu");

  ret = hv_vm_destroy();
  if (ret != HV_SUCCESS) {
    printf("could not destroy the vm: error code %x", ret);
    return;
  }

  puts("successfully destroyed the vm");
}

int
main(int argc, char *argv[])
{
  run();

  return 0;
}
