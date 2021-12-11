/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** Sub Test (1)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (infin_sub, basic_sub, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_sub("100", "50", "0123456789", "()+-*/%"), "50");
}

Test (infin_sub, basic_sub_carry, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_sub("-100", "99", "0123456789", "()+-*/%"), "-199");
}

Test (infin_sub, basic_sub_first_smaller, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_sub("50", "-299", "0123456789", "()+-*/%"), "349");
}

Test (infin_sub, basic_sub_other, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_sub("-20", "-99", "0123456789", "()+-*/%"), "79");
}