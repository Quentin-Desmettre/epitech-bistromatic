/*
** EPITECH PROJECT, 2021
** get_color
** File description:
** returns int value of an rgb color
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int value;

    value = red << 16;
    value += green << 8;
    value += blue;
    return value;
}
