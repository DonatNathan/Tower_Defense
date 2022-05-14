/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create my menu
*/

#include "../../includes/my_defender.h"

void draw_menu(global *game, menu *menus)
{
    sfRenderWindow_drawSprite(game->window, menus->background, sfFalse);
    sfRenderWindow_drawSprite(game->window, menus->continu, sfFalse);
    sfRenderWindow_drawSprite(game->window, menus->quit, sfFalse);
    sfRenderWindow_drawSprite(game->window, menus->map, sfFalse);
    sfRenderWindow_drawSprite(game->window, menus->restart, sfFalse);
    sfRenderWindow_drawText(game->window, menus->c_continu, sfFalse);
    sfRenderWindow_drawText(game->window, menus->c_restart, sfFalse);
    sfRenderWindow_drawSprite(game->window, menus->music, sfFalse);
    sfRenderWindow_drawSprite(game->window, menus->sounds, sfFalse);
    sfRenderWindow_drawText(game->window, game->infos->htp, sfFalse);
    if (game->boole->on_htp == 0)
        sfRenderWindow_drawSprite(game->window, game->how_to_play->htp, \
        sfFalse);
}

void set_pos_menu(menu *menus)
{
    sfVector2f scale_map = {1.5, 1.5};
    sfVector2f scale_back = {1.6, 1.6};

    menus->pos_continu.x = 250;
    menus->pos_continu.y = 700;
    menus->pos_quit.x = 800;
    menus->pos_quit.y = 740;
    menus->pos2_quit.x = 770;
    menus->pos2_quit.y = 730;
    menus->pos_map.x = 650;
    menus->pos_map.y = 50;
    menus->pos_restart.x = 1200;
    menus->pos_restart.y = 700;
    sfSprite_setPosition(menus->continu, menus->pos_continu);
    sfSprite_setPosition(menus->map, menus->pos_map);
    sfSprite_setPosition(menus->restart, menus->pos_restart);
    sfSprite_setScale(menus->map, scale_map);
    sfSprite_setScale(menus->background, scale_back);
    menus->t_menu->t_background = sfTexture_createFromFile\
    ("pictures/background2.png", NULL);
}

void create_text(menu *menus)
{
    sfVector2f scale_text = {1.8, 1.8};

    menus->pos_con.x = menus->pos_continu.x + 30;
    menus->pos_con.y = menus->pos_continu.y + 75;
    menus->pos_res.x = menus->pos_restart.x + 50;
    menus->pos_res.y = menus->pos_restart.y + 75;
    menus->t_menu->supercell = sfFont_createFromFile\
    ("fonts/supercell.x-font-ttf");
    menus->c_continu = sfText_create();
    menus->c_restart = sfText_create();
    sfText_setString(menus->c_continu, "CONTINUE (C)");
    sfText_setString(menus->c_restart, "RESTART (R)");
    sfText_setPosition(menus->c_continu, menus->pos_continu);
    sfText_setPosition(menus->c_restart, menus->pos_restart);
    sfText_setFont(menus->c_continu, menus->t_menu->supercell);
    sfText_setFont(menus->c_restart, menus->t_menu->supercell);
    sfText_setScale(menus->c_continu, scale_text);
    sfText_setScale(menus->c_restart, scale_text);
    sfText_setPosition(menus->c_continu, menus->pos_con);
    sfText_setPosition(menus->c_restart, menus->pos_res);
}

void set_textures_menu(menu *menus)
{
    sfSprite_setTexture(menus->background, menus->t_menu->t_background, \
    sfFalse);
    sfSprite_setTexture(menus->restart, menus->t_menu->t_battle, sfFalse);
    sfSprite_setTexture(menus->quit, menus->t_menu->t_quit, sfFalse);
    sfSprite_setTexture(menus->continu, menus->t_menu->t_battle, sfFalse);
}

menu *create_menu(int level)
{
    menu *menus = malloc(sizeof(menu));

    menus->t_menu = malloc(sizeof(t_menu_t));
    menus->level = level;
    menus->continu = sfSprite_create();
    menus->quit = sfSprite_create();
    menus->map = sfSprite_create();
    menus->restart = sfSprite_create();
    menus->background = sfSprite_create();
    menus->t_menu->t_battle = sfTexture_createFromFile\
    ("pictures/buttons/button.png", NULL);
    menus->t_menu->t_quit = sfTexture_createFromFile\
    ("pictures/buttons/quit.png", NULL);
    set_pos_menu(menus);
    create_text(menus);
    set_textures_menu(menus);
    return (menus);
}
