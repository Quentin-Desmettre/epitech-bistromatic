/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** prototypes for the eval_expr part
*/

#ifndef EVALEXPR_H
    #define EVALEXPR_H

char *evaluate(char *expr, char *base, char *ops);
char *get_next_number(char *str, int start, char *base, char *ops);
char *get_prev_number(char *str, int start, char *base, char *ops);
char *do_op(char *first, int op, char *second, expr_params_t *par);
char *eval_expr(char *str, char *base, char *ops);
char *val_tempo(char *calcul, int *i, int *j, char *ops);
char *prio(char *calcul, char *base, char *ops);
char *compute_raw(int start, int *len, int *len_1, expr_params_t *par);
char *evaluate_with(char *expr, char *base, char *ops, char *op_valid);
int len_to_next(char *str, int start, char *base, char *ops);
int len_to_prev(char *str, int start, char *base, char *ops);
void show_extrem_min(char **jambon);
void do_recursion_part(int nb, char **jambon);
int nb_len(int nb);

#endif
