        .align 4
        .text
        .globl _injected
_injected:
        mov $4, %eax            # write
        mov $1, %ebx
        mov $13, %edx
        lea _msg, %ecx
        sysenter
        jmp _injected
_msg:
        .ascii "hello, world!"
        .globl _injected_end
_injected_end:


