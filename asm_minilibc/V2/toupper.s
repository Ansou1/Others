[BITS 64]
DEFAULT REL
;; global toupper:function
	
section .text
	
toupper:
	enter 0, 0
	
	test dil, 97
	jl ret_up
	test dil, 122
	jg ret_up
	mov rax, rdi
	sub rax, 32
	jmp end_up
	
ret_up:
	xor rax, rax
	mov al, dil
end_up:	
	leave
	ret