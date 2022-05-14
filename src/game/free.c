/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to set a basic window
*/

#include "../../includes/my_defender.h"

void free_menu(global *game, menu *menus)
{
    free(menus->t_menu);
    free(menus);
    free(game->infos);
    free(game->bonus);
    free(game->how_to_play);
    free(game->transition);
    free(game);
}
