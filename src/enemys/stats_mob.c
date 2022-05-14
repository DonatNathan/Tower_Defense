/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create stats of mobs
*/

#include "../../includes/my_defender.h"

void stats_barbar(global *game, enemy_ *new)
{
    new->pv = 10;
    new->pv_base = 10;
    new->damage = 8;
    new->level_hdv = 1;
    new->level = 1;
    new->speed = 1;
    new->reward = 10;
    new->type = 1;
    new->offset = 81.5;
    new->max_value = 1050;
    new->x_size = 82;
    new->y_size = 82;
}

void stats_archer(global *game, enemy_ *new)
{
    new->pv = 20;
    new->pv_base = 20;
    new->damage = 7;
    new->level_hdv = 1;
    new->level = 1;
    new->speed = 2;
    new->type = 2;
    new->reward = 15;
    new->offset = 76;
    new->max_value = 1064;
    new->x_size = 76;
    new->y_size = 89;
}

void stats_gobelin(global *game, enemy_ *new)
{
    new->pv = 25;
    new->pv_base = 25;
    new->damage = 11;
    new->level_hdv = 1;
    new->level = 1;
    new->speed = 1;
    new->reward = 30;
    new->type = 3;
    new->offset = 99.5;
    new->max_value = 690;
    new->x_size = 99;
    new->y_size = 90;
}

void stats_giant(global *game, enemy_ *new)
{
    new->pv = 300;
    new->pv_base = 300;
    new->damage = 22;
    new->level_hdv = 1;
    new->level = 1;
    new->speed = 3;
    new->type = 5;
    new->reward = 50;
    new->offset = 109.3;
    new->max_value = 970;
    new->x_size = 109;
    new->y_size = 85;
}

void stats_dragon(global *game, enemy_ *new)
{
    new->pv = 1900;
    new->pv_base = 1900;
    new->damage = 175;
    new->level_hdv = 7;
    new->level = 1;
    new->speed = 4;
    new->reward = 100;
    new->type = 5;
    new->offset = 129.6;
    new->max_value = 1030;
    new->x_size = 130;
    new->y_size = 107;
}
