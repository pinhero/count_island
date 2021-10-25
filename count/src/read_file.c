/*
** EPITECH PROJECT, 2021
** read
** File description:
** read
*/

#include "../include/my.h"

extern int last_row;

int file_len(char *filepath)
{
    struct stat buf;

    if (stat(filepath, &buf) == -1)
        return (-1);
    return (buf.st_size);
}

int rows(int fd)
{
    int rd, i = 0, j = 0;
    char d;

    rd = read(fd, &d, 1);
    for (i = 0; rd > 0; i++) {
        if ((d < '0') || (d > '9'))
            return (j);
        j = (j * 10) + (d - '0');
        rd = read(fd, &d, 1);
    } return (j);
}

char **load_a_map(int fd, int row, int col)
{
    int i = 0, j, rd, c, m = 0, go, n = 0, *p;
    char **buf, d, *str;

    if (fd == -1) return (NULL);
    buf = malloc(sizeof(char *) * (row + 1));
    str = malloc(col);
    for (j = 0; j < row; j++) {
        rd = read(fd, str, col);
        if (rd == -1) return (NULL);
        if (str[col - 1] == '\n') {
            buf[j] = malloc(sizeof(char) * col);
            for (go = 0; str[go] != '\0'; go++)
                buf[j][go] = str[go];
            buf[j][go - 1] = '\0';
            n++;
        } else return (NULL);
    } buf[j] = NULL;
    free(str);
    if (row != n) return (NULL);
    return (buf);
}

void my_free(char **b)
{
    for (int i = 0; b[i] != NULL; i++) free(b[i]);
    free(b);
}

int bsq(char *buf)
{
    int fd = open(buf, O_RDONLY), i, j, size, row, col;
    char **b;

    size = file_len(buf);
    row = rows(fd);
    last_row = row;
    if (row <= 0) return (84);
    for (i = row, j = 0; i > 0; i = i / 10, j++);
    col = ((size - (j + 1)) / row);
    b = load_a_map(fd, row, col);
    if (b == NULL) return (84);
    my_put_tab(b), my_putstr("\n\n");
    i = count_island(b);
    close(fd), my_free(b);
    return (i);
}
