[BITS 64]
DEFAULT REL
global rindex:function

%include "strlen.s"
	
section .text

rindex:
	enter 0, 0
	
	test rdi, rdi
	jz fail
	push rdi
	call strlen
	pop rdi
	mov rcx, rax
while:
	mov al, [rdi + rcx]
	sub al, sil
	test al, al
	jz ret
	dec rcx
	test rcx, rcx
	jl fail
	jmp while
	
ret:
	mov rax, rdi
	add rax, rcx
	jmp end
fail:
	xor rax, rax
end:	
	leave
	ret