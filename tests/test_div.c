/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"
#include "../include/div.h"

Test (search_who_is_upper_n, grep_ten_nb)
{
    expr_params_t par = {0, "0123456789", "()+-*/%"};
    char *ten_n = char_to_str(par.base[1]);
    char *ten_n_b = my_strdup("12");
    char *r = my_strdup("5697");

    search_who_is_upper_n(&ten_n, &ten_n_b, r, &par);
    cr_assert_str_eq(ten_n, "100");
    cr_assert_str_eq(ten_n_b, "1200");
}

Test (search_who_is_upper_c, grep_ten_nbc)
{
    expr_params_t par = {0, "0123456789", "()+-*/%"};
    char *ten_n = my_strdup("1200");
    char *r = my_strdup("5697");
    int c = 1;

    ten_n = search_who_is_upper_c(ten_n, r, &c, &par);
    cr_assert_str_eq(ten_n, "4800");
}

Test (replace_add, replace_q_euclidienne)
{
    char *q = my_strdup("0");
    char *ten_n = my_strdup("1200");
    int c = 4;
    expr_params_t par = {0, "0123456789", "()+-*/%"};

    replace_add(&q, ten_n, c, &par);
    cr_assert_str_eq(q, "4800");
}

Test (replace_sub, replace_r_euclidienne)
{
    char *r = my_strdup("5697");
    char *ten_n_bc = my_strdup("4800");
    expr_params_t par = {0, "0123456789", "()+-*/%"};

    replace_sub(&r, ten_n_bc, &par);
    cr_assert_str_eq(r, "897");
}
