[BITS 64]
	global	to_lower
				;Debut de la fonction
	section	.text
to_lower:			;Fonction to_lower
	push	rbp		;Prologue
	mov	rbp, rsp	;Prologue

	mov	rax, rdi	;on move rdi (1 argument) dans rax
	cmp	rdi, 90		;on compare rdi et 90 dernière lettre de l'alphabet Z
	jng	small		;on jump si c'est plus petit
	jmp	exit		;jump a exit

change:
	add	rax, 32		;on ajoute 32 pour obtenir minuscule
	jmp	exit		;on sort
small:
	cmp	rdi, 65		;on compare rdi avec 65
	jnl	change		;si il est positif jump

exit:
	leave			;Epilogue
	ret			;Sortie
