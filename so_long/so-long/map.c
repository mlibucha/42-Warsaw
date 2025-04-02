/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:47:55 by mlibucha          #+#    #+#             */
/*   Updated: 2025/04/02 19:57:26 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_tile_size(t_game *game)
{
	int	max_tile_size;
	int	screen_width;
	int	screen_height;

	max_tile_size = 64;
	screen_width = 1920;
	screen_height = 1080;
	game->tile_size = max_tile_size;
	while (game->map.width * game->tile_size > screen_width
		|| game->map.height * game->tile_size > screen_height)
	{
		game->tile_size -= 8;
		if (game->tile_size < 16)
		{
			ft_printf("Error:\nMap is too large to fit within the window.\n");
			cleanup(game);
			exit(1);
		}
	}
	game->window_width = game->map.width * game->tile_size;
	game->window_height = game->map.height * game->tile_size;
}

void	x_while(t_game *game, int y)
{
	int	x;
	int	tile_size;

	tile_size = game->tile_size;
	x = 0;
	while (x < game->map.width)
	{
		if (game->map.grid[y][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win,
				game->wall_texture, x * tile_size, y * tile_size);
		else if (game->map.grid[y][x] == '0')
			mlx_put_image_to_window(game->mlx, game->win,
				game->floor_texture, x * tile_size, y * tile_size);
		else if (game->map.grid[y][x] == 'C')
			mlx_put_image_to_window(game->mlx, game->win,
				game->cole_texture, x * tile_size, y * tile_size);
		else if (game->map.grid[y][x] == 'E')
			mlx_put_image_to_window(game->mlx, game->win,
				game->exit_texture, x * tile_size, y * tile_size);
		x++;
	}
	return ;
}

void	render_map(t_game *game)
{
	int	y;
	int	tile_size;

	tile_size = game->tile_size;
	y = 0;
	while (y < game->map.height)
	{
		x_while(game, y);
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player_texture,
		game->player_x * tile_size, game->player_y * tile_size);
	render_enemy(game);
}

int	parse_map(const char *filename, t_map *map, t_game *game)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error:\nThere is no map named like that\n", 40);
		cleanup(game);
		exit (1);
	}
	map->height = count_lines(fd, map);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || !read_map(fd, map, game))
		return (close(fd), 0);
	close(fd);
	return (1);
}
