/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create enemys
*/

#include "../../includes/my_defender.h"

int get_path_pos_x(int i)
{
    struct stat st;
    stat("src/txt/out.txt", &st);
    int size = st.st_size;
    char *buffer = malloc(sizeof(char) * size);
    int fd = open("src/txt/out.txt", O_RDONLY);
    char *path_x = malloc(sizeof(char) * size);
    int cmpt = 0;
    int j = 0;
    int k = 0;

    read(fd, buffer, size);
    for (; k != i; k++)
        for (; buffer[cmpt++] != '\n';);
    for (; buffer[cmpt] != ','; cmpt++, j++)
        path_x[j] = buffer[cmpt];
    path_x[j] = '\0';
    close(fd);
    return (my_getnbr(path_x));
}

int get_path_pos_y(int i)
{
    struct stat st;
    stat("src/txt/out.txt", &st);
    int size = st.st_size;
    char *buffer = malloc(sizeof(char) * size);
    int fd = open("src/txt/out.txt", O_RDONLY);
    char *path_y = malloc(sizeof(char) * size);
    int cmpt = 0;
    int j = 0;
    int k = 0;

    read(fd, buffer, size);
    for (; k != i; k++)
        for (; buffer[cmpt++] != '\n';);
    for (; buffer[cmpt] != ','; cmpt++);
    for (; buffer[cmpt] != '\n'; cmpt++, j++)
        path_y[j] = buffer[cmpt];
    path_y[j] = '\0';
    close(fd);
    return (my_getnbr(path_y));
}

void set_enemy_pos(global *game, struct enemy_ *enemy)
{
    enemy->old_x = enemy->pos.x;
    if (enemy->loc > 0) {
        enemy->pos.x = get_path_pos_x(enemy->loc);
        enemy->pos.y = get_path_pos_y(enemy->loc);
        enemy->pos.x -= 25;
        enemy->pos.y -= 20;
        if (enemy->old_x > enemy->pos.x)
            sfSprite_setTexture(enemy->enemy_1, enemy->mirror, sfFalse);
        else
            sfSprite_setTexture(enemy->enemy_1, enemy->texture, sfFalse);
        sfSprite_setPosition(enemy->enemy_1, enemy->pos);
    }
}

void change_game(global *game, enemy_ *enemy_f)
{
    sfCircleShape *radius = sfCircleShape_create();

    game->radius = radius;
    game->rad_god = 0;
    game->boole->click = 0;
    game->boole->unground = 0;
    game->enemy = enemy_f;
}

void set_enemy(global *game, struct enemy_ *enemy_f)
{
    sfTexture *e_1 = sfTexture_createFromFile\
    ("pictures/mob/dragon2.png", NULL);
    sfSprite *temp = sfSprite_create();

    enemy_f->enemy_1 = temp;
    enemy_f->pos.x = -100;
    enemy_f->pos.y = -100;
    enemy_f->texture = e_1;
    enemy_f->enemy_first = NULL;
    enemy_f->enemy_next = NULL;
    enemy_f->loc = 0;
    enemy_f->pv_max = -1;
    enemy_f->type = 0;
    enemy_f->clock = sfClock_create();
    enemy_f->offset = 0;
    enemy_f->max_value = 0;
    change_game(game, enemy_f);
    for (int i = 0; i != 15; i++)
        create_enemy(game, enemy_f, rand() % 5 + 1);
    set_enemy_pos(game, enemy_f);
}
