/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create rad of bats
*/

#include "../../includes/my_defender.h"

void set_rad1(batiment *bat_, sfVector2f radius_pos)
{
    if (bat_->stats->bat_name == 1) {
        sfCircleShape_setRadius(bat_->radius, 90);
        radius_pos.x -= 90 / 2 - 60 / 2 + 12;
        radius_pos.y -= 90 / 2 - 60 / 2 + 2;
        bat_->rad_size = 90;
        bat_->rad_pos = radius_pos;
    }
    if (bat_->stats->bat_name == 2) {
        sfCircleShape_setRadius(bat_->radius, 110);
        radius_pos.x -= 110 / 2 - 60 / 2 + 22;
        radius_pos.y -= 110 / 2 - 60 / 2 + 12;
        bat_->rad_size = 110;
        bat_->rad_pos = radius_pos;
    }
}

void set_rad2(batiment *bat_, sfVector2f radius_pos)
{
    if (bat_->stats->bat_name == 3) {
        sfCircleShape_setRadius(bat_->radius, 140);
        radius_pos.x -= 140 / 2 - 60 / 2 + 45;
        radius_pos.y -= 140 / 2 - 60 / 2 + 25;
        bat_->rad_size = 140;
        bat_->rad_pos = radius_pos;
    }
    if (bat_->stats->bat_name == 4) {
        sfCircleShape_setRadius(bat_->radius, 140);
        radius_pos.x -= 140 / 2 - 60 / 2 + 45;
        radius_pos.y -= 140 / 2 - 60 / 2 + 25;
        bat_->rad_size = 140;
        bat_->rad_pos = radius_pos;
    }
}

void set_rad3(batiment *bat_, sfVector2f radius_pos)
{
    if (bat_->stats->bat_name == 5) {
        sfCircleShape_setRadius(bat_->radius, 200);
        radius_pos.x -= 200 / 2 - 60 / 2 + 80;
        radius_pos.y -= 200 / 2 - 60 / 2 + 50;
        bat_->rad_size = 200;
        bat_->rad_pos = radius_pos;
    }
    if (bat_->stats->bat_name == 6) {
        sfCircleShape_setRadius(bat_->radius, 90);
        radius_pos.x -= 80 / 2 - 60 / 2 + 12;
        radius_pos.y -= 80 / 2 - 60 / 2 + 2;
        bat_->rad_size = 90;
        bat_->rad_pos = radius_pos;
    }
}

void draw_rad(global *game, batiment *bat_)
{
    sfColor opacity = {255, 255, 255, 100};

    if (bat_->type != 9) {
        bat_->radius = sfCircleShape_create();
        if (game->rad_god == 1) {
            set_rad1(bat_, bat_->pos);
            set_rad2(bat_, bat_->pos);
            set_rad3(bat_, bat_->pos);
            sfCircleShape_setFillColor(bat_->radius, opacity);
            sfCircleShape_setPosition(bat_->radius, bat_->rad_pos);
            sfRenderWindow_drawCircleShape(game->window, bat_->radius, NULL);
        }
    }
    if (bat_->next != NULL)
        draw_rad(game, bat_->next);
}
