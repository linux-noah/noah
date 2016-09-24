	.global _start
	.text
_start:
	pop	%rdi
	mov	%rsp, %rsi
	call	_main
	hlt
