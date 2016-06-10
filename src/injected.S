
.align 4
.text
.globl _injected
_injected:
  add %bx, %ax
  vmcall
.globl _injected_end
_injected_end:


