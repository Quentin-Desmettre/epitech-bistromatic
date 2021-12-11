##
## EPITECH PROJECT, 2021
## Bistromatic
## File description:
## Makefile for checkers
##

SRC = check_args.c \
	check_expr.c \
	clean_expr.c \
	check_expr_others.c \
	check_decimals.c

OBJ = $(SRC:.c=.o)

FLAGS = -c -g -Wall -Wextra

INCLUDE = ../../include/

LIB = ../../lib/my/

all:
	gcc $(FLAGS) -I $(INCLUDE) $(SRC) -L $(LIB) -lmy
	cp $(OBJ) ../../

clean:
	rm -f $(OBJ)

re: clean all
