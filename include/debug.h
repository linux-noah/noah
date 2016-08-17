#include <stdio.h>
#include <stdint.h>
#include <Hypervisor/hv.h>

char *vmcs_field_to_str(uint32_t vmcs_field);
void fprint_vmcs(FILE *out, hv_vcpuid_t vcpuid, uint32_t vmcs_field);
void fhvdump(FILE *out, hv_vcpuid_t vcpuid);
