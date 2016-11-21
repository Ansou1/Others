##
## Makefile for libasm in /home/ampotos/asm_minilibc
## 
## Made by ampotos
## Login   <ampotos@epitech.net>
## 
## Started on  Tue Mar 18 10:26:20 2014 ampotos
## Last update Thu Mar 20 15:41:20 2014 ampotos
##

ASM = nasm

ASFLAGS = -f elf64

CC = gcc

LDFLAGS = -shared

RM = rm -f

NAME = libasm.so

SRC =	memmove.s\
	memset.s\
	rindex.s\
	strcasecmp.s\
	strchr.s\
	strcmp.s\
	strpbrk.s\
	strcspn.s\
	strstr.s\
	tolower.s\
	link.s

OBJ = $(SRC:.s=.o)

%.o: %.s
	$(ASM) $(ASFLAGS) $< -o $@
	strip --strip-unneeded  $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re