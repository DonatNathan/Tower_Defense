/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create a skill
*/

#include "../../includes/my_defender.h"

void set_string_skills(global *game, chained_skill_t *skill)
{
    if (skill->type == 1)
        sfText_setString(skill->infos, my_strcat(my_strcat(new_put_nbr_str\
        (game->bonus->strenght), " + "), new_put_nbr_str(skill->value)));
    if (skill->type == 2)
        sfText_setString(skill->infos, my_strcat(my_strcat(new_put_nbr_str\
        (game->bonus->speed), " + "), new_put_nbr_str(skill->value)));
    if (skill->type == 3)
        sfText_setString(skill->infos, my_strcat(my_strcat(new_put_nbr_str\
        (game->bonus->gold), " + "), new_put_nbr_str(skill->value)));
    if (skill->type == -1)
        sfText_setString(skill->infos, my_strcat(my_strcat(new_put_nbr_str\
        (game->bonus->all), " + "), new_put_nbr_str(skill->value)));
    if (skill->type == 0)
        sfText_setString(skill->infos, my_strcat(my_strcat(new_put_nbr_str\
        (game->bonus->life), " + "), new_put_nbr_str(skill->value)));
    sfText_setString(skill->cost, \
    my_strcat(new_put_nbr_str(skill->price), " GOLD"));
}

void set_stats_skill(global *game, int cmpt, int level, \
chained_skill_t *new_skill)
{
    if (cmpt == 0) {
        new_skill->value = 10 * (level + 1);
        sfSprite_setTexture(new_skill->skill, game->tree->hearth, sfFalse);
    } if (cmpt == 1) {
        new_skill->value = 2 * (level + 1);
        sfSprite_setTexture(new_skill->skill, game->tree->sword, sfFalse);
    } if (cmpt == 2) {
        new_skill->value = 1 * (level + 1);
        sfSprite_setTexture(new_skill->skill, game->tree->speed, sfFalse);
    } if (cmpt == 3) {
        new_skill->value = 1 * (level + 1);
        sfSprite_setTexture(new_skill->skill, game->tree->gold, sfFalse);
    } if (cmpt == -1) {
        new_skill->value = 100;
        sfSprite_setTexture(new_skill->skill, game->tree->tree, sfFalse);
    }
}

void create_infos_skill(global *game, chained_skill_t *new_skill)
{
    new_skill->infos = sfText_create();
    new_skill->cost = sfText_create();
    new_skill->scale.x = 1;
    new_skill->scale.y = 1;
    new_skill->pos_infos.x = new_skill->pos_skill.x + 100;
    new_skill->pos_infos.y = new_skill->pos_skill.y + 10;
    new_skill->pos_cost.x = new_skill->pos_skill.x - 200;
    new_skill->pos_cost.y = new_skill->pos_skill.y + 10;
    sfText_setFont(new_skill->infos, game->infos->font);
    sfText_setScale(new_skill->infos, new_skill->scale);
    sfText_setPosition(new_skill->infos, new_skill->pos_infos);
    sfText_setColor(new_skill->infos, sfBlack);
    sfText_setFont(new_skill->cost, game->infos->font);
    sfText_setScale(new_skill->cost, new_skill->scale);
    sfText_setPosition(new_skill->cost, new_skill->pos_cost);
    sfText_setColor(new_skill->cost, sfYellow);
}

void set_skill(global *game, chained_skill_t *new_skill)
{
    new_skill->first = game->tree->first_skill;
    new_skill->skill = sfSprite_create();
    new_skill->next = NULL;
    new_skill->pos_skill.x = game->tree->x;
    new_skill->pos_skill.y = game->tree->y;
    new_skill->pos_skill2.x = new_skill->pos_skill.x - 14;
    new_skill->pos_skill2.y = new_skill->pos_skill.y - 14;
    new_skill->active = 1;
}

chained_skill_t *create_skill(global *game, int cmpt, int level)
{
    chained_skill_t *new_skill = malloc(sizeof(chained_skill_t));
    chained_skill_t *first = malloc(sizeof(chained_skill_t));
    sfColor unactive = {255, 255, 255, 150};

    if (cmpt == -1) {
        new_skill->prev = first;
        new_skill->prev->active = 0;
    } else
        new_skill->prev = check_prev(game, cmpt);
    set_skill(game, new_skill);
    if (level == -1)
        new_skill->price = 1000;
    else
        new_skill->price = 100 * (level + 1);
    set_stats_skill(game, cmpt, level, new_skill);
    sfSprite_setPosition(new_skill->skill, new_skill->pos_skill);
    new_skill->type = cmpt;
    sfSprite_setColor(new_skill->skill, unactive);
    create_infos_skill(game, new_skill);
    return (new_skill);
}
