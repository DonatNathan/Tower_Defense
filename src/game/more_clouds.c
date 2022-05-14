/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create clouds
*/

#include "../../includes/my_defender.h"

void set_color_clouds(global *game)
{
    sfSprite_setColor(game->transition->clouds, \
    game->transition->opacity);
    sfSprite_setColor(game->transition->clouds2, game->transition->\
    opacity);
    sfSprite_setColor(game->transition->clouds3, \
    game->transition->opacity);
    sfSprite_setColor(game->transition->clouds4, game->transition->\
    opacity);
}
