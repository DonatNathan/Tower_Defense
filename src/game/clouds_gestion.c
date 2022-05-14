/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create clouds
*/

#include "../../includes/my_defender.h"

void set_pos_clouds(global *game)
{
    game->transition->pos_clouds.x = 0;
    game->transition->pos_clouds.y = 0;
    game->transition->pos_clouds2.x = 0;
    game->transition->pos_clouds2.y = 0;
    game->transition->pos_clouds3.x = 0;
    game->transition->pos_clouds3.y = 0;
    game->transition->pos_clouds4.x = 0;
    game->transition->pos_clouds4.y = 0;
}

void set_pos_trans(global *game)
{
    sfSprite_setColor(game->transition->clouds, game->transition->opacity);
    sfSprite_setColor(game->transition->clouds2, game->transition->opacity);
    sfSprite_setColor(game->transition->clouds3, game->transition->opacity);
    sfSprite_setColor(game->transition->clouds4, game->transition->opacity);
    set_pos_clouds(game);
}

void set_pos_dissip(global *game)
{
    game->transition->pos_clouds.x -= 60;
    game->transition->pos_clouds.y += 40;
    game->transition->pos_clouds2.x += 60;
    game->transition->pos_clouds2.y -= 40;
    game->transition->pos_clouds3.x -= 60;
    game->transition->pos_clouds3.y -= 40;
    game->transition->pos_clouds4.x += 60;
    game->transition->pos_clouds4.y += 40;
}

void set_pos_clouds2(global *game)
{
    sfSprite_setPosition(game->transition->clouds, game->transition->\
    pos_clouds);
    sfSprite_setPosition(game->transition->clouds2, game->transition->\
    pos_clouds2);
    sfSprite_setPosition(game->transition->clouds3, game->transition->\
    pos_clouds3);
    sfSprite_setPosition(game->transition->clouds4, game->transition->\
    pos_clouds4);
}

void set_pos_come(global *game)
{
    if (game->transition->pos_clouds.x < 0)
        game->transition->pos_clouds.x += 60;
    if (game->transition->pos_clouds.y > 0)
        game->transition->pos_clouds.y -= 40;
    if (game->transition->pos_clouds2.x > 0)
        game->transition->pos_clouds2.x -= 60;
    if (game->transition->pos_clouds2.y < 0)
        game->transition->pos_clouds2.y += 40;
    if (game->transition->pos_clouds3.x < 0)
        game->transition->pos_clouds3.x += 60;
    if (game->transition->pos_clouds3.y < 0)
        game->transition->pos_clouds3.y += 40;
    if (game->transition->pos_clouds4.x > 0)
        game->transition->pos_clouds4.x -= 60;
    if (game->transition->pos_clouds4.y > 0)
        game->transition->pos_clouds4.y -= 40;
}
