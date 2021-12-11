/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (check_expr, paren, .init = redirect_all_stdout)
{
    cr_assert(check_paren("(test(second)third)", "()+-*/%") == 1);
    cr_assert(check_paren("test(second)third)", "()+-*/%") == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}

Test (check_expr, paren_2, .init = redirect_all_stdout)
{
    cr_assert(check_paren("(test(second)third", "()+-*/%") == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}

Test (check_expr, paren_3, .init = redirect_all_stdout)
{
    cr_assert(check_paren("(test)second(third", "()+-*/%") == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}

Test (check_expr, empty_paren, .init = redirect_all_stdout)
{
    cr_assert(check_double_paren("hello()world", "()+-*/%", 5) == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
    cr_assert(check_double_paren("hello( )world", "()+-*/%", 5) == 1);
}

Test (check_expr, double_ops, .init = redirect_all_stdout)
{
    cr_assert(check_double_ops("+-345", "()+-*/%", 0) == 1);
    cr_assert(check_double_ops("+*345", "()+-*/%", 0) == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
    cr_assert(check_double_ops("+-----++++--", "()+-*/%", 0) == 1);
}
