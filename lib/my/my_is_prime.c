/*
** EPITECH PROJECT, 2021
** MY_IS_PRIME
** File description:
** It's a program that return if a number is prime or not
*/

int my_is_prime(int nb)
{
    int cmpt;

    if (nb <= 1)
        return (0);
    for (cmpt = 1; cmpt < nb; cmpt += 1) {
        if (cmpt != 1 && cmpt != nb && nb % cmpt == 0) {
            return (0);
        }
    }
    return (1);
}
