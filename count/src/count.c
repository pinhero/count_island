/*
** EPITECH PROJECT, 2021
** count
** File description:
** count
*/

#include <unistd.h>
#include "../include/my.h"

extern int last_row;

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++);
    return (i);
}

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_put_tab(char **world)
{
    for (int i = 0; world[i] != NULL; i++)
        my_putstr(world[i]), my_putstr("\n");
}

char **format_world(char **world, char c)
{
    for (int i = 0; world[i] != NULL; i++)
        for (int j = 0; world[i][j]; j++)
            if (world[i][j] == '$')
                world[i][j] = c;
    return (world);
}

int transform(char **tab, int x, int y)
{
    if (tab[x][y] != 'X') return (0);
    tab[x][y] = '$';
    if (x < last_row - 1 && tab[x + 1][y] == 'X' \
        && transform(tab, x + 1, y) == 0)
        return (0);
    if (y > 0 && tab[x][y - 1] == 'X' && transform(tab, x, y - 1) == 0)
        return (0);
    if (x > 0 && tab[x - 1][y] == 'X' && transform(tab, x - 1, y) == 0)
        return (0);
    if (tab[x][y] != '\0' && tab[x][y + 1] == 'X' \
        && transform(tab, x, y + 1) == 0)
        return (0);
    return (84);
}

int count_island(char **world)
{
    int n = 0;

    for (int i = 0; world[i] != NULL; i++) {
        for (int j = 0; world[i][j]; j++) {
            if (n == 10) return (84);
            if (world[i][j] == 'X') {
                transform(world, i, j);
                world = format_world(world, n + '0');
                n++;
            }
        }
    } my_put_tab(world);
    return (n);
}
