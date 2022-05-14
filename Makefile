##
## EPITECH PROJECT, 2021
## MY_HUNTER
## File description:
## It's the Makefile of my_hunter project
##

LIB	 =      lib/my/my_revstr.c      \
                lib/my/my_str_isprintable.c     \
                lib/my/my_compute_power_rec.c   \
                lib/my/my_showmem.c     \
                lib/my/my_str_isupper.c \
                lib/my/my_showstr.c     \
                lib/my/my_strlen.c      \
                lib/my/my_compute_square_root.c \
                lib/my/my_sort_int_array.c      \
                lib/my/my_strlowcase.c  \
                lib/my/my_find_prime_sup.c      \
                lib/my/my_getnbr.c      \
                lib/my/my_isneg.c       \
                lib/my/my_is_prime.c    \
                lib/my/my_putchar.c     \
                lib/my/my_put_nbr.c     \
                lib/my/my_putstr.c      \
                lib/my/my_strcapitalize.c       \
                lib/my/my_strcat.c      \
                lib/my/my_strcmp.c      \
                lib/my/my_strcpy.c      \
                lib/my/my_str_isalpha.c \
                lib/my/my_str_islower.c \
                lib/my/my_str_isnum.c   \
                lib/my/my_strncat.c     \
                lib/my/my_strncmp.c     \
                lib/my/my_strncpy.c     \
                lib/my/my_strstr.c      \
                lib/my/my_strupcase.c   \
                lib/my/my_swap.c        \
		lib/my/new_put_nbr_str.c	\
		lib/my/my_printf.c	\
		lib/my/my_printf2.c	\
		lib/my/new_put_nbr.c	\

SRC =   src/bats/*.c      \
        src/game/*.c    \
        src/map/*.c     \
        src/menus/*.c   \
        src/shop/*.c    \
        src/enemys/*.c  \

OBJ = $(LIB:.c=.o)

NAME = my_defender

all: $(NAME)

$(NAME): $(OBJ)
	@echo ">>> Librairy compiled."
	@ar rc libmy.a $(OBJ)
	@echo ">>> Executable \"${NAME}\" created."
	@gcc -g3 -o ${NAME} $(SRC) -lcsfml-graphics -lcsfml-audio \
        -lcsfml-system -lcsfml-window -Wall -lm -L. libmy.a

clean:
	@rm -f $(OBJ)

fclean: clean
	@echo ">>> All files was clean."
	@rm -f $(NAME)
	@rm -f libmy.a

re: fclean all
