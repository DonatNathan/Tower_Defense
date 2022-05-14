/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions set stats at all defences
*/

#include "../../includes/my_defender.h"

void set_stats_hdv(global *game, batiment *bat)
{
    bat->stats->name = "HDV";
    bat->stats->pv = 1000;
    bat->stats->pv_max = 1000;
    bat->stats->damage = 0;
    bat->stats->attack_speed = 0;
    bat->stats->price = game->price_hdv;
}

void set_stats_cannon(global *game, batiment *bat)
{
    bat->stats->name = "Cannon";
    bat->stats->pv = 100;
    bat->stats->pv_max = bat->stats->pv;
    bat->stats->damage = 10;
    bat->stats->attack_speed = 1;
    bat->stats->price = 100;
    bat->type = 0;
}

void set_stats_archer(global *game, batiment *bat)
{
    bat->stats->name = "Archer Tower";
    bat->stats->pv = 150;
    bat->stats->pv_max = bat->stats->pv;
    bat->stats->damage = 8;
    bat->stats->attack_speed = 2;
    bat->stats->price = 200;
    bat->type = 2;
}

void set_stats_mortar(global *game, batiment *bat)
{
    bat->stats->name = "Mortar";
    bat->stats->pv = 200;
    bat->stats->pv_max = bat->stats->pv;
    bat->stats->damage = 20;
    bat->stats->attack_speed = 0.2;
    bat->stats->price = 500;
    bat->type = 0;
}
