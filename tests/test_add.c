/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** Add Test (1)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (infin_add, basic_add, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_add("5", "5", "0123456789", "()+-*/%"), "10");
}

Test (infin_add, basic_add_both_neg, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_add("-5", "-5", "0123456789", "()+-*/%"), "-10");
}

Test (infin_add, basic_add_left_neg, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_add("-5", "5", "0123456789", "()+-*/%"), "");
}

Test (infin_add, basic_add_right_neg, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_add("5", "-5", "0123456789", "()+-*/%"), "");
}

Test (infin_add, basic_add_two, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_add("20", "100", "0123456789", "()+-*/%"), "120");
}
