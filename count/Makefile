##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/count.c	\
		src/main.c	\
		src/read_file.c

OBJ	=	$(SRC:.c=.o)

NAME	=	count_island

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -g3

clean:
	rm -rf $(OBJ)
	rm -rf *~
	rm -rf src/*~
	rm -rf include/*~
	rm -rf vgcore*

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
