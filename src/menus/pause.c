/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create pause menu
*/

#include "../../includes/my_defender.h"

void draw_pause(global *game)
{
    sfRenderWindow_drawSprite(game->window, game->pause->back, sfFalse);
    sfRenderWindow_drawSprite(game->window, game->pause->quit, sfFalse);
    sfRenderWindow_drawSprite(game->window, game->pause->restart, sfFalse);
    sfRenderWindow_drawSprite(game->window, game->pause->continu, sfFalse);
    sfRenderWindow_drawSprite(game->window, game->pause->music, sfFalse);
    sfRenderWindow_drawSprite(game->window, game->pause->sounds, sfFalse);
    sfRenderWindow_drawText(game->window, game->pause->c_quit, sfFalse);
    sfRenderWindow_drawText(game->window, game->pause->c_restart, sfFalse);
    sfRenderWindow_drawText(game->window, game->pause->c_continu, sfFalse);
    sfRenderWindow_drawText(game->window, game->pause->text, sfFalse);
}

void create_texts_pause(global *game)
{
    sfFont *font = sfFont_createFromFile("fonts/supercell.x-font-ttf");

    game->pause->c_quit = sfText_create();
    game->pause->c_restart = sfText_create();
    game->pause->c_continu = sfText_create();
    sfText_setString(game->pause->c_quit, "QUIT (Q)");
    sfText_setString(game->pause->c_restart, "RESTART (R)");
    sfText_setString(game->pause->c_continu, "CONTINUE (C)");
    sfText_setFont(game->pause->c_quit, font);
    sfText_setFont(game->pause->c_restart, font);
    sfText_setFont(game->pause->c_continu, font);
    game->pause->p_pause->pos_c_quit.x = game->pause->p_pause->pos_quit.x + 50;
    game->pause->p_pause->pos_c_quit.y = game->pause->p_pause->pos_quit.y + 35;
    game->pause->p_pause->pos_c_res.x = game->pause->p_pause->pos_res.x + 15;
    game->pause->p_pause->pos_c_res.y = game->pause->p_pause->pos_res.y + 35;
    game->pause->p_pause->pos_c_con.x = game->pause->p_pause->pos_con.x + 6;
    game->pause->p_pause->pos_c_con.y = game->pause->p_pause->pos_con.y + 35;
    set_pos_text(game);
    sfText_setFont(game->pause->text, font);
}

void set_textures_pause(global *game)
{
    sfVector2f scale_text = {3, 3};

    sfSprite_setTexture(game->pause->back, game->pause->t_back, sfFalse);
    sfSprite_setTexture(game->pause->quit, game->pause->button, sfFalse);
    sfSprite_setTexture(game->pause->continu, game->pause->button, sfFalse);
    sfSprite_setTexture(game->pause->restart, game->pause->button, sfFalse);
    set_pos_buttons(game);
    create_texts_pause(game);
    game->pause->p_pause->pos_music.x = game->pause->p_pause->pos_back.x + 30;
    game->pause->p_pause->pos_music.y = game->pause->p_pause->pos_back.y + 70;
    set_pos_sounds(game, scale_text);
}

void create_pause(global *game)
{
    game->pause = malloc(sizeof(menu_pause));
    game->pause->p_pause = malloc(sizeof(p_pause_t));
    game->pause->back = sfSprite_create();
    game->pause->quit = sfSprite_create();
    game->pause->restart = sfSprite_create();
    game->pause->continu = sfSprite_create();
    game->pause->music = sfSprite_create();
    game->pause->sounds = sfSprite_create();
    game->pause->t_back = sfTexture_createFromFile\
    ("pictures/buttons/leandre.png", NULL);
    game->pause->button = sfTexture_createFromFile\
    ("pictures/buttons/button.png", NULL);
    set_textures_pause(game);
    sfText_setPosition(game->pause->c_continu, \
    game->pause->p_pause->pos_c_con);
    sfText_setPosition(game->pause->c_restart,
    game->pause->p_pause->pos_c_res);
    sfText_setPosition(game->pause->c_quit, game->pause->p_pause->pos_c_quit);
}

void in_pause(global *game)
{
    while (sfRenderWindow_isOpen(game->window) && game->boole->pause_is_open \
    == 0) {
        draw_pause(game);
        update_gold(game);
        sfRenderWindow_display(game->window);
        check_pause_event(game);
        update_game(game);
    }
}
