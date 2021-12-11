##
## EPITECH PROJECT, 2021
## Bistromatic
## File description:
## makefile for all source code
##

SRC = main.c \
		bistromatic.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra

INCLUDE = ../include

LIB = ../lib/my

FULL_LIBS = -L $(LIB) -lmy $(DEBUG_FLAGS)

all:
	make -C check/
	make -C compute/
	make -C evaluate/
	gcc $(FLAGS) -I $(INCLUDE) -c $(SRC) -L $(LIB) -lmy
	cp $(OBJ) ../

tests:
	make -C check/ tests
	make -C compute/ tests
	make -C evaluate/ tests
	gcc $(FLAGS) -I $(INCLUDE) -c bistromatic.c -L $(LIB) -lmy $(DEBUG_FLAGS)
	cp *.o ../

clean:
	rm -f *.o
	make -C check/ clean
	make -C compute/ clean
	make -C evaluate/ clean

re: clean all
