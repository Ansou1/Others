##
## Makefile for  in /home/daguen_s/rendu/ASM
##
## Made by daguen_s
## Login   <daguen_s@epitech.net>
##
## Started on  Fri Mar  7 17:16:00 2014 daguen_s
## Last update Wed Mar 26 20:28:23 2014 daguen_s
##

NAME		= libasm.so

CC		= gcc

SRC		= strlen.S\
		  strcmp.S\
		  strncmp.S\
		  memset.S\
		  to_lower.S\
		  to_upper.S\
		  strcspn.S\
		  strpbrk.S\
		  strcasecmp.S\
		  memcpy.S\
		  memmove.S\
		  strstr.S\
		  strchr.S\
		  rindex.S

OBJ		= $(SRC:.S=.o)

RM		= rm -f

$(NAME):	$(OBJ)
		$(CC) -shared -o $(NAME) $(OBJ)

%.o:		%.S
		nasm -f elf64 $< -o $@

all:		$(NAME)

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.SUFFIXES:	.S

.PHONY:		all clean fclean re
