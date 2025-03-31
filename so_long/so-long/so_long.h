/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:00:00 by e                 #+#    #+#             */
/*   Updated: 2025/03/31 13:38:08 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <time.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		player_x;
	int		player_y;
	int		steps;
	int		collected;
	int		collectibles;
	void	*wall_texture;
	void	*floor_texture;
	void	*player_texture;
	void	*cole_texture;
	void	*exit_texture;
	int		tile_size;
	int		window_width;
	int		window_height;
	int		enemy_x;
	int		enemy_y;
	int		enemy_speed;
	int		enemy_direction;
	void	*enemy_texture;
}	t_game;

typedef struct s_bfs
{
	bool	**visited;
	int		**queue;
	int		front;
	int		rear;
	int		dy[4];
	int		dx[4];
	int		y;
	int		x;
}	t_bfs;

typedef struct s_size
{
	int		old_width;
	int		old_height;
	int		new_width;
	int		new_height;
}	t_size;

typedef struct s_texture_data
{
	char	*old_data;
	char	*new_data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_texture_data;

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
int		handle_keypress(int keycode, t_game *game);

int		count_lines(int fd, t_map *map);
int		read_map(int fd, t_map *map, t_game *game);
void	calculate_tile_size(t_game *game);
void	render_map(t_game *game);
int		parse_map(const char *filename, t_map *map, t_game *game);
void	load_textures(t_game *game);
int		cleanup(t_game *game);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*get_next_line(int fd);
void	map_name(t_game *game);
void	load_next_map(t_game *game);
void	find_player(t_game *game);

void	position_x(t_game *game, int x);
void	position_y(t_game *game, int y);

void	colectibles(t_game *game);
int		is_map_solvable(t_game *game);

void	init_enemy(t_game *game);
void	update_enemy(t_game *game);
void	render_enemy(t_game *game);
void	lose(t_game *game);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
void	free_bfs_data(t_game *game, t_bfs *bfs);
void	init_bfs_data(t_game *game, t_bfs *bfs, int y, int x);
bool	bfs(t_game *game, t_bfs start, t_bfs target);
int		check_cells(t_game *g, t_bfs player, char type);
int		borders(t_game *game);
int		is_valid_map_chars(t_game *game);
void	*ft_memset(void *s, int c, size_t n);
#endif