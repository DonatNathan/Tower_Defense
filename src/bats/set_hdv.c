/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create hdv
*/

#include "../../includes/my_defender.h"

void basic_hdv2(global *game, batiment *hdv)
{
    hdv->type = 9;
    hdv->rad_size = 0;
    hdv->on_bat = 1;
    hdv->stats->bat_name = -1;
    hdv->rad_size = 0;
    hdv->pos.x = 0;
    hdv->pos.y = 0;
    hdv->level_up->pos_destroy.x = 0;
    hdv->level_up->pos_destroy.y = 0;
    hdv->level_up->pos_up.x = 0;
    hdv->level_up->pos_up.y = 0;
}

void basic_hdv(global *game, batiment *hdv)
{
    hdv->level_up = malloc(sizeof(level_up));
    hdv->stats = malloc(sizeof(stats_bat));
    hdv->temp = malloc(sizeof(char *));
    hdv->first = hdv;
    hdv->next = NULL;
    hdv->last = NULL;
    hdv->stats->level = game->level;
    hdv->gold = game->gold;
    hdv->bat = sfSprite_create();
    hdv->level_str = sfText_create();
    basic_hdv2(game, hdv);
    hdv->level_up->up = sfSprite_create();
    hdv->level_up->t_up = sfTexture_createFromFile\
    ("pictures/buttons/arrow.png", NULL);
    hdv->level_up->cost = sfText_create();
}

void update_v2(global *game, batiment *hdv)
{
    if (hdv->stats->pv <= hdv->stats->pv_max * 0.5 && hdv->stats->pv >= hdv->\
    stats->pv_max * 0.4)
        hdv->lifebar->rect.top = 151;
    if (hdv->stats->pv <= hdv->stats->pv_max * 0.4 && hdv->stats->pv >= hdv->\
    stats->pv_max * 0.3)
        hdv->lifebar->rect.top = 181.2;
    if (hdv->stats->pv <= hdv->stats->pv_max * 0.3 && hdv->stats->pv >= hdv->\
    stats->pv_max * 0.2)
        hdv->lifebar->rect.top = 211.4;
    if (hdv->stats->pv <= hdv->stats->pv_max * 0.2 && hdv->stats->pv >= hdv->\
    stats->pv_max * 0.1)
        hdv->lifebar->rect.top = 241.6;
    if (hdv->stats->pv <= hdv->stats->pv_max * 0.1 && hdv->stats->pv >= hdv->\
    stats->pv_max * 0)
        hdv->lifebar->rect.top = 271.8;
    change_rect(hdv->lifebar->rect, 108, 30.2);
    sfSprite_setTexture(hdv->lifebar->life, hdv->lifebar->t_life, sfFalse);
    sfSprite_setTextureRect(hdv->lifebar->life, hdv->lifebar->rect);
}

void update_lifebar_hdv(global *game, batiment *hdv)
{
    if (hdv->stats->pv <= hdv->stats->pv_max && hdv->stats->pv >= hdv->stats->\
    pv_max * 0.9)
        hdv->lifebar->rect.top = 0;
    if (hdv->stats->pv <= hdv->stats->pv_max * 0.9 && hdv->stats->pv >= hdv->\
    stats->pv_max * 0.8)
        hdv->lifebar->rect.top = 30.2;
    if (hdv->stats->pv <= hdv->stats->pv_max * 0.8 && hdv->stats->pv >= hdv->\
    stats->pv_max * 0.7)
        hdv->lifebar->rect.top = 60.4;
    if (hdv->stats->pv <= hdv->stats->pv_max * 0.7 && hdv->stats->pv >= hdv->\
    stats->pv_max * 0.6)
        hdv->lifebar->rect.top = 90.6;
    if (hdv->stats->pv <= hdv->stats->pv_max * 0.6 && hdv->stats->pv >= hdv->\
    stats->pv_max * 0.5)
        hdv->lifebar->rect.top = 120.8;
    update_v2(game, hdv);
}

batiment *create_hdv(global *game)
{
    batiment *hdv = malloc(sizeof(batiment));
    sfFont *font = sfFont_createFromFile("fonts/ArialCE.ttf");
    sfVector2f scale = {0.06, 0.06};

    basic_hdv(game, hdv);
    set_stats_hdv(game, hdv);
    sfText_setFont(hdv->level_up->cost, font);
    sfText_setString(hdv->level_up->cost, new_put_nbr_str(hdv->stats->price));
    sfText_setColor(hdv->level_up->cost, sfGreen);
    sfSprite_setTexture(hdv->level_up->up, hdv->level_up->t_up, sfFalse);
    sfSprite_setScale(hdv->level_up->up, scale);
    sfText_setFont(hdv->level_str, font);
    if (hdv->stats->level == 1)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/1.png", NULL);
    set_texture_hdv(game, hdv);
    sfText_setColor(hdv->level_str, sfBlue);
    create_bullet(game, hdv);
    create_lifebar_hdv(game, hdv);
    return (hdv);
}
