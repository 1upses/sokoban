/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "include/my.h"

char *open_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat sb;
    stat(filepath, &sb);
    int size = sb.st_size;
    char *buffer = malloc(sizeof(char) * size);
    read(fd, buffer, size);
    close(fd);
    return (buffer);
}

int verify_map(char *map, struct dimensions *dim)
{
    char *authorized_chars = "\n#XOP ";
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != authorized_chars[0] && map[i] != authorized_chars[1] &&
            map[i] != authorized_chars[2] && map[i] != authorized_chars[3] &&
            map[i] != authorized_chars[4] && map[i] != authorized_chars[5]) {
            return 84;
        }
    }
    return is_grid(map, dim);
}

struct dimensions *find_dimensions(char *map)
{
    struct dimensions *dim = malloc(sizeof(struct dimensions));
    int i = 0;
    int j = 0;
    while (map[i] != '\n') {
        i++;
    }
    dim->width = i;
    dim->height = 0;
    while (map[j] != '\0') {
        if (map[j] == '\n') {
            dim->height++;
        }
        j++;
    }
    dim->width++;
    return dim;
}

int main(int ac, char *av[])
{
    MAIN
}
