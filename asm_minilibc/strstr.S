[BITS 64]
	global	strstr

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

my_strncmp:			;Fonction my_strcmp
	push	rbp		;Prologue
	mov	rbp, rsp	;Prologue
	xor	rax, rax	;On initialise le compteur
debut:
	cmp	rdx, rax
	je	notrm
	mov	ch, [rdi + rax]	;On prend le charactere du 1er param.
	mov	cl, [rsi + rax]	;On prend le caractere du 2eme param
	cmp	ch, 0		;Si on est sur le dernier caractere de la première chaine.
	je	end		;On sort de la boucle.
	cmp	cl, 0		;Si on est sur le dernier charactere de la secone chaine.
	je	end		;On va a la fin.
	cmp	ch, cl		;On le compare au caractere du second param.
	jne	end		;Si different on sort de la boucle.
	inc	rax		;On incremente le compteur.
	jmp	debut		;On retourne au debut.

notrm:
	mov	rax, 0
	jmp	eexit
end:
	sub	ch, cl		;On soustrait les char.
	mov	al, ch		;On ch dans al
	cbw			;instruction sign-extends a byte into a word  AX sign-extend of AL
	cwde			;EAX  sign-extend of AX

eexit:
	leave			;Epilogue
	ret			;Sortie.


strstr:
	push	rbp		;Prologue
	mov	rbp, rsp	;Prologue

	push	rdi		;save rdi
	push	rsi		;save rsi
	mov	rdi, rsi	;move rsi dans rdi
	call	my_strlen	;appel de my_strlen
	mov	rdx, rax	;mov résult rax dans rdx
	pop	rsi		;resort de rsi
	pop	rdi		;resort de rdi

loop:
	push 	rdi		;save rdi
	push 	rsi		;save rsi
	push 	rdx		;save rdx
	call	my_strncmp	;appel de my_strlen
	pop 	rdx		;resort rdx
	pop	rsi		;resort rsi
	pop	rdi		;resort rdi

	cmp	rax, 0		;on compare le compteur avec 0
	je	fin		;si oui saut sur fin
	mov	bl, [rdi]	;on set a bl l'adresse de rdi
	cmp	bl, 0		;on check bl avec 0
	je	notfound	;si oui on saute
	inc	rdi		;incrément du rdi
	jmp	loop		;loop
fin:
	mov	rax, rdi	;on met rdi dans rax
	jmp	exit		;jump exit

notfound:
	mov	rax, 0		;set rax a 0
	jmp	exit		;jump to exit
exit:
	leave			;Epilogue
	ret			;Sortie
