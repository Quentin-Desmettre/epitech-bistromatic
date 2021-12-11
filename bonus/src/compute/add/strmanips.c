/*
** EPITECH PROJECT, 2021
** InfinAdd
** File description:
** string manipulations
*/

#include "bistromatic.h"
#include <stdlib.h>

void init_with(char *str, char c, int nb)
{
    for (int i = 0; i < nb; i++) {
        str[i] = c;
    }
}

void insert_at_beg(char **str, char what, int nb, int is_free)
{
    char *new = malloc(sizeof(char) * (my_strlen(*str) + nb + 1));

    for (int i = 0; i < nb; i++) {
        new[i] = what;
    }
    my_strcpy(new + nb, *str);
    is_free ? free(*str) : 0;
    *str = new;
}

int my_nbr_cmp(char *first, char *second, char *base)
{
    int len_f = my_strlen(first);
    int len_s = my_strlen(second);
    if (len_f != len_s)
        return len_f - len_s;
    for (int i = 0; i < len_f; i++) {
        if (first[i] != second[i])
            return index_of(first[i], base) - index_of(second[i], base);
    }
    return 0;
}

char *clean_str(char *str, char *base, char *ops)
{
    int insert_neg = 0;
    char *new;
    int start = 0;
    char *null = malloc(2);

    null[0] = base[0];
    null[1] = 0;
    if (str[0] == ops[3]) {
        start++;
        insert_neg = 1;
    }
    while (str[start] && str[start] == base[0])
        start++;
    if (my_nbr_cmp(str, "0", base) == 0)
        return null;
    new = my_strdup(str + start);
    (insert_neg == 1) ? insert_at_beg(&new, ops[3], 1, 1) : 0;
    free(null);
    return new;
}

int index_of(char c, char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}
