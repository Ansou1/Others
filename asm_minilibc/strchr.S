[BITS 64]
	global  strchr

	section .text

my_strlen:			;Fonction my_strlen
	push	rbp		;Prologue
	mov	rbp, rsp	;Prologue

	mov	rax, 0		;on set rax à 0
	xor	rcx, rcx	;On initialise la taille a 0.
	not	rcx		;on check si rcx -1 ou 4294967295
	cld			;met l'indicateur d'état DF à 0 et incrémente.
	repne	scasb		;scan les bytes dans la chaine
	not	rcx		;on check si rcx -1 ou 4294967295
	lea	rax, [rcx - 1]	;lea instruction places the address specified by its second operand into the register specified by its first operand

	leave			;Epilogue
	ret			;Sortie

strchr:
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
