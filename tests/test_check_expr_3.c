/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (check_expr, double_ops_2, .init = redirect_all_stdout)
{
    cr_assert(check_double_ops("/%345", "()+-*/%", 0) == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
    cr_assert(check_double_ops("345", "()+-*/%", 0) == 1);
}
Test (check_expr, ops_paren, .init = redirect_all_stdout)
{
    char *base = "0123456789";
    char *ops = "()+-*/%";
    cr_assert(check_expr("", base, ops) == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}