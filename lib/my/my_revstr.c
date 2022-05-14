/*
** EPITECH PROJECT, 2021
** MY_REVSTR
** File description:
** It's a program that reverse a string
*/

int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int size = my_strlen(str) - 1;
    int stop_condition = size / 2 + 1;
    int cmpt = 0;
    char temp;

    while (stop_condition > 0) {
        temp = str[cmpt];
        str[cmpt] = str[size];
        str[size] = temp;
        cmpt += 1;
        size -= 1;
        stop_condition -= 1;
    }
    return (str);
}
