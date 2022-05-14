/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to choose texture of map
*/

#include "../../includes/my_defender.h"

void set_minimap2(menu *menus)
{
    if (menus->level == 6)
        menus->t_menu->t_map = sfTexture_createFromFile("pictures/maps/\
miniatures/6.png", NULL);
    if (menus->level == 7)
        menus->t_menu->t_map = sfTexture_createFromFile("pictures/maps/\
miniatures/7.png", NULL);
    if (menus->level == 8)
        menus->t_menu->t_map = sfTexture_createFromFile("pictures/maps/\
miniatures/8.png", NULL);
    if (menus->level == 9)
        menus->t_menu->t_map = sfTexture_createFromFile("pictures/maps/\
miniatures/9.png", NULL);
    if (menus->level == 10)
        menus->t_menu->t_map = sfTexture_createFromFile("pictures/maps/\
miniatures/10.png", NULL);
    sfSprite_setTexture(menus->map, menus->t_menu->t_map, sfFalse);
}

void set_minimap(menu *menus)
{
    if (menus->level == 1)
        menus->t_menu->t_map = sfTexture_createFromFile("pictures/maps/\
miniatures/1.png", NULL);
    if (menus->level == 2)
        menus->t_menu->t_map = sfTexture_createFromFile("pictures/maps/\
miniatures/2.png", NULL);
    if (menus->level == 3)
        menus->t_menu->t_map = sfTexture_createFromFile("pictures/maps/\
miniatures/3.png", NULL);
    if (menus->level == 4)
        menus->t_menu->t_map = sfTexture_createFromFile("pictures/maps/\
miniatures/4.png", NULL);
    if (menus->level == 5)
        menus->t_menu->t_map = sfTexture_createFromFile("pictures/maps/\
miniatures/5.png", NULL);
    set_minimap2(menus);
}

void set_texture_map2(global *game)
{
    if (game->level == 6)
        game->map->t_map = sfTexture_createFromFile\
        ("pictures/maps/backgrounds/6.png", NULL);
    if (game->level == 7)
        game->map->t_map = sfTexture_createFromFile\
        ("pictures/maps/backgrounds/7.png", NULL);
    if (game->level == 8)
        game->map->t_map = sfTexture_createFromFile\
        ("pictures/maps/backgrounds/8.png", NULL);
    if (game->level == 9)
        game->map->t_map = sfTexture_createFromFile\
        ("pictures/maps/backgrounds/9.png", NULL);
    if (game->level == 10)
        game->map->t_map = sfTexture_createFromFile\
        ("pictures/maps/backgrounds/10.png", NULL);
    sfSprite_setTexture(game->map->map, game->map->t_map, sfFalse);
}

void set_texture_map(global *game)
{
    if (game->level == 1)
        game->map->t_map = sfTexture_createFromFile\
        ("pictures/maps/backgrounds/1.png", NULL);
    if (game->level == 2)
        game->map->t_map = sfTexture_createFromFile\
        ("pictures/maps/backgrounds/2.png", NULL);
    if (game->level == 3)
        game->map->t_map = sfTexture_createFromFile\
        ("pictures/maps/backgrounds/3.png", NULL);
    if (game->level == 4)
        game->map->t_map = sfTexture_createFromFile\
        ("pictures/maps/backgrounds/4.png", NULL);
    if (game->level == 5)
        game->map->t_map = sfTexture_createFromFile\
        ("pictures/maps/backgrounds/5.png", NULL);
    set_texture_map2(game);
}
