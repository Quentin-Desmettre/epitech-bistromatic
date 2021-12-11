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
#include "exp.h"
#include <stdio.h>

#define SQRT_E "1.6487212707001281468486507878141635716537761007101480115750793116406610211942156086327765200563666430028666377563077970046711669"

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

unsigned long long int_fac(int i){
    unsigned long long r = 1;

    while (i != 0){
        r *= i;
        i--;
    }
    return r;
}

int count_correct_numbers(char *f, char *s)
{
    int counter = 0;
    int count = 0;
    for (int i = 0; f[i] && s[i]; i++) {
        if (f[i] == '.' || s[i] == '.')
            count = 1;
        if (count && f[i] == s[i])
            counter++;
    }
    return counter;
}

void cap_decimals(char *str)
{
    int nb_dec = nb_decimals(str, OPS);
    if (nb_dec > OUTPUT_PRECISION)
        str[my_strlen(str) - nb_dec - 1 + OUTPUT_PRECISION] = 0;
}

void eval_powers(char **str);
int highest_powers(char *str);
char *new_ln(char *x);
int bistromatic(int ac, char **av)
{
    char *expr;
    if (ac < 2)
        return 84;
    expr = my_strdup(av[1]);
    if (ac < 2 || !check_expr(expr, BASE, OPS))
        return 84;
    cleanex(&expr, BASE, OPS);
    if (my_strcmp(expr, "0+0") == 0) {
        toto();
        return EXIT_SUCCESS;
    }
    expr = eval_expr(expr, BASE, OPS);
    cap_decimals(expr);
    my_putstr(expr);
    my_putchar('\n');
    free(expr);
    return EXIT_SUCCESS;
}
