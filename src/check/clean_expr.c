/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** clean the valid expression
*/

#include "bistromatic.h"
#include <stdlib.h>

int_pair_t lens_to_nb(char const *expr, char const *ops, int i)
{
    int neg = 0;
    int nb = 0;
    int_pair_t val;

    while (expr[i] == ops[2] || expr[i] == ops[3]) {
        if (expr[i] == ops[3])
            neg++;
        nb++;
        i++;
    }
    val.a = neg;
    val.b = nb;
    return val;
}

int replace_negs(char **expr, char *base, char *ops, int i)
{
    int nb_neg = lens_to_nb(*expr, ops, i).a;
    int op_len = lens_to_nb(*expr, ops, i).b;
    char new_ops[2] = {0, 0};
    char *tmp = *expr;

    new_ops[0] = (nb_neg % 2 == 0) ? (0) : (ops[3]);
    if (i != 0 && (contain(base, (*expr)[i - 1]) ||
    (*expr)[i - 1] == ops[1])) {
        new_ops[0] = (nb_neg % 2 == 0) ? (ops[2]) : (ops[3]);
    }
    *expr = replace(*expr, i, op_len, new_ops);
    free(tmp);
    return 1;
}

int remove_zeros(char **expr, char *base, int i)
{
    char *tmp;

    while ((*expr)[i] == base[0] && contain(base, (*expr)[i + 1])) {
        tmp = *expr;
        *expr = replace(*expr, i, 1, "");
        free(tmp);
    }
    return 1;
}

int is_rm_zero(char *expr, char *ops, int i)
{
    return i == 0 && ((expr[i] != ops[3]) && expr[i] != ops[0]);
}

int cleanex(char **expr, char *base, char *ops)
{
    int shift = 0;

    for (int i = 0; (*expr)[i]; i++) {
        if ((*expr)[i] == ops[2] ||
            (*expr)[i] == ops[3]) {
            replace_negs(expr, base, ops, i);
        }
    }
    for (int i = 0; (*expr)[i]; i++) {
        if (contain(ops, (*expr)[i]) || i == 0) {
            shift = is_rm_zero(*expr, ops, i);
            remove_zeros(expr, base, i + 1 - shift);
        }
    }
    return 1;
}
