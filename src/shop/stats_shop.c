/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create stats in the shop
*/

#include "../../includes/my_defender.h"

void set_pos_stat_shop(shop *my_shop)
{
    my_shop->stats->pos_cannon.x = my_shop->pos_cannon.x + 120;
    my_shop->stats->pos_cannon.y = my_shop->pos_cannon.y;
    my_shop->stats->pos_archer.x = my_shop->pos_archer.x + 120;
    my_shop->stats->pos_archer.y = my_shop->pos_archer.y;
    my_shop->stats->pos_mortar.x = my_shop->pos_mortar.x + 120;
    my_shop->stats->pos_mortar.y = my_shop->pos_mortar.y;
    my_shop->stats->pos_air.x = my_shop->pos_air_defence.x + 120;
    my_shop->stats->pos_air.y = my_shop->pos_air_defence.y;
    my_shop->stats->pos_xbow.x = my_shop->pos_xbow.x + 120;
    my_shop->stats->pos_xbow.y = my_shop->pos_xbow.y;
    my_shop->stats->pos_wizard.x = my_shop->pos_wizard.x + 120;
    my_shop->stats->pos_wizard.y = my_shop->pos_wizard.y;
    sfSprite_setPosition(my_shop->stats->cannon, my_shop->stats->pos_cannon);
    sfSprite_setPosition(my_shop->stats->archer, my_shop->stats->pos_archer);
    sfSprite_setPosition(my_shop->stats->mortar, my_shop->stats->pos_mortar);
    sfSprite_setPosition(my_shop->stats->air, my_shop->stats->pos_air);
    sfSprite_setPosition(my_shop->stats->xbow, my_shop->stats->pos_xbow);
    sfSprite_setPosition(my_shop->stats->wizard, my_shop->stats->pos_wizard);
}

void set_is_stats(shop *my_shop)
{
    my_shop->stats->mouse->is_cannon = 1;
    my_shop->stats->mouse->is_archer = 1;
    my_shop->stats->mouse->is_mortar = 1;
    my_shop->stats->mouse->is_air = 1;
    my_shop->stats->mouse->is_xbow = 1;
    my_shop->stats->mouse->is_wizard = 1;
}

void set_sprite_stats(shop *my_shop)
{
    my_shop->stats->cannon = sfSprite_create();
    my_shop->stats->archer = sfSprite_create();
    my_shop->stats->mortar = sfSprite_create();
    my_shop->stats->air = sfSprite_create();
    my_shop->stats->xbow = sfSprite_create();
    my_shop->stats->wizard = sfSprite_create();
    my_shop->stats->t_cannon = sfTexture_createFromFile\
    ("pictures/shop/stats/cannon.png", NULL);
    my_shop->stats->t_archer = sfTexture_createFromFile\
    ("pictures/shop/stats/archer.png", NULL);
    my_shop->stats->t_mortar = sfTexture_createFromFile\
    ("pictures/shop/stats/mortar.png", NULL);
    my_shop->stats->t_air = sfTexture_createFromFile\
    ("pictures/shop/stats/air.png", NULL);
    my_shop->stats->t_xbow = sfTexture_createFromFile\
    ("pictures/shop/stats/xbow.png", NULL);
    my_shop->stats->t_wizard = sfTexture_createFromFile\
    ("pictures/shop/stats/wizard.png", NULL);
}

void create_stat_shop(shop *my_shop)
{
    my_shop->stats = malloc(sizeof(stat_shop));
    my_shop->stats->mouse = malloc(sizeof(mouse_t));
    set_sprite_stats(my_shop);
    sfSprite_setTexture(my_shop->stats->cannon, my_shop->stats->t_cannon, \
    sfFalse);
    sfSprite_setTexture(my_shop->stats->archer, my_shop->stats->t_archer, \
    sfFalse);
    sfSprite_setTexture(my_shop->stats->mortar, my_shop->stats->t_mortar, \
    sfFalse);
    sfSprite_setTexture(my_shop->stats->air, my_shop->stats->t_air, sfFalse);
    sfSprite_setTexture(my_shop->stats->xbow, my_shop->stats->t_xbow, sfFalse);
    sfSprite_setTexture(my_shop->stats->wizard, my_shop->stats->t_wizard, \
    sfFalse);
    set_pos_stat_shop(my_shop);
    set_is_stats(my_shop);
}
