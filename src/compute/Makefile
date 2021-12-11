##
## EPITECH PROJECT, 2021
## bistromatic
## File description:
## makefile for computations
##

SRC = doop.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra

INCLUDE = ../../include/

LIB = ../../lib/my/

all:
	make -C add/
	make -C sub/
	make -C mul/
	make -C div/
	make -C mod/
	gcc $(FLAGS) -c $(SRC) -I $(INCLUDE) -L $(LIB) -lmy
	cp $(OBJ) ../../

tests:
	make -C add/ tests
	make -C sub/ tests
	make -C mul/ tests
	make -C div/ tests
	make -C mod/ tests
	gcc $(FLAGS) -c $(SRC) -I $(INCLUDE) -L $(LIB) -lmy --coverage -lcriterion
	cp $(OBJ) ../../

clean:
	make -C add/ clean
	make -C sub/ clean
	make -C mul/ clean
	make -C div/ clean
	make -C mod/ clean
	rm -f $(OBJ)

re: clean all
