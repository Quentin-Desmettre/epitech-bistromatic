/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** clean the valid expression
*/

#include "bistromatic.h"
#include <stdlib.h>

void clean_dot_at(char **str, int i, char *base, char *ops)
{
    char *decimals = get_next_number(*str, i, base, ops);
    int decimals_len = my_strlen(decimals);

    my_revstr(decimals);
    cleanex(&decimals, base, ops);
    my_revstr(decimals);
    if (decimals_len == 0 || (my_strlen(decimals) == 1 && decimals[0] == base[0]))
        re_alloc(str, replace(*str, i, decimals_len, ""), 1);
    else
        re_alloc(str, replace(*str, i + 1, decimals_len, decimals), 1);
    free(decimals);
}

void clean_dot(char **expr, char *base, char *ops)
{
    char *str = *expr;

    if (!str)
        return;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ops[8]) {
            clean_dot_at(&str, i, base, ops);
        }
    }
    *expr = str;
}

int check_multi_dot(char *str, char const *ops)
{
    int dot = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ops[8] && dot) {
            my_putstr(SYNTAX_ERROR_MSG);
            return 0;
        }
        if (str[i] == ops[8])
            dot = 1;
        else if (contain(ops + 2, str[i]))
            dot = 0;
    }
    return 1;
}