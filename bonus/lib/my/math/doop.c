/*
** EPITECH PROJECT, 2021
** do_op
** File description:
** compute a 2 number operation
*/

#include "../include/iomanip.h"
#include "../include/math.h"

static int is_operation(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

static int compute(int n1, int operation, int n2)
{
    int (*fonc[5])(int, int);

    fonc[0] = &add;
    fonc[1] = &substract;
    fonc[2] = &multiply;
    fonc[3] = &divide;
    fonc[4] = &modulo;
    return fonc[operation](n1, n2);
}

int doop(int argc, char **argv)
{
    int number_1;
    int number_2;
    char op;

    if (argc != 4)
        return 84;
    if (!is_operation(*argv[2])) {
        my_putstr_error("0\n");
        return 84;
    }
    number_1 = my_getnbr(argv[1]);
    number_2 = my_getnbr(argv[3]);
    op = argv[2][0];
    op = (op == '+') * 0 + (op == '-') + (op == '*') * 2;
    op += (argv[2][0] == '/') * 3 + (argv[2][0] == '%') * 4;
    return compute(number_1, op, number_2);
}
