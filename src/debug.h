
#if DEBUG_MODE
#define PUTS(...) puts(__VA_ARGS__)
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PUTS(...) 0
#define PRINTF(...) 0
#endif

char *vmcs_field_to_str(uint32_t vmcs_field);
void fprint_vmcs(FILE *out, hv_vcpuid_t vcpuid, uint32_t vmcs_field);
void fhvdump(FILE *out, hv_vcpuid_t vcpuid);
