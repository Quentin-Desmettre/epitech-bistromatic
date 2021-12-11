/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** splits a string into words
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/strmanip.h"

static int is_alphanumeric(char c)
{
    int value = (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z');

    value = value || (c >= 'A' && c <= 'Z');
    return value;
}

static int count_words(char const *str)
{
    int counter = 0;
    int checker = 0;
    int increment = 1;

    while (*str) {
        if (!checker && is_alphanumeric(*str)) {
            checker = 1;
            counter++;
        }
        increment = 1;
        while (*str && !is_alphanumeric(*str)) {
            str++;
            checker = 0;
            increment = 0;
        }
        if (increment)
            str++;
    }
    return counter;
}

static int get_word_length(char const *str)
{
    int len = 0;

    while (is_alphanumeric(*(str + len)))
        len++;
    return len;
}

static char *get_word(char const *str)
{
    int length = get_word_length(str);
    char *word = malloc(sizeof(char) * (length + 1));

    my_strncpy(word, str, length);
    word[length] = '\0';
    str += length;
    return word;
}

char **my_str_to_word_array(char const *str)
{
    int word_count = count_words(str);
    char **array = malloc(sizeof(char *) * (word_count + 1));

    while (*str && !is_alphanumeric(*str))
        str++;
    for (int index = 0; index < word_count && *str; index++) {
        array[index] = get_word(str);
        str += my_strlen(array[index]);
        while (*str && !is_alphanumeric(*str)) {
            str++;
        }
    }
    array[word_count] = 0;
    return array;
}
