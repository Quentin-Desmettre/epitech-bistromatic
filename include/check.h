/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** header for checks
*/

#ifndef INCLUDE_CHECK_H
    #define INCLUDE_CHECK_H

typedef struct int_pair {
    int a;
    int b;
} int_pair_t;

int check_nb_args(int ac);
int check_base(char const *base);
int check_ops(char const *ops);
int check_help(int ac, char **av);
int check_all(int ac, char **av);
int check_paren(char const *str, char const *ops);
int check_double_paren(char const *str, char const *ops, int i);
int check_double_ops(char const *str, char const *ops, int i);
int check_ops_paren(char const *str, char const *base,
    char const *ops, int i);
int check_expr(char const *str, char const *base, char const *ops);
int count_occurences(char const c, char const *str);
int check_redundance(char const *str);
int check_base_ops(char const *base, char const *ops);
int check_ops_place(char const *str, char const *ops);
int check_basic(char const *str, char const *base, char const *ops);
int_pair_t lens_to_nb(char const *expr, char const *ops, int i);
int replace_negs(char **expr, char *base, char *ops, int i);
int remove_zeros(char **expr, char *base, int i);
int is_rm_zero(char *expr, char *ops, int i);
int cleanex(char **expr, char *base, char *ops);
char *check_null(char **result, char *base);

#endif
