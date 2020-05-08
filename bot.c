/*
** EPITECH PROJECT, 2018
** Matchstick
** File description:
** bot.c
*/

#include "include/my.h"
#include "include/matchstick.h"
#include <stdlib.h>
#include <stdio.h>

int count_stick(char *line)
{
    int i = 0;
    int counter = 0;

    for (; line[i] != '\n' && line[i]; i++) {
        if (line[i] == '|')
            counter++;
    }
    return (counter);
}

void print_match(int line, int matches)
{
    my_putstr("\n\nAI's turn ...\n");
    my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
}

int ia(map_t *map_st)
{
    int length = map_st->nb_collumn;
    int rd_line = (random() % map_st->nb_line) + 1;
    int rd_matches = (random() % map_st->limit) + 1;

    if (count_stick(map_st->map[rd_line]) < rd_matches)
        return (ia(map_st));
    print_match(rd_line, rd_matches);
    for (; map_st->map[rd_line][length] != '|'; length--);
    for (; rd_matches != 0; rd_matches--, length--)
        map_st->map[rd_line][length] = ' ';
    my_putchar('\n');
    print_map(map_st);
    return (0);
}
