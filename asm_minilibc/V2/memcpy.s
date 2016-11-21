[BITS 64]
DEFAULT REL
;; global memcpy:function
	
section .text

memcpy:
	enter 0, 0
	
	test rdi, rdi
	jz end
	test rsi, rsi
	jz end
	mov rcx, rdx
	xor rax, rax
	test rdx, rdx
	jz end
while:
	dec rcx
	mov al, [rsi + rcx]
	mov [rdi + rcx], al
	test rcx, rcx
	jz end
	jmp while
end:
	mov rax, rdi
	leave
	ret