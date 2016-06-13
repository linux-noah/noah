
.align 4
.text
.globl _injected
_injected:
  add %ebx, %eax
  vmcall
.globl _injected_end
_injected_end:


