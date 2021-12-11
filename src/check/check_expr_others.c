/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** others checks
*/

#include "bistromatic.h"
#include <stdlib.h>

int count_occurences(char const c, char const *str)
{
    int oc = 0;

    for (int i = 0; str[i]; i++) {
        (str[i] == c) ? (oc++) : (0);
    }
    return oc;
}

int check_redundance(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (count_occurences(str[i], str) > 1) {
            my_putstr(SYNTAX_ERROR_MSG);
            return 0;
        }
    }
    return 1;
}

int check_base_ops(char const *base, char const *ops)
{
    if (contain_any_of(base, ops)) {
        my_putstr(SYNTAX_ERROR_MSG);
        return 0;
    }
    return check_redundance(base) && check_redundance(ops);
}

int check_ops_place(char const *str, char const *ops)
{
    if (contain(ops + 4, str[0]) ||
    contain(ops + 2, str[my_strlen(str) - 1])) {
        my_putstr(SYNTAX_ERROR_MSG);
        return 0;
    }
    return 1;
}

int check_basic(char const *str, char const *base, char const *ops)
{
    char base_ops[my_strlen(base) + my_strlen(ops) + 1];

    my_strcpy(base_ops, base);
    my_strcat(base_ops, ops);
    if (my_strlen(str) == 0 || !contain_only(str, base_ops)) {
        my_putstr(SYNTAX_ERROR_MSG);
        return 0;
    }
    return 1;
}
