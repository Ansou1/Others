[BITS 64]
DEFAULT REL
global memmove:function

%include "memcpy.s"
	
section .text

memmove:
	enter 0, 0
	
	test rsi, rsi
	jz end_mem
	test rdi, rdi
	jz end_mem
	test rdi, rsi
	jl not_call
	call memcpy
	jmp end_mem
not_call:
	xor rcx, rcx
while_mem:	
	test rcx, rdx
	je end_mem
	mov al, [rsi + rcx]
	mov [rdi + rcx], al
	inc rcx
	jmp while_mem
end_mem:
	leave
	ret