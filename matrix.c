/*
** EPITECH PROJECT, 2022
** matrix
** File description:
** matrix
*/

#include "include/my.h"

int my_strlen(char *str)
{
    int i = 0;
    while (str[i]) i++;
    return i;
}

char **mem_alloc_matrix(struct dimensions *dim)
{
    char **matrice = malloc(dim->height * sizeof(char *));
    for (int i = 0; i < dim->height; i++)
        matrice[i] = malloc(dim->width * sizeof(char));
    return matrice;
}

char **to_matrix(char *map)
{
    struct dimensions *dim = find_dimensions(map);
    char **matrix = mem_alloc_matrix(dim);
    for (int i = 0; i < dim->height; i++) {
        for (int j = 0; j < dim->width; j++) {
            matrix[i][j] = map[i * dim->width + j];
        }
    }
    return matrix;
}

void display_matrix(char **matrix, struct dimensions *dim, struct player *p)
{
    for (int i = 0; i < dim->height; i++) {
        printw("%s", matrix[i]);
    }
}

int is_grid(char *map, struct dimensions *dim)
{
    if (dim->height * dim->width != my_strlen(map)) return 84;
    return 0;
}
