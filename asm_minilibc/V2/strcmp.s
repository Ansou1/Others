[BITS 64]
DEFAULT REL
global strcmp:function
	
section .text

strcmp:
	enter 0, 0
	
	test rdi, rdi
	jz fail
	test rsi, rsi
	jz fail
	xor rcx, rcx
	xor rax, rax
while:
	mov al, [rdi + rcx]
	mov bl, [rsi + rcx]
	sub al, bl
	test al, al
	jnz ret
	test bl, bl
	jz ret
	inc rcx
	jmp while
ret:	
	cbw
	cwde
	jmp end
fail:
	mov rax, -1
end:	
	leave
	ret