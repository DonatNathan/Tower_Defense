/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the .h of my project "my_defender"
*/

#ifndef MY_DEFENDER_H_
    #define MY_DEFENDER_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "my.h"
    #include <stdlib.h>
    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <math.h>
    #include <string.h>

typedef struct sounds {
    sfSoundBuffer *music;
    sfSound *ambiance;
    int is_playing;
    sfSoundBuffer *b_anvil;
    sfSound *anvil;
    sfSoundBuffer *b_click;
    sfSound *click;
    sfSoundBuffer *b_destroy;
    sfSound *destroy;
} sounds;

typedef struct coords {
    int dx;
    int dy;
    int original_x;
    int original_y;
} coords_t;

typedef struct grid_cell {
    coords_t *coords;
    sfSprite* ground;
    int g_pos;
    int l_pos;
    int status;
    sfCircleShape * c_1;
    sfCircleShape * c_2;
    sfCircleShape * c_3;
    sfCircleShape * c_4;
    sfCircleShape * c_5;
    sfVector2f p_1;
    sfVector2f p_2;
    sfVector2f p_3;
    sfVector2f p_4;
    sfVector2f p_5;
    struct grid_cell *first_cell;
    struct grid_cell *prev_cell;
    struct grid_cell *next_cell;
    struct grid_cell *p_next_cell;
} grid_cell;

typedef struct level_up {
    sfSprite *up;
    sfSprite *destroy;
    sfTexture *t_up;
    sfTexture *t_destroy;
    sfVector2f pos_up;
    sfVector2f pos_destroy;
    sfText *cost;
    sfVector2f pos_cost;
} level_up;

typedef struct stats_bat {
    int pv;
    int pv_max;
    float damage;
    int price;
    float attack_speed;
    char *name;
    int bat_name;
    int level;
} stats_bat;

typedef struct bullet {
    sfSprite *bullet;
    sfTexture *t_bullet;
    sfTexture *fireball;
    sfTexture *left_arrow;
    sfTexture *right_arrow;
    sfTexture *up_arrow;
    sfTexture *down_arrow;
    sfVector2f pos_bullet;
    int shot;
} bullet_t;

typedef struct lifebar {
    sfSprite *life;
    sfTexture *t_life;
    sfVector2f pos_life;
    sfIntRect rect;
} lifebar_t;

typedef struct batiment {
    bullet_t *bullet;
    lifebar_t *lifebar;
    struct batiment *first;
    struct batiment *next;
    struct batiment *prev;
    struct batiment *last;
    stats_bat *stats;
    level_up *level_up;
    sfCircleShape *radius;
    sfVector2f rad_pos;
    int rad_size;
    int type;
    int status;
    float range;
    int gold;
    sfSprite *bat;
    sfTexture *t_bat;
    sfVector2f pos;
    char *temp;
    sfText *level_str;
    sfVector2f pos_level;
    int on_bat;
    struct enemy_ * target;
    int focus;
    int hitable;
} batiment;

typedef struct mouse {
    int is_cannon;
    int is_archer;
    int is_mortar;
    int is_air;
    int is_xbow;
    int is_wizard;
} mouse_t;

typedef struct stat_shop {
    sfSprite *cannon;
    sfSprite *archer;
    sfSprite *mortar;
    sfSprite *air;
    sfSprite *xbow;
    sfSprite *wizard;
    sfTexture *t_cannon;
    sfTexture *t_archer;
    sfTexture *t_mortar;
    sfTexture *t_air;
    sfTexture *t_xbow;
    sfTexture *t_wizard;
    sfVector2f pos_cannon;
    sfVector2f pos_archer;
    sfVector2f pos_mortar;
    sfVector2f pos_air;
    sfVector2f pos_xbow;
    sfVector2f pos_wizard;
    mouse_t *mouse;
} stat_shop;

typedef struct t_shop {
    sfTexture *cannon;
    sfTexture *archer;
    sfTexture *mortar;
    sfTexture *air_defence;
    sfTexture *xbow;
    sfTexture *wizard;
    sfTexture *t_wizard;
    sfTexture *t_xbow;
    sfTexture *t_air_defence;
    sfTexture *t_mortar;
    sfTexture *t_archer;
    sfTexture *t_cannon;
    sfTexture *open;
    sfTexture *close;
} t_shop_t;

typedef struct shop {
    stat_shop *stats;
    t_shop_t *t_shop;
    sfSprite *button;
    sfVector2f pos_button_close;
    sfVector2f pos_button_open;
    sfSprite *s_cannon;
    sfSprite *s_archer;
    sfSprite *s_mortar;
    sfSprite *s_air_defence;
    sfSprite *s_xbow;
    sfSprite *s_wizard;
    sfVector2f pos_cannon;
    sfVector2f pos_archer;
    sfVector2f pos_mortar;
    sfVector2f pos_air_defence;
    sfVector2f pos_xbow;
    sfVector2f pos_wizard;
    int snap;
} shop;

typedef struct t_menu {
    sfTexture *m_on;
    sfTexture *m_off;
    sfTexture *s_on;
    sfTexture *s_off;
    sfTexture *t_battle;
    sfTexture *t_quit;
    sfTexture *t_map;
    sfTexture *t_background;
    sfFont *supercell;
} t_menu_t;

typedef struct menu {
    int level;
    t_menu_t *t_menu;
    sfSprite *music;
    sfSprite *sounds;
    sfVector2f pos_music;
    sfVector2f pos_sounds;
    sfSprite *restart;
    sfSprite *quit;
    sfSprite *map;
    sfSprite *continu;
    sfVector2f pos_continu;
    sfVector2f pos_restart;
    sfVector2f pos_quit;
    sfVector2f pos2_quit;
    sfVector2f pos_map;
    sfText *c_continu;
    sfText *c_restart;
    sfVector2f pos_con;
    sfVector2f pos_res;
    sfSprite *background;
} menu;

typedef struct p_pause {
    sfVector2f pos_c_con;
    sfVector2f pos_c_res;
    sfVector2f pos_c_quit;
    sfVector2f pos_back;
    sfVector2f pos_con;
    sfVector2f pos_res;
    sfVector2f pos_quit;
    sfVector2f pos_music;
    sfVector2f pos_sounds;
    sfVector2f pos_text;
} p_pause_t;

typedef struct menu_pause {
    p_pause_t *p_pause;
    sfSprite *music;
    sfSprite *sounds;
    sfSprite *back;
    sfSprite *quit;
    sfSprite *continu;
    sfSprite *restart;
    sfTexture *t_back;
    sfTexture *button;
    sfText *c_quit;
    sfText *c_continu;
    sfText *c_restart;
    sfText *text;
} menu_pause;

typedef struct gold {
    sfText *money;
    sfText *number;
    sfVector2f pos_money;
    sfVector2f pos_number;
    char *temp;
} gold;

typedef struct enemy_ {
    int x_size;
    int y_size;
    float old_x;
    int direction;
    lifebar_t *lifebar;
    struct enemy_ *enemy_first;
    sfSprite *enemy_1;
    sfVector2f pos;
    sfTexture *texture;
    sfTexture *mirror;
    struct enemy_ *enemy_next;
    struct enemy_ *enemy_prev;
    int number;
    int pv;
    int pv_max;
    int pv_base;
    int damage;
    int level;
    int level_hdv;
    int type;
    sfVector2f direct;
    int loc;
    int speed;
    sfVector2f e_pos;
    int reward;
    sfIntRect rect;
    float offset;
    int max_value;
    sfClock *clock;
    sfTime time;
    int seconds;
    sfClock *clock2;
    sfTime time2;
    int seconds2;
} enemy_;

typedef struct boole {
    int path_nbr;
    int click;
    int take_pos;
    int on_bat;
    int unground;
    int shop_is_open;
    int pause_is_open;
    int god;
    int is_sounds;
    int is_music;
    int on_map;
    int take;
    int on_htp;
    int in_tree;
    int ground;
} boole_t;

typedef struct map {
    sfSprite *map;
    sfTexture *t_map;
    sfVector2f p_5;
    sfVector2f pos_free;
    char **path_way;
    char *total_path;
} map_t;

typedef struct transition {
    sfSprite *clouds;
    sfSprite *clouds2;
    sfSprite *clouds3;
    sfSprite *clouds4;
    sfTexture *t_clouds;
    sfColor opacity;
    sfVector2f pos_clouds;
    sfVector2f pos_clouds2;
    sfVector2f pos_clouds3;
    sfVector2f pos_clouds4;
} transition_t;

typedef struct how_to_play {
    sfSprite *htp;
    sfTexture *htp_1;
    sfTexture *htp_2;
    sfTexture *htp_3;
    sfTexture *htp_4;
    sfTexture *htp_5;
    sfTexture *htp_6;
    sfTexture *htp_7;
    sfVector2f scale;
    sfVector2f position;
    int page;
} how_to_play_t;

typedef struct chained_skill {
    struct chained_skill *first;
    struct chained_skill *prev;
    sfSprite *skill;
    sfVector2f pos_skill;
    sfVector2f pos_skill2;
    int type;
    int value;
    int active;
    struct chained_skill *next;
    int price;
    sfText *infos;
    sfText *cost;
    sfVector2f pos_infos;
    sfVector2f scale;
    sfVector2f pos_cost;
} chained_skill_t;

typedef struct skill_tree {
    sfSprite *back;
    sfTexture *t_back;
    sfTexture *tree;
    sfTexture *sword;
    sfTexture *gold;
    sfTexture *speed;
    sfTexture *hearth;
    chained_skill_t *first_skill;
    int x;
    int y;
} skill_tree_t;

typedef struct bonus {
    int all;
    int life;
    int strenght;
    int gold;
    int speed;
} bonus_t;

typedef struct infos {
    sfText *skills;
    sfText *shop;
    sfText *pause;
    sfFont *font;
    sfText *htp;
    sfVector2f scale;
    sfVector2f pos_skills;
    sfVector2f pos_pause;
    sfVector2f pos_shop;
    sfVector2f pos_htp;
} infos_t;

typedef struct endgame {
    int on_end;
    sfSprite *back;
    sfTexture *t_back;
    sfText *end;
    int enemy_kill;
    sfSprite *restart;
    sfText *res;
    sfSprite *quit;
    sfTexture *t_button;
    sfText *qui;
    sfVector2f pos_back;
    sfVector2f pos_end;
    sfVector2f pos_restart;
    sfVector2f pos_res;
    sfVector2f pos_quit;
    sfVector2f pos_qui;
    sfText *score;
    sfVector2f pos_score;
} endgame_t;

typedef struct global {
    endgame_t *endgame;
    infos_t *infos;
    bonus_t *bonus;
    skill_tree_t *tree;
    how_to_play_t *how_to_play;
    grid_cell *path_cell;
    transition_t *transition;
    shop *shop;
    boole_t *boole;
    map_t *map;
    enemy_ *enemy;
    sounds *sounds;
    menu_pause *pause;
    menu *menus;
    gold *gold_gestion;
    batiment *first;
    sfRenderWindow *window;
    sfCircleShape * radius;
    sfEvent event;
    int level;
    int rad_god;
    sfClock *clock;
    sfTime time;
    int secs;
    int other_secs;
    sfClock *archer_clock;
    sfTime archer_tower_time;
    int archer_tower;
    char *texture;
    int gold;
    int price_hdv;
    sfColor * opacity_down;
    sfVector2i pos_mouse;
    int split;
    int start;
} global;

void open_shop(global *game, shop *my_shop);
shop *create_shop(void);
void draw_menu(global *game, menu *menus);
menu *create_menu(int level);
void start_game(global *game);
void check_button_quit(global *game, menu *menus);
void set_minimap(menu *menus);
batiment *create_hdv(global *game);
void update_game(global *game);
void set_texture_map(global *game);
batiment *add_bat(global *game, batiment *prev, sfVector2f pos, int name);
void set_music(global *game);
void set_sounds_buttons(global *game, menu *menus);
void check_sounds(global *game, menu *menus, sfVector2i mouse);
void check_music(global *game, menu *menus, sfVector2i mouse);
void create_pause(global *game);
void draw_pause(global *game);
void in_pause(global *game);
void set_menu(global *game);
void check_sounds_pause(global *game, sfVector2i mouse);
void check_music_pause(global *game, sfVector2i mouse);
void set_pos_buttons(global *game);
void set_pos_sounds(global *game, sfVector2f scale_text);
void set_pos_text(global *game);
void create_window(int level, int gold);
void check_pause_event(global *game);
void set_game(global *game);
void draw_cell(global *game, grid_cell * new, shop * my_shop);
void draw_game(global *game, shop *my_shop, grid_cell grid_cell);
void draw_structs(global *game, batiment *bat);
batiment *get_last(global *game, sfVector2f pos, int name);
void shop_event(global *game, shop *my_shop);
void click_shop(global *game, shop *my_shop, sfVector2i pos_mouse, sfVector2f \
pos_button);
void check_shop(global *game, shop *my_shop);
grid_cell *make_grid(global *game , grid_cell * grid_cell_ , shop * my_shop);
grid_cell init_cell(global *game , grid_cell grid_cell_ , shop * my_shop);
void add_cell_status(grid_cell * new, grid_cell *next_cell,\
FILE *output_file, char *path);
void drop_cannon(global *game, shop *my_shop);
void drop_archer(global *game, shop *my_shop);
void drop_mortar(global *game, shop *my_shop);
void drop_air_defence(global *game, shop *my_shop);
void drop_xbow(global *game, shop *my_shop);
void drop_wizard(global *game, shop *my_shop);
void get_cannon(global *game, shop *my_shop);
void get_archer(global *game, shop *my_shop);
void get_mortar(global *game, shop *my_shop);
void get_air_defence(global *game, shop *my_shop);
void get_xbow(global *game, shop *my_shop);
void get_wizard(global *game, shop *my_shop);
void draw_rad(global *game, batiment * bat_);
void check_hit(global *game, batiment * bat_);
void read_path(global *game);
void update_gold(global *game);
void create_gold(global *game);
int is_only(global *game, int num);
void struct_event(global *game, batiment *bat_, grid_cell grid_cell_);
void check_name(global *game, int name, batiment *bat);
void set_stats_hdv(global *game, batiment *bat);
void set_stats_cannon(global *game, batiment *bat);
void set_stats_archer(global *game, batiment *bat);
void set_stats_mortar(global *game, batiment *bat);
void draw_ground(global *game , struct grid_cell *new, shop * my_shop);
void place_struct(global *game, struct grid_cell *new, shop *my_shop);
void up_struct(global *game, batiment *bat, grid_cell grid_cell_);
void destroy_struct(global *game, batiment *bat);
void set_texture_hdv(global *game, batiment *hdv);
void create_path(global *game, grid_cell *new, shop *my_shop);
void create_stat_shop(shop *my_shop);
void snap_obj(global *game, struct grid_cell *new, shop *my_shop, sfVector2i \
pos_mouse);
void add_ground(global *game , struct grid_cell *new, shop * my_shop);
void set_enemy(global *game, struct enemy_ *enemy_f);
void check_click(global *game, struct grid_cell *grid_cell, shop *my_shop);
struct grid_cell set_all(global *game, shop *my_shop, struct grid_cell \
grid_cell, struct enemy_ *enemy_f);
void create_transition(global *game);
void moov_enemy(global *game, struct enemy_ *enemy);
void update_enemy(global * game);
void check_time(global *game, batiment *bat, grid_cell grid_cell_);
void set_pos_clouds(global *game);
void set_pos_trans(global *game);
void set_pos_dissip(global *game);
void set_pos_clouds2(global *game);
void set_pos_come(global *game);
void set_color_clouds(global *game);
void dissip_clouds(global *game, grid_cell grid_cell_);
void create_enemy(global *game, struct enemy_ *enemy, int i);
enemy_ *create_dragon(global *game, struct enemy_ *enemy, int i, enemy_ * new);
enemy_ *create_archer(global *game, struct enemy_ *enemy, int i, enemy_ * new);
enemy_ *create_goblin(global *game, struct enemy_ *enemy, int i, enemy_ * new);
enemy_ *create_giant(global *game, struct enemy_ *enemy, int i, enemy_ * new);
enemy_ *create_barbar(global *game, struct enemy_ *enemy, int i, enemy_ * new);
void detect_enemy(global *game, struct enemy_ *enemy, batiment *bat_);
void draw_enemy(global *game, struct enemy_ *enemy);
void make_dmg(global *game, batiment *bat_);
void make_dmg_archer(global *game, batiment * bat_);
void create_htp(global *game);
void event_htp(global *game);
void update_htp(global *game);
void test_htp(global *game);
void create_tree(global *game);
void loop_tree(global *game);
void create_bonus(global *game);
void create_bullet(global *game, batiment *bat);
void update_bullet(global *game, batiment *bat);
void create_infos(global *game);
void create_htp_button(global *game);
void write_level(global *game);
void add_base(global *game, struct grid_cell *new, shop *my_shop);
void update_lifebar(global *game, struct enemy_ *enemy);
void create_lifebar(global *game, struct enemy_ *enemy);
sfIntRect change_rect(sfIntRect rect, float x, float y);
void do_rect_enemy(global *game, struct enemy_ *enemy);
void free_game(global *game);
char *my_itoa(int number);
void update_lifebar_hdv(global *game, batiment *hdv);
void create_lifebar_hdv(global *game, batiment *hdv);
void create_end(global *game);
void on_endgame(global *game);
void set_enemy_pos(global *game, struct enemy_ *enemy);
void stats_barbar(global *game, enemy_ *new);
void stats_archer(global *game, enemy_ *new);
void stats_gobelin(global *game, enemy_ *new);
void stats_giant(global *game, enemy_ *new);
void stats_dragon(global *game, enemy_ *new);
void set_texture_hdv(global *game, batiment *hdv);
void create_lifebar_hdv(global *game, batiment *hdv);
void do_pause_all(global *game, sfVector2i mouse);
void check_button_event(global *game);
void event_con(global *game, sfVector2i pos_mouse);
void event_quit(global *game, sfVector2i pos_mouse);
void event_res(global *game, sfVector2i pos_mouse);
void free_menu(global *game, menu *menus);
void draw_endgame(global *game);
void update_end(global *game);
chained_skill_t *check_prev(global *game, int cmpt);
void set_string_skills(global *game, chained_skill_t *skill);
chained_skill_t *get_last_skill(global *game, int cmpt, int level);
chained_skill_t *create_skill(global *game, int cmpt, int level);
void draw_skill_tree(global *game, chained_skill_t *skill);
void active_bonus(global *game, chained_skill_t *skill);
void create_shot(global *game, batiment *bat);
void set_texture_in(global *game, batiment *bat);

#endif /* MY_DEFENDER_H_ */
