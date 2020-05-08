/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** my_ls.h
*/
#include <stdlib.h>
#ifndef MATCHSTICK_H
#define MATCHSTICK_H

typedef struct map_s {
    char **map;
    int nb_line;
    int nb_collumn;
    int space;
    int size;
    int limit;
} map_t;

typedef struct game_s {
    int win;
    int line;
    int match;
} game_t;
/*-------------------------game.c------------------------*/
int matches(game_t *game_st, map_t *map_st, size_t length);
int line(game_t *, map_t *, char *, size_t);
int game(game_t *game_st, map_t *map_st);
/*-------------------------matchstick.c------------------*/
int malloc_map(map_t *map_st);
void first_line(map_t *map_st, int i);
void get_map(int nb, map_t *map_st);
/*------------------------bot.c--------------------------*/
int ia(map_t *map_st);
int count_stick(char *line);
/*------------------------error.c------------------------*/
int nb_matches(map_t *map_st, game_t *game_st);
int check_argv(char **av);
int check_input(char *av);
/*-------------------------utils.c-----------------------*/
void print_map(map_t *map_st);
int victory(map_t *map_st);
#endif //MATCHSTICK_H
