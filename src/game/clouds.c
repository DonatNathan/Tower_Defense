/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create clouds
*/

#include "../../includes/my_defender.h"

void update_hdv(global *game, batiment *bat)
{
    bat->stats->level += 1;
    bat->stats->price *= 1.5;
    game->price_hdv = bat->stats->price;
    game->first->next = NULL;
    game->gold = bat->gold;
    game->level += 1;
    set_texture_hdv(game, bat);
    set_texture_map(game);
    start_game(game);
}

void create_transition(global *game)
{
    sfColor opacity = {255, 255, 255, 255};

    game->transition = malloc(sizeof(transition_t));
    game->transition->clouds = sfSprite_create();
    game->transition->clouds2 = sfSprite_create();
    game->transition->clouds3 = sfSprite_create();
    game->transition->clouds4 = sfSprite_create();
    game->transition->t_clouds = sfTexture_createFromFile\
    ("pictures/maps/clouds.jpg", NULL);
    sfSprite_setTexture(game->transition->clouds, game->transition->t_clouds, \
    sfFalse);
    sfSprite_setTexture(game->transition->clouds2, \
    game->transition->t_clouds, sfFalse);
    sfSprite_setTexture(game->transition->clouds3, \
    game->transition->t_clouds, sfFalse);
    sfSprite_setTexture(game->transition->clouds4, \
    game->transition->t_clouds, sfFalse);
    game->transition->opacity = opacity;
    set_pos_trans(game);
}

void draw_clouds(global *game)
{
    sfRenderWindow_drawSprite(game->window, game->transition->clouds, \
    sfFalse);
    sfRenderWindow_drawSprite(game->window, game->transition->clouds2, \
    sfFalse);
    sfRenderWindow_drawSprite(game->window, game->transition->clouds3, \
    sfFalse);
    sfRenderWindow_drawSprite(game->window, game->transition->clouds4, \
    sfFalse);
}

void dissip_clouds(global *game, grid_cell grid_cell_)
{
    sfClock_restart(game->clock);
    game->secs = 0;
    while (game->secs < 150) {
        draw_game(game, game->shop, grid_cell_);
        draw_clouds(game);
        sfRenderWindow_display(game->window);
        update_game(game);
        if (game->transition->opacity.a - 3 >= 0) {
            game->transition->opacity.a -= 3;
            set_color_clouds(game);
        }
        set_pos_dissip(game);
        set_pos_clouds2(game);
    }
    set_pos_clouds(game);
}

void check_time(global *game, batiment *bat, grid_cell grid_cell_)
{
    game->secs = 0;
    sfClock_restart(game->clock);
    while (game->secs < 100) {
        draw_game(game, game->shop, grid_cell_);
        draw_clouds(game);
        sfRenderWindow_display(game->window);
        update_game(game);
        if (game->transition->opacity.a + 3 <= 255) {
            game->transition->opacity.a += 3;
            set_color_clouds(game);
        }
        set_pos_come(game);
        set_pos_clouds2(game);
    }
    update_hdv(game, bat);
}
