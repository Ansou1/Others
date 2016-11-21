[BITS 64]
DEFAULT REL
global strchr:function
	
section .text

strchr:
	enter 0, 0
	
	test rdi, rdi
	jz fail
	mov rdx, rdi
	mov rbx, rsi
	xor rcx, rcx
while:
	mov al, [rdx + rcx]
	sub al, bl
	test al, al
	je found
	mov al, [rdx + rcx]	
	test al, al
	jz fail
	inc rcx
	jmp while
found:
	mov rax, rdx
	add rax, rcx
	jmp end
fail:
	xor rax, rax
end:	
	leave
	ret