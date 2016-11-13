[BITS 64]
	global	strcasecmp
					;Debut de la fonction.
	section .text
to_lower:				;Fonction to_lower
	push	rbp			;Prologue
	mov	rbp, rsp		;Prologue

	mov	rax, rdi		;on move rdi (1 argument) dans rax
	cmp	rdi, 90			;on compare rdi et 90 dernière lettre de l'alphabet Z
	jng	small			;on jump si c'est plus petit
	jmp	exit			;jump a exit

change:
	add	rax, 32			;on ajoute 32 pour obtenir minuscule
	jmp	exit			;on sort
small:
	cmp	rdi, 65			;on compare rdi avec 65
	jnl	change			;si il est positif jump

exit:
	leave				;Epilogue
	ret				;Sortie

strcasecmp:				;Fonction my_strcmp
	push	rbp			;Prologue
	mov	rbp, rsp		;Prologue
	xor	rax, rax		;On initialise le compteur
debut:
	push	rax			;sauvegarde le conteur
	push	rdi			;sauvegarde la premiere chaine
	xor	rbx, rbx
	mov	bl,[rdi + rax]
	mov	rdi, rbx 		;on stock la valuer du charactere dans rax
	call	to_lower		;on recupere le upper du charactere
	pop	rdi
	mov	rbx, rax 		;on le met dans rbx
	pop	rax 			;reprend le compteur
	xor	rcx, rcx
	mov	ch,bl

	push	rax			;sauvegarde le conteur
	push	rdi			;sauvegarde la premiere chaine
	push	rcx			;sauvegarde de rcx
	xor	rbx, rbx
	mov	bl,[rsi + rax]
	mov	rdi, rbx 		;on stock la valuer du charactere dans rax
	call	to_lower		;on recupere le upper du charactere
	pop	rcx			;
	pop	rdi			;
	mov	rbx, rax 		;on le met dans rcx
	pop	rax 			;reprend le compteur
	mov	cl,bl			;

	cmp	ch, 0			;Si on est sur le dernier caractere de la première chaine.
	je	end			;On sort de la boucle.
	cmp	cl, 0			;Si on est sur le dernier charactere de la secone chaine.
	je	end			;On va a la fin.

	cmp	ch, cl			;On le compare au caractere du second param.
	jne	end			;Si different on sort de la boucle.
	inc	rax			;On incremente le compteur.
	jmp	debut			;On retourne au debut.
end:
	sub	ch, cl			;On soustrait les char.
	mov	al, ch			;On ch dans al
	cbw				;instruction sign-extends a byte into a word  AX sign-extend of AL
	cwde				;EAX  sign-extend of AX
	leave				;Epilogue
	ret				;Sortie
