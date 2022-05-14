/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create our game
*/

#include "../../includes/my_defender.h"

void draw_cell(global *game, grid_cell *new, shop *my_shop)
{
    sfRenderWindow_drawCircleShape(game->window, new->c_1, NULL);
    sfRenderWindow_drawCircleShape(game->window, new->c_2, NULL);
    sfRenderWindow_drawCircleShape(game->window, new->c_3, NULL);
    sfRenderWindow_drawCircleShape(game->window, new->c_4, NULL);
    sfRenderWindow_drawCircleShape(game->window, new->c_5, NULL);
    if (new->g_pos != 196)
        draw_cell(game, new->next_cell, my_shop);
}

void read_path(global *game)
{
    struct stat st;
    stat("src/txt/path", &st);
    int size = st.st_size;
    int level = game->level;
    char *buffer = malloc(sizeof(char) * size);
    int fd = open("src/txt/path", O_RDONLY);

    int test = read(fd, buffer, size);
    buffer[test - 1] = '\0';
    close(fd);
    char **temp_split = my_split_tab(buffer, '\n');
    game->split = my_count_split(temp_split[level - 1], '/') - 1;
    char **split_path = my_split_tab(temp_split[level - 1], '/');
    game->boole->path_nbr = my_count_split(temp_split[level - 1], '/');
    game->map->path_way = split_path;
}

void create_cell_intermediate(grid_cell *new, FILE *output_file, \
sfVector2f actual, sfVector2f next)
{
    int temp_x = my_intlen(actual.x) + 1;
    int temp_y = my_intlen(actual.y) + 1;
    int boucle = 1;
    float down_x = fabs((actual.x - (next.x)) / (float)30);
    float down_y = fabs((actual.y - (next.y)) / (float)30);

    if ((int)actual.x < (int)next.x && (int)actual.y < (int)next.y) {
        for (; boucle != 30; boucle++) {
            fwrite(my_itoa((int)new->p_5.x + down_x * boucle), 1, temp_x, \
            output_file);
            fwrite(",", 1, 1, output_file);
            fwrite(my_itoa((int)new->p_5.y + down_y * boucle), 1, temp_y, \
            output_file);
            fwrite("\n", 1, 1, output_file);
        }
    }
    if ((int)actual.x > (int)next.x && (int)actual.y > (int)next.y) {
        for (; boucle != 30; boucle++) {
            fwrite(my_itoa((int)new->p_5.x - down_x * boucle), 1, temp_x, \
            output_file);
            fwrite(",", 1, 1, output_file);
            fwrite(my_itoa((int)new->p_5.y - down_y * boucle), 1, temp_y, \
            output_file);
            fwrite("\n", 1, 1, output_file);
        }
    }
    if ((int)actual.x < (int)next.x && (int)actual.y > (int)next.y) {
        for (; boucle != 30; boucle++) {
            fwrite(my_itoa((int)new->p_5.x + down_x * boucle), 1, temp_x, \
            output_file);
            fwrite(",", 1, 1, output_file);
            fwrite(my_itoa((int)new->p_5.y - down_y * boucle), 1, temp_y, \
            output_file);
            fwrite("\n", 1, 1, output_file);
        }
    }
    if ((int)actual.x > (int)next.x && (int)actual.y < (int)next.y) {
        for (; boucle != 30; boucle++) {
            fwrite(my_itoa((int)new->p_5.x - down_x * boucle), 1, temp_x, \
            output_file);
            fwrite(",", 1, 1, output_file);
            fwrite(my_itoa((int)new->p_5.y + down_y * boucle), 1, temp_y, \
            output_file);
            fwrite("\n", 1, 1, output_file);
        }
    }
}

void add_cell_status(grid_cell *new, grid_cell *next_cell, \
FILE *output_file, char *path)
{
    int fd = open("src/txt/path", O_RDONLY);
    int temp_x = my_intlen(new->p_5.x);
    int temp_y = my_intlen(new->p_5.y);

    if (my_getnbr(path) == new->g_pos) {
        fwrite(my_itoa((int) new->p_5.x), 1, temp_x, output_file);
        fwrite(",", 1, 1, output_file);
        fwrite(my_itoa((int) new->p_5.y), 1, temp_y, output_file);
        fwrite("\n", 1, 1, output_file);
        if (new->g_pos != 196)
            create_cell_intermediate(new, output_file, new->p_5, \
            next_cell->p_5);
        new->status = 2;
    }
    if (new->status != 2)
        new->status = 1;
    close(fd);
    if (new->g_pos != 196)
        add_cell_status(new->next_cell, next_cell, output_file, path);
}
