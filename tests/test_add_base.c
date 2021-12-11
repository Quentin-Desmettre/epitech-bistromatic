/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** Add Test (1)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (infin_add, basic_add_base, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_add("t", "t", "pouet", "()+-*/%"), "oe");
}

Test (infin_add, basic_add_both_neg_base, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_add("-t", "-t", "pouet", "()+-*/%"), "-oe");
}

Test (infin_add, basic_add_left_neg_base, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_add("-t", "t", "pouet", "()+-*/%"), "");
}

Test (infin_add, add_carry_test_base, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_add("opop", "op", "pouet", "()+-*/%"),
    "opup");
}

Test (infin_add, add_big_base, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_add("eputotpeutpeuote", "poetouetpoetpoteoutpoteou",
    "pouet", "()+-*/%"), "oetouetpttoteetppeopupop");
}
