/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that draw all in game
*/

#include "../../includes/my_defender.h"

void is_big_if(global *game, struct enemy_ *enemy, batiment *bat_)
{
    if (((sqrt((enemy->pos.x - bat_->pos.x - 70) * (enemy->pos.x - bat_->pos.x - 70) + (enemy->pos.y - bat_->pos.y - 70) * (enemy->pos.y - bat_->pos.y - 70)) <= bat_->rad_size) || (sqrt((enemy->pos.x + enemy->x_size - bat_->pos.x - 70) * (enemy->pos.x + enemy->x_size - bat_->pos.x - 70) + (enemy->pos.y - bat_->pos.y - 70) * (enemy->pos.y - bat_->pos.y - 70)) <= bat_->rad_size) || (sqrt((enemy->pos.x - bat_->pos.x - 70) * (enemy->pos.x - bat_->pos.x - 70) + (enemy->pos.y + enemy->y_size - bat_->pos.y - 70) * (enemy->pos.y + enemy->y_size - bat_->pos.y - 70)) <= bat_->rad_size) || (sqrt((enemy->pos.x + enemy->x_size - bat_->pos.x - 70) * (enemy->pos.x + enemy->x_size - bat_->pos.x - 70) + (enemy->pos.y + enemy->y_size - bat_->pos.y - 70) * (enemy->pos.y + enemy->y_size - bat_->pos.y - 70)) <= bat_->rad_size)) && ((sqrt((bat_->target->pos.x - bat_->pos.x - 70) * (bat_->target->pos.x - bat_->pos.x - 70) + (bat_->target->pos.y - bat_->pos.y - 70) * (bat_->target->pos.y - bat_->pos.y - 70)) > bat_->rad_size) && (sqrt((bat_->target->pos.x + enemy->x_size - bat_->pos.x - 70) * (bat_->target->pos.x + enemy->x_size - bat_->pos.x - 70) + (bat_->target->pos.y - bat_->pos.y - 70) * (bat_->target->pos.y - bat_->pos.y - 70)) > bat_->rad_size) && (sqrt((bat_->target->pos.x - bat_->pos.x - 70) * (bat_->target->pos.x - bat_->pos.x - 70) + (bat_->target->pos.y + enemy->y_size - bat_->pos.y - 70) * (bat_->target->pos.y + enemy->y_size - bat_->pos.y - 70)) > bat_->rad_size) && (sqrt((bat_->target->pos.x + enemy->x_size - bat_->pos.x - 70) * (bat_->target->pos.x + enemy->x_size - bat_->pos.x - 70) + (bat_->target->pos.y + enemy->y_size - bat_->pos.y - 70) * (bat_->target->pos.y + enemy->y_size - bat_->pos.y - 70)) > bat_->rad_size)))
        bat_->target = enemy;
}

void detect_enemy(global *game, struct enemy_ *enemy, batiment *bat_)
{
    if (enemy->type >= 1 && enemy->type <= 5 && enemy->pos.x != 0 && \
    enemy->pos.y != 0) {
        if (((sqrt((enemy->pos.x - bat_->pos.x - 70) * (enemy->pos.x - bat_->\
        pos.x - 70) + (enemy->pos.y - bat_->pos.y - 70) * (enemy->pos.y - \
        bat_->pos.y - 70)) <= bat_->rad_size) || (sqrt((enemy->pos.x + enemy->\
        x_size - bat_->pos.x - 70) * (enemy->pos.x + enemy->x_size - bat_->\
        pos.x - 70) + (enemy->pos.y - bat_->pos.y - 70) * (enemy->pos.y - \
        bat_->pos.y - 70)) <= bat_->rad_size) || (sqrt((enemy->pos.x - bat_->\
        pos.x - 70) * (enemy->pos.x - bat_->pos.x - 70) + (enemy->pos.y + \
        enemy->y_size - bat_->pos.y - 70) * (enemy->pos.y + 63 - bat_->pos.y \
        - 70)) <= bat_->rad_size) || (sqrt((enemy->pos.x + enemy->x_size - \
        bat_->pos.x - 70) * (enemy->pos.x + enemy->x_size - bat_->pos.x - 70) \
        + (enemy->pos.y + enemy->y_size - bat_->pos.y - 70) * (enemy->pos.y + \
        enemy->y_size - bat_->pos.y - 70)) <= bat_->rad_size)) && bat_->\
        target == NULL)
            bat_->target = enemy;
        is_big_if(game, enemy, bat_);
    }
    if (enemy->enemy_next != NULL)
        detect_enemy(game, enemy->enemy_next, bat_);
}

void change_color_radius(batiment *bat_, sfColor color2)
{
    if (bat_->target->type >= 1 && bat_->target->type <= 5) {
        if ((sqrt((bat_->target->pos.x - bat_->pos.x - 70) * (bat_->target->\
        pos.x - bat_->pos.x - 70) + (bat_->target->pos.y - bat_->pos.y - 70) \
        * (bat_->target->pos.y - bat_->pos.y - 70)) < bat_->rad_size) || \
        (sqrt((bat_->target->pos.x + bat_->target->x_size - bat_->pos.x - 70) \
        * (bat_->target->pos.x + bat_->target->x_size - bat_->pos.x - 70) + \
        (bat_->target->pos.y - bat_->pos.y - 70) * (bat_->target->pos.y - \
        bat_->pos.y - 70)) < bat_->rad_size) || (sqrt((bat_->target->pos.x - \
        bat_->pos.x - 70) * (bat_->target->pos.x - bat_->pos.x - 70) + (bat_->\
        target->pos.y + bat_->target->y_size - bat_->pos.y - 70) * (bat_->\
        target->pos.y + bat_->target->y_size - bat_->pos.y - 70)) < bat_->\
        rad_size) || (sqrt((bat_->target->pos.x + bat_->target->x_size - \
        bat_->pos.x - 70) * (bat_->target->pos.x + bat_->target->x_size - \
        bat_->pos.x - 70) + (bat_->target->pos.y + bat_->target->y_size - \
        bat_->pos.y - 70) * (bat_->target->pos.y + bat_->target->y_size - \
        bat_->pos.y - 70)) < bat_->rad_size))
        sfCircleShape_setFillColor(bat_->radius, color2);
    }
}

void check_hit(global *game, batiment *bat_)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);
    sfColor color = {0, 255, 0, 150};
    sfColor color2 = {0, 0, 255, 150};

    if (bat_->type != 9 && game->rad_god == 1) {
        if (sqrt((pos_mouse.x - bat_->pos.x - 70) * (pos_mouse.x - bat_->\
        pos.x - 70) + (pos_mouse.y - bat_->pos.y - 70) * (pos_mouse.y - bat_->\
        pos.y - 70)) < bat_->rad_size)
            sfCircleShape_setFillColor(bat_->radius, color);
        if (game->enemy->enemy_next != NULL)
            detect_enemy(game, game->enemy->enemy_next, bat_);
        if (bat_->target != NULL) {
            change_color_radius(bat_, color2);
        }
        sfRenderWindow_drawCircleShape(game->window, bat_->radius, NULL);
    }
    if (bat_->next != NULL)
        check_hit(game, bat_->next);
}
