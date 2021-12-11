/*
** EPITECH PROJECT, 2021
** eval.c
** File description:
** eval.c
*/

#include "bistromatic.h"
#include <stdlib.h>

char *val_tempo(char *calcul, int *i, int *j, char *ops)
{
    char *tempo;
    int h = 0;

    for (; calcul[(*j)] && calcul[(*j)] != ops[1]; (*j)++)
        if (calcul[(*j)] == ops[0])
            (*i) = (*j);
    tempo = malloc(sizeof(char) * ((*j) - (*i)));
    for (; h != (*j) - (*i) - 1; h++)
        tempo[h] = calcul[(*i) + h + 1];
    tempo[h] = '\0';
    return tempo;
}

char *prio(char *calcul, char *base, char *ops)
{
    int i = 0;
    int j = 0;
    char *tempo = val_tempo(calcul, &i, &j, ops);
    char *to_rt;
    char *tempo2;

    if (calcul[i] != ops[0]) {
        free(tempo);
        to_rt = my_strdup(calcul);
        tempo2 = evaluate(to_rt, base, ops);
        to_rt = replace(calcul, 0, j, tempo2);
        free(tempo2);
        return to_rt;
    }
    tempo2 = evaluate(tempo, base, ops);
    to_rt = replace(calcul, i, j - i + 1, tempo2);
    return to_rt;
}

char *eval_expr(char *str, char *base, char *ops)
{
    char *tmp;

    while (my_strlen(str) > 1 && contain_any_of(str + 1, ops)) {
        cleanex(&str, base, ops);
        tmp = str;
        str = prio(str, base, ops);
        free(tmp);
    }
    cleanex(&str, base, ops);
    if (str[0] == 0 ||
    (str[0] == ops[3] && str[1] == base[0]) ||
    (str[0] == ops[3] && str[1] == 0)) {
        free(str);
        str = char_to_str(base[0]);
    }
    return str;
}
