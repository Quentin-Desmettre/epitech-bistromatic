/*
** EPITECH PROJECT, 2021
** Bistro test
** File description:
** Modulo Test (1)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (check_null, check_if_null)
{
    char *result = my_strdup("");
    char *base = "0123456789";

    cr_assert_str_eq(check_null(&result, base), "0");
    result = "56";
    cr_assert_str_neq(check_null(&result, base), "0");
}

Test (my_mod, check_nice_mod)
{
    char *a = "-5967";
    char *b = "12";
    char *base = "0123456789";
    char *ops = "()+-*/%";

    cr_assert_str_eq(my_mod(a + 1, b, base, ops), "3");
    cr_assert_str_eq(my_mod(a, b, base, ops), a);
}

Test (infin_mod, check_all_mod)
{
    char *a = "-5697";
    char *b = "-12";
    char *result;
    char * base = "0123456789";
    char *ops = "()+-*/%";

    result = infin_mod(a, b, base, ops);
    cr_assert_str_eq(result, "-9");
    result = infin_mod(a + 1, b, base, ops);
    cr_assert_str_eq(result, "9");
    result = infin_mod(a + 1, b + 1, base, ops);
    cr_assert_str_eq(result, "9");
    result = infin_mod(a, b + 1, base, ops);
    cr_assert_str_eq(result, "-9");
}