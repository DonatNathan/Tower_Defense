/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-nathan.donat-filliod
** File description:
** make_dmg
*/

#include "../../includes/my_defender.h"

void create_shot(global *game, batiment *bat)
{
    bat->bullet->fireball = sfTexture_createFromFile\
    ("pictures/fireball.png", NULL);
    bat->bullet->t_bullet = sfTexture_createFromFile\
    ("pictures/bullet.png", NULL);
    bat->bullet->right_arrow = sfTexture_createFromFile\
    ("pictures/arrow_right.png", NULL);
    bat->bullet->left_arrow = sfTexture_createFromFile\
    ("pictures/arrow_left.png", NULL);
}

void set_texture_in(global *game, batiment *bat)
{
    if (bat->stats->bat_name == 2 || bat->stats->bat_name == 3 || bat->stats->\
    bat_name == 4 || bat->stats->bat_name == 5) {
        if (bat->bullet->pos_bullet.x < bat->target->pos.x)
            sfSprite_setTexture(bat->bullet->bullet, bat->bullet->\
            right_arrow, sfFalse);
        if (bat->bullet->pos_bullet.x > bat->target->pos.x)
            sfSprite_setTexture(bat->bullet->bullet, bat->bullet->left_arrow, \
            sfFalse);
    }
}

void damage_archer(global *game, batiment *bat_)
{
    if ((sqrt((bat_->target->pos.x - bat_->pos.x - 70) * (bat_->target->pos.x \
    - bat_->pos.x - 70) + (bat_->target->pos.y - bat_->pos.y - 70) * (bat_->\
    target->pos.y - bat_->pos.y - 70)) < bat_->rad_size) || (sqrt((bat_->\
    target->pos.x + bat_->target->x_size - bat_->pos.x - 70) * (bat_->target->\
    pos.x + bat_->target->x_size - bat_->pos.x - 70) + (bat_->target->pos.y - \
    bat_->pos.y - 70) * (bat_->target->pos.y - bat_->pos.y - 70)) < bat_->\
    rad_size) || (sqrt((bat_->target->pos.x - bat_->pos.x - 70) * (bat_->\
    target->pos.x - bat_->pos.x - 70) + (bat_->target->pos.y + bat_->target->\
    y_size - bat_->pos.y - 70) * (bat_->target->pos.y + bat_->target->y_size \
    - bat_->pos.y - 70)) < bat_->rad_size) || (sqrt((bat_->target->pos.x + \
    bat_->target->x_size - bat_->pos.x - 70) * (bat_->target->pos.x + bat_->\
    target->x_size - bat_->pos.x - 70) + (bat_->target->pos.y + bat_->target->\
    y_size - bat_->pos.y - 70) * (bat_->target->pos.y + bat_->target->y_size \
    - bat_->pos.y - 70)) < bat_->rad_size))
        bat_->target->pv -= bat_->stats->damage;
}

void make_dmg_archer(global *game, batiment *bat_)
{
    if (bat_->type != 9 && bat_->target != NULL) {
        if (bat_->target->type >= 1 && bat_->target->type <= 5) {
            damage_archer(game, bat_);
            sfClock_restart(game->clock);
            bat_->bullet->shot = 0;
        }
        if (bat_->target->pv <= 0)
            game->endgame->enemy_kill += 1;
    }
    if (bat_->next != NULL)
        make_dmg_archer(game, bat_->next);
}
