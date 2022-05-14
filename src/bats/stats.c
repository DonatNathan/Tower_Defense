/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions set stats at all defences
*/

#include "../../includes/my_defender.h"

void set_stats_air(global *game, batiment *bat)
{
    bat->stats->name = "Air Defence";
    bat->stats->pv = 400;
    bat->stats->pv_max = bat->stats->pv;
    bat->stats->damage = 50;
    bat->stats->attack_speed = 1;
    bat->stats->price = 2000;
    bat->type = 1;
}

void set_stats_xbow(global *game, batiment *bat)
{
    bat->stats->name = "x-Bow";
    bat->stats->pv = 1000;
    bat->stats->pv_max = bat->stats->pv;
    bat->stats->damage = 8;
    bat->stats->attack_speed = 0.05;
    bat->stats->price = 10000;
    bat->type = 2;
}

void set_stats_wizard(global *game, batiment *bat)
{
    bat->stats->name = "Wizard Tower";
    bat->stats->pv = 500;
    bat->stats->pv_max = bat->stats->pv;
    bat->stats->damage = 15;
    bat->stats->attack_speed = 1.5;
    bat->stats->price = 5000;
    bat->type = 2;
}

void check_name(global *game, int name, batiment *bat)
{
    if (name == 1)
        set_stats_cannon(game, bat);
    if (name == 2)
        set_stats_archer(game, bat);
    if (name == 3)
        set_stats_mortar(game, bat);
    if (name == 4)
        set_stats_air(game, bat);
    if (name == 5)
        set_stats_xbow(game, bat);
    if (name == 6)
        set_stats_wizard(game, bat);
}
