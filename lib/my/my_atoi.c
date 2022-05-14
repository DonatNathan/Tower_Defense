/*
** EPITECH PROJECT, 2022
** MY_ATOI
** File description:
** Transform string into int
*/

int my_atoi(char *str)
{
    int number = 0;

    for (int cmpt = 0; str[cmpt] != '\0'; cmpt += 1) {
        number *= 10;
        number += (str[cmpt] - 48);
    }
    return (number);
}
