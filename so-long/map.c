#include "so_long.h"

void	calculate_tile_size(t_game *game)
{
	int	tile_width;
	int	tile_height;

	tile_width = WINDOW_WIDTH / game->map.width;
	tile_height = WINDOW_HEIGHT / game->map.height;
	game->tile_size = (tile_width < tile_height) ? tile_width : tile_height;
	if (game->tile_size > 64)
		game->tile_size = 64;
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	tile_size;

	tile_size = game->tile_size;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_texture,
					x * tile_size, y * tile_size);
			else if (game->map.grid[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor_texture,
					x * tile_size, y * tile_size);
			x++;
		}
		y++;
	}
}

static int	count_lines(int fd, t_map *map)
{
	char	*line;
	int		count;

	count = 0;
	while ((line = get_next_line(fd)))
	{
		if (count == 0)
			map->width = ft_strlen(line) - 1;
		free(line);
		count++;
	}
	return (count);
}

static int	read_map(int fd, t_map *map)
{
	char	*line;
	int		i;

	map->grid = (char **)malloc(sizeof(char *) * map->height);
	if (!map->grid)
		return (0);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		map->grid[i] = ft_strdup(line);
		free(line);
		if (!map->grid[i])
			return (0);
		i++;
	}
	return (1);
}

int	parse_map(const char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	map->height = count_lines(fd, map);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || !read_map(fd, map))
		return (close(fd), 0);
	close(fd);
	return (1);
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->wall_texture = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &width, &height);
	if (!game->wall_texture)
	{
		printf("Error: Failed to load wall texture.\n");
		cleanup(game);
		exit(1);
	}
	game->floor_texture = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &width, &height);
	if (!game->floor_texture)
	{
		printf("Error: Failed to load floor texture.\n");
		cleanup(game);
		exit(1);
	}
}