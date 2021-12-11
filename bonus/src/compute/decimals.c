/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** clean the valid expression
*/

#include "bistromatic.h"
#include <stdlib.h>

int nb_decimals(char *str, char *ops)
{
    int dot = 0;
    int nb = 0;

    for (int i = 0; str[i]; i++) {
        if (dot)
            nb++;
        if (str[i] == ops[8])
            dot = 1;
    }
    return nb;
}

void adapt(char **str, char *ops)
{
    int index = index_of(ops[8], *str);

    if (index >= 0)
        *str = replace(*str, index, 1, "");
}

void put_coma(char **result, int index, char *ops)
{
    index = my_strlen(*result) - index;
    
    if (index <= 0) {
        index *= -1;
        insert_at_beg(result, '0', index + 1, 1);
        re_alloc(result, replace(*result, 1, 0, &ops[8]), 0);
    }
    else if (index != my_strlen(*result))
        re_alloc(result, replace(*result, index, 0, &ops[8]), 0);
}

void compute_decimal_part(char **result, char *r, char *diviseur, expr_params_t *par)
{
    char *tmp;
    char *base = par->base;
    char *ops = par->ops;
    char *mod = my_mod(r, diviseur, base, ops);

    r = my_strdup(r);
    if (mod[0] != base[0])
        append_char(result, ops[8], 1);
    else {
        free(mod);
        return;
    }
    for (int i = 0; i < PRECISION && mod[0] != base[0]; i++) {
        append_char(&r, base[0], 1);
        tmp = my_div(r, diviseur, par, 0);
        mod = my_mod(r, diviseur, base, ops);
        append(result, tmp, 1);
        re_alloc(&r, mod, 1);
        free(tmp);    
    }
}

void adapt_decimals(char **first, char **second, char *base, char *ops)
{
    int deci_fir = nb_decimals(*first, ops);
    int deci_sec = nb_decimals(*second, ops);
    int fir_dot = index_of(ops[8], *first);
    int sec_dot = index_of(ops[8], *second);
    int len = ABS(deci_fir - deci_sec);
    char zeros[len + 1];

    init_with(zeros, base[0], len);
    zeros[len] = 0;
    if (fir_dot >= 0)
        re_alloc(first, replace(*first, fir_dot, 1, ""), 1);
    if (sec_dot >= 0)
        re_alloc(second, replace(*second, sec_dot, 1, ""), 1);
    cleanex(first, base, ops);
    cleanex(second, base, ops);
    if (deci_fir > deci_sec)
        append(second, zeros, 0);
    else
        append(first, zeros, 0);
}