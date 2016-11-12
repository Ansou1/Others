[BITS 64]
	global	rindex

	section	.text

my_strlen:			;Fonction my_strlen
	push	rbp		;Prologue
	mov	rbp, rsp	;Prologue

	mov	rax, 0
	xor	rcx, rcx	;On initialise la taille a 0.
	not	rcx		;on check si rcx -1 ou 4294967295
	cld			;met l'indicateur d'état DF à 0 et incrémente.
	repne	scasb		;scan les bytes dans la chaine
	not	rcx		;on check si rcx -1 ou 4294967295
	lea	rax, [rcx - 1]	;lea instruction places the address specified by its second operand into the register specified by its first operand

	leave			;Epilogue
	ret			;Sortie

rindex:
	push	rbp		;Prologue
	mov	rbp, rsp	;Prologue

	test	rdi, rdi	;on test si le 1 argument egal 0
	jz	notfound	;si oui
	push	rdi		;save rdi
	push	rsi		;save rsi
	call	my_strlen
	pop	rsi		;sort rsi
	pop	rdi		;sort rdi

test:
	cmp	rax, 0		;compare
	je	notfound	;si egal
	mov	rbx, 0		;on set 0
	mov	bl, [rdi + rax]	;récupére le charactere et set dans bl
	cmp	rsi, rbx	;compare rsi rbx
	je	finish		;jump finish si =
	dec	rax		;decremente
	jmp	test		;loop

notfound:
	mov	rax, 0		;set a 0
	jmp	end		;jump end

finish:
	add	rdi, rax	;on add le rax avec le rdi
	mov	rax, rdi	;on mov le rdi dans rax
	jmp	end		;jump to end

end:
	leave			;Epilogue
	ret			;Sortie
