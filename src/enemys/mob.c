/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create enemys
*/

#include "../../includes/my_defender.h"

enemy_ *create_barbar(global *game, struct enemy_ *enemy, int i, enemy_ *new)
{
    sfTexture *e_1 = sfTexture_createFromFile\
    ("pictures/mob/barbarian2.png", NULL);
    sfTexture *e_2 = sfTexture_createFromFile\
    ("pictures/mob/mirror_barbarian2.png", NULL);
    sfSprite *temp = sfSprite_create();
    sfVector2f pos = {-100, -100};

    new->mirror = e_2;
    new->enemy_prev = enemy;
    new->loc = enemy->loc - 50;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    stats_barbar(game, new);
    sfSprite_setPosition(new->enemy_1, pos);
    new->rect = change_rect(new->rect, 81.5, 82);
    sfSprite_setTextureRect(new->enemy_1, new->rect);
    sfSprite_setTexture(new->enemy_1, new->texture, sfFalse);
    return (new);
}

enemy_ *create_archer(global *game, struct enemy_ *enemy, int i, enemy_ *new)
{
    sfTexture *e_1 = sfTexture_createFromFile\
    ("pictures/mob/archer2.png", NULL);
    sfTexture *e_2 = sfTexture_createFromFile\
    ("pictures/mob/mirror_archer2.png", NULL);
    sfSprite *temp = sfSprite_create();
    sfVector2f pos = {-100, -100};

    new->mirror = e_2;
    new->enemy_prev = enemy;
    new->loc = enemy->loc - 50;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    stats_archer(game, new);
    new->rect = change_rect(new->rect, 76, 89);
    sfSprite_setTextureRect(new->enemy_1, new->rect);
    sfSprite_setTexture(new->enemy_1, new->texture, sfFalse);
    sfSprite_setPosition(new->enemy_1, pos);
    return (new);
}

enemy_ *create_goblin(global *game, struct enemy_ *enemy, int i, enemy_ *new)
{
    sfTexture *e_1 = sfTexture_createFromFile\
    ("pictures/mob/goblin2.png", NULL);
    sfTexture *e_2 = sfTexture_createFromFile\
    ("pictures/mob/mirror_goblin2.png", NULL);
    sfSprite *temp = sfSprite_create();
    sfVector2f pos = {-100, -100};

    new->mirror = e_2;
    new->enemy_prev = enemy;
    new->loc = enemy->loc - 50;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    stats_gobelin(game, new);
    new->rect = change_rect(new->rect, 99.5, 90);
    sfSprite_setTextureRect(new->enemy_1, new->rect);
    sfSprite_setTexture(new->enemy_1, new->texture, sfFalse);
    sfSprite_setPosition(new->enemy_1, pos);
    return (new);
}

enemy_ *create_giant(global *game, struct enemy_ *enemy, int i, enemy_ *new)
{
    sfTexture *e_1 = sfTexture_createFromFile\
    ("pictures/mob/giant2.png", NULL);
    sfTexture *e_2 = sfTexture_createFromFile\
    ("pictures/mob/mirror_giant2.png", NULL);
    sfSprite *temp = sfSprite_create();
    sfVector2f pos = {-100, -100};

    new->mirror = e_2;
    new->enemy_prev = enemy;
    new->loc = enemy->loc - 50;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    stats_giant(game, new);
    new->rect = change_rect(new->rect, 109.3, 85);
    sfSprite_setTextureRect(new->enemy_1, new->rect);
    sfSprite_setTexture(new->enemy_1, new->texture, sfFalse);
    sfSprite_setPosition(new->enemy_1, pos);
    return (new);
}

enemy_ *create_dragon(global *game, struct enemy_ *enemy, int i, enemy_ *new)
{
    sfTexture *e_1 = sfTexture_createFromFile\
    ("pictures/mob/dragon2.png", NULL);
    sfTexture *e_2 = sfTexture_createFromFile\
    ("pictures/mob/mirror_dragon2.png", NULL);
    sfSprite *temp = sfSprite_create();
    sfVector2f pos = {-100, -100};

    new->mirror = e_2;
    new->enemy_prev = enemy;
    new->loc = enemy->loc - 50;
    new->enemy_1 = temp;
    new->texture = e_1;
    new->enemy_next = NULL;
    new->enemy_first = new;
    stats_dragon(game, new);
    new->rect = change_rect(new->rect, 129.6, 107);
    sfSprite_setTextureRect(new->enemy_1, new->rect);
    sfSprite_setTexture(new->enemy_1, new->texture, sfFalse);
    sfSprite_setPosition(new->enemy_1, pos);
    return (new);
}
