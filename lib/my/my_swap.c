/*
** EPITECH PROJECT, 2021
** MY_SWAP
** File description:
** It's a program that swap the content of integers
*/

void my_swap(int *a, int *b)
{
    int ptr_temp;

    ptr_temp = *a;
    *a = *b;
    *b = ptr_temp;
}
