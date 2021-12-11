/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** prototypes for string manips
*/

#ifndef STR_MANIPULATIONS_H
    #define STR_MANIPULATIONS_H

void init_with(char *str, char c, int nb);
void insert_at_beg(char **str, char what, int nb, int is_free);
int my_nbr_cmp(char *first, char *second, char *base);
char *clean_str(char *str, char *base, char *ops);
int index_of(char c, char *str);
int int_to_str(int nb, char **str);
void re_alloc(char **str, char *new, int is_free);
void init_with_int(unsigned long long *array, int what, int len);
void put_same_length(char **first, char **second, char *base, char *ops);
char *reput_str_good(char **result, int len, char *base, char *ops);

#endif
