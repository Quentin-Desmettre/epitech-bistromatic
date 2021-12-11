/*
** EPITECH PROJECT, 2021
** div_test
** File description:
** div2_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"
#include "../include/div.h"

Test (my_div, do_div)
{
    char *a = "5697";
    char *b = "12";
    char *result;
    expr_params_t par = {0, "0123456789", "()+-*/%"};

    result = my_div(a, b, &par);
    cr_assert_str_eq(result, "474");
    a = "-5697";
    result = my_div(a, b, &par);
    cr_assert_str_eq(result, "0");
}

Test (inf_div, all_possibility)
{
    char *a = "-5697";
    char *b = "-12";
    char *result;
    char * base = "0123456789";
    char *ops = "()+-*/%";

    result = infin_div(a, b, base, ops);
    cr_assert_str_eq(result, "474");
    result = infin_div(a + 1, b, base, ops);
    cr_assert_str_eq(result, "-474");
    result = infin_div(a + 1, b + 1, base, ops);
    cr_assert_str_eq(result, "474");
    result = infin_div(a, b + 1, base, ops);
    cr_assert_str_eq(result, "-474");
}

Test (my_div, err_div_by_zero, .init = redirect_all_stdout, .exit_code = 84)
{
    char *a = "0";
    char *base = "0123456789";

    error_inf_div(a, base);
    cr_expect_stdout_eq_str("error");
}
