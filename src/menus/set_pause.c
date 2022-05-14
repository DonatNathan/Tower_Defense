/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to set pause menu
*/

#include "../../includes/my_defender.h"

void set_textures(global *game, menu *menus)
{
    menus->t_menu->m_on = sfTexture_createFromFile\
    ("pictures/buttons/music_on.png", NULL);
    menus->t_menu->m_off = sfTexture_createFromFile\
    ("pictures/buttons/music_off.png", NULL);
    menus->t_menu->s_on = sfTexture_createFromFile\
    ("pictures/buttons/sounds_on.png", NULL);
    menus->t_menu->s_off = sfTexture_createFromFile\
    ("pictures/buttons/sounds_off.png", NULL);
}

void set_sounds_buttons(global *game, menu *menus)
{
    sfVector2f size_music = {2, 2};
    sfVector2f size_sounds = {2, 2};

    menus->music = sfSprite_create();
    menus->sounds = sfSprite_create();
    menus->pos_music.x = 20;
    menus->pos_music.y = 10;
    menus->pos_sounds.x = 1800;
    menus->pos_sounds.y = 10;
    set_textures(game, menus);
    sfSprite_setTexture(menus->music, menus->t_menu->m_on, sfFalse);
    sfSprite_setTexture(menus->sounds, menus->t_menu->s_on, sfFalse);
    sfSprite_setPosition(menus->music, menus->pos_music);
    sfSprite_setPosition(menus->sounds, menus->pos_sounds);
    sfSprite_setScale(menus->music, size_music);
    sfSprite_setScale(menus->sounds, size_sounds);
}

void set_pos_buttons(global *game)
{
    sfVector2f scale = {0.5, 0.5};

    game->pause->p_pause->pos_back.x = 480;
    game->pause->p_pause->pos_back.y = 250;
    game->pause->p_pause->pos_con.x = game->pause->p_pause->pos_back.x + 50;
    game->pause->p_pause->pos_con.y = game->pause->p_pause->pos_back.y + 300;
    game->pause->p_pause->pos_res.x = game->pause->p_pause->pos_back.x + 360;
    game->pause->p_pause->pos_res.y = game->pause->p_pause->pos_back.y + 300;
    game->pause->p_pause->pos_quit.x = game->pause->p_pause->pos_back.x + 670;
    game->pause->p_pause->pos_quit.y = game->pause->p_pause->pos_back.y + 300;
    sfSprite_setPosition(game->pause->continu, game->pause->p_pause->pos_con);
    sfSprite_setPosition(game->pause->restart, game->pause->p_pause->pos_res);
    sfSprite_setPosition(game->pause->quit, game->pause->p_pause->pos_quit);
    sfSprite_setPosition(game->pause->back, game->pause->p_pause->pos_back);
    sfSprite_setScale(game->pause->continu, scale);
    sfSprite_setScale(game->pause->restart, scale);
    sfSprite_setScale(game->pause->quit, scale);
    sfSprite_setScale(game->pause->back, scale);
}

void set_pos_sounds(global *game, sfVector2f scale_text)
{
    game->pause->p_pause->pos_sounds.x = \
    game->pause->p_pause->pos_back.x + 880;
    game->pause->p_pause->pos_sounds.y = game->pause->p_pause->pos_back.y + 70;
    sfSprite_setPosition(game->pause->music, game->pause->p_pause->pos_music);
    sfSprite_setPosition(game->pause->sounds, \
    game->pause->p_pause->pos_sounds);
    if (game->boole->is_music == 0)
        sfSprite_setTexture(game->pause->music, game->menus->t_menu->m_on, \
        sfFalse);
    else
        sfSprite_setTexture(game->pause->music, game->menus->t_menu->m_off, \
        sfFalse);
    if (game->boole->is_sounds == 0)
        sfSprite_setTexture(game->pause->sounds, game->menus->t_menu->s_on, \
        sfFalse);
    else
        sfSprite_setTexture(game->pause->sounds, game->menus->t_menu->s_off, \
        sfFalse);
    sfText_setScale(game->pause->text, scale_text);
}

void set_pos_text(global *game)
{
    game->pause->text = sfText_create();
    sfText_setString(game->pause->text, "PAUSE");
    game->pause->p_pause->pos_text.x = game->pause->p_pause->pos_back.x + 300;
    game->pause->p_pause->pos_text.y = game->pause->p_pause->pos_back.y + 100;
    sfText_setPosition(game->pause->text, game->pause->p_pause->pos_text);
    sfText_setColor(game->pause->text, sfBlack);
}
