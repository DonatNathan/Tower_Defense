/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to get bat
*/

#include "../../includes/my_defender.h"

void set_mortar_reach(global *game, shop *my_shop, sfVector2f rad_pos)
{
    sfColor opacity_down = {255, 255, 255, 150};

    sfCircleShape_setPosition(game->radius, rad_pos);
    sfCircleShape_setFillColor(game->radius, opacity_down);
    sfCircleShape_setRadius(game->radius, 140);
    game->boole->on_map = 1;
    game->texture = "pictures/defences/mortar/1.png";
    my_shop->t_shop->mortar = sfTexture_createFromFile(game->texture, \
    sfFalse);
    sfSprite_setTexture(my_shop->s_mortar, my_shop->t_shop->mortar, \
    sfFalse);
    sfSprite_setColor(my_shop->s_mortar, opacity_down);
}

void get_mortar(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);
    sfVector2f rad_pos;

    if (pos_mouse.x >= my_shop->pos_mortar.x && pos_mouse.x <= \
    my_shop->pos_mortar.x + 120 && pos_mouse.y >= my_shop->pos_mortar.y && \
    pos_mouse.y <= my_shop->pos_mortar.y + 100) {
        my_shop->stats->mouse->is_mortar = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && is_only\
        (game, 3) == 0) {
            rad_pos.x = pos_mouse.x - 140;
            rad_pos.y = pos_mouse.y - 140;
            set_mortar_reach(game, my_shop, rad_pos);
            my_shop->pos_mortar.x = pos_mouse.x - 60;
            my_shop->pos_mortar.y = pos_mouse.y - 60;
            sfSprite_setPosition(my_shop->s_mortar, my_shop->pos_mortar);
            game->boole->take = 3;
        }
    } else
        my_shop->stats->mouse->is_mortar = 1;
}

void set_air_reach(global *game, shop *my_shop, sfVector2f rad_pos)
{
    sfColor opacity_down = {255, 255, 255, 150};

    sfCircleShape_setPosition(game->radius, rad_pos);
    sfCircleShape_setFillColor(game->radius, opacity_down);
    sfCircleShape_setRadius(game->radius, 140);
    game->boole->on_map = 1;
    game->texture = "pictures/defences/air_defence/1.png";
    my_shop->t_shop->air_defence = sfTexture_createFromFile\
    (game->texture, sfFalse);
    sfSprite_setTexture(my_shop->s_air_defence, my_shop->t_shop->\
    air_defence, sfFalse);
    sfSprite_setColor(my_shop->s_air_defence, opacity_down);
}

void get_air_defence(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);
    sfVector2f rad_pos;

    if (pos_mouse.x >= my_shop->pos_air_defence.x && pos_mouse.x <= \
    my_shop->pos_air_defence.x + 120 && pos_mouse.y >= my_shop->\
    pos_air_defence.y && pos_mouse.y <= my_shop->pos_air_defence.y + 100) {
        my_shop->stats->mouse->is_air = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && is_only\
        (game, 4) == 0) {
            rad_pos.x = pos_mouse.x - 140;
            rad_pos.y = pos_mouse.y - 140;
            set_air_reach(game, my_shop, rad_pos);
            my_shop->pos_air_defence.x = pos_mouse.x - 60;
            my_shop->pos_air_defence.y = pos_mouse.y - 60;
            sfSprite_setPosition(my_shop->s_air_defence, my_shop->\
            pos_air_defence);
            game->boole->take = 4;
        }
    } else
        my_shop->stats->mouse->is_air = 1;
}
