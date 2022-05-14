/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain function to check action of bats
*/

#include "../../includes/my_defender.h"

void destroy_struct(global *game, batiment *bat)
{
    batiment *prev = malloc(sizeof(batiment));

    sfSound_play(game->sounds->destroy);
    prev = bat->prev;
    prev->next = bat->next;
    if (prev->next)
        prev->next->prev = prev;
    game->first->gold += bat->stats->price / 3;
}

void up_struct(global *game, batiment *bat, grid_cell grid_cell_)
{
    if (bat->on_bat == 0) {
        game->boole->ground = 1;
        sfSound_play(game->sounds->anvil);
        bat->stats->level += 1;
        game->first->gold -= bat->stats->price;
        bat->stats->damage *= 1.5;
        bat->stats->price *= 1.5;
        bat->stats->pv *= 1.5;
        if (bat->stats->bat_name == -1)
            check_time(game, bat, grid_cell_);
    }
}

void give_ground(global *game, grid_cell *grid_cell)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);

    if ((abs(pos_mouse.x - 60 - grid_cell->p_5.x)) * (abs(pos_mouse.x - 60 - \
    grid_cell->p_5.x)) + (abs(pos_mouse.y - 90 - grid_cell->p_5.y)) * \
    (abs(pos_mouse.y - 90 - grid_cell->p_5.y)) < 900) {
        grid_cell->status = 1;
        add_base(game, grid_cell, game->shop);
    }
    if (grid_cell->g_pos != 196)
        give_ground(game, grid_cell->next_cell);
}

void button_struct(global *game, batiment *bat_, sfVector2i pos_mouse, \
grid_cell grid_cell_)
{
    if (bat_->stats->level < 10 && game->first->gold >= bat_->stats->price && \
    pos_mouse.x > bat_->level_up->pos_up.x && pos_mouse.x < bat_->level_up->\
    pos_up.x + 30 && pos_mouse.y > bat_->level_up->pos_up.y && pos_mouse.y < \
    bat_->level_up->pos_up.y + 30 && game->event.type ==
    sfEvtMouseButtonReleased)
        up_struct(game, bat_, grid_cell_);
    if (bat_->on_bat == 0 && pos_mouse.x > bat_->level_up->pos_destroy.x && \
    pos_mouse.x < bat_->level_up->pos_destroy.x + 30 && pos_mouse.y > bat_->\
    level_up->pos_destroy.y && pos_mouse.y < bat_->level_up->pos_destroy.y + \
    30 && game->event.type == sfEvtMouseButtonReleased) {
        destroy_struct(game, bat_);
        give_ground(game, &grid_cell_);
    }
}

void struct_event(global *game, batiment *bat_, grid_cell grid_cell_)
{
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);

    button_struct(game, bat_, pos_mouse, grid_cell_);
    if (game->event.type == sfEvtMouseButtonReleased && !(pos_mouse.x > bat_->\
    level_up->pos_up.x && pos_mouse.x < bat_->level_up->pos_up.x + 30 && \
    pos_mouse.y > bat_->level_up->pos_up.y && pos_mouse.y < bat_->level_up->\
    pos_up.y + 30))
        bat_->on_bat = 1;
    if (pos_mouse.x > bat_->pos.x + 30 && pos_mouse.x < bat_->pos.x + 90 && \
    pos_mouse.y > bat_->pos.y + 30 && pos_mouse.y < bat_->pos.y + 90 && game->\
    event.type == sfEvtMouseButtonReleased) {
        if (bat_->on_bat == 1 && game->secs != 5) {
            bat_->on_bat = 0;
            game->secs = 5;
        }
        if (bat_->on_bat == 0 && game->secs != 5)
            bat_->on_bat = 1;
    }
    if (bat_->next != NULL)
        struct_event(game, bat_->next, grid_cell_);
}
