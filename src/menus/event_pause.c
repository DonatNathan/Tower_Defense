/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain event pause functions
*/

#include "../../includes/my_defender.h"

void event_res(global *game, sfVector2i pos_mouse)
{
    if (pos_mouse.x >= game->pause->p_pause->pos_res.x && pos_mouse.x <= \
    game->pause->p_pause->pos_res.x + 240 && pos_mouse.y >= game->pause->\
    p_pause->pos_res.y && pos_mouse.y <= game->pause->p_pause->pos_res.y + \
    120) {
        sfText_setColor(game->pause->c_restart, sfWhite);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfText_setColor(game->pause->c_restart, sfRed);
            game->other_secs = 0;
        }
        if (game->event.type == sfEvtMouseButtonReleased && game->other_secs \
        != 0) {
            sfSound_play(game->sounds->click);
            start_game(game);
        }
    } else
        sfText_setColor(game->pause->c_restart, sfBlack);
}

void event_quit(global *game, sfVector2i pos_mouse)
{
    if (pos_mouse.x >= game->pause->p_pause->pos_quit.x && pos_mouse.x <= \
    game->pause->p_pause->pos_quit.x + 240 && pos_mouse.y >= game->pause->\
    p_pause->pos_quit.y && pos_mouse.y <= game->pause->p_pause->pos_quit.y + \
    120) {
        sfText_setColor(game->pause->c_quit, sfWhite);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfText_setColor(game->pause->c_quit, sfRed);
            game->other_secs = 0;
        }
        if (game->event.type == sfEvtMouseButtonReleased && game->other_secs \
        != 0) {
            sfSound_play(game->sounds->click);
            game->secs = 4;
            game->menus->level = game->first->stats->level;
            set_menu(game);
        }
    } else
        sfText_setColor(game->pause->c_quit, sfBlack);
}

void event_con(global *game, sfVector2i pos_mouse)
{
    if (pos_mouse.x >= game->pause->p_pause->pos_con.x && pos_mouse.x <= \
    game->pause->p_pause->pos_con.x + 240 && pos_mouse.y >= game->pause->\
    p_pause->pos_con.y && pos_mouse.y <= game->pause->p_pause->pos_con.y + \
    120) {
        sfText_setColor(game->pause->c_continu, sfWhite);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfText_setColor(game->pause->c_continu, sfRed);
            game->other_secs = 0;
        }
        if (game->event.type == sfEvtMouseButtonReleased && game->other_secs \
        != 0) {
            sfSound_play(game->sounds->click);
            game->boole->pause_is_open = 1;
        }
    } else
        sfText_setColor(game->pause->c_continu, sfBlack);
}

void check_button_event(global *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyC)) {
        game->boole->pause_is_open = 1;
        sfSound_play(game->sounds->click);
    }
    if (sfKeyboard_isKeyPressed(sfKeyR)) {
        sfSound_play(game->sounds->click);
        start_game(game);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        game->secs = 4;
        game->menus->level = game->first->stats->level;
        sfSound_play(game->sounds->click);
        set_menu(game);
    }
}

void check_pause_event(global *game)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if ((game->boole->pause_is_open == 0 && sfKeyboard_isKeyPressed\
        (sfKeyEscape) && game->other_secs != 0) || (mouse.x > 1370 && mouse.x \
        < 1430 && mouse.y > 270 && mouse.y < 300 && game->event.type == \
        sfEvtMouseButtonReleased)) {
            sfSound_play(game->sounds->click);
            sfSound_play(game->sounds->ambiance);
            game->boole->pause_is_open = 1;
            game->other_secs = 0;
        }
        do_pause_all(game, mouse);
    }
}
