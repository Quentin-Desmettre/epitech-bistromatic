##
## EPITECH PROJECT, 2021
## bistromatic
## File description:
## makefile for add
##

SRC = div.c \
		inf_div.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra

INCLUDE = ../../../include/

LIB = ../../../lib/my/

all:
	gcc $(FLAGS) -I $(INCLUDE) -c $(SRC) -L $(LIB) -lmy
	cp $(OBJ) ../../../

tests:
	gcc $(FLAGS) -I $(INCLUDE) -c $(SRC) -L $(LIB) -lmy --coverage -lcriterion
	cp $(OBJ) ../../../

clean:
	rm -f $(OBJ)
