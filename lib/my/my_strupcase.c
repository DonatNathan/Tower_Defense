/*
** EPITECH PROJECT, 2021
** MY_STRUPCASE
** File description:
** Change lowercase into uppercase
*/

#include <stdlib.h>

char *my_strupcase(char *str)
{
    char *new_str = malloc(sizeof(char *));

    for (int cmpt = 0; str[cmpt] != '\0'; cmpt += 1) {
        if (str[cmpt] > 96 && str[cmpt] < 123) {
            new_str[cmpt] = str[cmpt] - 32;
        }
    }
    return (new_str);
}
