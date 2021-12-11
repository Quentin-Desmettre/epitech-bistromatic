/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** get previous and next number
*/

#include <stdlib.h>
#include "lib/strmanip.h"
#include "bistromatic.h"

int len_to_prev_paren(char *str, int start)
{
    int stack = 0;
    int i = start - 1;
    int len = 0;

    if (str[i] != ')') {
        len = len_to_prev(str, start, BASE, OPS);
        if (str[start - len] == '-')
            return len - 1;
        return len;
    }
    while (i >= 0) {
        if ((contain(BASE, str[i]) || contain(OPS, str[i])))
            len++;
        if (str[i] == OPS[1])
            stack--;
        if (str[i] == OPS[0])
            stack++;
        if (str[i] == OPS[0] && stack == 0)
            break;
        i--;
    }
    return len;
}

int len_to_next_paren(char *str, int start)
{
    int stack = 0;
    int i = start + 1;
    int len = 0;

    if (str[i] != '(')
        return len_to_next(str, start, BASE, OPS);
    while (str[i]) {
        if ((contain(BASE, str[i]) || contain(OPS, str[i])))
            len++;
        if (str[i] == '(')
            stack++;
        if (str[i] == ')')
            stack--;
        if (str[i] == ')' && stack == 0)
            break;
        i++;
    }
    return len;
}

char *get_next_number_paren(char *str, int start)
{
    int len = len_to_next_paren(str, start);
    char *num = malloc(sizeof(char) * len + 1);
    int i = start + 1;

    for (int j = 0; j < len; j++) {
        num[j] = str[i + j];
    }
    num[len] = 0;
    return num;
}

char *get_prev_number_paren(char *str, int start)
{
    int len = len_to_prev_paren(str, start);
    char *num = malloc(sizeof(char) * len + 1);
    int i = start - 1;

    for (int j = 0; j < len; j++) {
        num[j] = str[i - j];
    }
    num[len] = 0;
    my_revstr(num);
    return num;
}