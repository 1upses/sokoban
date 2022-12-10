/*
** EPITECH PROJECT, 2022
** check state
** File description:
** check state
*/

#include "include/my.h"

int check_win(struct boxes *boxes)
{
    int trigger = boxes->count;
    for (int i = 0; i < boxes->count; i++) {
        if (BOX->under == 'O') trigger--;
    }
    if (trigger) return 0;
    return 1;
}

int check_loss(struct boxes *boxes)
{
    int counter = boxes->count;
    int trigger;
    for (int i = 0; i < boxes->count; i++) {
        trigger = 1;
        DOWN DEC
        LEFT DEC
        UP DEC
        RIGHT DEC
    }
    if (counter) return 0;
    return 1;
}
