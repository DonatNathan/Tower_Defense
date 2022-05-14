/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to set endgame menu
*/

#include "../../includes/my_defender.h"

void draw_endgame(global *game)
{
    sfRenderWindow_drawSprite(game->window, game->endgame->back, sfFalse);
    sfRenderWindow_drawSprite(game->window, game->endgame->restart, sfFalse);
    sfRenderWindow_drawSprite(game->window, game->endgame->quit, sfFalse);
    sfRenderWindow_drawText(game->window, game->endgame->res, sfFalse);
    sfRenderWindow_drawText(game->window, game->endgame->qui, sfFalse);
    sfRenderWindow_drawText(game->window, game->endgame->end, sfFalse);
    sfRenderWindow_drawText(game->window, game->endgame->score, sfFalse);
}

void update_end(global *game)
{
    if (game->endgame->on_end == 2) {
        sfText_setString(game->endgame->end, "VICTORY !");
        game->endgame->pos_end.x = game->endgame->pos_back.x + 520;
        sfText_setColor(game->endgame->end, sfGreen);
    } else if (game->endgame->on_end == 3) {
        sfText_setString(game->endgame->end, "DEFEAT !");
        sfText_setColor(game->endgame->end, sfRed);
    }
    sfText_setPosition(game->endgame->end, game->endgame->pos_end);
    sfText_setString(game->endgame->score, my_strcat("ENEMYS KILLED : ", \
    my_itoa(game->endgame->enemy_kill)));
    sfText_setColor(game->endgame->score, sfYellow);
}

void set_texts_end(global *game)
{
    sfFont *supercell = sfFont_createFromFile("fonts/supercell.x-font-ttf");
    sfVector2f buttons_scale = {2, 2};
    sfVector2f score_scale = {3, 3};
    sfVector2f title_scale = {5, 5};

    game->endgame->res = sfText_create();
    game->endgame->qui = sfText_create();
    game->endgame->end = sfText_create();
    game->endgame->score = sfText_create();
    sfText_setFont(game->endgame->res, supercell);
    sfText_setFont(game->endgame->qui, supercell);
    sfText_setFont(game->endgame->end, supercell);
    sfText_setFont(game->endgame->score, supercell);
    sfText_setString(game->endgame->res, "RESTART (R)");
    sfText_setString(game->endgame->qui, "MENU (M)");
    sfText_setScale(game->endgame->end, title_scale);
    sfText_setScale(game->endgame->score, score_scale);
    sfText_setScale(game->endgame->qui, buttons_scale);
    sfText_setScale(game->endgame->res, buttons_scale);
}

void set_positions_end(global *game)
{
    game->endgame->pos_back.x = 0;
    game->endgame->pos_back.y = 0;
    game->endgame->pos_restart.x = game->endgame->pos_back.x + 200;
    game->endgame->pos_restart.y = game->endgame->pos_back.y + 450;
    game->endgame->pos_quit.x = game->endgame->pos_back.x + 1250;
    game->endgame->pos_quit.y = game->endgame->pos_back.y + 450;
    game->endgame->pos_res.x = game->endgame->pos_restart.x + 25;
    game->endgame->pos_res.y = game->endgame->pos_restart.y + 70;
    game->endgame->pos_qui.x = game->endgame->pos_quit.x + 75;
    game->endgame->pos_qui.y = game->endgame->pos_quit.y + 70;
    game->endgame->pos_end.x = game->endgame->pos_back.x + 600;
    game->endgame->pos_end.y = game->endgame->pos_back.y + 150;
    game->endgame->pos_score.x = game->endgame->pos_back.x + 400;
    game->endgame->pos_score.y = game->endgame->pos_back.y + 800;
    sfSprite_setPosition(game->endgame->back, game->endgame->pos_back);
    sfSprite_setPosition(game->endgame->restart, game->endgame->pos_restart);
    sfSprite_setPosition(game->endgame->quit, game->endgame->pos_quit);
}

void create_end(global *game)
{
    game->endgame = malloc(sizeof(endgame_t));
    game->endgame->on_end = 1;
    game->endgame->enemy_kill = 0;
    game->endgame->back = sfSprite_create();
    game->endgame->restart = sfSprite_create();
    game->endgame->quit = sfSprite_create();
    game->endgame->t_back = sfTexture_createFromFile\
    ("pictures/buttons/leandre2.png", NULL);
    game->endgame->t_button = sfTexture_createFromFile\
    ("pictures/buttons/button.png", NULL);
    sfSprite_setTexture(game->endgame->back, game->endgame->t_back, sfFalse);
    sfSprite_setTexture\
    (game->endgame->restart, game->endgame->t_button, sfFalse);
    sfSprite_setTexture(game->endgame->quit, game->endgame->t_button, sfFalse);
    set_texts_end(game);
    set_positions_end(game);
    sfText_setPosition(game->endgame->qui, game->endgame->pos_qui);
    sfText_setPosition(game->endgame->res, game->endgame->pos_res);
    sfText_setPosition(game->endgame->end, game->endgame->pos_end);
    sfText_setPosition(game->endgame->score, game->endgame->pos_score);
}
