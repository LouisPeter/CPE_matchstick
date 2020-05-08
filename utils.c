/*
** EPITECH PROJECT, 2018
** Matchstick
** File description:
** utils.c
*/

#include "include/my.h"
#include "include/matchstick.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void print_map(map_t *map_st)
{
    for (int i = 0; i < map_st->nb_line; i++)
        my_putstr(map_st->map[i]);
}

int victory(map_t *map_st)
{
    int y = 0;
    int counter = 0;

    for (; y < map_st->nb_line; y++)
        for (int i = 0; map_st->map[y][i]; i++)
            counter += (map_st->map[y][i] == '|') ? 1: 0;
    return (counter);
}

int malloc_map(map_t *map_st)
{
    map_st->map = malloc(sizeof(char *) * (map_st->nb_line + 2));
    if (map_st->map == NULL)
        return (84);
    for (int y = 0; y < map_st->nb_line + 2; y++) {
        map_st->map[y] = malloc(sizeof(char) * (map_st->nb_collumn + 2));
        if (map_st->map[y] == NULL)
            return (84);
    }
    return (0);
}

