/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/
#include <stdlib.h>
#include <unistd.h>
#include "bistromatic.h"
#include "div.h"

char *check_null(char **result, char *base)
{
    char *r = *result;

    if (r[0] == 0) {
        free(r);
        r = malloc(2);
        r[0] = base[0];
        r[1] = 0;
    }
    return r;
}

char *my_mod(char *a, char *b, char *base, char *ops)
{
    char *q = char_to_str(base[0]);
    char *r = my_strdup(a);
    char *ten_n_b = NULL;
    char *ten_n = NULL;
    char *ten_n_bc = NULL;
    int c = 1;
    expr_params_t par = {0, base, ops};

    error_inf_div(b, base);
    while ((my_nbr_cmp(r, b, base) >= 0) && r[0] != ops[3]) {
        ten_n_b = my_strdup(b);
        ten_n = char_to_str(base[1]);
        search_who_is_upper_n(&ten_n, &ten_n_b, r, &par);
        ten_n_bc = search_who_is_upper_c(ten_n_b, r, &c, &par);
        replace_add(&q, ten_n, c, &par);
        replace_sub(&r, ten_n_bc, &par);
        free_all(ten_n_b, ten_n, ten_n_bc);
    }
    free(q);
    return check_null(&r, base);
}

char *infin_mod(char *a, char *b, char *base, char *ops)
{
    char *result;
    int nb_dec_a = nb_decimals(a, OPS);
    int nb_dec_b = nb_decimals(b, OPS);
    int nb_dec = (nb_dec_a > nb_dec_b) ? nb_dec_a : nb_dec_b;
    char *zeros = "";
    char *zero = char_to_str(base[0]);

    a = my_strdup(a);
    b = my_strdup(b);
    adapt_decimals(&a, &b, BASE, OPS);
    if (a[0] == ops[3] && b[0] == ops[3]) {
        result = my_mod(a + 1, b + 1, base, ops);
        insert_at_beg(&result, ops[3], 1, 1);
    }
    if (a[0] != ops[3] && b[0] != ops[3])
        result = my_mod(a, b, base, ops);
    if (a[0] == ops[3] && b[0] != ops[3]) {
        result = my_mod(a + 1, b, base, ops);
        insert_at_beg(&result, ops[3], 1, 1);
    }
    if (a[0] != ops[3] && b[0] == ops[3])
        result = my_mod(a, b + 1, base, ops);
    if (nb_dec > 0){
        if (nb_dec > my_strlen(result)) {
            zeros = malloc(sizeof(char) * nb_dec - my_strlen(result) + 1);
            init_with(zeros, '0', nb_dec - my_strlen(result));
            zeros[nb_dec - my_strlen(result)] = 0;
            re_alloc(&result, replace(result, 0, 0, zeros), 1);
            free(zeros);
        }
        re_alloc(&result, replace(result, my_strlen(result) - nb_dec, 0, &ops[8]), 1);
    }
    if (result[0] == ops[8] || (result[0] == ops[3] && result[1] == ops[8]))
        re_alloc(&result, replace(result, 0, 0, zero), 1);
    return (result);
}
