/*
** EPITECH PROJECT, 2021
** Bistro
** File description:
** bistro.h
*/
#ifndef DECIMALS_H
    #define DECIMALS_H

void compute_decimal_part(char **result, char *r, char *diviseur, expr_params_t *par);
void adapt_decimals(char **first, char **second, char *base, char *ops);
void adapt(char **str, char *ops);
void put_coma(char **result, int index, char *ops);
int nb_decimals(char *str, char *ops);

#endif