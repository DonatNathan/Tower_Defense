/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to set the tree skill
*/

#include "../../includes/my_defender.h"

void draw_skill_tree(global *game, chained_skill_t *skill)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    if (mouse.x > skill->pos_skill.x && mouse.x < skill->pos_skill.x + 100 \
    && mouse.y > skill->pos_skill.y && mouse.y < skill->pos_skill.y + 100 && \
    skill->active == 1) {
        set_string_skills(game, skill);
        sfRenderWindow_drawText(game->window, skill->infos, sfFalse);
        sfRenderWindow_drawText(game->window, skill->cost, sfFalse);
    }
    sfRenderWindow_drawSprite(game->window, skill->skill, sfFalse);
    if (skill->next != NULL) {
        draw_skill_tree(game, skill->next);
    }
}

void set_texture_tree(global *game)
{
    game->tree->hearth = sfTexture_createFromFile\
    ("pictures/buttons/hearth.png", NULL);
    game->tree->tree = sfTexture_createFromFile\
    ("pictures/buttons/tree.png", NULL);
    game->tree->sword = sfTexture_createFromFile\
    ("pictures/buttons/sword.png", NULL);
    game->tree->speed = sfTexture_createFromFile\
    ("pictures/buttons/speed.png", NULL);
    game->tree->gold = sfTexture_createFromFile\
    ("pictures/buttons/gold.png", NULL);
}

void create_bonus(global *game)
{
    game->bonus = malloc(sizeof(bonus_t));
    game->bonus->all = 0;
    game->bonus->gold = 0;
    game->bonus->life = 0;
    game->bonus->speed = 0;
    game->bonus->strenght = 0;
}

void create_tree(global *game)
{
    game->tree = malloc(sizeof(skill_tree_t));
    game->tree->back = sfSprite_create();
    game->tree->t_back = sfTexture_createFromFile\
    ("pictures/buttons/leandre.png", NULL);
    set_texture_tree(game);
    sfSprite_setTexture(game->tree->back, game->tree->t_back, sfFalse);
    game->tree->x = 900;
    game->tree->y = 200;
    game->tree->first_skill = create_skill(game, -1, -1);
    game->tree->y = 300;
    game->tree->x = 150;
    for (int level = 0; level < 7; level += 1) {
        for (int cmpt = 0; cmpt < 4; cmpt += 1) {
            game->tree->x += 300;
            get_last_skill(game, cmpt, level);
        }
        game->tree->y += 100;
        game->tree->x = 150;
    }
}

void active_bonus(global *game, chained_skill_t *skill)
{
    sfColor active = {255, 255, 255, 255};

    skill->active = 0;
    sfSprite_setColor(skill->skill, active);
    game->first->gold -= skill->price;
    if (skill->type == 0)
        game->bonus->life += skill->value;
    if (skill->type == 1)
        game->bonus->strenght += skill->value;
    if (skill->type == 2)
        game->bonus->speed += skill->value;
    if (skill->type == 3)
        game->bonus->gold += skill->value;
    if (skill->type == -1)
        game->bonus->all += skill->value;
}
