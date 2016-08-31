#include <stdio.h>
#include <stdint.h>
#include <Hypervisor/hv.h>

void init_debug(const char *name);

void printk(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
void print_regs(void);
void dump_instr(void);
void noah_strace(char *syscall_name, u_int64_t ret, ...);
char *vmcs_field_to_str(uint32_t vmcs_field);
void fprint_vmcs(FILE *out, hv_vcpuid_t vcpuid, uint32_t vmcs_field);
void fhvdump(FILE *out, hv_vcpuid_t vcpuid);
