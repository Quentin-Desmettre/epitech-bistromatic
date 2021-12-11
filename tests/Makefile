##
## EPITECH PROJECT, 2021
## Bistromatic
## File description:
## makefile for all source code
##

SRC = test_check_2.c \
	test_check_expr_2.c \
	test_check_expr.c \
	test_check_expr_others.c \
	test_mul_base.c \
	test_mul_others.c \
	test_mul_func.c \
	test_add.c \
	test_add_base.c \
	test_add_others.c \
	test_sub.c \
	test_check.c \
	test_check_expr_3.c \
	test_check_expr_others_2.c \
	test_mul.c \
	test_computations.c \
	test_evaluate_simple.c \
	test_get_prev_next.c \
	test_nb_to_str.c \
	test_bistromatic.c \
	test_strmanips.c \
	test_eval_expr.c \
	test_clean_expr.c \
	test_mod.c \
	test_div.c \
	test_div2.c

FLAGS = -c -g -Wall -Wextra

INCLUDE = ../include/

LIB = ../lib/my/

all:
	gcc $(FLAGS) -I $(INCLUDE) $(SRC) -L $(LIB) -lmy --coverage -lcriterion
	cp *.o ../

clean:
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno
