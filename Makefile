##
## Makefile for allum1 in /home/garcin_s/rendu/CPE_2014_Allum1
## 
## Made by garcin_s
## Login   <garcin_s@epitech.net>
## 
## Started on  Thu Jan 30 15:23:07 2014 garcin_s
## Last update Fri Feb 14 09:34:29 2014 garcin_s
##

NAME		= allum1

SRC		= sources/main.c \
		  sources/my_getnbr.c \
		  sources/create_game.c \
		  sources/my_put_nbr.c \
		  sources/up_down.c \
		  sources/calc.c \
		  sources/check2.c \
		  sources/left_right.c \
		  sources/base_game.c \
		  sources/strxcpy.c \
		  sources/mouvement.c \
		  sources/move_curs.c \
		  sources/options.c \
		  sources/game.c \
		  sources/my_putchar.c \
		  sources/check.c \
		  sources/my_strlen.c

OBJ		= $(SRC:.c=.o)

CFLAGS		= -Iinclude

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) -lncurses

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
