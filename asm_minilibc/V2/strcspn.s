[BITS 64]
DEFAULT REL
global strcspn:function
	
section .text

in_str2:
	enter 0, 0
	
	xor rcx, rcx
	xor rax, rax
	
while_fcnt:
	mov al, [rsi + rcx]
	test al, al
	jz not_found
	sub al, dil
	test al, al
	jz found
	inc rcx
	jmp while_fcnt
not_found:	
	mov rax, 1
	jmp end_fcnt
found:	
	xor rax, rax
end_fcnt:	
	leave
	ret
	
strcspn:
	enter 0, 0

	test rdi, rdi
	jz fail
	test rsi, rsi
	jz fail
	xor rcx, rcx
	xor rax, rax
while:	
	mov al, [rdi + rcx]
	test al, al
	jz ret
	push rdi
	push rcx
	xor rdi, rdi
	mov dil, al
	call in_str2
	pop rcx
	pop rdi
	test rax, rax
	jz ret
	inc rcx
	jmp while
ret:	
	test rcx, rcx
	jz fail
	mov rax, rcx
	jmp end
fail:		
	xor rax, rax
end:	
	leave
	ret