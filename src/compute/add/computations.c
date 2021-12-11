/*
** EPITECH PROJECT, 2021
** InfinAdd
** File description:
** Computations
*/

#include "bistromatic.h"
#include <stdlib.h>

void put_same_length(char **first, char **second, char *base, char *ops)
{
    int len_f;
    int len_s;

    if (**first == ops[3])
        (*first)++;
    if (**second == ops[3])
        (*second)++;
    len_f = my_strlen(*first);
    len_s = my_strlen(*second);
    if (len_f < len_s) {
        insert_at_beg(first, base[0], len_s - len_f, 0);
        *second = my_strdup(*second);
    }
    if (len_s < len_f) {
        insert_at_beg(second, base[0], len_f - len_s, 0);
        *first = my_strdup(*first);
    }
}

char *reput_str_good(char **result, int len, char *base, char *ops)
{
    for (int i = 0; i < len + 1; i++) {
        (*result)[i] = base[(int) (*result)[i]];
    }
    re_alloc(result, clean_str(*result, base, ops), 1);
    return *result;
}

char *compute_sub(char *first, char *second, char *base, char *ops)
{
    int len = my_strlen(first);
    int index_of_first = 0;
    char *result = malloc(sizeof(char) * (len + 2));

    init_with(result, 0, len + 2);
    for (int i = len - 1; i >= 0; i--) {
        if (first[i] < 0) {
            first[i - 1]--;
            first[i] = base[my_strlen(base) + first[i]];
        }
        result[i + 1] += index_of(first[i], base) - index_of(second[i], base);
        if (result[i + 1] < 0) {
            index_of_first = index_of(first[i - 1], base);
            first[i - 1] = (index_of_first == 0) ? (-1) :
            base[index_of_first - 1];
            result[i + 1] += my_strlen(base);
        }
    }
    return reput_str_good(&result, len, base, ops);
}

char *my_sub(char *first, char *second, int is_rec, expr_params_t *par)
{
    char *result;
    int len_f = strlen_free(clean_str(first, par->base, par->ops));
    int len_s = strlen_free(clean_str(second, par->base, par->ops));

    second = my_strdup(second);
    first = my_strdup(first);
    if (len_f < len_s) {
        result = my_sub(second, first, 1, par);
        if (!is_rec)
            insert_at_beg(&result, par->ops[3], 1, 1);
        return result;
    }
    put_same_length(&first, &second, par->base, par->ops);
    if (my_nbr_cmp(first, second, par->base) < 0) {
        result = my_sub(second, first, 1, par);
        if (!is_rec)
            insert_at_beg(&result, par->ops[3], 1, 1);
        return result;
    }
    return compute_sub(first, second, par->base, par->ops);
}

char *my_add(char *first, char *second, char *base, char *ops)
{
    int len;
    char *result;
    int len_base = my_strlen(base);

    put_same_length(&first, &second, base, ops);
    len = my_strlen(first);
    result = malloc(sizeof(char) * (len + 2));
    init_with(result, '\0', len + 2);
    for (int i = len - 1; i >= 0; i--) {
        result[i + 1] += index_of(first[i], base) + index_of(second[i], base);
        result[i] = result[i + 1] / len_base;
        result[i + 1] -= result[i] * len_base;
    }
    for (int i = 0; i < len + 1; i++)
        result[i] = base[(int) result[i]];
    return result;
}
