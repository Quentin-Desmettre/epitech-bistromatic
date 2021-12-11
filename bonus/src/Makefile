##
## EPITECH PROJECT, 2021
## Bistromatic
## File description:
## makefile for all source code
##

SRC = main.c \
		bistromatic.c \
		toto.c

OBJ = $(SRC:.c=.o)

FLAGS = -c

INCLUDE = ../include

LIB = ../lib/my

all:
	make -C check/
	make -C compute/
	make -C evaluate/
	gcc $(FLAGS) -I $(INCLUDE) $(SRC) -L $(LIB) -lmy
	cp $(OBJ) ../

clean:
	rm -f *.o
	make -C check/ clean
	make -C compute/ clean
	make -C evaluate/ clean

re: clean all
