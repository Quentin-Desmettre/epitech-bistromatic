/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** compute a ^ b
*/

int my_pow(int nb, int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    return nb * my_pow(nb, p - 1);
}
