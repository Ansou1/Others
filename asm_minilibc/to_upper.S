[BITS 64]
	global	to_upper
				;Debut de la fonction
	section	.text
to_upper:			;Fonction to_upper
	push	rbp		;Prologue
	mov	rbp, rsp	;Prologue

	mov	rax, rdi	;on move rdi (1 argument) dans rax
	cmp	rdi, 122	;on compare rdi et 90 dernière lettre de l'alphabet z
	jng	small		;on jump si c'est plus petit
	jmp	exit		;jump a exit

change:
	sub	rax, 32		;on soustrait 32 pour obtenir majuscule
	jmp	exit		;jump a exit
small:
	cmp	rdi, 97		;on compare rdi avec 97
	jnl	change		;si il est positif jump

exit:
	leave			;Epilogue
	ret			;Sortie
