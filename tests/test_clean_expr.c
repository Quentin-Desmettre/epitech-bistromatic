/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** others checks
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (clean_expr, lens_to_nb_test, .init = redirect_all_stdout)
{
    int_pair_t pair = lens_to_nb("++-++-78", "()+-*/%", 0);

    cr_assert(pair.a == 2);
    cr_assert(pair.b == 6);
}

Test (clean_expr, replace_negs, .init = redirect_all_stdout)
{
    char *expr = my_strdup("+---+78");

    (replace_negs(&expr, "0123456789", "()+-*/%", 0));
    cr_assert_str_eq(expr, "-78");
    expr = my_strdup("8+---+78");
    (replace_negs(&expr, "0123456789", "()+-*/%", 1));
    cr_assert_str_eq(expr, "8-78");
    expr = my_strdup("8+(55)--78");
    (replace_negs(&expr, "0123456789", "()+-*/%", 6));
    cr_assert_str_eq(expr, "8+(55)+78");
}

Test (clean_expr, remove_zeros, .init = redirect_all_stdout)
{
    char *expr = my_strdup("0078");

    remove_zeros(&expr, "0123456789", 0);
    cr_assert_str_eq(expr, "78");
}

Test (clean_expr, is_rm_zero, .init = redirect_all_stdout)
{
    char *expr = my_strdup("789");

    cr_assert(is_rm_zero(expr, "0123456789", 0) == 1);
}

Test (clean_expr, cleanex, .init = redirect_all_stdout)
{
    char *expr = my_strdup("+--++00789");

    cleanex(&expr, "0123456789", "()+-*/%");
    cr_assert_str_eq(expr, "789");
}
