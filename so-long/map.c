#include "so_long.h"

void calculate_tile_size(t_game *game)
{
	int desired_tile_size = 64;
	game->tile_size = desired_tile_size;
	game->window_width = game->map.width * game->tile_size;
	game->window_height = game->map.height * game->tile_size;
	if (game->window_width < 1 || game->window_height < 1)
	{
		printf("Error: Map is too large to fit within the window.\n");
		cleanup(game);
		exit(1);
	}
}

void render_map(t_game *game)
{
	int x;
	int y;
	int tile_size = game->tile_size;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_texture, x * tile_size, y * tile_size);
			else if (game->map.grid[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor_texture, x * tile_size, y * tile_size);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player_texture, game->player_x * tile_size, game->player_y * tile_size);
}

static int count_lines(int fd, t_map *map)
{
	char *line;
	int count;

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

static int read_map(int fd, t_map *map)
{
	char *line;
	int i;

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

int parse_map(const char *filename, t_map *map)
{
	int fd;

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

void load_textures(t_game *game)
{
	int width;
	int height;

	game->wall_texture = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &width, &height);
	game->floor_texture = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &width, &height);
	game->player_texture = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &width, &height);
	if (!game->wall_texture || !game->floor_texture || !game->player_texture)
	{
		printf("Error: Failed to load textures.\n");
		cleanup(game);
		exit(1);
	}
}

void generate_map(t_map *map)
{
	int y = 0;
	int x;

	map->width = 20;
	map->height = 20;
	map->grid = (char **)malloc(sizeof(char *) * 20);
	while (y < 20)
	{
		map->grid[y] = (char *)malloc(sizeof(char) * (20 + 1));
		x = 0;
		while (x < 20)
		{
			if (y == 0 || y == 20 - 1 || x == 0 || x == 20 - 1)
				map->grid[y][x] = '1';
			else if (y == 2 || y == 20 - 3 || x == 2 || x == 20 - 3)
				map->grid[y][x] = '1';
			else if (y == 5 && x >= 5 && x <= 15)
				map->grid[y][x] = '1';
			else if (x == 10 && y >= 5 && y <= 15)
				map->grid[y][x] = '1';
			else
				map->grid[y][x] = '0';
			x++;
		}
		map->grid[y][20] = '\0';
		y++;
	}
}
