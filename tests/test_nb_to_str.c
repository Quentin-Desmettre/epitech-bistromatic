/*
** EPITECH PROJECT, 2021
** Bistro
** File description:
** Bistro
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test(nb_to_str, put_negative_overflow)
{
    char *jambon = malloc(30);
    show_extrem_min(&jambon);
    cr_assert_str_eq(jambon, "-2147483648");
}

Test(nb_to_str, put_int_in_str)
{
    int nb = 25;
    char *jambon = malloc(3);

    init_with(jambon, '\0', 3);
    do_recursion_part(nb, &jambon);
    cr_assert_str_eq(jambon, "25");
    init_with(jambon, '\0', 3);
    nb -= 20;
    do_recursion_part(nb, &jambon);
    cr_assert_str_eq(jambon, "5");
}

Test(nb_to_str, len_nb)
{
    int nb = 56894;

    cr_assert(nb_len(nb) == 5);
    nb = 0;
    cr_assert(nb_len(nb) == 1);
}

Test(nb_to_str, int_to_str)
{
    int nb = -56894;
    char *jambon = malloc(11);

    int_to_str(nb, &jambon);
    cr_assert(jambon[0] == '-');
    cr_assert_str_eq(jambon, "-56894");
    nb = -2147483648;
    int_to_str(nb, &jambon);
    cr_assert_str_eq(jambon, "-2147483648");
    cr_assert(int_to_str(nb, &jambon) == 0);
}