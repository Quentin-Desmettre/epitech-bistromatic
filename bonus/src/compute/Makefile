##
## EPITECH PROJECT, 2021
## bistromatic
## File description:
## makefile for computations
##

SRC = doop.c \
	decimals.c

OBJ = $(SRC:.c=.o)

FLAGS = -c

INCLUDE = ../../include/

LIB = ../../lib/my/

all:
	make -C add/
	make -C sub/
	make -C mul/
	make -C div/
	make -C mod/
	make -C pow/
	gcc $(FLAGS) $(SRC) -I $(INCLUDE) -L $(LIB) -lmy
	cp $(OBJ) ../../

clean:
	make -C add/ clean
	make -C sub/ clean
	make -C mul/ clean
	make -C div/ clean
	make -C mod/ clean
	make -C pow/ clean
	rm -f $(OBJ)

re: clean all
