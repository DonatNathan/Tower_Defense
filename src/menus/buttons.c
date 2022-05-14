/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to click on buttons
*/

#include "../../includes/my_defender.h"

void check_button_res(global *game, menu *menus, sfVector2i mouse)
{
    if (mouse.x >= menus->pos_restart.x && mouse.x <= menus->pos_restart.x \
    + 473 && mouse.y >= menus->pos_restart.y && mouse.y <= menus->\
    pos_restart.y + 236) {
        sfText_setColor(menus->c_restart, sfWhite);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfText_setColor(menus->c_restart, sfBlue);
        }
        if (game->event.type == sfEvtMouseButtonReleased && game->other_secs \
        != 0) {
            game->level = 1;
            game->gold = game->start;
            game->price_hdv = 1000;
            sfSound_play(game->sounds->click);
            start_game(game);
        }
    } else
        sfText_setColor(menus->c_restart, sfBlack);
}

void check_button_con(global *game, menu *menus, sfVector2i mouse)
{
    if (mouse.x >= menus->pos_continu.x && mouse.x <= menus->pos_continu.x \
    + 473 && mouse.y >= menus->pos_continu.y && mouse.y <= menus->\
    pos_continu.y + 236) {
        sfText_setColor(menus->c_continu, sfWhite);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfText_setColor(menus->c_continu, sfBlue);
            game->other_secs = 0;
        }
        if (game->event.type == sfEvtMouseButtonReleased && game->other_secs \
        != 0) {
            sfSound_play(game->sounds->click);
            start_game(game);
        }
    } else
        sfText_setColor(menus->c_continu, sfBlack);
}

void check_button_quit(global *game, menu *menus)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);
    sfVector2f scale_min = {1, 1};
    sfVector2f scale_max = {1.2, 1.2};

    if (mouse.x >= menus->pos_quit.x && mouse.x <= menus->pos_quit.x + 314 \
    && mouse.y >= menus->pos_quit.y && mouse.y <= menus->pos_quit.y + 145) {
        sfSprite_setScale(menus->quit, scale_max);
        sfSprite_setPosition(menus->quit, menus->pos2_quit);
        if (game->event.type == sfEvtMouseButtonReleased) {
            write_level(game);
            sfSound_play(game->sounds->click);
            sfRenderWindow_close(game->window);
        }
    } else {
        sfSprite_setScale(menus->quit, scale_min);
        sfSprite_setPosition(menus->quit, menus->pos_quit);
    }
    check_button_con(game, menus, mouse);
    check_button_res(game, menus, mouse);
}
