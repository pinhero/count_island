/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "color.h"

int my_strlen(char *str);
int my_putstr(char *str);
void my_put_tab(char **tab);
int transform(char **tab, int x, int y);
int count_island(char **world);
int file_len(char *filepath);
int rows(int fd);
char **load_a_map(int fd, int row, int col);
int bsq(char *buf);
