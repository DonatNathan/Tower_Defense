/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create our game
*/

#include "../../includes/my_defender.h"

void creatre_textures_htp(global *game)
{
    game->how_to_play->htp_1 = sfTexture_createFromFile\
    ("pictures/htp/menu_defender.png", NULL);
    game->how_to_play->htp_2 = sfTexture_createFromFile\
    ("pictures/htp/game_defender.png", NULL);
    game->how_to_play->htp_3 = sfTexture_createFromFile\
    ("pictures/htp/shop_defender.png", NULL);
    game->how_to_play->htp_4 = sfTexture_createFromFile\
    ("pictures/htp/reach_defender.png", NULL);
    game->how_to_play->htp_5 = sfTexture_createFromFile\
    ("pictures/htp/map_defender.png", NULL);
    game->how_to_play->htp_6 = sfTexture_createFromFile\
    ("pictures/htp/pause_defender.png", NULL);
    game->how_to_play->htp_7 = sfTexture_createFromFile\
    ("pictures/htp/skills_defender.png", NULL);
}

void update_htp(global *game)
{
    if (game->how_to_play->page == 1)
        sfSprite_setTexture(game->how_to_play->htp, game->how_to_play->\
        htp_1, sfFalse);
    if (game->how_to_play->page == 2)
        sfSprite_setTexture(game->how_to_play->htp, game->how_to_play->\
        htp_2, sfFalse);
    if (game->how_to_play->page == 3)
        sfSprite_setTexture(game->how_to_play->htp, game->how_to_play->\
        htp_3, sfFalse);
    if (game->how_to_play->page == 4)
        sfSprite_setTexture(game->how_to_play->htp, game->how_to_play->\
        htp_4, sfFalse);
    if (game->how_to_play->page == 5)
        sfSprite_setTexture(game->how_to_play->htp, game->how_to_play->\
        htp_5, sfFalse);
    if (game->how_to_play->page == 6)
        sfSprite_setTexture(game->how_to_play->htp, game->how_to_play->\
        htp_6, sfFalse);
    (game->how_to_play->page == 7) ? sfSprite_setTexture(game->how_to_play\
    ->htp, game->how_to_play->htp_7, sfFalse) : 1;
}

void create_htp(global *game)
{
    game->how_to_play = malloc(sizeof(how_to_play_t));
    game->how_to_play->page = 1;
    game->how_to_play->htp = sfSprite_create();
    creatre_textures_htp(game);
    game->how_to_play->position.x = 300;
    game->how_to_play->position.y = 150;
    game->how_to_play->scale.x = 0.7;
    game->how_to_play->scale.y = 0.7;
    sfSprite_setScale(game->how_to_play->htp, game->how_to_play->scale);
    sfSprite_setPosition(game->how_to_play->htp, game->how_to_play->position);
}

void change_page(global *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && game->boole->on_htp == 0 && \
    game->secs > 30) {
        sfSound_play(game->sounds->click);
        if (game->how_to_play->page > 1)
            game->how_to_play->page -= 1;
        else
            game->how_to_play->page = 7;
        game->secs = 0;
        sfClock_restart(game->clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && game->boole->on_htp == 0 && \
    game->secs > 30) {
        sfSound_play(game->sounds->click);
        if (game->how_to_play->page < 7)
            game->how_to_play->page += 1;
        else
            game->how_to_play->page = 1;
        game->secs = 0;
        sfClock_restart(game->clock);
    }
}

void test_htp(global *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyH) && game->boole->on_htp == 1 && \
        game->other_secs > 30) {
        sfSound_play(game->sounds->click);
        game->boole->on_htp = 0;
        game->other_secs = 0;
        sfClock_restart(game->clock);
    }
    if ((sfKeyboard_isKeyPressed(sfKeyEscape) || sfKeyboard_isKeyPressed\
    (sfKeyH)) && game->boole->on_htp == 0 && game->other_secs > 30) {
        sfSound_play(game->sounds->click);
        game->boole->on_htp = 1;
        game->how_to_play->page = 1;
        game->other_secs = 0;
        sfClock_restart(game->clock);
    }
    change_page(game);
}
