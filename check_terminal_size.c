/*
** EPITECH PROJECT, 2022
** is terminal big enough
** File description:
** is terminal big enough
*/

#include "include/my.h"

int check_terminal_size(struct dimensions *dim)
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    if (w.ws_col < dim->width || w.ws_row < dim->height) {
        return 84;
    }
    return 0;
}

void display_message(void)
{
    mvprintw(LINES / 2, COLS / 2 - 10, "Terminal too small");
}
