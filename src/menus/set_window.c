/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to set a basic window
*/

#include "../../includes/my_defender.h"

void create_sounds(global *game)
{
    game->sounds = malloc(sizeof(sounds));
    game->sounds->music = sfSoundBuffer_createFromFile("sounds/ambiance.ogg");
    game->sounds->b_anvil = sfSoundBuffer_createFromFile("sounds/anvil.ogg");
    game->sounds->b_click = sfSoundBuffer_createFromFile("sounds/click.ogg");
    game->sounds->b_destroy = sfSoundBuffer_createFromFile\
    ("sounds/destroy.ogg");
    game->sounds->ambiance = sfSound_create();
    game->sounds->anvil = sfSound_create();
    game->sounds->click = sfSound_create();
    game->sounds->destroy = sfSound_create();
    sfSound_setBuffer(game->sounds->ambiance, game->sounds->music);
    sfSound_setBuffer(game->sounds->anvil, game->sounds->b_anvil);
    sfSound_setBuffer(game->sounds->click, game->sounds->b_click);
    sfSound_setBuffer(game->sounds->destroy, game->sounds->b_destroy);
    game->sounds->is_playing = 1;
}

void check_event(global *game, menu *menus, sfVector2i mouse)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if ((game->event.type == sfEvtClosed || \
        sfKeyboard_isKeyPressed(sfKeyQ)) && game->secs != 4) {
            write_level(game);
            sfSound_play(game->sounds->click);
            sfRenderWindow_close(game->window);
        } if (sfKeyboard_isKeyPressed(sfKeyC)) {
            sfSound_play(game->sounds->click);
            start_game(game);
        } if (sfKeyboard_isKeyPressed(sfKeyR)) {
            sfSound_play(game->sounds->click);
            game->gold = game->start;
            game->price_hdv = 1000;
            game->level = 1;
            start_game(game);
        }
        check_button_quit(game, menus);
        check_sounds(game, menus, mouse);
        check_music(game, menus, mouse);
    }
}

void set_menu(global *game)
{
    sfVector2i mouse;

    set_minimap(game->menus);
    create_htp(game);
    create_bonus(game);
    while (sfRenderWindow_isOpen(game->window)) {
        mouse = sfMouse_getPosition((sfWindow *)game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        update_htp(game);
        draw_menu(game, game->menus);
        check_event(game, game->menus, mouse);
        update_game(game);
        sfRenderWindow_display(game->window);
        test_htp(game);
    }
}

void set_basic_game(global *game, int gold, int level)
{
    game->level = level;
    game->clock = sfClock_create();
    game->archer_clock = sfClock_create();
    game->boole->is_sounds = 0;
    game->boole->is_music = 0;
    game->start = gold;
    game->gold = game->start;
    game->price_hdv = 1000;
}

void create_window(int level, int gold)
{
    sfVideoMode mode = {1920, 1080, 64};
    global *game = malloc(sizeof(global));
    menu *menus = create_menu(level);

    game->boole = malloc(sizeof(boole_t));
    game->map = malloc(sizeof(map_t));
    game->window = sfRenderWindow_create\
    (mode, "My Defender", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 120);
    set_basic_game(game, gold, level);
    create_sounds(game);
    set_sounds_buttons(game, menus);
    game->menus = menus;
    game->boole->on_htp = 1;
    create_htp_button(game);
    set_menu(game);
    free_menu(game, menus);
}
