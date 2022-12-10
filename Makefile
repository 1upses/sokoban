##
## EPITECH PROJECT, 2022
## truc
## File description:
## muche
##

all:
	gcc check_terminal_size.c matrix.c player.c player_bis.c boxes.c \
	move_box.c check_state.c main.c -lncurses -o my_sokoban
