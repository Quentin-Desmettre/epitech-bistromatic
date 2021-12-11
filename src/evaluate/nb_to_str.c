/*
** EPITECH PROJECT, 2021
** nb
** File description:
** nb
*/

#include <stdlib.h>
#include "lib/strmanip.h"

void show_extrem_min(char **jambon)
{
    *jambon = my_strcpy(*jambon, "-2147483648");
}

void do_recursion_part(int nb, char **jambon)
{
    if (nb >= 0 && nb <= 9) {
        (*jambon)[my_strlen(*jambon)] = (nb + 48);
    } else {
        do_recursion_part(nb / 10, jambon);
        (*jambon)[my_strlen(*jambon)] = (nb % 10 + 48);
    }
}

int nb_len(int nb)
{
    int i = 0;

    do {
        nb /= 10;
        i++;
    } while (nb);
    return i;
}

int int_to_str(int nb, char **jambon)
{
    int neg = (nb < 0) ? (1) : (0);
    (*jambon) = malloc(sizeof(char) * (nb_len(nb) + 1 + neg));
    for (int i = 0; i <= nb_len(nb) + neg; (*jambon)[i] = '\0', i++);
    if (nb < 0) {
        (*jambon)[0] = ('-');
        nb *= -1;
    }
    if (nb == -2147483648) {
        show_extrem_min(jambon);
        return (0);
    }
    do_recursion_part(nb, jambon);
    return (0);
}
