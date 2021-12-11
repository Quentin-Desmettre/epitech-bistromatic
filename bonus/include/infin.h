/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** prototypes for infin computations
*/

#ifndef INFIN_H
    #define INFIN_H

char *infin_add(char *fir, char *sec, char *base, char *ops);
char *infin_sub(char *fir, char *sec, char *base, char *ops);
char *my_add(char *first, char *second, char *base, char *ops);
char *my_sub(char *first, char *second, int rec, expr_params_t *par);
char *infin_div(char *a, char *b, char *base, char *ops);
char *infin_mul(char *fir, char *sec, char *base, char *ops);
char *infin_mod(char *a, char *b, char *base, char *ops);
char *my_mod(char *a, char *b, char *base, char *ops);
char *my_div(char *a, char *b, expr_params_t *par, int decimal);
char *my_exp(char *x, char *base, char *ops);
char *infin_pow(char *a, char *b, char *, char *);
char *my_ln (char *x);
char *my_pow(char *nb, char *pwr, char *base, char *ops);


#endif
