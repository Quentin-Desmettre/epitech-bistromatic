/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (errors, all, .init = redirect_all_stdout)
{
    char **array = malloc(sizeof(char *) * 3);
    array[0] = "jytqe";
    array[1] = "-h";
    array[2] = 0;
    char **array_base = malloc(sizeof(char *) * 4);
    array_base[0] = "jyesyf";
    array_base[1] = "0123456789";
    array_base[2] = "()+-*/%";
    array_base[3] = 0;
    cr_expect(check_all(2, array) == 0);
    cr_expect_stdout_eq_str("USAGE\n./calc base operators size_read\n\n"
    "DESCRIPTION\n- base: all the symbols of the base\n"
    "- operators: the symbols for the parentheses and the 5 operators\n"
    "- size_read: numbers of characters to be read\n");
    cr_expect(check_all(4, array_base) == 1);
}

Test (errors, all_second, .init = redirect_all_stdout)
{
    char **array = malloc(sizeof(char *) * 3);
    array[0] = "jytqe";
    array[1] = "juksef";
    cr_assert(check_all(2, array) == 0);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}