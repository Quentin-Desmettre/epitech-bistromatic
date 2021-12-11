##
## EPITECH PROJECT, 2021
## Bistromatic
## File description:
## makefile for all source code
##

SRC = exponential.c \
	log.c

FLAGS = -c 

INCLUDE = ../../../include/

LIB = ../../../lib/my/

all:
	gcc $(FLAGS) -I $(INCLUDE) $(SRC) -L $(LIB) -lmy
	cp *.o ../../../

clean:
	rm -f *.o
