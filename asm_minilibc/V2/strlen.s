[BITS 64]
DEFAULT REL
;; global strlen :function
	
section .text

strlen:
	enter 0, 0
	
	test rdi, rdi
	jz fail_strlen
	xor rcx, rcx
	not rcx
	repne scasb
	not rcx
	dec rcx
	
	mov rax, rcx
	jmp end_strlen
fail_strlen:
	xor rax, rax
end_strlen:	
	leave
	ret