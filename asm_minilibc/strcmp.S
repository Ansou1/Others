[BITS 64]
	global	strcmp
				; Debut de la fonction.
	section .text
strcmp:				;Fonction my_strcmp
	push	rbp		;Prologue
	mov	rbp, rsp	;Prologue
	xor	rax, rax	;On met a 0
loop:
	mov	ch, [rdi + rax]	;charactere du 1er param.
	mov	cl, [rsi + rax]	;charactere du 2eme param
	cmp	ch, 0		;dernier charactere de s1
	je	end		;jump end
	cmp	cl, 0		;dernier charactere de s2
	je	end		;jump end
	cmp	ch, cl		;compare caractere du second param.
	jne	end		;Si not equal
	inc	rax		;incremente compteur.
	jmp	loop		;loop
end:
	sub	ch, cl		;On soustrait les char.
	mov	al, ch		;On ch dans al
	cbw			;instruction sign-extends a byte into a word  AX sign-extend of AL
	cwde			;EAX  sign-extend of AX
	leave			;Epilogue
	ret			;Sortie.
