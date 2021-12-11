/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** others checks
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (clean_expr, init_with, .init = redirect_all_stdout)
{
    char str[15];

    init_with(str, 'y', 15);
    for (int i = 0; i < 15; i++)
        cr_assert(str[i] == 'y');
}

Test (clean_expr, insert_at_beg, .init = redirect_all_stdout)
{
    char *expr = my_strdup("yo");

    insert_at_beg(&expr, 'h', 3, 1);
    cr_assert_str_eq(expr, "hhhyo");
}

Test (clean_expr, my_nbrcmp, .init = redirect_all_stdout)
{
    char first[3] = {'1', '5', 0};
    char secnd[3] = {'1', '2', 0};

    cr_assert(my_nbr_cmp(first, secnd, "0123456789") > 0);
    cr_assert(my_nbr_cmp(secnd, first, "0123456789") < 0);
    cr_assert(my_nbr_cmp(secnd, secnd, "0123456789") == 0);
    first[1] = 0;
    cr_assert(my_nbr_cmp(first, secnd, "0123456789") < 0);
}

Test (clean_expr, indexof, .init = redirect_all_stdout)
{
    char first[3] = {'1', '5', 0};

    cr_assert(index_of('1', first) == 0);
    cr_assert(index_of('r', first) == -1);
}

Test (clean_expr, clean_str, .init = redirect_all_stdout)
{
    char *first = my_strdup("-00045");

    cr_assert_str_eq(clean_str(first, "0123456789", "()+-*/%"), "-45");
    first = my_strdup("0");
    cr_assert_str_eq(clean_str(first, "0123456789", "()+-*/%"), "0");
}
