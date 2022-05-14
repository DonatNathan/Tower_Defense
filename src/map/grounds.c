/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create our ground
*/

#include "../../includes/my_defender.h"

void add_base(global *game, struct grid_cell *new, shop *my_shop)
{
    if (new->status == 1) {
        sfSprite *ground_struct = sfSprite_create();
        sfTexture *ground_struct_text = sfTexture_createFromFile\
        ("pictures/maps/ground/struct_ground.png", sfFalse);
        sfVector2f ground_size = {0.8, 0.6};
        sfVector2f ground_pos;

        ground_pos.x = new->p_3.x - 60 + 7;
        ground_pos.y = new->p_3.y - (abs(new->coords->dy) + \
        abs(new->coords->dy) + abs(new->coords->dy)) + 40;
        sfSprite_setScale(ground_struct, ground_size);
        sfSprite_setTexture(ground_struct, ground_struct_text, sfFalse);
        sfSprite_setPosition(ground_struct, ground_pos);
        new->ground = ground_struct;
    }
}

void add_ground(global *game, struct grid_cell *new, shop *my_shop)
{
    add_base(game, new, my_shop);
    if (new->status == 2) {
        sfSprite *ground_enemy = sfSprite_create();
        sfTexture *ground_enemy_text = sfTexture_createFromFile\
        ("pictures/maps/ground/enemy_ground.png", sfFalse);
        sfVector2f ground_size = {0.8, 0.6};
        sfVector2f ground_pos;

        ground_pos.x = new->p_3.x - 60 + 7;
        ground_pos.y = new->p_3.y - (abs(new->coords->dy) + \
        abs(new->coords->dy) + abs(new->coords->dy)) + 40;
        sfSprite_setScale(ground_enemy, ground_size);
        sfSprite_setTexture(ground_enemy, ground_enemy_text, sfFalse);
        sfSprite_setPosition(ground_enemy, ground_pos);
        new->ground = ground_enemy;
    }
    if (new->g_pos != 196)
        add_ground(game, new->next_cell, my_shop);
}

void draw_ground(global *game, struct grid_cell *new, shop *my_shop)
{
    if (new->status == 1 || new->status == 2) {
        sfRenderWindow_drawSprite(game->window, new->ground, sfFalse);
    }
    if (new->g_pos != 196)
        draw_ground(game, new->next_cell, my_shop);
}
