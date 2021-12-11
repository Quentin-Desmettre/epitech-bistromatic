/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** check if arguments are valid
*/

#include <stdlib.h>
#include "bistromatic.h"

int check_nb_args(int ac)
{
    if (ac != 4) {
        my_putstr(SYNTAX_ERROR_MSG);
        return 0;
    }
    return 1;
}

int check_base(char const *base)
{
    if (my_strlen(base) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        return 0;
    }
    return 1;
}

int check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        return 0;
    }
    return 1;
}

int check_help(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usage();
        return 0;
    }
    return 1;
}

int check_all(int ac, char **av)
{
    return check_help(ac, av) && check_nb_args(ac)
    && check_base(av[1]) && check_ops(av[2]);
}
