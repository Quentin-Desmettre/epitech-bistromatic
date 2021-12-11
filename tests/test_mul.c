/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** Multiplication Test (1)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (infin_mul, basic_mul, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("5", "5", "0123456789", "()+-*/%"), "25");
}

Test (infin_mul, basic_mul_both_neg, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("-5", "-5", "0123456789", "()+-*/%"), "25");
}

Test (infin_mul, basic_mul_left_neg, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("-5", "5", "0123456789", "()+-*/%"), "-25");
}

Test (infin_mul, basic_mul_right_neg, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("5", "-5", "0123456789", "()+-*/%"), "-25");
}

Test (infin_mul, basic_mul_two, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("20", "100", "0123456789", "()+-*/%"), "2000");
}
