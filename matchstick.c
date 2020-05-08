/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** matchstick.c
*/

#include "include/my.h"
#include "include/matchstick.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void first_line(map_t *map_st, int i)
{
    for (; i < map_st->nb_collumn; i++)
        map_st->map[0][i] = '*';
    map_st->map[0][i] = '\n';
    map_st->map[0][i + 1] = '\0';
}

void last_collumn(map_t *map_st, int i, int k)
{
    for (; k < map_st->nb_collumn; k++)
        map_st->map[i][k] = '*';
    map_st->map[i][k] = '\n';
    map_st->map[i][k] = '\0';
}

void map_create(map_t *map_st, int j, int k, int i)
{
    first_line(map_st, i);
    for (i = 1; i < map_st->nb_line - 1; i++) {
        map_st->map[i][0] = '*';
        for (; j < map_st->space; j++)
            map_st->map[i][j] = ' ';
        for (; k < map_st->nb_collumn - (map_st->space * 2); k++, j++)
            map_st->map[i][j] = '|';
        k = 0;
        for (; k < map_st->space - 1; k++, j++)
            map_st->map[i][j] = ' ';
        map_st->map[i][j] = '*';
        map_st->map[i][j + 1] = '\n';
        map_st->map[i][j + 2] = '\0';
        map_st->space--;
        j = 1;
        k = 0;
    }
    last_collumn(map_st, i, k);
}

void get_map(int nb, map_t *map_st)
{
    map_st->nb_line = nb + 2;
    map_st->nb_collumn = nb * 2 + 1;
    int j = 1;
    int k = 0;
    int i = 0;
    map_st->space = map_st->nb_collumn / 2;

    malloc_map(map_st);
    map_create(map_st, j, k, i);
    for (int i = 0; i < map_st->nb_line; i++)
        my_putstr(map_st->map[i]);
}

int main(int ac, char **av)
{
    map_t *map_st = malloc(sizeof(*map_st));
    game_t *game_st = malloc(sizeof(*game_st));

    srandom(time(0));
    if (ac != 3)
        return (84);
    if (check_argv(av) == 84)
        return (84);
    map_st->size = my_getnbr(av[1]);
    map_st->limit = my_getnbr(av[2]);
    int a = game(game_st, map_st);
    free(map_st);
    free(game_st);
    return (a);
}
