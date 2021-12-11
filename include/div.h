/*
** EPITECH PROJECT, 2021
** div.h
** File description:
** div.h
*/
#ifndef BISTRO_DIV_H
    #define BISTRO_DIV_H

void replace_sub(char **r, char *ten_n_bc, expr_params_t *);
void free_all(char *ten_n_b, char *ten_n, char *ten_n_bc);
void error_inf_div(char *b, char *base);
void replace_add(char **q, char *ten_n, int c, expr_params_t *par);
char *search_who_is_upper_c(char *ten_n_b, char *r, int *c,
    expr_params_t *par);
void search_who_is_upper_n(char **ten_n, char **ten_n_b, char *r,
    expr_params_t *par);
void append_char(char **str, char c, int is_free);
char *char_to_str(char c);
char *my_div(char *a, char *b, expr_params_t *par);
char *infin_div(char *a, char *b, char *base, char *ops);

#endif
