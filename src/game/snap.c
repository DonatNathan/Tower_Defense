/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to snap bat on map
*/

#include "../../includes/my_defender.h"

void snap1(global *game, struct grid_cell *new, shop *my_shop, sfVector2f \
snap_radius)
{
    if (game->boole->take == 0) {
        snap_radius.x = new->p_3.x - 60 - 12;
        snap_radius.y = new->p_3.y - (abs(new->coords->dy) + \
        abs(new->coords->dy) + abs(new->coords->dy)) - 2;
        my_shop->pos_cannon.x = new->p_3.x - 60;
        my_shop->pos_cannon.y = new->p_3.y - (abs(new->coords->dy) + \
        abs(new->coords->dy) + abs(new->coords->dy));
        game->map->pos_free.x = my_shop->pos_cannon.x;
        game->map->pos_free.y = my_shop->pos_cannon.y;
        sfCircleShape_setPosition(game->radius, snap_radius);
    } if (game->boole->take == 2) {
        snap_radius.x = new->p_3.x - 110;
        snap_radius.y = new->p_3.y - 140;
        my_shop->pos_archer.x = new->p_3.x - 60;
        my_shop->pos_archer.y = new->p_3.y - (abs(new->coords->dy) + \
        abs(new->coords->dy) + abs(new->coords->dy));
        game->map->pos_free.x = my_shop->pos_archer.x;
        game->map->pos_free.y = my_shop->pos_archer.y;
        sfCircleShape_setPosition(game->radius, snap_radius);
    }
}

void snap2(global *game, struct grid_cell *new, shop *my_shop, sfVector2f \
snap_radius)
{
    if (game->boole->take == 3) {
        snap_radius.x = new->p_3.x - 140;
        snap_radius.y = new->p_3.y - 175;
        my_shop->pos_mortar.x = new->p_3.x - 60;
        my_shop->pos_mortar.y = new->p_3.y - (abs(new->coords->dy) + \
        abs(new->coords->dy) + abs(new->coords->dy));
        game->map->pos_free.x = my_shop->pos_mortar.x;
        game->map->pos_free.y = my_shop->pos_mortar.y;
        sfCircleShape_setPosition(game->radius, snap_radius);
    }
    if (game->boole->take == 4) {
        snap_radius.x = new->p_3.x - 140;
        snap_radius.y = new->p_3.y - 175;
        my_shop->pos_air_defence.x = new->p_3.x - 60;
        my_shop->pos_air_defence.y = new->p_3.y - (abs(new->coords->dy) + \
        abs(new->coords->dy) + abs(new->coords->dy));
        game->map->pos_free.x = my_shop->pos_air_defence.x;
        game->map->pos_free.y = my_shop->pos_air_defence.y;
        sfCircleShape_setPosition(game->radius, snap_radius);
    }
}

void snap3(global *game, struct grid_cell *new, shop *my_shop, sfVector2f \
snap_radius)
{
    if (game->boole->take == 5) {
        snap_radius.x = new->p_3.x - 200;
        snap_radius.y = new->p_3.y - 250;
        my_shop->pos_xbow.x = new->p_3.x - 60;
        my_shop->pos_xbow.y = new->p_3.y - (abs(new->coords->dy) + \
        abs(new->coords->dy) + abs(new->coords->dy));
        game->map->pos_free.x = my_shop->pos_xbow.x;
        game->map->pos_free.y = my_shop->pos_xbow.y;
        sfCircleShape_setPosition(game->radius, snap_radius);
    }
    if (game->boole->take == 6) {
        snap_radius.x = new->p_3.x - 90;
        snap_radius.y = new->p_3.y - 113;
        my_shop->pos_wizard.x = new->p_3.x - 55;
        my_shop->pos_wizard.y = new->p_3.y - (abs(new->coords->dy) + \
        abs(new->coords->dy) + abs(new->coords->dy) + 15);
        game->map->pos_free.x = my_shop->pos_wizard.x;
        game->map->pos_free.y = my_shop->pos_wizard.y;
        sfCircleShape_setPosition(game->radius, snap_radius);
    }
}

void reset_pos_shop(shop *my_shop)
{
    sfSprite_setPosition(my_shop->s_cannon, my_shop->pos_cannon);
    sfSprite_setPosition(my_shop->s_archer, my_shop->pos_archer);
    sfSprite_setPosition(my_shop->s_mortar, my_shop->pos_mortar);
    sfSprite_setPosition(my_shop->s_air_defence, my_shop->\
    pos_air_defence);
    sfSprite_setPosition(my_shop->s_xbow, my_shop->pos_xbow);
    sfSprite_setPosition(my_shop->s_wizard, my_shop->pos_wizard);
}

void snap_obj(global *game, struct grid_cell *new, shop *my_shop, sfVector2i \
pos_mouse)
{
    sfVector2f snap_radius;

    if (pow(abs(pos_mouse.x - 25 - new->p_5.x), 2) + pow(abs(pos_mouse.y - \
    25 - new->p_5.y), 2) < 1089 && sfMouse_isButtonPressed(sfMouseLeft) == \
    sfTrue && game->boole->take != 1 && game->boole->shop_is_open == 0) {
        game->boole->on_map = 0;
        if (new->status == 1) {
            snap1(game, new, my_shop, snap_radius);
            snap2(game, new, my_shop, snap_radius);
            snap3(game, new, my_shop, snap_radius);
        }
        reset_pos_shop(my_shop);
        game->boole->click = 1;
        game->boole->take_pos = new->g_pos;
    }
}
