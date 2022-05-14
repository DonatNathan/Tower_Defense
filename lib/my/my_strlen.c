/*
** EPITECH PROJECT, 2021
** MY_STRLEN
** File description:
** It's a program that return the number of caracters in a string
*/

int my_strlen(char const *str)
{
    int cmpt;

    for (cmpt = 0; str[cmpt] != '\0'; cmpt += 1);
    return (cmpt);
}

int my_intlen(int argc)
{
    int i = 1;

    while (argc > 9) {
        i++;
        argc = argc / 10;
    }
    return (i);
}
