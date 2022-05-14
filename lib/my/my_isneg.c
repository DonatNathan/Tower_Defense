/*
** EPITECH PROJECT, 2021
** MY_ISNEG
** File description:
** It's a program that return if a number is positive or negative
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar(78);
    else
        my_putchar(80);
}
