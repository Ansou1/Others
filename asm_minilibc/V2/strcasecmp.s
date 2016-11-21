[BITS 64]
DEFAULT REL
global strcasecmp:function

%include "toupper.s"
	
section .text

strcasecmp:
	enter 0, 0
	
	test rdi, rdi
	jz fail
	test rsi, rsi
	jz fail
	xor rcx, rcx
	xor rax, rax
while:
	push rdi
	xor rdi, rdi
	mov dil, [rsi + rcx]
	test dil, dil
	jz finish
	call toupper
	mov rbx, rax
	pop rdi
	push rdi
	mov al, [rdi + rcx]
	xor rdi, rdi
	mov dil, al
	test dil, dil
	jz finish
	call toupper
	pop rdi
	sub al, bl
	test al, al
	jnz ret
	test bl, bl
	jz ret
	inc rcx
	jmp while
finish:
	pop rdi
	mov al, [rdi + rcx]
	sub al, [rsi + rcx]
ret:	
	cbw
	cwde
	jmp end
fail:	
	mov rax, -1
end:	
	leave
	ret