/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** others checks
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (computations, my_add, .init = redirect_all_stdout)
{
    cr_assert_str_eq(my_add("78", "5", "0123456789", "()+-*/%"), "083");
}

Test (computations, put_same_length, .init = redirect_all_stdout)
{
    char *first = my_strdup("78");
    char *second = my_strdup("0078");

    put_same_length(&first, &second, "0123456789", "()+-*/%");
    cr_assert_str_eq(first, "0078");
    cr_assert_str_eq(second, "0078");
    first = my_strdup("-7800");
    second = my_strdup("-78");
    put_same_length(&first, &second, "0123456789", "()+-*/%");
    cr_assert_str_eq(first, "7800");
    cr_assert_str_eq(second, "0078");
}

Test (computations, reput_str_good, .init = redirect_all_stdout)
{
    char buf[5] = {1, 2, 3, 4, 0};
    char *str = my_strdup(buf);

    reput_str_good(&str, 3, "0123456789", "()+-*/%");
    cr_assert_str_eq(str, "1234");
}

Test (computations, my_sub, .init = redirect_all_stdout)
{
    expr_params_t par = {0, "0123456789", "()+-*/%"};

    cr_assert_str_eq(my_sub("78", "5", 0, &par), "73");
    cr_assert_str_eq(my_sub("100", "52", 0, &par), "48");
    cr_assert_str_eq(my_sub("52", "100", 0, &par), "-48");
    cr_assert_str_eq(my_sub("10", "20", 0, &par), "-10");
    //cr_assert_str_eq(compute_sub("78", "5", "0123456789", "()+-*/%"), "73");
    //cr_assert_str_eq(compute_sub("100", "52", "0123456789", "()+-*/%"), "48");
}