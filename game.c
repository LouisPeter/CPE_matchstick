/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** game.c
*/

#include "include/my.h"
#include "include/matchstick.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void algo(map_t *map_st, game_t *game_st)
{
    int length = map_st->nb_collumn;

    for (;map_st->map[game_st->line][length] != '|';
    length--);
    for (;game_st->match != 0; game_st->match--, length--) {
        map_st->map[game_st->line][length] = ' ';
    }
}

int line(game_t *game_st, map_t *map_st, char *buffer, size_t length)
{
    my_putstr("Line: ");
    if (getline(&buffer, &length, stdin) == -1)
        return (0);
    if (check_input(buffer) == 84) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (line(game_st, map_st, buffer, length));
    }
    game_st->line = my_getnbr(buffer);
    if (buffer != NULL)
        free(buffer);
    if (game_st->line > map_st->size || game_st->line == 0) {
        my_putstr("Error: this line is out of range\n");
        return (line(game_st, map_st, buffer, length));
    }
    if (matches(game_st, map_st, length) == 0)
        return (0);
    return (10);
}

int matches(game_t *game_st, map_t *map_st, size_t length)
{
    char *buffer = NULL;

    my_putstr("Matches: ");
    if (getline(&buffer, &length, stdin) == -1)
        return (0);
    if (check_input(buffer) == 84) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (line(game_st, map_st, buffer, length));
    }
    game_st->match = my_getnbr(buffer);
    if (nb_matches(map_st, game_st) == 84)
        return (line(game_st, map_st, buffer, length));
    if (buffer != NULL)
        free(buffer);
    return (10);
}

int player(game_t *game_st, map_t *map_st, char *buffer, size_t length)
{
    my_putstr("\n\n");
    my_putstr("Your turn:\n");
    if (line(game_st, map_st, buffer, length) == 0)
        return (0);
    my_putstr("Player removed ");
    my_put_nbr(game_st->match);
    my_putstr(" match(es) from line ");
    my_put_nbr(game_st->line);
    my_putchar('\n');
    algo(map_st, game_st);
    print_map(map_st);
    return (10);
}

int game(game_t *game_st, map_t *map_st)
{
    char *buffer = NULL;
    size_t length = 0;

    get_map(map_st->size, map_st);
    while (victory(map_st)) {
        if (player(game_st, map_st, buffer, length) == 0)
            return (0);
        if (victory(map_st) == 0)
            return (my_putstr("\n\nYou lost, too bad...\n"), 2);
        ia(map_st);
        if (victory(map_st) == 0) {
            my_putstr("\n\nI lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
    return (10);
}
