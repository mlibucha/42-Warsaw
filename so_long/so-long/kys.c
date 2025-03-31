/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kys.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:26:08 by mlibucha          #+#    #+#             */
/*   Updated: 2025/03/30 14:17:14 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_enemy_position(t_game *game)
{
	int	i;
	int	y;
	int	x;
	int	totalcells;

	i = 0;
	totalcells = game->map.height * game->map.width;
	while (i < totalcells)
	{
		y = i / game->map.width;
		x = i % game->map.width;
		if (game->map.grid[y][x] == 'S')
		{
			game->enemy_x = x;
			game->enemy_y = y;
			return ;
		}
		i++;
	}
}

void	init_enemy(t_game *game)
{
	game->enemy_speed = 1;
	game->enemy_direction = 1;
	find_enemy_position(game);
}

static int	get_random_direction(t_game *game, int *new_x, int *new_y)
{
	static int	seeded = 0;
	int			direction;

	if (!seeded)
	{
		srand(time(NULL));
		seeded = 1;
	}
	*new_x = game->enemy_x;
	*new_y = game->enemy_y;
	direction = rand() % 4;
	if (direction == 0)
		(*new_y)--;
	else if (direction == 1)
		(*new_y)++;
	else if (direction == 2)
		(*new_x)--;
	else if (direction == 3)
		(*new_x)++;
	return (direction);
}

void	update_enemy(t_game *game)
{
	static int	frame_counter = 0;
	int			new_x;
	int			new_y;

	if (frame_counter++ % 30 != 0)
		return ;
	get_random_direction(game, &new_x, &new_y);
	if (game->enemy_x == game->player_x && game->enemy_y == game->player_y)
	{
		printf("\033[31m""YOU LOSE\n");
		cleanup(game);
		exit(0);
	}
	if (new_x >= 0 && new_x < game->map.width
		&& new_y >= 0 && new_y < game->map.height
		&& game->map.grid[new_y][new_x] != '1'
		&& game->map.grid[new_y][new_x] != 'E'
		&& game->map.grid[new_y][new_x] != 'C')
	{
		game->map.grid[game->enemy_y][game->enemy_x] = '0';
		game->enemy_x = new_x;
		game->enemy_y = new_y;
		game->map.grid[game->enemy_y][game->enemy_x] = 'S';
	}
}

void	render_enemy(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->enemy_texture,
		game->enemy_x * game->tile_size, game->enemy_y * game->tile_size);
}
