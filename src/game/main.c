/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the main file of my program "my_defender"
*/

#include "../../includes/my_defender.h"

int read_level(void)
{
    char *buffer = malloc(sizeof(char) * 2);
    int fd = open("src/txt/level", O_RDONLY);
    char *level = malloc(sizeof(char) * 3);
    int cmpt;

    read(fd, buffer, 2);
    for (cmpt = 0; cmpt != 2; cmpt += 1)
        level[cmpt] = buffer[cmpt];
    level[cmpt] = '\0';
    close(fd);
    return (my_getnbr(level));
}

void draw_help(void)
{
    my_printf("\n\n\n############### MY DEFENDER ###############\n\n");
    my_printf("The goal of our game is to protect the \nTown Hall from waves \
of ennemis. \nTo do this, we must buy differents towers \nto kill ennemis.\n");
    my_printf("We have 10 levels and, when the game is \nlaunch, we can \
choose to continue our \nsession or to restart a new game.\n\n");
    my_printf("Commands : \n");
    my_printf("-> In menu : \n\tR : Restart\n\tC : Continue\n\tQ : Quit\n");
    my_printf("-> In game : \n\tEscape : Pause\n\tS : Shop\n\tO : \
Cheatmod\n\tP : Reach\n\tT : Skills Tree\n\n");
    my_printf("You can launch the game with this command : ./my_defender\n\
You can also write a pseudo : ./my_defender <pseudo>\nIf the pseudo is \
\"Jessica\", you will start with a lot of gold.\n\n");
    my_printf("By : Corentin & Nathan\n");
}

int get_pseudo(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "Jessica") == 0)
        return (1000000);
    else
        return (100);
}

int error_gestion(int argc, char **argv, int level)
{
    if (argc > 2)
        return (84);
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        draw_help();
    else
        create_window(level, get_pseudo(argc, argv));
    return (0);
}

int main(int argc, char **argv)
{
    int level = read_level();

    if (error_gestion(argc, argv, level) == 84)
        return (84);
    return (0);
}
