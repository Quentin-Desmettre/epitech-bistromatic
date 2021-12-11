/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (check_expr, ops_paren_2, .init = redirect_all_stdout)
{
    char *base = "0123456789";
    char *ops = "()+-*/%";
    cr_assert(check_expr("hello", base, ops) == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
    cr_assert(check_expr("(5*8)", base, ops) == 1);
}

Test (check_expr, ops_paren_3, .init = redirect_all_stdout)
{
    char *base = "0123456789";
    char *ops = "()+-*/%";
    cr_assert(check_expr("(5*)", base, ops) == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}

Test (check_expr, ops_paren_4, .init = redirect_all_stdout)
{
    char *base = "0123456789";
    char *ops = "()+-*/%";
    cr_assert(check_expr("(5*9)8", base, ops) == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}

Test (check_expr, ops_paren_5, .init = redirect_all_stdout)
{
    char *base = "0123456789";
    char *ops = "()+-*/%";
    cr_assert(check_expr("(678)()", base, ops) == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}

Test (check_expr, ops_paren_6, .init = redirect_all_stdout)
{
    char *base = "0123456789";
    char *ops = "()+-*/%";
    cr_assert(check_expr("(*678)", base, ops) == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}