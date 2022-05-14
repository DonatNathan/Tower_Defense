/*
** EPITECH PROJECT, 2021
** MY_STRCPY
** File description:
** It's a program that copie a string into another
*/

#include <stdlib.h>

int my_putstr(char const *str);
int my_strlen(char const *str);

char *my_strcpy(char *dest, char *src)
{
    int cmpt = 0;

    while (src[cmpt] != '\0') {
        dest[cmpt] = src[cmpt];
        cmpt += 1;
    }
    while (dest[cmpt] != '\0') {
        dest[cmpt] = '\0';
        cmpt += 1;
    }
    return (dest);
}
