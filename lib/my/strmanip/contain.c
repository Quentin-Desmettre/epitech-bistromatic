/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** check if a string contain a char
*/

int contain(char const *str, char const c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

int is_op(char const c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int contain_any_of(char const *str, char const *check)
{
    for (int i = 0; check[i]; i++) {
        if (contain(str, check[i]))
            return 1;
    }
    return 0;
}

int contain_only(char const *str, char const *check)
{
    for (int i = 0; str[i]; i++) {
        if (!contain(check, str[i]))
            return 0;
    }
    return 1;
}
