/*
** EPITECH PROJECT, 2022
** player bis
** File description:
** player bis
*/

#include "include/my.h"

void player_move(char **matrix, struct player *player,
struct dimensions *dim, ARGS)
{
    switch (key) {
        case KEY_UP:
            move_up(matrix, player, dim, boxes);
            break;
        case KEY_DOWN:
            move_down(matrix, player, dim, boxes);
            break;
        case KEY_LEFT:
            move_left(matrix, player, dim, boxes);
            break;
        case KEY_RIGHT:
            move_right(matrix, player, dim, boxes);
            break;
    }
}
