/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** header for bistromatic
*/

#ifndef BISTROMATIC_H
    #define BISTROMATIC_H
    #define OPEN_PARENT_IDX 0
    #define CLOSE_PARENT_IDX 1
    #define PLUS_IDX 2
    #define SUB_IDX 3
    #define NEG_IDX 3
    #define MULT_IDX 4
    #define DIV_IDX 5
    #define MOD_IDX 6
    #define EXIT_USAGE 84
    #define EXIT_BASE 84
    #define EXIT_SIZE_NEG 84
    #define EXIT_MALLOC 84
    #define EXIT_READ 84
    #define EXIT_OPS 84
    #define EXIT_SYNTAX_ERROR 84
    #define EXIT_SUCCESS 0
    #define SYNTAX_ERROR_MSG "syntax error\n"
    #define ERROR_MSG "error\n"
    #include <stdio.h>
    #define PRECISION 50
    #define OUTPUT_PRECISION 10
    #define BASE "0123456789"
    #define OPS "()+-*/%^."

typedef struct expr_params {
    char *expr;
    char *base;
    char *ops;
} expr_params_t;

    #include "check.h"
    #include "str_manipulations.h"
    #include "evalexpr.h"
    #include "infin.h"
    #include "lib/iomanip.h"
    #include "lib/strmanip.h"
    #include "div.h"
    #include "exp.h"
    #include "decimals.h"
    #define ABS(x) ((x) < 0) ? (-(x)) : (x)

typedef unsigned long long ull;

void usage(void);
int bistromatic(int ac, char **av);
void redirect_all_stdout(void);
char *my_exp(char *x, char *base, char *ops);
char *ln (char *x);
void toto(void);

#endif
