/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create gold
*/

#include "../../includes/my_defender.h"
#include <stdlib.h>
#include <string.h>

void create_gold(global *game)
{
    sfFont *font = sfFont_createFromFile("fonts/supercell.x-font-ttf");

    game->gold_gestion = malloc(sizeof(gold));
    game->gold_gestion->money = sfText_create();
    game->gold_gestion->number = sfText_create();
    game->gold_gestion->pos_money.x = 10;
    game->gold_gestion->pos_money.y = 10;
    game->gold_gestion->pos_number.x = 120;
    game->gold_gestion->pos_number.y = 10;
    sfText_setPosition(game->gold_gestion->money, game->gold_gestion->\
    pos_money);
    sfText_setFont(game->gold_gestion->money, font);
    sfText_setPosition(game->gold_gestion->number, game->gold_gestion->\
    pos_number);
    sfText_setFont(game->gold_gestion->number, font);
    sfText_setColor(game->gold_gestion->number, sfYellow);
    sfText_setColor(game->gold_gestion->money, sfYellow);
    game->gold_gestion->temp = malloc(sizeof(char *));
}

char *my_itoa(int number)
{
    int len;
    char *str;
    int tmp = number;

    for (len = 0; tmp > 0; tmp /= 10, len += 1);
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = number % 10 + '0';
        number /= 10;
    }
    return (str);
}

void update_gold(global *game)
{
    sfText_setString(game->gold_gestion->money, "Gold : ");
    sfText_setString(game->gold_gestion->number, my_itoa(game->first->gold));
    sfRenderWindow_drawText(game->window, game->gold_gestion->money, sfFalse);
    sfRenderWindow_drawText(game->window, game->gold_gestion->number, sfFalse);
    sfRenderWindow_drawText(game->window, game->infos->skills, sfFalse);
    sfRenderWindow_drawText(game->window, game->infos->pause, sfFalse);
    sfRenderWindow_drawText(game->window, game->infos->shop, sfFalse);
}
