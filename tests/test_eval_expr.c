/*
** EPITECH PROJECT, 2021
** Bistro
** File description:
** Bistro
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test(val_tempo, grep_calc_in_parenthese)
{
    char *calcul = "(5+5*5+(5*8+1*5))";
    int i = 0;
    int j = 16;
    char *ops = "()+-*/%";

    cr_assert_str_eq(val_tempo(calcul, &i, &j, ops), "5+5*5+(5*8+1*5)");
    calcul = "(5+5*5+(5*8+1*5))";
    i = 7;
    j = 15;
    cr_assert_str_eq(val_tempo(calcul, &i, &j, ops), "5*8+1*5");
}

Test(prio, calc_only_1time)
{
    char *calcul = "(5+5*5+(5*8+1*5))";
    char *base = "0123456789";
    char *ops = "()+-*/%";

    cr_assert_str_eq(prio(calcul, base, ops), "(5+5*5+45)");
    calcul = "(5+5*5+45)";
    cr_assert_str_eq(prio(calcul, base, ops), "75");
    calcul = "55";
    cr_assert_str_eq(prio(calcul, base, ops), "55");
}

Test(eval_expr, calc_all)
{
    char *str = my_strdup("(5+5*5+(5*8+1*5))");
    char *base = "0123456789";
    char *ops = "()+-*/%";

    cr_assert_str_eq(eval_expr(str, base, ops), "75");
    str =  my_strdup("-0-0");
    cr_assert_str_eq(eval_expr(str, base, ops), "0");
}