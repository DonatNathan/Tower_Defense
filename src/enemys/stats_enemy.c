/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create enemy's stats
*/

#include "../../includes/my_defender.h"

void create_enemy(global *game, struct enemy_ *enemy, int i)
{
    enemy_ *new = malloc(sizeof(enemy_));

    if (i >= 1 && i <= 2)
        new = create_barbar(game, enemy, i, new);
    if (i >= 3 && i <= 4)
        new = create_archer(game, enemy, i, new);
    if (i >= 5 && i <= 6)
        new = create_goblin(game, enemy, i, new);
    if (i >= 7 && i <= 8)
        new = create_giant(game, enemy, i, new);
    if (i >= 9 && i <= 10)
        new = create_dragon(game, enemy, i, new);
    new->pv_max = new->pv;
    new->clock = sfClock_create();
    new->seconds = 0;
    enemy->pos.x = -100;
    enemy->pos.y = -100;
    create_lifebar(game, new);
    (enemy->enemy_next == NULL) ? enemy->enemy_next = new : \
    create_enemy(game, enemy->enemy_next, i);
}

void moov_enemy(global *game, struct enemy_ *enemy)
{
    enemy->loc++;
    if (enemy->loc >= 0) {
        if (enemy->pv <= 0 && enemy->pv_max != -1) {
            enemy->loc = 0;
            enemy->pv = enemy->pv_base;
            game->first->gold += enemy->reward;
            update_gold(game);
        }
        if (enemy->loc >= game->split * 30) {
            enemy->loc = 0;
            enemy->pv = enemy->pv_base;
            game->first->stats->pv -= enemy->damage;
            update_lifebar_hdv(game, game->first);
        }
        set_enemy_pos(game, enemy);
    }
    if (enemy->enemy_next != NULL)
        moov_enemy(game, enemy->enemy_next);
}

sfIntRect move_rect(sfIntRect rect, float offset, int max_value)
{
    rect.left += offset;
    if (rect.left >= max_value)
        rect.left = 0;
    return (rect);
}

void do_rect_enemy(global *game, struct enemy_ *enemy)
{
    enemy->time = sfClock_getElapsedTime(enemy->clock);
    enemy->seconds = enemy->time.microseconds / 5000;
    if (enemy->seconds >= 20) {
        enemy->rect = move_rect(enemy->rect, enemy->offset, enemy->max_value);
        sfClock_restart(enemy->clock);
    }
    sfSprite_setTextureRect(enemy->enemy_1, enemy->rect);
}

void draw_enemy(global *game, struct enemy_ *enemy)
{
    if (enemy->pv_max != -1) {
        sfRenderWindow_drawSprite(game->window, enemy->enemy_1, sfFalse);
        do_rect_enemy(game, enemy);
        update_lifebar(game, enemy);
        sfSprite_setTextureRect(enemy->lifebar->life, enemy->lifebar->rect);
        enemy->lifebar->pos_life.x = enemy->pos.x;
        enemy->lifebar->pos_life.y = enemy->pos.y + 70;
        sfSprite_setPosition(enemy->lifebar->life, enemy->lifebar->pos_life);
        sfRenderWindow_drawSprite(game->window, enemy->lifebar->life, sfFalse);
    }
    if (enemy->enemy_next != NULL)
        draw_enemy(game, enemy->enemy_next);
}
