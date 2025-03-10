#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For time()

typedef struct s_map
{
	char **grid;
	int width;
	int height;
} t_map;

typedef struct s_game
{
	void *mlx;
	void *win;
	t_map map;
	int player_x;
	int player_y;
	int steps;
	int collected;
	int collectibles;
	void *wall_texture;
	void *floor_texture;
	void *player_texture;
	void *cole_texture;
	void *exit_texture;
	int tile_size;
	int window_width;
	int window_height;
	int enemy_x;
	int enemy_y;
	int enemy_speed;
	int end;
	int enemy_direction;
	void *enemy_texture;
} t_game;

void move_up(t_game *game);
void move_down(t_game *game);
void move_left(t_game *game);
void move_right(t_game *game);
int handle_keypress(int keycode, t_game *game);

void calculate_tile_size(t_game *game);
void render_map(t_game *game);
int parse_map(const char *filename, t_map *map, t_game *game);
void load_textures(t_game *game);
void cleanup(t_game *game);
size_t ft_strlen(const char *s);
char *ft_strdup(const char *src);
char *get_next_line(int fd);
void map_name(t_game *game);
void load_next_map(t_game *game);
void FindPlayerPosition(t_game *game);

// position.c
void position_x(t_game *game, int x);
void position_y(t_game *game, int y);

// render.c
void colelctibles(t_game *game);
int is_map_solvable(t_game *game);

//kys
void init_enemy(t_game *game);
void update_enemy(t_game *game);
void render_enemy(t_game *game);
void lose(t_game *game);

//lib
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
#endif