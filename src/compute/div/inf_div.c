/*
** EPITECH PROJECT, 2021
** Bistro
** File description:
** Bistro
*/
#include <stdlib.h>
#include <unistd.h>
#include "bistromatic.h"

void replace_sub(char **r, char *ten_n_bc, expr_params_t *par)
{
    re_alloc(r, infin_sub(*r, ten_n_bc, par->base, par->ops), 1);
}

void free_all(char *ten_n_b, char *ten_n, char *ten_n_bc)
{
    free(ten_n_bc);
    free(ten_n);
    free(ten_n_b);
}

void error_inf_div(char *b, char *base)
{
    if (b[0] == base[0]) {
        my_putstr(ERROR_MSG);
        exit(84);
    }
}
