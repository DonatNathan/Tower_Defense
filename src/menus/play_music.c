/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain function to play sounds and music
*/

#include "../../includes/my_defender.h"

void check_music(global *game, menu *menus, sfVector2i mouse)
{
    if (mouse.x >= menus->pos_music.x && mouse.x <= menus->pos_music.x + 100 \
    && mouse.y >= menus->pos_music.y && mouse.y <= menus->pos_music.y + 100 \
    && game->event.type == sfEvtMouseButtonReleased) {
        if (game->boole->is_music == 1 && game->secs != 2) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(menus->music, menus->t_menu->m_on, sfFalse);
            game->boole->is_music = 0;
            game->secs = 2;
            sfSound_setVolume(game->sounds->ambiance, 100);
        }
        if (game->boole->is_music == 0 && game->secs != 2) {
            sfSound_play(game->sounds->click);
            sfSprite_setTexture(menus->music, menus->t_menu->m_off, sfFalse);
            game->boole->is_music = 1;
            sfSound_setVolume(game->sounds->ambiance, 0);
        }
    }
}

void check_sounds(global *game, menu *menus, sfVector2i mouse)
{
    if (mouse.x >= menus->pos_sounds.x && mouse.x <= menus->pos_sounds.x + 100\
    && mouse.y >= menus->pos_sounds.y && mouse.y <= menus->pos_sounds.y +\
    100 && game->event.type == sfEvtMouseButtonReleased) {
        if (game->boole->is_sounds == 1 && game->secs != 2) {
            sfSprite_setTexture(menus->sounds, menus->t_menu->s_on, sfFalse);
            game->boole->is_sounds = 0;
            game->secs = 2;
            sfSound_setVolume(game->sounds->click, 100);
            sfSound_setVolume(game->sounds->anvil, 100);
            sfSound_setVolume(game->sounds->destroy, 100);
        }
        if (game->boole->is_sounds == 0 && game->secs != 2) {
            sfSprite_setTexture(menus->sounds, menus->t_menu->s_off, sfFalse);
            game->boole->is_sounds = 1;
            sfSound_setVolume(game->sounds->click, 0);
            sfSound_setVolume(game->sounds->anvil, 0);
            sfSound_setVolume(game->sounds->destroy, 0);
        }
        sfSound_play(game->sounds->click);
    }
}
