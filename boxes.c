/*
** EPITECH PROJECT, 2022
** boxes
** File description:
** boxes
*/

#include "include/my.h"

struct boxes *init_boxes(char **matrix, struct dimensions *dim)
{
    int count = 0, k = 0;
    for (int i = 0; i < dim->height; i++) {
        for (int j = 0; j < dim->width; j++) {
            COND_BOX ? count++ : 0;
        }
    } struct box **boxes = malloc(sizeof(struct box *) * count);
    for (int i = 0; i < dim->height; i++) {
        for (int j = 0; j < dim->width; j++) {
            COND_BOX ? boxes[k] = malloc(sizeof(struct box)) : 0; COND_BOX ?
            boxes[k]->x = j : 0; COND_BOX ? boxes[k]->y = i : 0;
            COND_BOX ? boxes[k]->under = ' ' : 0;
            COND_BOX ? boxes[k]->up = matrix[i - 1][j] : 0;
            COND_BOX ? boxes[k]->down = matrix[i + 1][j] : 0;
            COND_BOX ? boxes[k]->left = matrix[i][j - 1] : 0;
            COND_BOX ? boxes[k]->right = matrix[i][j + 1] : 0;
            COND_BOX ? k++ : 0;
        }
    } struct boxes *to_return = malloc(sizeof(struct boxes));
    to_return->boxes = boxes; to_return->count = count;
    return to_return;
}

struct box *find_box(char **matrix, struct dimensions *dim, int *coords,
struct boxes *boxes)
{
    for (int i = 0; i < boxes->count; i++) {
        if (boxes->boxes[i]->x == coords[0] && boxes->boxes[i]->y == coords[1])
            return boxes->boxes[i];
    }
    return NULL;
}
