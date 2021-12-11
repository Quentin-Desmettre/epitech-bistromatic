/*
** EPITECH PROJECT, 2021
** InfinAdd
** File description:
** main file
*/

#include "bistromatic.h"
#include <stdlib.h>

char *infin_add(char *first, char *second, char *base, char *ops)
{
    char *fir = my_strdup(first);
    char *sec = my_strdup(second);
    char *result;
    expr_params_t par = {0, base, ops};
    int first_decim = nb_decimals(fir, ops);
    int sec_decim = nb_decimals(sec, ops);    
    int nb_dec = (first_decim > sec_decim) ? (first_decim) : (sec_decim);
    char *zero = char_to_str(base[0]);
    int isneg;
    char *zeros = "";

    adapt_decimals(&fir, &sec, base, ops);
    if (fir[0] == ops[3] && sec[0] == ops[3]) {
        result = my_add(fir, sec, base, ops);
        insert_at_beg(&result, ops[3], 1, 1);
    }
    if (fir[0] == ops[3] && sec[0] != ops[3])
        result = my_sub(sec, fir + 1, 0, &par);
    if (fir[0] != ops[3] && sec[0] == ops[3])
        result = my_sub(fir, sec + 1, 0, &par);
    if (fir[0] != ops[3] && sec[0] != ops[3]) {
        result = my_add(fir, sec, base, ops);
    }
    free(fir);
    free(sec);
    cleanex(&result, base, ops);
    isneg = (result[0] == ops[3]) ? 1 : 0;
    if (nb_dec > 0){
        if (nb_dec > my_strlen(result) - isneg) {
            zeros = malloc(sizeof(char) * nb_dec - my_strlen(result) + isneg + 1);
            init_with(zeros, '0', nb_dec - my_strlen(result) + isneg);
            zeros[nb_dec - my_strlen(result) + isneg] = 0;
            re_alloc(&result, replace(result, isneg, 0, zeros), 1);
            free(zeros);
        }
        re_alloc(&result, replace(result, my_strlen(result) - nb_dec, 0, &ops[8]), 1);
    }
    if (result[0] == ops[8] || (result[0] == ops[3] && result[1] == ops[8]))
        re_alloc(&result, replace(result, isneg, 0, zero), 1);
    cleanex(&result, base, ops);
    free(zero);
    return result;
}
