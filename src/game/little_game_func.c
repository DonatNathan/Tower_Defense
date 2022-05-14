/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain some little functions
*/

#include "../../includes/my_defender.h"

batiment *get_last(global *game, sfVector2f pos, int name)
{
    batiment *temp = game->first;

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = add_bat(game, temp, pos, name);
    return (temp->next);
}

void set_game(global *game)
{
    sfCircleShape *radius = sfCircleShape_create();

    game->first = create_hdv(game);
    game->boole->god = 1;
    game->map->map = sfSprite_create();
    set_texture_map(game);
    set_music(game);
    create_pause(game);
    game->boole->shop_is_open = 1;
    game->boole->take = 1;
    game->boole->pause_is_open = 1;
    game->boole->on_bat = 1;
    game->radius = radius;
    game->rad_god = 1;
}
