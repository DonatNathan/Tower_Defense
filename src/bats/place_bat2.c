/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to place all bats
*/

#include "../../includes/my_defender.h"

void drop_air_defence(global *game, shop *my_shop)
{
    sfColor opacity_up = {255, 255, 255, 255};
    sfColor opacity_none = {255, 255, 255, 0};

    sfSprite_setColor(my_shop->s_air_defence, opacity_up);
    sfSprite_setTexture(my_shop->s_air_defence, my_shop->t_shop->\
    t_air_defence, sfFalse);
    sfCircleShape_setFillColor(game->radius, opacity_none);
    if (game->boole->on_map == 0 && game->first->gold >= 1300 && my_shop->\
    pos_air_defence.x == game->map->pos_free.x && my_shop->pos_air_defence.y \
    == game->map->pos_free.y) {
        get_last(game, my_shop->pos_air_defence, 4);
        game->first->gold -= 1300;
        sfSound_play(game->sounds->anvil);
        game->boole->unground = 1;
    }
    my_shop->pos_air_defence.x = 0;
    my_shop->pos_air_defence.y = 510;
    sfSprite_setPosition(my_shop->s_air_defence, my_shop->pos_air_defence);
    game->boole->take = 1;
}

void drop_xbow(global *game, shop *my_shop)
{
    sfColor opacity_up = {255, 255, 255, 255};
    sfColor opacity_none = {255, 255, 255, 0};

    sfSprite_setColor(my_shop->s_xbow, opacity_up);
    sfSprite_setTexture(my_shop->s_xbow, my_shop->t_shop->t_xbow, sfFalse);
    sfCircleShape_setFillColor(game->radius, opacity_none);
    sfCircleShape_setRadius(game->radius, 200);
    if (game->boole->on_map == 0 && game->first->gold >= 7000 && my_shop->\
    pos_xbow.x == game->map->pos_free.x && my_shop->pos_xbow.y == \
    game->map->pos_free.y) {
        get_last(game, my_shop->pos_xbow, 5);
        game->first->gold -= 7000;
        sfSound_play(game->sounds->anvil);
        game->boole->unground = 1;
    }
    my_shop->pos_xbow.x = 0;
    my_shop->pos_xbow.y = 630;
    sfSprite_setPosition(my_shop->s_xbow, my_shop->pos_xbow);
    game->boole->take = 1;
}

void drop_wizard(global *game, shop *my_shop)
{
    sfColor opacity_up = {255, 255, 255, 255};
    sfColor opacity_none = {255, 255, 255, 0};

    sfSprite_setColor(my_shop->s_wizard, opacity_up);
    sfSprite_setTexture(my_shop->s_wizard, my_shop->t_shop->t_wizard, sfFalse);
    sfCircleShape_setFillColor(game->radius, opacity_none);
    sfCircleShape_setRadius(game->radius, 90);
    if (game->boole->on_map == 0 && game->first->gold >= 3000 && my_shop->\
    pos_wizard.x == game->map->pos_free.x && my_shop->pos_wizard.y == \
    game->map->pos_free.y) {
        get_last(game, my_shop->pos_wizard, 6);
        game->first->gold -= 3000;
        sfSound_play(game->sounds->anvil);
        game->boole->unground = 1;
    }
    my_shop->pos_wizard.x = 0;
    my_shop->pos_wizard.y = 750;
    sfSprite_setPosition(my_shop->s_wizard, my_shop->pos_wizard);
    game->boole->take = 1;
}

void place_struct(global *game, struct grid_cell *new, shop *my_shop)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);

    sfCircleShape_setFillColor(new->c_5, sfRed);
    if (pow(abs(pos_mouse.x - 25 - new->p_5.x), 2) + pow(abs(pos_mouse.y - 25 \
    - new->p_5.y), 2) < 900)
        sfCircleShape_setFillColor(new->c_5, sfGreen);
    (new->status == 1) ? sfCircleShape_setFillColor(new->c_5, sfGreen) : 1;
    snap_obj(game, new, my_shop, pos_mouse);
    if (new->g_pos == 92) {
        game->first->pos.x = new->p_3.x - 55;
        game->first->pos.y = new->p_3.y - (abs(new->coords->dy) + \
        abs(new->coords->dy) + abs(new->coords->dy)) + 10;
        sfSprite_setPosition(game->first->bat, game->first->pos);
    }
    if (new->g_pos != 196)
        place_struct(game, new->next_cell, my_shop);
}
