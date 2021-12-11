/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** infinsub
*/

#include "bistromatic.h"
#include <stdlib.h>

char *infin_sub(char *fir, char *sec, char *base, char *ops)
{
    char *result = 0;

    if (fir[0] == ops[3] && sec[0] == ops[3])
        return infin_add(fir, sec + 1, base, ops);
    if (fir[0] == ops[3] && sec[0] != ops[3]) {
        insert_at_beg(&sec, ops[3], 1, 0);
        result = infin_add(fir, sec, base, ops);
        free(sec);
    }
    if (fir[0] != ops[3] && sec[0] == ops[3])
        return infin_add(fir, sec + 1, base, ops);
    if (fir[0] != ops[3] && sec[0] != ops[3]) {
        insert_at_beg(&sec, ops[3], 1, 0);
        result = infin_add(fir, sec, base, ops);
        free(sec);
    }
    return result;
}
