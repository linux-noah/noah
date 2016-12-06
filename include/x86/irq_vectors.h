/* See also http://wiki.osdev.org/Exceptions#Virtualization_Exception */
#define X86_VEC_DE 0            /* division by zero */
#define X86_VEC_DB 1            /* debug */
#define X86_VEC_BP 3            /* breakpoint */
#define X86_VEC_OF 4            /* overflow */
#define X86_VEC_BR 5            /* bound range exceeded */
#define X86_VEC_UD 6            /* invalid opcode */
#define X86_VEC_NM 7            /* device not available */
#define X86_VEC_DF 8            /* double fault */
#define X86_VEC_TS 10           /* invalid TSS */
#define X86_VEC_NP 11           /* segment not present */
#define X86_VEC_SS 12           /* stack segment fault */
#define X86_VEC_GP 13           /* general protection fault */
#define X86_VEC_PF 14           /* page fault */
#define X86_VEC_MF 16           /* x87 floating-point exception */
#define X86_VEC_AC 17           /* alignment check */
#define X86_VEC_MC 18           /* machine check */
#define X86_VEC_XM 19           /* SIMD floating-point exception */
#define X86_VEC_VE 20           /* virtualization exception */
#define X86_VEC_SX 30           /* security exception */

