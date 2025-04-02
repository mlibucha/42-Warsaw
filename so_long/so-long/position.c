/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:07:44 by e                 #+#    #+#             */
/*   Updated: 2025/04/02 19:57:50 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position_x(t_game *game, int x)
{
	int	new_x;

	new_x = x;
	game->map.grid[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->map.grid[game->player_y][game->player_x] = 'P';
	game->steps++;
	ft_printf("number of steps %d\n", game->steps);
	if (game->enemy_x == game->player_x && game->enemy_y == game->player_y)
	{
		ft_printf("\033[31m""YOU LOSE\n");
		cleanup(game);
		exit(0);
	}
	render_map(game);
}

void	position_y(t_game *game, int y)
{
	int	new_y;

	new_y = y;
	game->map.grid[game->player_y][game->player_x] = '0';
	game->player_y = new_y;
	game->map.grid[game->player_y][game->player_x] = 'P';
	game->steps++;
	ft_printf("number of steps %d\n", game->steps);
	if (game->enemy_x == game->player_x && game->enemy_y == game->player_y)
	{
		ft_printf("\033[31m""YOU LOSE\n");
		cleanup(game);
		exit(0);
	}
	render_map(game);
}

void	while_y(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		if (game->map.grid[y][0] != '1' ||
			game->map.grid[y][game->map.width - 1] != '1')
		{
			write(2, "Error:\nInvalid left/right border\n", 32);
			cleanup(game);
			exit(1);
		}
		y++;
	}
	return ;
}

int	borders(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map.width)
	{
		if (game->map.grid[0][x] != '1' ||
			game->map.grid[game->map.height - 1][x] != '1')
		{
			write(2, "Error:\nInvalid top/bottom border\n", 32);
			cleanup(game);
			exit(1);
		}
		x++;
	}
	while_y(game);
	return (1);
}

int	is_valid_map_chars(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			c = game->map.grid[y][x];
			if (!(c == '0' || c == '1' || c == 'E'
					|| c == 'C' || c == 'P' || c == 'S'))
			{
				write(2, "Error:\nInvalid character in map\n", 31);
				cleanup(game);
				exit(1);
			}
			x++;
		}
		y++;
	}
	return (1);
}
