/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create my clock
*/

#include "../../includes/my_defender.h"

void set_music(global *game)
{
    sfSound_setLoop(game->sounds->ambiance, sfTrue);
    sfSound_play(game->sounds->ambiance);
}

void update_game(global *game)
{
    game->archer_tower_time = sfClock_getElapsedTime(game->archer_clock);
    game->archer_tower = game->archer_tower_time.microseconds / 5000.0;
    game->time = sfClock_getElapsedTime(game->clock);
    game->secs = game->time.microseconds / 5000.0;
    game->other_secs = game->time.microseconds / 5000.0;
}

void update_enemy(global *game)
{
    if (game->secs > 2) {
        moov_enemy(game, game->enemy->enemy_next);
        sfClock_restart(game->clock);
    }
    if (game->archer_tower > 300) {
        make_dmg_archer(game, game->first);
        sfClock_restart(game->archer_clock);
    }
}
