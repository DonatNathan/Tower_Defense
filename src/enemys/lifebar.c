/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to draw enemy life
*/

#include "../../includes/my_defender.h"

void update_lifebar(global *game, struct enemy_ *enemy)
{
    if (enemy->pv <= enemy->pv_max && enemy->pv >= enemy->pv_max * 0.9)
        enemy->lifebar->rect.top = 0;
    if (enemy->pv <= enemy->pv_max * 0.9 && enemy->pv >= enemy->pv_max * 0.8)
        enemy->lifebar->rect.top = 30.2;
    if (enemy->pv <= enemy->pv_max * 0.8 && enemy->pv >= enemy->pv_max * 0.7)
        enemy->lifebar->rect.top = 60.4;
    if (enemy->pv <= enemy->pv_max * 0.7 && enemy->pv >= enemy->pv_max * 0.6)
        enemy->lifebar->rect.top = 90.6;
    if (enemy->pv <= enemy->pv_max * 0.6 && enemy->pv >= enemy->pv_max * 0.5)
        enemy->lifebar->rect.top = 120.8;
    if (enemy->pv <= enemy->pv_max * 0.5 && enemy->pv >= enemy->pv_max * 0.4)
        enemy->lifebar->rect.top = 151;
    if (enemy->pv <= enemy->pv_max * 0.4 && enemy->pv >= enemy->pv_max * 0.3)
        enemy->lifebar->rect.top = 181.2;
    if (enemy->pv <= enemy->pv_max * 0.3 && enemy->pv >= enemy->pv_max * 0.2)
        enemy->lifebar->rect.top = 211.4;
    if (enemy->pv <= enemy->pv_max * 0.2 && enemy->pv >= enemy->pv_max * 0.1)
        enemy->lifebar->rect.top = 241.6;
    if (enemy->pv <= enemy->pv_max * 0.1 && enemy->pv >= enemy->pv_max * 0)
        enemy->lifebar->rect.top = 271.8;
}

sfIntRect change_rect(sfIntRect rect, float x, float y)
{
    rect.top = 0;
    rect.left = 0;
    rect.width = x;
    rect.height = y;
    return (rect);
}

void create_lifebar(global *game, struct enemy_ *enemy)
{
    sfVector2f scale = {0.5, 0.5};

    enemy->lifebar = malloc(sizeof(lifebar_t));
    enemy->lifebar->life = sfSprite_create();
    enemy->lifebar->t_life = sfTexture_createFromFile\
    ("pictures/lifebar.png", NULL);
    enemy->lifebar->pos_life.x = -100;
    enemy->lifebar->pos_life.y = -100;
    sfSprite_setPosition(enemy->lifebar->life, enemy->lifebar->pos_life);
    enemy->lifebar->rect = change_rect(enemy->lifebar->rect, 108, 30.2);
    sfSprite_setTexture(enemy->lifebar->life, enemy->lifebar->t_life, sfFalse);
    sfSprite_setScale(enemy->lifebar->life, scale);
    sfSprite_setTextureRect(enemy->lifebar->life, enemy->lifebar->rect);
}
