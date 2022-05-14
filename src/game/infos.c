/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to display some informations
*/

#include "../../includes/my_defender.h"

void set_all_infos(global *game)
{
    sfText_setString(game->infos->skills, "[T] SKILLS");
    sfText_setFont(game->infos->skills, game->infos->font);
    sfText_setScale(game->infos->skills, game->infos->scale);
    sfText_setPosition(game->infos->skills, game->infos->pos_skills);
    sfText_setColor(game->infos->skills, sfYellow);
    sfText_setString(game->infos->pause, "[ESCAPE] PAUSE");
    sfText_setFont(game->infos->pause, game->infos->font);
    sfText_setScale(game->infos->pause, game->infos->scale);
    sfText_setPosition(game->infos->pause, game->infos->pos_pause);
    sfText_setColor(game->infos->pause, sfYellow);
    sfText_setString(game->infos->shop, "[S] SHOP");
    sfText_setFont(game->infos->shop, game->infos->font);
    sfText_setScale(game->infos->shop, game->infos->scale);
    sfText_setPosition(game->infos->shop, game->infos->pos_shop);
    sfText_setColor(game->infos->shop, sfYellow);
}

void create_infos(global *game)
{
    game->infos->pos_skills.x = 1700;
    game->infos->pos_skills.y = 900;
    game->infos->pos_pause.x = 1600;
    game->infos->pos_pause.y = 950;
    game->infos->pos_shop.x = 1700;
    game->infos->pos_shop.y = 850;
    game->infos->skills = sfText_create();
    game->infos->shop = sfText_create();
    game->infos->pause = sfText_create();
    set_all_infos(game);
}

void create_htp_button(global *game)
{
    game->infos = malloc(sizeof(infos_t));
    game->infos->font = sfFont_createFromFile("fonts/supercell.x-font-ttf");
    game->infos->scale.x = 1;
    game->infos->scale.y = 1;
    game->infos->pos_htp.x = 810;
    game->infos->pos_htp.y = 980;
    game->infos->htp = sfText_create();
    sfText_setString(game->infos->htp, "[H] HOW TO PLAY");
    sfText_setFont(game->infos->htp, game->infos->font);
    sfText_setScale(game->infos->htp, game->infos->scale);
    sfText_setPosition(game->infos->htp, game->infos->pos_htp);
    sfText_setColor(game->infos->htp, sfYellow);
}

void write_level(global *game)
{
    int fd = open("src/txt/level", O_WRONLY);

    if (game->level < 10)
        write(fd, my_strcat("0", new_put_nbr_str(game->level)), 2);
    else
        write(fd, new_put_nbr_str(game->level), 1);
    close(fd);
}
