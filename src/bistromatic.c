/*
** EPITECH PROJECT, 2021
** bistro_matic
** File description:
** main file
*/

#include <stdlib.h>
#include "bistromatic.h"
#include <fcntl.h>
#include <unistd.h>

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("./calc base operators size_read\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols for the parentheses");
    my_putstr(" and the 5 operators\n");
    my_putstr("- size_read: numbers of characters to be read\n");
}

char *get_expr(int const read_size)
{
    char *expr = 0;

    if (read_size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        return 0;
    }
    expr = malloc(sizeof(char) * (read_size + 1));
    if (expr == NULL) {
        my_putstr(ERROR_MSG);
        return 0;
    }
    if (read(0, expr, read_size) != read_size) {
        my_putstr(SYNTAX_ERROR_MSG);
        return 0;
    }
    expr[read_size] = '\0';
    return expr;
}

int bistromatic(int ac, char **av)
{
    int size = 0;
    char *expr;

    if (!check_all(ac, av))
        return 84;
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    if (!expr)
        return 84;
    if (!check_expr(expr, av[1], av[2]))
        return 84;
    cleanex(&expr, av[1], av[2]);
    expr = (eval_expr(expr, av[1], av[2]));
    my_putstr(expr);
    free(expr);
    return EXIT_SUCCESS;
}
