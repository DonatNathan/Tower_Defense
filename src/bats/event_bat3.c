/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to get bat
*/

#include "../../includes/my_defender.h"

void set_xbow_reach(global *game, shop *my_shop, sfVector2f rad_pos)
{
    sfColor opacity_down = {255, 255, 255, 150};

    sfCircleShape_setPosition(game->radius, rad_pos);
    sfCircleShape_setFillColor(game->radius, opacity_down);
    sfCircleShape_setRadius(game->radius, 200);
    game->boole->on_map = 1;
    game->texture = "pictures/defences/x_bow/1.png";
    my_shop->t_shop->xbow = sfTexture_createFromFile(game->texture, \
    sfFalse);
    sfSprite_setTexture(my_shop->s_xbow, my_shop->t_shop->xbow, \
    sfFalse);
    sfSprite_setColor(my_shop->s_xbow, opacity_down);
}

void get_xbow(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);
    sfVector2f rad_pos;

    if (pos_mouse.x >= my_shop->pos_xbow.x && pos_mouse.x <= \
    my_shop->pos_xbow.x + 120 && pos_mouse.y >= my_shop->pos_xbow.y && \
    pos_mouse.y <= my_shop->pos_xbow.y + 100) {
        my_shop->stats->mouse->is_xbow = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && is_only\
        (game, 5) == 0) {
            rad_pos.x = pos_mouse.x - 200;
            rad_pos.y = pos_mouse.y - 200;
            set_xbow_reach(game, my_shop, rad_pos);
            my_shop->pos_xbow.x = pos_mouse.x - 60;
            my_shop->pos_xbow.y = pos_mouse.y - 60;
            sfSprite_setPosition(my_shop->s_xbow, my_shop->pos_xbow);
            game->boole->take = 5;
        }
    } else
        my_shop->stats->mouse->is_xbow = 1;
}

void set_wizard_reach(global *game, shop *my_shop, sfVector2f rad_pos)
{
    sfColor opacity_down = {255, 255, 255, 150};

    sfCircleShape_setPosition(game->radius, rad_pos);
    sfCircleShape_setFillColor(game->radius, opacity_down);
    sfCircleShape_setRadius(game->radius, 90);
    game->boole->on_map = 1;
    game->texture = "pictures/defences/wizard_tower/1.png";
    my_shop->t_shop->wizard = sfTexture_createFromFile(game->texture, \
    sfFalse);
    sfSprite_setTexture(my_shop->s_wizard, my_shop->t_shop->wizard, \
    sfFalse);
    sfSprite_setColor(my_shop->s_wizard, opacity_down);
}

void get_wizard(global *game, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);
    sfVector2f rad_pos;

    if (pos_mouse.x >= my_shop->pos_wizard.x && pos_mouse.x <= \
    my_shop->pos_wizard.x + 120 && pos_mouse.y >= my_shop->pos_wizard.y && \
    pos_mouse.y <= my_shop->pos_wizard.y + 100) {
        my_shop->stats->mouse->is_wizard = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && is_only\
        (game, 6) == 0) {
            rad_pos.x = pos_mouse.x - 90;
            rad_pos.y = pos_mouse.y - 90;
            set_wizard_reach(game, my_shop, rad_pos);
            my_shop->pos_wizard.x = pos_mouse.x - 60;
            my_shop->pos_wizard.y = pos_mouse.y - 60;
            sfSprite_setPosition(my_shop->s_wizard, my_shop->pos_wizard);
            game->boole->take = 6;
        }
    } else
        my_shop->stats->mouse->is_wizard = 1;
}
