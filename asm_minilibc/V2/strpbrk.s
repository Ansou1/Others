[BITS 64]
DEFAULT REL
global strpbrk:function
	
section .text

strpbrk:
	enter 0, 0
	
	test rdi, rdi
	jz fail
	test rsi, rsi
	jz fail
	xor rcx, rcx

while_str:	
	xor rbx, rbx
	mov rdx, [rdi + rcx]
	test dl, dl
	jz fail
	
while_char:
	mov rax, [rsi + rbx]
	test al, al
	jz end_while
	sub al, dl
	test al, al
	jz found
	inc rbx
	jmp while_char
	
end_while:	
	inc rcx
	jmp while_str

found:
	mov rax, rdi
	add rax, rcx
	jmp end
fail:
	xor rax, rax
end:	
	leave
	ret