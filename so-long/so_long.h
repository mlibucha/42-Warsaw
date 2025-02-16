#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define WINDOW_WIDTH 1500
# define WINDOW_HEIGHT 1000

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
	void	*wall_texture;
	void	*floor_texture;
	int		tile_size;
}	t_game;

int		parse_map(const char *filename, t_map *map);
void	render_map(t_game *game);
int		handle_keypress(int keycode, t_game *game);
void	cleanup(t_game *game);
void	move_up(void);
void	move_down(void);
void	move_left(void);
void	move_right(void);
char	*get_next_line(int fd);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
void	load_textures(t_game *game);
void	calculate_tile_size(t_game *game);

#endif