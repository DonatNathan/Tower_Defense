/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to initialise first cell
*/

#include "../../includes/my_defender.h"

grid_cell set_grid_cell(grid_cell grid_cell_)
{
    grid_cell_.status = 0;
    grid_cell_.prev_cell = NULL;
    grid_cell_.next_cell = NULL;
    grid_cell_.first_cell = &grid_cell_;
    grid_cell_.g_pos = 0;
    grid_cell_.l_pos = 0;
    grid_cell_.first_cell = &grid_cell_;
    return (grid_cell_);
}

grid_cell pos_grid_cell2(grid_cell grid_cell_, int i, int r)
{
    grid_cell_.p_3.x = grid_cell_.coords->original_x + (grid_cell_.coords->dx \
    * (1 + i));
    grid_cell_.p_3.y = grid_cell_.coords->original_y - grid_cell_.coords->dy \
    + (grid_cell_.coords->dy * (0 + i));
    grid_cell_.c_4 = sfCircleShape_create();
    grid_cell_.p_4.y = grid_cell_.coords->original_x + (grid_cell_.coords->dx \
    * (2 + i));
    grid_cell_.p_4.y = grid_cell_.coords->original_y + (grid_cell_.coords->dy \
    * (0 + i));
    grid_cell_.c_5 = sfCircleShape_create();
    grid_cell_.p_5.x = grid_cell_.coords->original_x + (grid_cell_.coords->dx \
    * (0 + i)) + grid_cell_.coords->dx - 25;
    grid_cell_.p_5.y = grid_cell_.coords->original_y + (grid_cell_.coords->dy \
    * (0 + i) - 25);
    return (grid_cell_);
}

grid_cell pos_grid_cell(grid_cell grid_cell_, int i, int r)
{
    grid_cell_.coords->original_x = 260 - 17 + (grid_cell_.coords->dx * r);
    grid_cell_.coords->original_y = 540 - 11 + (abs(grid_cell_.coords->dy) \
    * r);
    grid_cell_.c_1 = sfCircleShape_create();
    grid_cell_.p_1.x = grid_cell_.coords->original_x + (grid_cell_.coords->dx \
    * (0 + i));
    grid_cell_.p_1.y = grid_cell_.coords->original_y + (grid_cell_.coords->dy \
    * (0 + i));
    grid_cell_.c_2 = sfCircleShape_create();
    grid_cell_.p_2.x = grid_cell_.coords->original_x + (grid_cell_.coords->dx \
    * (1 + i));
    grid_cell_.p_2.y = grid_cell_.coords->original_y + (grid_cell_.coords->dy \
    * (1 + i));
    grid_cell_.c_3 = sfCircleShape_create();
    return (grid_cell_);
}

grid_cell set_shape_grid_cell(grid_cell grid_cell_)
{
    sfCircleShape_setFillColor(grid_cell_.c_1, sfBlue);
    sfCircleShape_setRadius(grid_cell_.c_1, 5.0);
    sfCircleShape_setPosition(grid_cell_.c_1, grid_cell_.p_1);
    sfCircleShape_setFillColor(grid_cell_.c_2, sfBlue);
    sfCircleShape_setRadius(grid_cell_.c_2, 5.0);
    sfCircleShape_setPosition(grid_cell_.c_2, grid_cell_.p_2);
    sfCircleShape_setFillColor(grid_cell_.c_3, sfBlue);
    sfCircleShape_setRadius(grid_cell_.c_3, 5.0);
    sfCircleShape_setPosition(grid_cell_.c_3, grid_cell_.p_3);
    sfCircleShape_setFillColor(grid_cell_.c_4, sfBlue);
    sfCircleShape_setRadius(grid_cell_.c_4, 5.0);
    sfCircleShape_setPosition(grid_cell_.c_4, grid_cell_.p_4);
    sfCircleShape_setRadius(grid_cell_.c_5, 33.0);
    sfCircleShape_setPosition(grid_cell_.c_5, grid_cell_.p_5);
    return (grid_cell_);
}

grid_cell init_cell(global *game, grid_cell grid_cell_, shop *my_shop)
{
    int i = 0;
    int r = 0;

    grid_cell_.coords = malloc(sizeof(coords_t));
    grid_cell_.coords->dx = 51;
    grid_cell_.coords->dy = -33;
    grid_cell_ = pos_grid_cell(grid_cell_, i, r);
    grid_cell_ = pos_grid_cell2(grid_cell_, i, r);
    grid_cell_ = set_shape_grid_cell(grid_cell_);
    grid_cell_ = set_grid_cell(grid_cell_);
    return (grid_cell_);
}
