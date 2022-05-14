/*
** EPITECH PROJECT, 2021
** MY_STRNCPY
** File description:
** It's a program that copies charcter in another string
*/

int my_strlen(char const *str);
char my_putstr(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int cmpt;
    for (cmpt = 0; cmpt < n; cmpt += 1) {
        dest[cmpt] = src[cmpt];
    }
    while (cmpt < my_strlen(dest)) {
        dest[cmpt] = '\0';
        cmpt += 1;
    }
    my_putstr(dest);
    return (dest);
}
