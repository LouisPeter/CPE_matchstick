/*
** EPITECH PROJECT, 2018
** Matchstick
** File description:
** error.c
*/

#include "include/my.h"
#include "include/matchstick.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int nb_matches(map_t *map_st, game_t *game_st)
{
    if (game_st->match == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (84);
    }
    if (game_st->match > count_stick(map_st->map[game_st->line])) {
        my_putstr("Error: not enough matches on this line\n");
        return (84);
    }
    return (0);
}

int invalid_imput(char **av, int y)
{
    for (int i = 0; av[y][i] != '\0'; i++) {
        if (av[y][i] < '0' || av[y][i] > '9') {
            write(2, "Error: invalid input (positive number expected)\n", 48);
            return (84);
        }
    }
    return (0);
}

int check_argv(char **av)
{
    for (int y = 1; y != 3; y++)
        if (invalid_imput(av, y) == 84)
            return (84);
    return (0);
}

int check_input(char *av)
{
    for (int i = 0; av[i] != '\0'; i++) {
        if ((av[i] < '0' || av[i] > '9') && av[i] != '\n') {
            return (84);
        }
    }
    return (0);
}
