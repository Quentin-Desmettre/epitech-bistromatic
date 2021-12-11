/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** Multiplication Test (1)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (infin_mul, mul_carry_test, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("777", "7777", "0123456789", "()+-*/%"),
    "6042729");
}

Test (infin_mul, mul_zero_test, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("0", "0", "0123456789", "()+-*/%"), "");
}

Test (infin_mul, mul_big, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("123456789987654321",
    "9876543211234567890123456789", "0123456789", "()+-*/%"),
    "1219326321033379056636183509998475842112635269");
}
