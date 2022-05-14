/*
** EPITECH PROJECT, 2021
** MY_PUT_NBR
** File description:
** put number
*/

void my_putchar(char c);

int puissance(int y)
{
    int compteur = 0;
    int resultat = 1;

    while (compteur <= y) {
        resultat = resultat * 10;
        compteur = compteur + 1;
    }
    return resultat;
}

void my_put_nbr(int nb)
{
    int count = -1;
    int digits = nb;
    int result;

    if (nb < 0) {
        nb = nb - nb * 2;
        my_putchar(45);
    }
    if (nb == 0)
        my_putchar(48);
    while (digits != 0) {
        digits = digits / 10;
        count = count + 1;
    }
    while (count >= 0) {
        count = count - 1;
        result = nb / puissance(count);
        result = result % 10 + 48;
        my_putchar((char)result);
    }
}
