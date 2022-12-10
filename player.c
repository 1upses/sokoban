/*
** EPITECH PROJECT, 2022
** player
** File description:
** player
*/

#include "include/my.h"

struct player *init_player(char **matrix, struct dimensions *dim)
{
    struct player *player = malloc(sizeof(struct player));
    int trigger = 0;
    for (int i = 0; i < dim->height; i++) {
        for (int j = 0; j < dim->width; j++) {
            (matrix[i][j] == 'P') ? player->x = j : 0;
            (matrix[i][j] == 'P') ? player->y = i : 0;
            (matrix[i][j] == 'P') ? player->under = ' ' : 0;
            (matrix[i][j] == 'P' && trigger) ? player->x = -84 : 0;
            (matrix[i][j] == 'P') ? trigger = 1 : 0;
        }
    }
    if (trigger == 0) player->x = -84;
    return player;
}

void move_up(char **matrix, struct player *player, struct dimensions *dim,
struct boxes *boxes)
{
    if (player->y - 1 >= 0 && matrix[player->y - 1][player->x] != '#') {
        matrix[player->y][player->x] = player->under;
        player->under = matrix[player->y - 1][player->x];
        matrix[player->y - 1][player->x] = 'P';
        player->y--;
    }
    if (player->under == 'X') box_move_up(matrix, player, boxes, dim);
}

void move_down(char **matrix, struct player *player, struct dimensions *dim,
struct boxes *boxes)
{
    if (player->y + 1 < dim->height &&
    matrix[player->y + 1][player->x] != '#') {
        matrix[player->y][player->x] = player->under;
        player->under = matrix[player->y + 1][player->x];
        matrix[player->y + 1][player->x] = 'P';
        player->y++;
    }
    if (player->under == 'X') box_move_down(matrix, player, boxes, dim);
}

void move_left(char **matrix, struct player *player, struct dimensions *dim,
struct boxes *boxes)
{
    if (player->x > 0 && matrix[player->y][player->x - 1] != '#') {
        matrix[player->y][player->x] = player->under;
        player->under = matrix[player->y][player->x - 1];
        player->x--;
        matrix[player->y][player->x] = 'P';
    }
    if (player->under == 'X') box_move_left(matrix, player, boxes, dim);
}

void move_right(char **matrix, struct player *player, struct dimensions *dim,
struct boxes *boxes)
{
    if (player->x < dim->width - 2 && matrix[player->y][player->x + 1] != '#') {
        matrix[player->y][player->x] = player->under;
        player->under = matrix[player->y][player->x + 1];
        player->x++;
        matrix[player->y][player->x] = 'P';
    }
    if (player->under == 'X') box_move_right(matrix, player, boxes, dim);
}
