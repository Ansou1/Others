[BITS 64]
	global  strcspn
	section .text

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

my_strchr:
	push	rbp		;Prologue
	mov	rbp, rsp	;Prologue

	push  	rdi		;save rdi
	push	rsi		;save rsi
	call	my_strlen	;appel strlen
	pop	rsi		;sort rsi
	pop	rdi		;sort rdi
	mov	rcx, rax	;je move rax dans rcx compteur
	mov	rax, rsi	;je move le nombre dans le résultat
	cld			;on check si rcx -1 ou 4294967295
	repne	scasb		;scan les bytes dans la chaine
	inc	rcx		;incrément rcx
	cmp	rcx, 1		;je compare le compteur a 1
	je	what		;si oui on jump a what
	dec	rdi		;on décremente rdi
	mov	rax, rdi	;on move rdi dans rax
	jmp	return		;on move a return

what:
	mov	rax, rdi	;on set rdi dans rax
	cmp	rsi, 0		;on compare rsi a 0
	jne	ret_0		;si n'est pas égale
	jmp	return		;jump return

ret_0:
	mov	rax, 0		;set rax a 0
	jmp	return		;jump return
return:
	leave			;Epilogue
	ret			;Sortie


strcspn:
	push	rbp		;Epilogue
	mov	rbp, rsp	;Epilogue
	xor	rcx, rcx	;on set 0

try:
	xor	rbx, rbx	;initialise a 0
	mov	bl, [rdi]	;check fin de chiane
	cmp	bl, 0		;si a la fin on sort
	je	notfound	;egal

	push	rdi		;save rdi
	push	rsi		;save rsi
	push	rcx		;save rcx
	mov	rdi, rsi	;met chaine 2 dans rdi
	xor	rsi, rsi	;met rsi a 0
	mov	rsi, rbx	;on me le char dans 2eme param
	call	my_strchr	;appel strchr
	pop	rcx		;sort rcx
	pop	rsi		;sort rsi
	pop	rdi		;sort rdi

	cmp	rax, 0		;si trouver on sort
	jne	notfound	;si not equal
	inc	rdi		;sinon on increment
	inc	rcx		;incremant le rcx
	jmp	try		;on boucle
notfound:
	mov	rax, rcx	;on met le compteur sur rax
	jmp	exit		;jump exit

exit:
	leave			;Epilogue
	ret			;Sortie
