/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** others checks
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (check_expr_others, count_occurence, .init = redirect_all_stdout)
{
    cr_assert(count_occurences('z', "") == 0);
    cr_assert(count_occurences('z', "zalut les zamis") == 2);
    cr_assert(count_occurences('z', "zzzzz zzzzz dodo") == 10);
}

Test (check_expr_others, check_redundancy, .init = redirect_all_stdout)
{
    cr_assert(check_redundance("Z1234567890") == 1);
    cr_assert(check_redundance("!:;,?./§@^\\`|[{") == 1);
    cr_assert(check_redundance("aaa") == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}

Test (check_expr_others, check_base_ops_1, .init = redirect_all_stdout)
{
    cr_assert(check_base_ops("0123456789", "()+-*/%") == 1);
    cr_assert(check_base_ops("^\\`|[{#~", "0123456") == 1);
    cr_assert(check_base_ops("01234567899", "()+-*/%") == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}

Test (check_expr_others, check_base_ops_2, .init = redirect_all_stdout)
{
    cr_assert(check_base_ops("0123456789", "()+-*%%") == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}

Test (check_expr_others, check_base_ops_3, .init = redirect_all_stdout)
{
    cr_assert(check_base_ops("0123456789", "()+-*%9") == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}