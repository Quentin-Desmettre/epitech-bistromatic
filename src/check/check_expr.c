/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** check validity of expr
*/

#include "bistromatic.h"
#include <stdlib.h>

int check_paren(char const *str, char const *ops)
{
    int stack = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ops[0])
            stack++;
        if (str[i] == ops[1])
            stack--;
        if (stack < 0) {
            my_putstr(SYNTAX_ERROR_MSG);
            return 0;
        }
    }
    if (stack != 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        return 0;
    }
    return 1;
}

int check_double_paren(char const *str, char const *ops, int i)
{
    if (str[i] == ops[0] && str[i + 1] == ops[1]) {
        my_putstr(SYNTAX_ERROR_MSG);
        return 0;
    }
    return 1;
}

int check_double_ops(char const *str, char const *ops, int i)
{
    if (contain(ops + 2, str[i]) && contain(ops + 4, str[i + 1])) {
        my_putstr(SYNTAX_ERROR_MSG);
        return 0;
    }
    return 1;
}

int check_ops_paren(char const *str, char const *base,
    char const *ops, int i)
{
    if (contain(base, str[i]) &&
        (str[i + 1] == ops[0] || (i && str[i - 1] == ops[1]))) {
        my_putstr(SYNTAX_ERROR_MSG);
        return 0;
    }
    if (contain(ops + 2, str[i])) {
        if (str[i + 1] == ops[1]) {
            my_putstr(SYNTAX_ERROR_MSG);
            return 0;
        }
        if (i && str[i - 1] == ops[0] &&
            ((str[i] != ops[2] && str[i] != ops[3]))) {
            my_putstr(SYNTAX_ERROR_MSG);
            return 0;
        }
    }
    return 1;
}

int check_expr(char const *str, char const *base, char const *ops)
{
    if (!(check_base_ops(base, ops) &&
    check_basic(str, base, ops) && check_paren(str, ops) &&
    check_ops_place(str, ops)))
        return 0;
    for (int i = 0; str[i]; i++) {
        if (!(check_ops_paren(str, base, ops, i) &&
        check_double_ops(str, ops, i) &&
        check_double_paren(str, ops, i)))
            return 0;
    }
    return 1;
}
