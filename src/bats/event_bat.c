/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to get bat
*/

#include "../../includes/my_defender.h"

void set_cannon_reach(global *game, shop *my_shop, sfVector2f rad_pos)
{
    sfColor opacity_down = {255, 255, 255, 150};

    sfCircleShape_setPosition(game->radius, rad_pos);
    sfCircleShape_setFillColor(game->radius, opacity_down);
    sfCircleShape_setRadius(game->radius, 90);
    game->boole->on_map = 1;
    game->texture = "pictures/defences/cannon/1.png";
    my_shop->t_shop->cannon = sfTexture_createFromFile(game->texture\
    , sfFalse);
    sfSprite_setTexture(my_shop->s_cannon, my_shop->t_shop->cannon\
    , sfFalse);
    sfSprite_setColor(my_shop->s_cannon, opacity_down);
}

void get_cannon(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);
    sfVector2f rad_pos;

    if (pos_mouse.x >= my_shop->pos_cannon.x && pos_mouse.x <= \
        my_shop->pos_cannon.x + 120 && pos_mouse.y >= my_shop->pos_cannon.y \
        && pos_mouse.y <= my_shop->pos_cannon.y + 100) {
        my_shop->stats->mouse->is_cannon = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && is_only\
        (game, 0) == 0) {
            rad_pos.x = pos_mouse.x - 90;
            rad_pos.y = pos_mouse.y - 90;
            set_cannon_reach(game, my_shop, rad_pos);
            my_shop->pos_cannon.x = pos_mouse.x - 60;
            my_shop->pos_cannon.y = pos_mouse.y - 60;
            sfSprite_setPosition(my_shop->s_cannon, my_shop->pos_cannon);
            game->boole->take = 0;
        }
    } else
        my_shop->stats->mouse->is_cannon = 1;
}

void set_archer_reach(global *game, shop *my_shop, sfVector2f rad_pos)
{
    sfColor opacity_down = {255, 255, 255, 150};

    sfCircleShape_setPosition(game->radius, rad_pos);
    sfCircleShape_setFillColor(game->radius, opacity_down);
    sfCircleShape_setRadius(game->radius, 110);
    game->boole->on_map = 1;
    game->texture = "pictures/defences/archer_tower/1.png";
    my_shop->t_shop->archer = sfTexture_createFromFile(game->texture, \
    sfFalse);
    sfSprite_setTexture(my_shop->s_archer, my_shop->t_shop->archer, \
    sfFalse);
    sfSprite_setColor(my_shop->s_archer, opacity_down);
}

void get_archer(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);
    sfVector2f rad_pos;

    if (pos_mouse.x >= my_shop->pos_archer.x && pos_mouse.x <= \
    my_shop->pos_archer.x + 120 && pos_mouse.y >= my_shop->pos_archer.y && \
    pos_mouse.y <= my_shop->pos_archer.y + 100) {
        my_shop->stats->mouse->is_archer = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && is_only\
        (game, 2) == 0) {
            rad_pos.x = pos_mouse.x - 110;
            rad_pos.y = pos_mouse.y - 110;
            set_archer_reach(game, my_shop, rad_pos);
            my_shop->pos_archer.x = pos_mouse.x - 60;
            my_shop->pos_archer.y = pos_mouse.y - 60;
            sfSprite_setPosition(my_shop->s_archer, my_shop->pos_archer);
            game->boole->take = 2;
        }
    } else
        my_shop->stats->mouse->is_archer = 1;
}
