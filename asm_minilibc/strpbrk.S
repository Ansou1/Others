[BITS 64]
	global	strpbrk

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
	cld			;met l'indicateur d'état DF à 0 et incrémente.
	repne	scasb		;scan les bytes dans la chaine
	inc	rcx		;on incrémente le compteur
	cmp	rcx, 1		;je compare le compteur a 1
	je	what		;si oui on jump a what
	dec	rdi		;on décremente rdi
	mov	rax, rdi	;on move rdi dans rax
	jmp	return		;jump to return

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

strpbrk:
	push	rbp		;Prologue
	mov	rbp, rsp	;Prologue
try:
	mov	bl, [rdi]	;on récup le charctere dans bl
	cmp	bl, 0		;on check bl avec 0
	je	notfound	;si c'est egale jump

	push	rdi		;save rdi
	push	rsi		;save rsi
	mov	bl, [rdi]	;on set bl avec rdi
	mov	rdi, rsi	;on set rsi dans rdi
	xor	rsi, rsi	;on set rsi a 0
	mov	rsi, rbx	;on move rbx dans rsi
	call	my_strchr	;on appel strchr
	pop	rsi		;sort rsi
	pop	rdi		;sort rdi
	cmp	rax, 0		;on compare
	jne	find		;si pas egale jump find
	inc	rdi		;incrémente rdi
	jmp	try		;boucle

find:
	mov	rax, rdi	;on set rdi dans rax
	jmp	exit		;jump exit

notfound:
	mov	rax, 0		;on set 0 dans le resultat
	jmp	exit		;jump exit
exit:
	leave			;Epilogue
	ret			;Sortie
