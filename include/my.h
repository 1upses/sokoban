/*
** EPITECH PROJECT, 2022
** header
** File description:
** header
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <sys/ioctl.h>

#ifndef header
    #define header

    #define CHECK_LOSS \
        if (check_loss(boxes)) { \
            endwin(); return 1;\
        }
    #define COND_BOX    (matrix[i][j] == 'X')
    #define BOX boxes->boxes[i]
    #define CHECK_WIN   if (check_win(boxes)) break;
    #define DEC { \
                    counter--; trigger = 0; \
                }
    #define BOXDOWN (BOX->down == '#' || BOX->down == 'X')
    #define BOXRIGHT (BOX->right == '#' || BOX->right == 'X')
    #define BOXLEFT (BOX->left == '#' || BOX->left == 'X')
    #define BOXUP (BOX->up == '#' || BOX->up == 'X')
    #define DOWN    if (BOXDOWN && BOXRIGHT && trigger)
    #define LEFT    if (BOXDOWN && BOXLEFT && trigger)
    #define UP  if (BOXLEFT && BOXUP && trigger)
    #define RIGHT   if (BOXRIGHT && BOXUP && trigger)
    #define RESET   matrix = to_matrix(map); \
                    player = init_player(matrix, dim); \
                    boxes = init_boxes(matrix, dim);
    #define ARGS    int key, struct boxes *boxes
    #define MAIN    if (ac != 2) return 84; \
                    char *map = open_map(av[1]); \
                    if (my_strlen(map) == 0) return 84; \
                    struct dimensions *dim = find_dimensions(map); \
                    if (verify_map(map, dim) == 84) return 84; \
                    char **matrix = to_matrix(map); \
                    struct player *player = init_player(matrix, dim); \
                    if (player->x == -84) return 84; \
                    struct boxes *boxes = init_boxes(matrix, dim); \
                    initscr(); \
                    display_matrix(matrix, dim, player); \
                    keypad(stdscr, TRUE); \
                    int key = getch(); \
                    while (1) { \
                        clear(); \
                        if (!(check_terminal_size(dim))) { \
                            player_move(matrix, player, dim, key, boxes); \
                            display_matrix(matrix, dim, player); \
                            if (key == 32) { \
                                RESET \
                            } \
                        } else \
                            display_message(); \
                        refresh(); \
                        CHECK_WIN \
                        CHECK_LOSS \
                        key = getch(); \
                    } \
                    endwin(); \
                    return 0;

struct player {
    int x;
    int y;
    char under;
};

struct dimensions {
    int width;
    int height;
};

struct box {
    int x;
    int y;
    char under;
    char up;
    char down;
    char right;
    char left;
};

struct boxes {
    struct box **boxes;
    int count;
};

struct style {
    int key;
    struct dimensions *dim;
};

char **mem_alloc_matrix(struct dimensions *dim);
char **to_matrix(char *map);
void display_matrix(char **matrix, struct dimensions *dim, struct player *p);
struct dimensions *find_dimensions(char *map);
struct player *init_player(char **matrix, struct dimensions *dim);
void move_down(char **matrix, struct player *player, struct dimensions *dim,
struct boxes *boxes);
void move_up(char **matrix, struct player *player, struct dimensions *dim,
struct boxes *boxes);
void move_left(char **matrix, struct player *player, struct dimensions *dim,
struct boxes *boxes);
void move_right(char **matrix, struct player *player, struct dimensions *dim,
struct boxes *boxes);
void player_move(char **matrix, struct player *player,
struct dimensions *dim, ARGS);
int is_grid(char *map, struct dimensions *dim);
int my_strlen(char *str);
int check_terminal_size(struct dimensions *dim);
void display_message(void);
struct boxes *init_boxes(char **matrix, struct dimensions *dim);
struct box *find_box(char **matrix, struct dimensions *dim, int *coords,
struct boxes *boxes);
void box_move_right(char **matrix, struct player *player, struct boxes *boxes,
struct dimensions *dim);
void box_move_left(char **matrix, struct player *player, struct boxes *boxes,
struct dimensions *dim);
void box_move_up(char **matrix, struct player *player, struct boxes *boxes,
struct dimensions *dim);
void box_move_down(char **matrix, struct player *player, struct boxes *boxes,
struct dimensions *dim);
int check_win(struct boxes *boxes);
int check_loss(struct boxes *boxes);

#endif /* !header */
