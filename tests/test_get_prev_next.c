/*
** EPITECH PROJECT, 2021
** Bistro
** File description:
** Bistro
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test(get_prev_number, grep_number_at_left)
{
    char *str = my_strdup("5+5-5*5");
    int start = 5;
    char *base = "0123456789";
    char *ops = "()+-*/%";

    cr_assert_str_eq(get_prev_number(str, start, base, ops), "5");
    str = my_strdup("-5+5");
    start = 2;
    cr_assert_str_eq(get_prev_number(str, start, base, ops), "-5");
}

Test(get_next_number, grep_number_at_right)
{
    char *str = my_strdup("5+5-5*569");
    int start = 5;
    char *base = "0123456789";
    char *ops = "()+-*/%";

    cr_assert_str_eq(get_next_number(str, start, base, ops), "569");
    str = my_strdup("5*-95685");
    start = 1;
    cr_assert_str_eq(get_next_number(str, start, base, ops), "-95685");
}

Test(len_to_prev, grep_len_at_left)
{
    char *str = my_strdup("5+5-5*569");
    int start = 5;
    char *base = "0123456789";
    char *ops = "()+-*/%";

    cr_assert(len_to_prev(str, start, base, ops) == 1);
    str = my_strdup("-5*-95685");
    start = 2;
    cr_assert(len_to_prev(str, start, base, ops) == 2);
}

Test(len_to_prev, grep_len_at_right)
{
    char *str = my_strdup("5+5-5*569");
    int start = 5;
    char *base = "0123456789";
    char *ops = "()+-*/%";

    cr_assert(len_to_next(str, start, base, ops) == 3);
    str = my_strdup("-5*-95685");
    start = 2;
    cr_assert(len_to_next(str, start, base, ops) == 6);
}
