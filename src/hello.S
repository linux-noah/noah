        .align 4
        .text
        .globl _start
_start:
        mov $4, %eax            # write
        mov $1, %ebx
        mov $14, %edx
        lea _msg, %ecx
        int $0x80
        mov $1, %eax            # exit
        mov $0, %ebx
        int $0x80
_msg:
        .ascii "hello, world!\n"


