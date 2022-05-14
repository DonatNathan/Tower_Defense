/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create our game
*/

#include "../../includes/my_defender.h"

void test_shop(global *game, shop *my_shop)
{
    if (game->boole->shop_is_open == 1 && sfKeyboard_isKeyPressed(sfKeyS) \
    && game->other_secs != 0) {
        sfSound_play(game->sounds->click);
        sfSprite_setTexture(my_shop->button, my_shop->t_shop->open, \
        sfFalse);
        game->boole->shop_is_open = 0;
        sfSprite_setPosition(my_shop->button, my_shop->pos_button_open);
        game->other_secs = 0;
    }
    if (game->boole->shop_is_open == 0 && sfKeyboard_isKeyPressed(sfKeyS) \
    && game->other_secs != 0) {
        sfSound_play(game->sounds->click);
        sfSprite_setTexture(my_shop->button, my_shop->t_shop->close, \
        sfFalse);
        game->boole->shop_is_open = 1;
        sfSprite_setPosition(my_shop->button, my_shop->pos_button_close);
        game->other_secs = 0;
    }
}

void personnal_test(global *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyW)) {
        game->endgame->on_end = 2;
        on_endgame(game);
    } else if (sfKeyboard_isKeyPressed(sfKeyD)) {
        game->endgame->on_end = 3;
        on_endgame(game);
    }
}

void check_game_event(global *game, shop *my_shop, grid_cell grid_cell_)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        personnal_test(game);
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        test_shop(game, my_shop);
        check_shop(game, my_shop);
        struct_event(game, game->first, grid_cell_);
        if (sfKeyboard_isKeyPressed(sfKeyT) && game->other_secs != 0) {
            sfSound_play(game->sounds->click);
            loop_tree(game);
        }
    }
}

void do_all(global *game, shop *my_shop, grid_cell grid_cell, enemy_ *enemy_f)
{
    draw_game(game, my_shop, grid_cell);
    update_enemy(game);
    draw_enemy(game, enemy_f);
    update_game(game);
    (game->boole->shop_is_open == 0) ? open_shop(game, my_shop) : 1;
    check_game_event(game, my_shop, grid_cell);
    check_click(game, &grid_cell, my_shop);
    update_gold(game);
}

void start_game(global *game)
{
    shop *my_shop = create_shop();
    struct grid_cell grid_cell;
    struct enemy_ *enemy_f = malloc(sizeof(struct enemy_));

    game->shop = malloc(sizeof(shop));
    game->shop = my_shop;
    create_end(game);
    create_transition(game);
    create_tree(game);
    grid_cell = set_all(game, my_shop, grid_cell, enemy_f);
    dissip_clouds(game, grid_cell);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        do_all(game, my_shop, grid_cell, enemy_f);
        sfRenderWindow_display(game->window);
        if (game->first->stats->pv < 0)
            on_endgame(game);
    }
}
