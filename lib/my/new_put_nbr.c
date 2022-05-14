/*
** EPITECH PROJECT, 2021
** EVAL_EXPR
** File description:
** It's a program that take a string an return the result as an integer
*/

#include <stdlib.h>

int puissance(int y);

char calculs(int count, int nb, char resultat, int cmpt_str)
{
    int result;

    while (count >= 0) {
        count = count - 1;
        result = nb / puissance(count);
        result = result % 10;
        resultat = result + 48;
        cmpt_str += 1;
    }
    return (resultat);
}

char new_put_nbr(int nb)
{
    int count = -1;
    int digits = nb;
    char resultat;
    int cmpt_str = 0;

    if (nb < 0) {
        nb = nb - nb * 2;
        resultat = '-';
        cmpt_str += 1;
    }
    if (nb == 0)
        resultat = '0';
    while (digits != 0) {
        digits = digits / 10;
        count = count + 1;
    }
    resultat = calculs(count, nb, resultat, cmpt_str);
    return (resultat);
}
