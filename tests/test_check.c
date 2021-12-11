/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (errors, arguments_len, .init = redirect_all_stdout)
{
    cr_expect(check_nb_args(4) == 1);
    cr_expect(check_nb_args(-1) == 0);
    cr_expect_stdout_eq_str(SYNTAX_ERROR_MSG);
}

Test (errors, base_len, .init = redirect_all_stdout)
{
    cr_expect(check_base("0123456789") == 1);
    cr_expect(check_base("0") == 0);
    cr_expect_stdout_eq_str(SYNTAX_ERROR_MSG);
    cr_expect(check_base("azbcdfghqtyeà987654321FKLMPOIUYH") == 1);
}

Test (errors, ops_len, .init = redirect_all_stdout)
{
    cr_expect(check_ops("()+-*/%") == 1);
    cr_expect(check_ops("") == 0);
    cr_expect_stdout_eq_str(SYNTAX_ERROR_MSG);
}
Test (errors, help, .init = redirect_all_stdout)
{
    char **array = malloc(16);
    array[0] = "jytqe";
    array[1] = "-h";
    cr_expect(check_help(2, array) == 0);
    cr_expect_stdout_eq_str("USAGE\n./calc base operators size_read\n\n"
    "DESCRIPTION\n- base: all the symbols of the base\n"
    "- operators: the symbols for the parentheses and the 5 operators\n"
    "- size_read: numbers of characters to be read\n", "");
    cr_expect(check_help(3, array) == 1);
    char **array_2 = my_str_to_word_array("aout help");
    cr_expect(check_help(2, array_2) == 1);
}