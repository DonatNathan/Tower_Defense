/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that draw all in game
*/

#include "../../includes/my_defender.h"

void draw_level(global *game, batiment *temp)
{
    if (temp->stats->level == 10) {
        temp->temp = malloc(sizeof(char) * 3);
        temp->temp[2] = '\0';
    } else {
        temp->temp = malloc(sizeof(char) * 2);
        temp->temp[1] = '\0';
    }
    temp->pos_level.x = temp->pos.x + 56;
    temp->pos_level.y = temp->pos.y + 90;
    sfText_setPosition(temp->level_str, temp->pos_level);
    sfText_setString(temp->level_str, new_put_nbr_str(temp->stats->level));
    sfRenderWindow_drawText(game->window, temp->level_str, sfFalse);
}

void draw_stats(global *game, shop *my_shop)
{
    if (my_shop->stats->mouse->is_cannon == 0 && game->boole->take == 1)
        sfRenderWindow_drawSprite(game->window, my_shop->stats->cannon, \
        sfFalse);
    if (my_shop->stats->mouse->is_archer == 0 && game->boole->take == 1)
        sfRenderWindow_drawSprite(game->window, my_shop->stats->archer, \
        sfFalse);
    if (my_shop->stats->mouse->is_mortar == 0 && game->boole->take == 1)
        sfRenderWindow_drawSprite(game->window, my_shop->stats->mortar, \
        sfFalse);
    if (my_shop->stats->mouse->is_air == 0 && game->boole->take == 1)
        sfRenderWindow_drawSprite(game->window, my_shop->stats->air, sfFalse);
    if (my_shop->stats->mouse->is_xbow == 0 && game->boole->take == 1)
        sfRenderWindow_drawSprite(game->window, my_shop->stats->xbow, sfFalse);
    if (my_shop->stats->mouse->is_wizard == 0 && game->boole->take == 1)
        sfRenderWindow_drawSprite(game->window, my_shop->stats->wizard, \
        sfFalse);
}

void draw_game(global *game, shop *my_shop, grid_cell grid_cell)
{
    sfRenderWindow_drawSprite(game->window, game->map->map, sfFalse);
    sfRenderWindow_drawSprite(game->window, my_shop->button, sfFalse);
    draw_ground(game, &grid_cell, my_shop);
    (game->boole->god == 0) ? draw_cell(game, grid_cell.next_cell, \
    my_shop) : 1;
    draw_rad(game, game->first);
    sfRenderWindow_drawCircleShape(game->window, game->radius, sfFalse);
    place_struct(game, &grid_cell, my_shop);
    check_hit(game, game->first);
    update_lifebar_hdv(game, game->first);
    game->first->lifebar->pos_life.x = game->first->pos.x + 35;
    game->first->lifebar->pos_life.y = game->first->pos.y - 5;
    sfSprite_setPosition(game->first->lifebar->life, game->first->lifebar->\
    pos_life);
    sfRenderWindow_drawSprite(game->window, game->first->lifebar->life, \
    sfFalse);
    draw_structs(game, game->first);
    draw_stats(game, my_shop);
    update_bullet(game, game->first);
}

void draw_structs(global *game, batiment *bat_)
{
    if (bat_->on_bat == 0) {
        bat_->level_up->pos_up.x = bat_->pos.x + 15;
        bat_->level_up->pos_up.y = bat_->pos.y + 97;
        sfSprite_setPosition(bat_->level_up->up, bat_->level_up->pos_up);
        sfRenderWindow_drawSprite(game->window, bat_->level_up->up, sfFalse);
        if (bat_->stats->bat_name != -1)
            sfRenderWindow_drawSprite(game->window, bat_->level_up->destroy, \
            sfFalse);
        sfText_setString(bat_->level_up->cost, new_put_nbr_str(bat_->stats->\
        price));
        bat_->level_up->pos_cost.x = bat_->level_up->pos_up.x - 20;
        bat_->level_up->pos_cost.y = bat_->level_up->pos_up.y + 30;
        sfText_setPosition(bat_->level_up->cost, bat_->level_up->pos_cost);
        sfRenderWindow_drawText(game->window, bat_->level_up->cost, sfFalse);
    }
    sfRenderWindow_drawSprite(game->window, bat_->bat, sfFalse);
    draw_level(game, bat_);
    if (bat_->next != NULL)
        draw_structs(game, bat_->next);
}
