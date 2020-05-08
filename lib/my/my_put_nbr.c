/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include <unistd.h>
#include "my.h"

void my_put_nbr(int nb)
{
    int b;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            b = nb % 10;
            nb = (nb - b) / 10;
            my_put_nbr(nb);
            my_putchar(b + 48);
        } else
            my_putchar(nb + 48);
    }
}
