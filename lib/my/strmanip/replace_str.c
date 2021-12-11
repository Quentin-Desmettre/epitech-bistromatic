/*
** EPITECH PROJECT, 2021
** rep.c
** File description:
** rep.c
*/
#include "../include/strmanip.h"
#include "../include/iomanip.h"
#include <stdlib.h>

char *replace(char const *str, int from, int nb, char *new)
{
    int len = my_strlen(str) - nb + my_strlen(new) + 1;
    char *new_string = malloc(sizeof(char) * len);
    int len_new = my_strlen(new);

    for (int i = 0; i < from; i++) {
        new_string[i] = str[i];
    }
    for (int i = from; i < len_new + from; i++) {
        new_string[i] = new[i - from];
    }
    for (int i = from + len_new; str[i + nb - len_new]; i++) {
        new_string[i] = str[i + nb - len_new];
    }
    new_string[len - 1] = '\0';
    return new_string;
}
