/*
** EPITECH PROJECT, 2021
** MY.H
** File description:
** It's just all function's prototype of our library
*/

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char *new_put_nbr_str(int nb);
void deci_to_oct(int character);
void deci_to_octal(int nb);
void binary(int nb);
void integer(int nb);
void int_to_hexa(int nb);
char new_put_nbr(int nb);
int my_printf(char *s, ...);
char **my_split_tab(char * argv, char char_);
void my_print_tab(char **tab);
int my_count_split(char *argv, char char_);
int my_intlen(int argc);

#endif /* MY_H_ */
