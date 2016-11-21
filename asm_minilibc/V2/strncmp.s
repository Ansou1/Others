[BITS 64]
DEFAULT REL
;; global strncmp:function
	
section .text

strncmp:
	enter 0, 0
	
	test rdi, rdi
	jz fail_ncmp
	test rsi, rsi
	jz fail_ncmp
	xor rcx, rcx
	xor rax, rax
	test rdx, rdx
	jz ret_ncmp
	
while_ncmp:
	mov al, [rdi + rcx]
	test al, al
	jz ret_ncmp
	sub al, [rsi + rcx]
	test al, al
	jnz ret_ncmp
	inc rcx
	mov rbx, rdx
	sub rbx, rcx
	test rbx, rbx
	je ret_ncmp
	jmp while_ncmp
ret_ncmp:
	cbw
	cwde
	jmp end_ncmp
fail_ncmp:
	mov rax, -1
end_ncmp:	
	leave
	ret