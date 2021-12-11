/*
** EPITECH PROJECT, 2021
** eval.c
** File description:
** eval.c
*/

#include "bistromatic.h"
#include <stdlib.h>

static char *val_tempo(char *calcul, int *i, int *j, char *ops)
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

static char *prio(char *calcul, char *base, char *ops)
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

int highest_powers(char *str)
{
    int highest_order = 0;
    int tmp_order = 0;
    int i_max;
    int tmp_max;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '^'){
            tmp_order++;
            tmp_max = i;
        }
        else if (contain(OPS, str[i])) {
            if (highest_order < tmp_order) {
                highest_order = tmp_order;
                tmp_order = 0;
                i_max = tmp_max;
            }
        }
    }
    if (highest_order < tmp_order)
        return tmp_max;
    return i_max;
}

void eval_powers(char **str)
{
    char *left;
    char *right;
    char *tmp;
    int i = 0;
    int start = 0;
    int nn = 0;
    int mm = 0;
    int nb_rm = 0;

    while (contain(*str, '^')) {
        i = highest_powers(*str);
        left = get_prev_number_paren(*str, i);
        right = get_next_number_paren(*str, i);
        start = i - my_strlen(left);
        nb_rm = my_strlen(left) + my_strlen(right) + 1;
        if (left[0] == '('){
            re_alloc(&left, replace(left, 0, 1, ""), 1);
            re_alloc(&left, replace(left, my_strlen(left) - 1, 1, ""), 1);
            i--;
        }
        if (right[0] == '('){
            re_alloc(&right, replace(right, 0, 1, ""), 1);
            re_alloc(&right, replace(right, my_strlen(right) - 1, 1, ""), 1);
        }
        // evaluation
        // si il y a ^ dans right/gauche, eval_powers:
        if (contain(left, '^'))
            eval_powers(&left);
        if (contain(right, '^'))
            eval_powers(&right);
        re_alloc(&left, eval_expr(my_strdup(left), BASE, OPS), 1);
        re_alloc(&right, eval_expr(my_strdup(right), BASE, OPS), 1);
        tmp = infin_pow(left, right, BASE, OPS);
        re_alloc(str, replace(*str, start, nb_rm, tmp), 1);
        free(left);
        free(right);
        cleanex(str, BASE, OPS);
        free(tmp);
    }
}

char *eval_expr(char *str, char *base, char *ops)
{
    char *tmp;
    char *ops_without_dot = replace(ops, 8, 1, "");

    if (contain(str, '^'))    
        eval_powers(&str);
    while (my_strlen(str) > 1 &&
    contain_any_of(str + 1, ops_without_dot)) {
        cleanex(&str, base, ops);
        tmp = str;
        str = prio(str, base, ops);
        free(tmp);
    }
    cleanex(&str, base, ops);
    if (str[0] == 0 ||
    (str[0] == ops[3] && str[1] == base[0] && str[2] != '.') ||
    (str[0] == ops[3] && str[1] == 0)) {
        free(str);
        str = char_to_str(base[0]);
    }
    free(ops_without_dot);
    return str;
}
