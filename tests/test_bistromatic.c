/*
** EPITECH PROJECT, 2021
** Bistro
** File description:
** TODO: add description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"
#include  <unistd.h>

Test (get_expr, syntax_error_invalid_len, .init = redirect_all_stdout)
{
    int const read_size = -10;
    get_expr(read_size);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}

Test (bistromatic_func, invalid_args, .init = redirect_all_stdout)
{
    char **array = malloc(sizeof(char *) * 4);

    array[0] = "./a.out";
    array[1] = "0123456789";
    array[2] = "()+-*/%";
    array[3] = "-1";
    cr_assert(bistromatic(2, array) == 84);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}

Test (bistromatic_func, invalid_args_2, .init = redirect_all_stdout)
{
    char **array = malloc(sizeof(char *) * 4);

    array[0] = "./a.out";
    array[1] = "0123456789";
    array[2] = "()+-*/%";
    array[3] = "-1";
    cr_assert(bistromatic(4, array) == 84);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}
