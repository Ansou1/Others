[BITS 64]
	global  memmove
					;Debut du programme.
	section .text
memmove:				;Fonction my_memmove
	push	rbp			;Prologue
	mov	rbp, rsp		;Prologue

	mov	rax, 0
	mov	rbx, rdi		;set base register de rdi(1 argument)
	mov	rcx, rdx		;on set counter de rdx(3 argument)
	cld				;met l'indicateur d'état DF à 0 et incrémente.
	rep	movsb			;copier Octet l'adresse DS:SI dans l'adresse ES:DI et incrémente/décrémente les registres DI et SI
	mov	rax, rbx		;on move le rbx dans rax(Accumulator register)

	leave				;Epilogue
	ret				;Sortie
