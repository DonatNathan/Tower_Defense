/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-nathan.donat-filliod
** File description:
** It's the file that contain function to create a bullet
*/

#include "../../includes/my_defender.h"

void create_bullet(global *game, batiment *bat)
{
    bat->bullet = malloc(sizeof(bullet_t));
    bat->bullet->bullet = sfSprite_create();
    create_shot(game, bat);
    if (bat->stats->bat_name == 1 || bat->stats->bat_name == 3)
        sfSprite_setTexture(bat->bullet->bullet, bat->bullet->t_bullet, \
        sfFalse);
    else if (bat->stats->bat_name == 6)
        sfSprite_setTexture(bat->bullet->bullet, bat->bullet->fireball, \
        sfFalse);
    else
        sfSprite_setTexture(bat->bullet->bullet, bat->bullet->right_arrow, \
        sfFalse);
    bat->bullet->pos_bullet.x = bat->pos.x + 50;
    bat->bullet->pos_bullet.y = bat->pos.y + 50;
    sfSprite_setPosition(bat->bullet->bullet, bat->bullet->pos_bullet);
    bat->bullet->shot = 1;
}

void check_my_bullet(batiment *bat)
{
    if (bat->bullet->pos_bullet.x < bat->target->pos.x + 20)
        bat->bullet->pos_bullet.x += 5;
    else
        bat->bullet->pos_bullet.x -= 5;
    if (bat->bullet->pos_bullet.y < bat->target->pos.y + 20)
        bat->bullet->pos_bullet.y += 5;
    else
        bat->bullet->pos_bullet.y -= 5;
    sfSprite_setPosition(bat->bullet->bullet, bat->bullet->pos_bullet);
}

void update_bullet(global *game, batiment *bat)
{
    if (bat->bullet->shot == 0) {
        set_texture_in(game, bat);
        if ((bat->bullet->pos_bullet.x + 24 > bat->target->pos.x && bat->\
        bullet->pos_bullet.x < bat->target->pos.x + 47 && bat->bullet->\
        pos_bullet.y + 23 > bat->target->pos.y && bat->bullet->pos_bullet.y < \
        bat->target->pos.y + 70) || (bat->target->pv <= 0 && game->secs < \
        150)) {
            bat->bullet->pos_bullet.x = bat->pos.x + 50;
            bat->bullet->pos_bullet.y = bat->pos.y + 50;
            sfSprite_setPosition(bat->bullet->bullet, bat->bullet->pos_bullet);
            bat->bullet->shot = 1;
        }
        if (bat->bullet->shot == 0) {
            check_my_bullet(bat);
            sfRenderWindow_drawSprite(game->window, bat->bullet->bullet, \
            sfFalse);
        }
    }
    if (bat->next != NULL)
        update_bullet(game, bat->next);
}
