/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain function to turn on/off sounds
*/

#include "../../includes/my_defender.h"

void do_pause_all(global *game, sfVector2i mouse)
{
    check_button_event(game);
    check_sounds_pause(game, mouse);
    check_music_pause(game, mouse);
    event_con(game, mouse);
    event_res(game, mouse);
    event_quit(game, mouse);
}

void set_volume_music(global *game)
{
    if (game->boole->is_music == 1 && game->secs != 2) {
        sfSound_play(game->sounds->click);
        sfSprite_setTexture(game->menus->music, game->menus->t_menu->m_on, \
        sfFalse);
        sfSprite_setTexture(game->pause->music, game->menus->t_menu->m_on, \
        sfFalse);
        game->boole->is_music = 0;
        game->secs = 2;
        sfSound_setVolume(game->sounds->ambiance, 100);
    } else if (game->boole->is_music == 0 && game->secs != 2) {
        sfSound_play(game->sounds->click);
        sfSprite_setTexture(game->menus->music, game->menus->\
        t_menu->m_off, sfFalse);
        sfSprite_setTexture(game->pause->music, game->menus->\
        t_menu->m_off, sfFalse);
        game->boole->is_music = 1;
        game->secs = 2;
        sfSound_setVolume(game->sounds->ambiance, 0);
    }
}

void check_music_pause(global *game, sfVector2i mouse)
{
    if (mouse.x >= game->pause->p_pause->pos_music.x && mouse.x <= game->\
    pause->p_pause->pos_music.x + 100 && mouse.y >= game->pause->p_pause->\
    pos_music.y && mouse.y <= game->pause->p_pause->pos_music.y + 100 && \
    game->event.type == sfEvtMouseButtonReleased)
        set_volume_music(game);
}

void set_volume_sounds(global *game)
{
    sfSound_play(game->sounds->click);
    sfSprite_setTexture(game->menus->sounds, game->menus->\
    t_menu->s_off, sfFalse);
    sfSprite_setTexture(game->pause->sounds, game->menus->\
    t_menu->s_off, sfFalse);
    game->boole->is_sounds = 1;
    game->secs = 2;
    sfSound_setVolume(game->sounds->click, 0);
    sfSound_setVolume(game->sounds->anvil, 0);
    sfSound_setVolume(game->sounds->destroy, 0);
}

void check_sounds_pause(global *game, sfVector2i mouse)
{
    if (mouse.x >= game->pause->p_pause->pos_sounds.x && mouse.x <= game->\
    pause->p_pause->pos_sounds.x + 50 && mouse.y >= game->pause->p_pause->\
    pos_sounds.y && mouse.y <= game->pause->p_pause->pos_sounds.y + 50 && \
    game->event.type == sfEvtMouseButtonReleased) {
        if (game->boole->is_sounds == 1 && game->secs != 2) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(game->menus->sounds, game->menus->\
            t_menu->s_on, sfFalse);
            sfSprite_setTexture(game->pause->sounds, game->menus->\
            t_menu->s_on, sfFalse);
            game->boole->is_sounds = 0;
            game->secs = 2;
            sfSound_setVolume(game->sounds->click, 100);
            sfSound_setVolume(game->sounds->anvil, 100);
            sfSound_setVolume(game->sounds->destroy, 100);
        }
        if (game->boole->is_sounds == 0 && game->secs != 2)
            set_volume_sounds(game);
    }
}
