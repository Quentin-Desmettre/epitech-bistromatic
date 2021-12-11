/*
** EPITECH PROJECT, 2021
** Bistro
** File description:
** toto.c
*/

#include <unistd.h>
#include <fcntl.h>

void toto()
{
    int fd = open("toto.txt", O_RDONLY);
    int buffer[273];
    int size;

    while (1) {
        size = read(fd, buffer, sizeof(buffer));
        if (size <= 0) {
            close(fd);
            break;
        }
        write (1, "\e[1;1H\e[2J", 11);
        write(1, buffer, size);
        usleep(300000);
    }
}
