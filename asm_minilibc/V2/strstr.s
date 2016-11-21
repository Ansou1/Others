[BITS 64]
DEFAULT REL
global strstr:function

%include "strlen.s"
%include "strncmp.s"
	
section .text

strstr:
	enter 0, 0

	test rdi, rdi
	jz fail
	test rsi, rsi
	jz fail
	xor rcx, rcx
	xor rax, rax
	mov al, [rsi]
	test al, al
	jnz while
	mov rax, rdi
	jmp end
while:
	mov al, [rdi + rcx]
	test al, al
	jz fail
	mov bl, [rsi]
	sub al, bl
	test al, al
	jnz next
	push rdi
	mov rdi, rsi
	call strlen ;; wrt ..plt
	mov rdx, rax
	pop rdi
	push rdi
	push rsi
	call strncmp ;; wrt ..plt
	test eax, eax
	jne pre_next
	pop rsi
	pop rdi
	add rdi, rcx
	mov rax, rdi
	jmp end
	
pre_next:
	pop rsi
	pop rdi
next:	
	inc rcx
	jmp while

fail:
	xor rax, rax
end:	
	leave
	ret