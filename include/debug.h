#include <stdio.h>
#include <stdint.h>
#include <Hypervisor/hv.h>

void init_sink(const char *fn, FILE **sinkp, const char *name);
void init_printk(const char *fn);
void init_meta_strace(const char *fn);

void printk(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
void print_regs(void);
void dump_instr(void);
void meta_strace_pre(int syscall_num, char *syscall_name, ...);
void meta_strace_post(int syscall_num, char *syscall_name, uint64_t ret, ...);
void print_bt(void);

char *vmcs_field_to_str(uint32_t vmcs_field);
void fprint_vmcs(FILE *out, hv_vcpuid_t vcpuid, uint32_t vmcs_field);
void fhvdump(FILE *out, hv_vcpuid_t vcpuid);
