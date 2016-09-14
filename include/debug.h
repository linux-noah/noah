#include <stdio.h>
#include <stdint.h>
#include <Hypervisor/hv.h>

void init_debug_sink(const char *fn, FILE **sinkp, const char *name);
void init_printk(const char *fn);

void printk(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
void print_regs(void);
void dump_instr(void);
void noah_strace(char *syscall_name, ...);
void noah_strace_ret(char *syscall_name, uint64_t ret);
char *vmcs_field_to_str(uint32_t vmcs_field);
void fprint_vmcs(FILE *out, hv_vcpuid_t vcpuid, uint32_t vmcs_field);
void fhvdump(FILE *out, hv_vcpuid_t vcpuid);
