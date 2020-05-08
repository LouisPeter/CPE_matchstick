##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC =	my_putchar.c			\
		my_strlen.c	   	\
		my_putstr.c	    	\
		my_getnbr.c		\
		my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all	=	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME)	$(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)
	rm -f ../$(NAME)

fclean:	clean
	rm -f $(NAME)