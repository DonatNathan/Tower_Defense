/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to check event on endgame menu
*/

#include "../../includes/my_defender.h"

void check_mouse_qui(global *game, sfVector2i mouse)
{
    if (mouse.x > game->endgame->pos_quit.x && mouse.x < game->\
    endgame->pos_quit.x + 470 && mouse.y > game->endgame->pos_quit.y \
    && mouse.y < game->endgame->pos_quit.y + 230) {
        sfText_setColor(game->endgame->qui, sfWhite);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfText_setColor(game->endgame->qui, sfRed);
            game->other_secs = 0;
        }
        if (game->event.type == sfEvtMouseButtonReleased && game->other_secs \
        != 0) {
            game->secs = 4;
            game->menus->level = game->first->stats->level;
            sfSound_play(game->sounds->click);
            set_menu(game);
        }
    } else
        sfText_setColor(game->endgame->qui, sfBlack);
}

void check_mouse_res(global *game)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    if (mouse.x > game->endgame->pos_restart.x && mouse.x < game->endgame->\
    pos_restart.x + 470 && mouse.y > game->endgame->pos_restart.y && mouse.y \
    < game->endgame->pos_restart.y + 230) {
        sfText_setColor(game->endgame->res, sfWhite);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfText_setColor(game->endgame->res, sfRed);
            game->other_secs = 0;
        }
        if (game->event.type == sfEvtMouseButtonReleased && game->other_secs \
        != 0) {
            sfSound_play(game->sounds->click);
            start_game(game);
        }
    } else
        sfText_setColor(game->endgame->res, sfBlack);
    check_mouse_qui(game, mouse);
}

void check_endgame(global *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyR)) {
            sfSound_play(game->sounds->click);
            start_game(game);
        }
        if (sfKeyboard_isKeyPressed(sfKeyM)) {
            game->secs = 4;
            game->menus->level = game->first->stats->level;
            sfSound_play(game->sounds->click);
            set_menu(game);
        }
        check_mouse_res(game);
    }
}

void on_endgame(global *game)
{
    update_end(game);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        update_game(game);
        check_endgame(game);
        draw_endgame(game);
        sfRenderWindow_display(game->window);
    }
}
