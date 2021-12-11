/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** Do operations
*/

#include "bistromatic.h"

char *do_op(char *first, int op, char *second, expr_params_t *par)
{
    char *(*fonc[5])(char *, char *, char *, char *);

    fonc[0] = &infin_add;
    fonc[1] = &infin_sub;
    fonc[2] = &infin_mul;
    fonc[3] = &infin_div;
    fonc[4] = &infin_mod;
    return (fonc[op])(first, second, par->base, par->ops);
}
