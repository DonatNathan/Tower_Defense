/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to add a bat in the linked list
*/

#include "../../includes/my_defender.h"

void add_bat_end(global *game, batiment *new_bat)
{
    sfVector2f scale_up = {0.06, 0.06};
    sfVector2f scale_cross = {0.05, 0.05};

    sfSprite_setTexture(new_bat->level_up->up, new_bat->level_up->t_up, \
    sfFalse);
    sfSprite_setTexture(new_bat->level_up->destroy, new_bat->level_up->\
    t_destroy, sfFalse);
    new_bat->level_up->pos_up.x = new_bat->pos.x + 90;
    new_bat->level_up->pos_up.y = new_bat->pos.y + 100;
    new_bat->level_up->pos_destroy.x = new_bat->pos.x + 90;
    new_bat->level_up->pos_destroy.y = new_bat->pos.y + 100;
    sfSprite_setPosition(new_bat->level_up->up, new_bat->level_up->pos_up);
    sfSprite_setPosition(new_bat->level_up->destroy, new_bat->level_up->\
    pos_destroy);
    sfSprite_setScale(new_bat->level_up->up, scale_up);
    sfSprite_setScale(new_bat->level_up->destroy, scale_cross);
    create_lifebar_hdv(game, new_bat);
}

void add_bat_buttons(global *game, batiment *new_bat)
{
    sfFont *font = sfFont_createFromFile("fonts/ArialCE.ttf");

    new_bat->stats->level = 1;
    new_bat->on_bat = 1;
    new_bat->level_str = sfText_create();
    sfText_setColor(new_bat->level_str, sfBlue);
    sfText_setFont(new_bat->level_str, font);
    new_bat->level_up = malloc(sizeof(level_up));
    new_bat->level_up->up = sfSprite_create();
    new_bat->level_up->destroy = sfSprite_create();
    new_bat->level_up->cost = sfText_create();
    sfText_setFont(new_bat->level_up->cost, font);
    sfText_setColor(new_bat->level_up->cost, sfGreen);
    new_bat->level_up->t_up = sfTexture_createFromFile\
    ("pictures/buttons/arrow.png", NULL);
    new_bat->level_up->t_destroy = sfTexture_createFromFile\
    ("pictures/buttons/cross.png", NULL);
    add_bat_end(game, new_bat);
}

void set_basic_bat(global *game, batiment *new_bat, batiment *prev)
{
    new_bat->first = game->first;
    new_bat->prev = prev;
    new_bat->next = NULL;
    new_bat->last = NULL;
    new_bat->target = NULL;
    new_bat->focus = 0;
    new_bat->temp = malloc(sizeof(char *));
}

batiment *add_bat(global *game, batiment *prev, sfVector2f pos, int name)
{
    batiment *new_bat = malloc(sizeof(batiment));

    new_bat->stats = malloc(sizeof(stats_bat));
    set_basic_bat(game, new_bat, prev);
    new_bat->bat = sfSprite_create();
    new_bat->t_bat = sfTexture_createFromFile(game->texture, NULL);
    sfSprite_setTexture(new_bat->bat, new_bat->t_bat, sfFalse);
    new_bat->pos.x = pos.x;
    new_bat->pos.y = pos.y;
    new_bat->stats->bat_name = name;
    sfSprite_setPosition(new_bat->bat, new_bat->pos);
    add_bat_buttons(game, new_bat);
    check_name(game, name, new_bat);
    game->secs = 5;
    create_bullet(game, new_bat);
    return (new_bat);
}

void set_texture_hdv(global *game, batiment *hdv)
{
    if (hdv->stats->level == 2)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/2.png", NULL);
    if (hdv->stats->level == 3)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/3.png", NULL);
    if (hdv->stats->level == 4)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/4.png", NULL);
    if (hdv->stats->level == 5)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/5.png", NULL);
    if (hdv->stats->level == 6)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/6.png", NULL);
    if (hdv->stats->level == 7)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/7.png", NULL);
    if (hdv->stats->level == 8)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/8.png", NULL);
    if (hdv->stats->level == 9)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/9.png", NULL);
    if (hdv->stats->level == 10)
        hdv->t_bat = sfTexture_createFromFile("pictures/hdv/10.png", NULL);
    sfSprite_setTexture(hdv->bat, hdv->t_bat, sfFalse);
}
