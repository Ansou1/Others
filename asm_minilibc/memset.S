[BITS 64]
	global  memset

	section .text
memset:
	push	rbp		;Prologue
	mov	rbp, rsp	;Prologue

	xor	rcx, rcx	;compteur mis a 0
	mov	rax, rsi	;on set rsi(2 argument) dans rcx
loop:
	cmp	rcx, rdx	;On compare le compteur avec la taille (3eme param).
	je	end		;on regarde compteur == rdx
	mov	[rdi + rcx], al	;On remplit (1er param) avec la valeur (2eme param).
	inc	rcx		;incremennte
	jmp	loop		;boucle
end:
	mov	rax, rdi	;On place le pointeur dans la valeur de retour.
	leave			;Epilogue
	ret			;Sortie
