/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** get previous and next number
*/

#include <stdlib.h>
#include "lib/strmanip.h"
#include "bistromatic.h"

int len_to_prev(char *str, int start, char *base, char *ops)
{
    int i = start - 1;
    int len = 0;

    while (i >= 0) {
        if (contain(base, str[i]) || str[i] == ops[8])
            len++;
        else if (str[i] == ops[3] && (!i || contain(ops, str[i - 1])))
            len++;
        else
            break;
        i--;
    }
    return len;
}

int len_to_next(char *str, int start, char *base, char *ops)
{
    int i = start + 1;
    int len = 0;

    while (1) {
        if ((str[i] && contain(base, str[i])) || str[i] == ops[8])
            len++;
        else if (str[i] == ops[3] && (!i || contain(ops, str[i - 1])))
            len++;
        else
            break;
        i++;
    }
    return len;
}

char *get_next_number(char *str, int start, char *base, char *ops)
{
    int len = len_to_next(str, start, base, ops);
    char *num = malloc(sizeof(char) * len + 1);
    int i = start + 1;

    for (int j = 0; j < len; j++) {
        num[j] = str[i + j];
    }
    num[len] = 0;
    return num;
}

char *get_prev_number(char *str, int start, char *base, char *ops)
{
    int len = len_to_prev(str, start, base, ops);
    char *num = malloc(sizeof(char) * len + 1);
    int i = start - 1;

    for (int j = 0; j < len; j++) {
        num[j] = str[i - j];
    }
    num[len] = 0;
    my_revstr(num);
    return num;
}