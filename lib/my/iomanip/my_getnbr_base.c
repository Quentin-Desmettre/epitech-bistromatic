/*
** EPITECH PROJECT, 2021
** my_getnbr_base
** File description:
** converts and returns a string to decimal
*/

#include "../include/strmanip.h"
#include "../include/math.h"
#include <stdlib.h>

static const unsigned MAX_POS = 2147483647;
static const unsigned MAX_NEG = 2147483648;

static int index_of(char c, char const *str)
{
    for (int index = 0; str[index]; index++) {
        if (c == str[index])
            return index;
    }
    return -1;
}

static int my_check(char s, char *output, int *sign)
{
    if ((s == '-' || s == '+') && my_strlen(output) == 0) {
        (s == '-') ? (*sign = -1) : (*sign = 1);
    } else if (my_strlen(output) > 0) {
        return 0;
    }
    return 1;
}

static void clean_string(char const *src, char const *b, char *output, int *s)
{
    int index = 0;

    while (*src) {
        if (index_of(*src, b) + 1) {
            output[index] = *src;
            ++index;
        } else if (!my_check(*src, output, s))
            break;
        src++;
    }
    output[index] = '\0';
}

int my_getnbr_base(char const *str, char const *base)
{
    unsigned long long value = 0;
    int sign = 1;
    int b_l = my_strlen(base);
    int c_l;
    char *copy = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (int i = 0; i < my_strlen(str) + 1; i++)
        copy[i] = '\0';
    clean_string(str, base, copy, &sign);
    c_l = my_strlen(copy);
    for (int i = 0; copy[i]; i++) {
        value += index_of(copy[i], base) * my_pow(b_l, c_l - i - 1);
        if ((sign == 1 && value > MAX_POS) || (sign == -1 && value > MAX_NEG))
            return 0;
    }
    free(copy);
    return value * sign;
}
