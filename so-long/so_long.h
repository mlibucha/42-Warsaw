#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_map {
	char **grid;
	int width;
	int height;
	int map_number;
	const char *map[5];
} t_map;

typedef struct s_game {
	void *mlx;
	void *win;
	t_map map;
	int tile_size;
	int window_width;
	int window_height;
	int player_x;
	int player_y;
	int steps;
	void *wall_texture;
	void *floor_texture;
	void *player_texture;
} t_game;

void move_up(t_game *game);
void move_down(t_game *game);
void move_left(t_game *game);
void move_right(t_game *game);
int handle_keypress(int keycode, t_game *game);
void calculate_tile_size(t_game *game);
void render_map(t_game *game);
int parse_map(const char *filename, t_map *map);
void load_textures(t_game *game);
void cleanup(t_game *game);
size_t ft_strlen(const char *s);
char *ft_strdup(const char *src);
char *get_next_line(int fd);
void exit_map(t_game *game);
void map_name(t_game *game);
void load_next_map(t_game *game);
void FindPlayerPosition(t_game *game);
void cleanup_map(t_map *map);
#endif