/*
** EPITECH PROJECT, 2022
** move box
** File description:
** move box
*/

#include "include/my.h"

void update_surroundings(char **matrix, struct boxes *boxes)
{
    for (int i = 0; i < boxes->count; i++) {
        BOX->down = matrix[BOX->y + 1][BOX->x];
        BOX->up = matrix[BOX->y - 1][BOX->x];
        BOX->left = matrix[BOX->y][BOX->x - 1];
        BOX->right = matrix[BOX->y][BOX->x + 1];
    }
}

void box_move_right(char **matrix, struct player *player, struct boxes *boxes,
struct dimensions *dim)
{
    int coords[2] = {player->x, player->y};
    struct box *box = find_box(matrix, dim, coords, boxes);
    if (box->right == '#' || box->right == 'X') move_left(matrix, player, dim,
    boxes);
    else {
        player->under = box->under;
        box->under = matrix[box->y][box->x + 1];
        matrix[box->y][box->x + 1] = 'X';
        box->x++;
        update_surroundings(matrix, boxes);
    }
}

void box_move_left(char **matrix, struct player *player, struct boxes *boxes,
struct dimensions *dim)
{
    int coords[2] = {player->x, player->y};
    struct box *box = find_box(matrix, dim, coords, boxes);
    if (box->left == '#' || box->left == 'X') move_right(matrix, player, dim,
    boxes);
    else {
        player->under = box->under;
        box->under = matrix[box->y][box->x - 1];
        matrix[box->y][box->x - 1] = 'X';
        box->x--;
        update_surroundings(matrix, boxes);
    }
}

void box_move_up(char **matrix, struct player *player, struct boxes *boxes,
struct dimensions *dim)
{
    int coords[2] = {player->x, player->y};
    struct box *box = find_box(matrix, dim, coords, boxes);
    if (box->up == '#' || box->up == 'X') move_down(matrix, player, dim, boxes);
    else {
        player->under = box->under;
        box->under = matrix[box->y - 1][box->x];
        matrix[box->y - 1][box->x] = 'X';
        box->y--;
        update_surroundings(matrix, boxes);
    }
}

void box_move_down(char **matrix, struct player *player, struct boxes *boxes,
struct dimensions *dim)
{
    int coords[2] = {player->x, player->y};
    struct box *box = find_box(matrix, dim, coords, boxes);
    if (box->down == '#' || box->down == 'X') move_up(matrix, player, dim,
    boxes);
    else {
        player->under = box->under;
        box->under = matrix[box->y + 1][box->x];
        matrix[box->y + 1][box->x] = 'X';
        box->y++;
        update_surroundings(matrix, boxes);
    }
}
