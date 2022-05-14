/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_SQUARE_ROOT
** File description:
** It's a program that return the square root of a number
*/

int my_compute_square_root(int nb)
{
    int cmpt = 1;

    while (cmpt < nb) {
        if (nb == cmpt * cmpt)
            return (nb);
        cmpt += 1;
    }
    return (0);
}
