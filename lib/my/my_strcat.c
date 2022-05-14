/*
** EPITECH PROJECT, 2021
** MY_STRCAT
** File description:
** It's a program that concatenates two strings
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int k = 0;
    char *res;

    res = malloc(sizeof(*res) * (my_strlen(dest) + my_strlen(src) + 1));
    while (dest[i] != '\0') {
        res[i] = dest[i];
        i++;
    }
    while (src[k] != '\0') {
        res[i + k] = src[k];
        k++;
    }
    res[i + k] = '\0';
    return (res);
}
