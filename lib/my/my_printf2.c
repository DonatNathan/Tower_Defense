/*
** EPITECH PROJECT, 2021
** MY_PRINTF
** File description:
** It's the file that countains functions to convert bases
*/

#include <stdlib.h>
#include "../../includes/my.h"

void deci_to_oct(int character)
{
    char *result = malloc(sizeof(char *));
    int cmpt;
    int modulo;

    for (cmpt = 0; character > 0; cmpt += 1) {
        modulo = character % 8;
        result[cmpt] = new_put_nbr(modulo);
        character = character / 8;
    }
    if (cmpt < 3) {
        while (cmpt < 3) {
            result[cmpt] = '0';
            cmpt += 1;
        }
    }
    result[cmpt] = '\\';
    my_revstr(result);
    my_putstr(result);
    free(result);
}

void deci_to_octal(int nb)
{
    char *result = malloc(sizeof(char *));
    int cmpt;
    int modulo;

    if (nb == 0)
        my_putchar('0');
    else {
        for (cmpt = 0; nb > 0; cmpt += 1) {
            modulo = nb % 8;
            result[cmpt] = new_put_nbr(modulo);
            nb = nb / 8;
        }
        my_revstr(result);
        my_putstr(result);
    }
    free(result);
}

void binary(int nb)
{
    char *result = malloc(sizeof(char *));
    int cmpt = 0;
    int modulo;

    if (nb == 0)
        my_putchar('0');
    else {
        while (nb > 0) {
            modulo = nb % 2;
            result[cmpt] = new_put_nbr(modulo);
            nb = nb / 2;
            cmpt += 1;
        }
        my_revstr(result);
        my_putstr(result);
    }
    free(result);
}

void integer(int nb)
{
    char *new_nb = malloc(sizeof(char *));

    if (nb >= 0) {
        my_strcpy(new_nb, new_put_nbr_str(nb));
    } else {
        new_nb = new_put_nbr_str(4294967295 + nb);
    }
    my_putstr(new_nb);
    free(new_nb);
}

void int_to_hexa(int nb)
{
    char *result = malloc(sizeof(char *));
    int cmpt = 0;
    char modulo;
    char *character = "0123456789abcdef";

    if (nb == 0)
        my_putchar('0');
    else {
        while (nb > 0) {
            modulo = character[nb % 16];
            result[cmpt] = modulo;
            nb = nb / 16;
            cmpt += 1;
        }
        my_revstr(result);
        my_putstr(result);
    }
    free(result);
}
