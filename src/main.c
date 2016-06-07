#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>

/*
 mov rax, rbx
 vmcall
 */
const unsigned char text[] = "\x48\x89\xd8\x0f\x01\x01";
/* const unsigned char text[] = "\x0f\x01\x01"; */

void
run(void)
{
  hv_return_t ret;
  hv_vcpuid_t vcpuid;
  void *mem = malloc(4 * 1024);
  uint64_t value;

  memcpy(mem, text, sizeof text);

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

  ret = hv_vm_map(text, 0x20000000, sizeof mem, HV_MEMORY_READ | HV_MEMORY_WRITE | HV_MEMORY_EXEC);
  if (ret != HV_SUCCESS) {
    printf("could not map a memory region: error code %x", ret);
    return;
  }

  puts("successfully created a memory mapping");

  ret = hv_vcpu_write_register(vcpuid, HV_X86_RIP, 0x20000000);
  if (ret != HV_SUCCESS) {
    printf("could not set rip: error code %x", ret);
    return;
  }

  puts("successfully set rip");

  hv_vcpu_read_register(vcpuid, HV_X86_CR0, &value);
  printf("cr0 = %llx\n", value);
  hv_vcpu_write_register(vcpuid, HV_X86_CR0, value | 0x1); /* enter protect mode */
  hv_vcpu_read_register(vcpuid, HV_X86_CR0, &value);
  printf("cr0 = %llx\n", value);

  hv_vcpu_write_register(vcpuid, HV_X86_RAX, 42);
  hv_vcpu_write_register(vcpuid, HV_X86_RBX, 0);

  /* now vm is ready */

  puts("now vm is ready");

  ret = hv_vcpu_run(vcpuid);
  if (ret != HV_SUCCESS) {
    puts("oops");
    return;
  }

  hv_vcpu_read_register(vcpuid, HV_X86_RBX, &value);
  printf("rbx = %llx\n", value);

  ret = hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_EXIT_REASON, &value);
  if (ret != HV_SUCCESS) {
    puts("oops");
    return;
  }
  printf("exit reason = %llu\n", value);

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
