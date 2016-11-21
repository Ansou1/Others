[BITS 64]
DEFAULT REL
global memset:function
	
section .text

memset:
	enter 0, 0
	
	test rdi, rdi
	jz end
	xor rcx, rcx
	mov rax, rsi
while:
	mov [rdi + rcx], al
	inc rcx
	mov rbx, rdx
	sub rbx, rcx
	test bl, bl
	jz end
	jmp while
end:
	mov rax, rdi
	leave
	ret