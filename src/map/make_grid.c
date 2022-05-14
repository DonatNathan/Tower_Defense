/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to copy cell
*/

#include "../../includes/my_defender.h"

void set_new(struct grid_cell *new, grid_cell *grid_cell_)
{
    new->status = 0;
    new->prev_cell = grid_cell_;
    new->first_cell = grid_cell_->first_cell;
    new->next_cell = NULL;
    grid_cell_->next_cell = new;
    new->g_pos = grid_cell_->g_pos + 1;
    new->l_pos = grid_cell_->l_pos + 1;
    grid_cell_->next_cell = new;
    (new->l_pos == 14) ? new->l_pos = 0 : 1;
}

void pos_new(struct grid_cell *new, int i, int r)
{
    new->coords->dx = 51;
    new->coords->dy = -33;
    new->coords->original_x = 260 - 17 + (new->coords->dx * r);
    new->coords->original_y = 540 - 11 + (abs(new->coords->dy) * r);
    new->c_1 = sfCircleShape_create();
    new->p_1.x = new->coords->original_x + (new->coords->dx * (0 + i));
    new->p_1.y = new->coords->original_y + (new->coords->dy * (0 + i));
    new->c_2 = sfCircleShape_create();
    new->p_2.x = new->coords->original_x + (new->coords->dx * (1 + i));
    new->p_2.y = new->coords->original_y + (new->coords->dy * (1 + i));
    new->c_3 = sfCircleShape_create();
    new->p_3.x = new->coords->original_x + (new->coords->dx * (1 + i));
    new->p_3.y = new->coords->original_y - new->coords->dy + (new->coords->dy \
    * (0 + i));
    new->c_4 = sfCircleShape_create();
    new->p_4.x = new->coords->original_x + (new->coords->dx * (2 + i));
    new->p_4.y = new->coords->original_y + (new->coords->dy * (0 + i));
    new->c_5 = sfCircleShape_create();
    new->p_5.x = new->coords->original_x + (new->coords->dx * (0 + i)) + \
    new->coords->dx - 25;
}

void set_shape_new(grid_cell *new)
{
    sfCircleShape_setFillColor(new->c_1, sfBlue);
    sfCircleShape_setRadius(new->c_1, 5.0);
    sfCircleShape_setPosition(new->c_1, new->p_1);
    sfCircleShape_setFillColor(new->c_2, sfBlue);
    sfCircleShape_setRadius(new->c_2, 5.0);
    sfCircleShape_setPosition(new->c_2, new->p_2);
    sfCircleShape_setFillColor(new->c_3, sfBlue);
    sfCircleShape_setRadius(new->c_3, 5.0);
    sfCircleShape_setPosition(new->c_3, new->p_3);
    sfCircleShape_setFillColor(new->c_4, sfBlue);
    sfCircleShape_setRadius(new->c_4, 5.0);
    sfCircleShape_setPosition(new->c_4, new->p_4);
    sfCircleShape_setRadius(new->c_5, 33.0);
    sfCircleShape_setPosition(new->c_5, new->p_5);
}

grid_cell *make_grid(global *game, grid_cell *grid_cell_, shop *my_shop)
{
    struct grid_cell *new = (grid_cell *) malloc(sizeof(grid_cell));
    int i = grid_cell_->l_pos;
    int r = (grid_cell_->g_pos) / 14;

    new->coords = malloc(sizeof(coords_t));
    pos_new(new, i, r);
    new->p_5.y = new->coords->original_y + (new->coords->dy * (0 + i) - 25);
    set_shape_new(new);
    set_new(new, grid_cell_);
    if (new->g_pos != 196)
        make_grid(game, new, my_shop);
    return (grid_cell_);
}
