/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** Add Test (1)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (infin_add, add_carry_test, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_add("777", "7777", "0123456789", "()+-*/%"),
    "8554");
}

Test (infin_add, add_zero_test, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_add("0", "0", "0123456789", "()+-*/%"), "");
}

Test (infin_add, add_big, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_add("123456789987654321",
    "9876543211234567890123456789", "0123456789", "()+-*/%"),
    "9876543211358024680111111110");
}
