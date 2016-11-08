[BITS 64]
	global	memcpy
					;Debut du programme.
	section .text

memcpy:					;Fonction my_memcpy
	push	rbp			;Prologue
	mov	rbp, rsp		;Prologue

	mov	rcx, rdx		;On set rdx(3 argument) dans rcx
	xor	rax, rax		;On initialise a 0
while:
	dec	rcx			;On décremente rcx qui a était set a rdx
	mov	al, [rsi + rcx]		;on set al(8), [rsi + rcx]
	mov	[rdi + rcx], al		;on set [rdi + rcx], al
	test	rcx, rcx		;effectue un & logique de comparaison
	jz	end			;on test le 0 de rcx
	jmp	while			;on boucle
end:
	mov	rax, rdi		;On move le résultat dans rax
	leave				;Epiloque
	ret				;Sortie
