##
## Makefile for lol in /home/single_j/work/TP/graph/tp_4
## 
## Made by julien singler
## Login   <single_j@epitech.net>
## 
## Started on  Tue Feb  2 14:28:07 2010 julien singler
## Last update Thu Mar 18 10:56:56 2010 julien singler
##

NAME		=		rtv1

SRC		=		main.c		\
				expose.c	\
				rotate.c	\
				get_next_line.c	\
				liste.c		\
				get_conf2.c	\
				get_conf.c	\
				my_libx.c	\
				calcul.c	\
				luminosite.c	\
				objet.c		\
				tore.c		\
				equation_4.c	\
				equation_3.c	\
				equation_2.c	\
				equation_1.c

OBJ		=		$(SRC:.c=.o)

CFLAGS		=		-Wall -pedantic -ansi -error

LIB		=		-L/usr/local/lib -lX11 -lXext -L./ -lmlx -L./ -lmy -L./ -lmlx -lm

all		:		$(OBJ)
				cc -o $(NAME) $(OBJ) $(LIB)

clean		:
				rm -f $(OBJ) core *.core *~ \#*\#

fclean		:		clean
				rm -f $(NAME)

re		:		fclean all