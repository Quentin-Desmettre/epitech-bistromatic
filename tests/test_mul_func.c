/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** Multiplication Func Test (1)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (infin_mul, re_alloc_test, .init = redirect_all_stdout)
{
    char *result = my_strdup("saussure");
    char *new = my_strdup("soooz");
    re_alloc(&result, new, 1);
    cr_assert_str_eq(result, new);
}

Test (infin_mul, init_with_int_test, .init = redirect_all_stdout)
{
    unsigned long long *array = malloc(sizeof(unsigned long long) * 5);
    init_with_int(array, 0, 5);
    for (int i = 0; i < 5; i++)
        cr_assert(array[i] == 0);
}
/*
Test (infin_mul, replace_digit_test, .init = redirect_all_stdout)
{
    unsigned long long result;
    char *fir = "35";
    char *sec = "100";
    char *base = "0123456789";
    unsigned long long expected = 3500;
    result = replace_digit(fir, sec, base);
    cr_assert(result == expected);
}

Test (infin_mul, my_mul_test, .init = redirect_all_stdout)
{
    char result = my_strdup("0000");
    char *fir = "35";
    char *sec = "100";
    char *base = "0123456789";
    char *ops = "()+-/%";
    my_mul(fir, sec, base, ops);
    cr_assert_str_eq(result, "3500");
}*/
