##
## Makefile for  in /home/eax/dev/kcatos/modules/t2
## 
## Made by eax
## Login   <soules_k@epitech.net>
## 
## Started on  Mon Feb 23 06:11:00 2015 eax
## Last update Wed Feb 25 08:00:57 2015 eax
##

CC	=	gcc
LD	=	ld

CFLAGS	=	-g -m32 -nostdlib -fPIC -shared -W -Wall -Wextra -fno-builtin
LDFLAGS	=	-melf_i386 -fPIC -shared -einit_module

SRC	=	libk.c malloc.c
OBJ	=	$(SRC:.c=.o)

NAME	=	libk.kso

DESTDIR	=       ../../initrd_content/
DESTFILE=	$(DESTDIR)$(NAME)

all:	$(NAME)

$(NAME): $(OBJ)
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJ) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

load: $(DESTFILE)

$(DESTFILE): $(NAME)
	cp $(NAME) $(DESTFILE)


.PHONY: all clean fclean re load
