/*
** EPITECH PROJECT, 2021
** swap_endian_color
** File description:
** changes argb to bgra
*/

int swap_endian_color(int color)
{
    int value = 0;

    value += (color & 4278190080) >> 24;
    value += (color & 0b111111110000000000000000) >> 8;
    value += (color & 0b1111111100000000) << 8;
    value += (color & 0b11111111) << 24;
    return value;
}
