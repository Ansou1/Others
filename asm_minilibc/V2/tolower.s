[BITS 64]
DEFAULT REL
global tolower:function
	
section .text

tolower:
	enter 0, 0
	
	test dil, 65
	jl ret
	test dil, 90
	jg ret
	mov rax, rdi
	add rax, 32
	jmp end
	
ret:
	xor rax, rax
	mov al, dil
end:	
	leave
	ret