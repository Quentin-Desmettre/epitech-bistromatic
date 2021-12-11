/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** evaluation functions
*/

#include <stdlib.h>
#include "bistromatic.h"

void check_evaluate(char **expr, char *op_valid, int *i, expr_params_t *par)
{
    char *tmp;
    int nb_rm;
    int len_first;
    char *tmp2;

    if (contain(op_valid, par->expr[*i])) {
        tmp = compute_raw(*i, &nb_rm, &len_first, par);
        if (tmp) {
            tmp2 = replace(par->expr, *i - len_first, nb_rm, tmp);
            free(par->expr);
            par->expr = tmp2;
            *expr = tmp2;
            *i = 0;
        }
        free(tmp);
    }
}

char *compute_raw(int start, int *len, int *len_1, expr_params_t *par)
{
    char *first = get_prev_number(par->expr, start, par->base, par->ops);
    char *second = get_next_number(par->expr, start, par->base, par->ops);
    char *tmp;

    if (my_strlen(first) == 0 || my_strlen(second) == 0)
        return 0;
    tmp = do_op(first, index_of(par->expr[start], par->ops) - 2,
    second, par);

    *len = my_strlen(first) + my_strlen(second) + 1;
    *len_1 = my_strlen(first);
    free(first);
    free(second);
    return tmp;
}

char *evaluate_with(char *expr, char *base, char *ops, char *op_valid)
{
    expr_params_t par = {expr, base, ops};

    for (int i = 0; my_strlen(expr) > 1 &&
    contain_any_of(expr + 1, op_valid); i++) {
        check_evaluate(&expr, op_valid, &i, &par);
    }
    return par.expr;
}

char *evaluate(char *expr, char *base, char *ops)
{
    char fir[4] = {ops[4], ops[5], ops[6], 0};
    char sec[3] = {ops[2], ops[3], 0};

    cleanex(&expr, base, ops);
    expr = evaluate_with(expr, base, ops, fir);
    cleanex(&expr, base, ops);
    expr = evaluate_with(expr, base, ops, sec);
    return expr;
}
