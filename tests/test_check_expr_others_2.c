/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (check_expr_others, check_ops_place, .init = redirect_all_stdout)
{
    cr_assert(check_ops_place("3*9*(5-78)", "()+-*/%") == 1);
    cr_assert(check_ops_place("*3*9*(5-78)", "()+-*/%") == 0);
    cr_assert(check_ops_place("/3*9*(5-78)", "()+-*/%") == 0);
    cr_assert(check_ops_place("%3*9*(5-78)", "()+-*/%") == 0);
    cr_assert(check_ops_place("+3*9*(5-78)", "()+-*/%") == 1);
    cr_assert(check_ops_place("-3*9*(5-78)", "()+-*/%") == 1);
    cr_assert(check_ops_place("+3*9*(5-78)/", "()+-*/%") == 0);
    cr_assert(check_ops_place("+3*9*(5-78)%", "()+-*/%") == 0);
    cr_assert(check_ops_place("+3*9*(5-78)*", "()+-*/%") == 0);
}

Test (check_expr_others, check_basics, .init = redirect_all_stdout)
{
    cr_assert(check_basic("", "0123456789", "()+-*/%") == 0);
    cr_assert(check_basic("69420", "0123456789", "()+-*/%") == 1);
    cr_assert(check_basic("fffff", "0123456789", "()+-*/%") == 0);
    cr_assert(check_basic("ff9ff", "012345678f", "()+-9/%") == 1);
}