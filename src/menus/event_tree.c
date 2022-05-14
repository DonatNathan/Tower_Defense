/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to check event on skill's tree
*/

#include "../../includes/my_defender.h"

chained_skill_t *check_prev(global *game, int cmpt)
{
    chained_skill_t *temp = game->tree->first_skill;
    chained_skill_t *last_type = NULL;

    while (temp->next != NULL) {
        temp = temp->next;
        if (temp->type == cmpt)
            last_type = temp;
    }
    if (last_type == NULL)
        return (game->tree->first_skill);
    else
        return (last_type);
}

chained_skill_t *get_last_skill(global *game, int cmpt, int level)
{
    chained_skill_t *temp = game->tree->first_skill;

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = create_skill(game, cmpt, level);
    return (temp->next);
}

void check_mouse_tree(global *game, chained_skill_t *skill)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);
    sfVector2f scale = {1.5, 1.5};
    sfVector2f scale_basic = {1, 1};

    if (mouse.x > skill->pos_skill.x && mouse.x < skill->pos_skill.x + 100 \
    && mouse.y > skill->pos_skill.y && mouse.y < skill->pos_skill.y + 100 && \
    skill->active == 1) {
        sfSprite_setPosition(skill->skill, skill->pos_skill2);
        sfSprite_setScale(skill->skill, scale);
        if (game->event.type == sfEvtMouseButtonReleased && game->first->gold \
        >= skill->price && skill->prev->active == 0) {
            sfSound_play(game->sounds->click);
            active_bonus(game, skill);
        }
    } else {
        sfSprite_setPosition(skill->skill, skill->pos_skill);
        sfSprite_setScale(skill->skill, scale_basic);
    }
    if (skill->next != NULL)
        check_mouse_tree(game, skill->next);
}

void event_tree(global *game)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if ((sfKeyboard_isKeyPressed(sfKeyT) && game->other_secs != 0) || \
        sfKeyboard_isKeyPressed(sfKeyEscape) || (mouse.x > 1790 && mouse.x \
        < 1890 && mouse.y > 15 && mouse.y < 90 && game->event.type == \
        sfEvtMouseButtonReleased)) {
            game->boole->in_tree = 1;
            game->other_secs = 0;
            sfSound_play(game->sounds->click);
        }
        check_mouse_tree(game, game->tree->first_skill);
    }
}

void loop_tree(global *game)
{
    game->boole->in_tree = 0;
    game->other_secs = 0;
    while (sfRenderWindow_isOpen(game->window) && game->boole->in_tree == 0) {
        sfRenderWindow_drawSprite(game->window, game->tree->back, sfFalse);
        draw_skill_tree(game, game->tree->first_skill);
        event_tree(game);
        sfRenderWindow_display(game->window);
        update_game(game);
    }
}
