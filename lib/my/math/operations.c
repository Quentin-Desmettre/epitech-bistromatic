/*
** EPITECH PROJECT, 2021
** do_op
** File description:
** +, -, *, /, % operators
*/

#include "../include/iomanip.h"

int add(int a, int b)
{
    long long tmp = a + b;

    if (tmp > 2147483647 || tmp < -2147483648) {
        my_putstr_error("0\n");
        return 84;
    }
    my_put_nbr(tmp);
    my_putchar('\n');
    return 0;
}

int substract(int a, int b)
{
    return add(a, -1 * b);
}

int multiply(int a, int b)
{
    int x = a * b;

    if (a != 0 && x / a != b) {
        my_putstr_error("0\n");
        return 84;
    }
    my_put_nbr(x);
    my_putchar('\n');
    return 0;
}

int divide(int a, int b)
{
    if (b == 0) {
        my_putstr_error("Stop: division by zero\n");
        return 84;
    }
    my_put_nbr(a / b);
    my_putchar('\n');
    return 0;
}

int modulo(int a, int b)
{
    if (b == 0) {
        my_putstr_error("Stop: modulo by zero\n");
        return 84;
    }
    my_put_nbr(a % b);
    my_putchar('\n');
    return 0;
}
