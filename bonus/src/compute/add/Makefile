##
## EPITECH PROJECT, 2021
## bistromatic
## File description:
## makefile for add
##

SRC = computations.c \
	infinadd.c \
	strmanips.c

OBJ = $(SRC:.c=.o)

FLAGS = -c -g -Wall -Wextra

INCLUDE = ../../../include/

LIB = ../../../lib/my/

all:
	gcc $(FLAGS) -I $(INCLUDE) $(SRC) -L $(LIB) -lmy
	cp $(OBJ) ../../../

tests:
	gcc $(FLAGS) -I $(INCLUDE) $(SRC) -L $(LIB) -lmy --coverage  -lcriterion
	cp $(OBJ) ../../../

clean:
	rm -f $(OBJ)
