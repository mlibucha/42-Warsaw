/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:29:09 by e                 #+#    #+#             */
/*   Updated: 2025/04/02 13:39:52 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	int	new_y;

	new_y = game->player_y - 1;
	if (new_y >= 0 && game->map.grid[new_y][game->player_x] != '1')
	{
		if (game->map.grid[new_y][game->player_x] == 'C')
		{
			game->collected++;
			position_y(game, new_y);
		}
		else if (game->map.grid[new_y][game->player_x] == 'E')
		{
			if (game->collected == game->collectibles)
			{
				position_y(game, new_y);
				ft_printf("\033[32m""YOU WIN\n");
				cleanup(game);
				exit(0);
			}
			else
				ft_printf("You need to collect all the collectibles\n");
		}
		else
			position_y(game, new_y);
	}
}

void	move_down(t_game *game)
{
	int	new_y;

	new_y = game->player_y + 1;
	if (new_y >= 0 && game->map.grid[new_y][game->player_x] != '1')
	{
		if (game->map.grid[new_y][game->player_x] == 'C')
		{
			game->collected++;
			position_y(game, new_y);
		}
		else if (game->map.grid[new_y][game->player_x] == 'E')
		{
			if (game->collected == game->collectibles)
			{
				position_y(game, new_y);
				ft_printf("\033[32m""YOU WIN\n");
				cleanup(game);
				exit(0);
			}
			else
				ft_printf("You need to collect all the collectibles\n");
		}
		else
			position_y(game, new_y);
	}
}

void	move_left(t_game *game)
{
	int	new_x;

	new_x = game->player_x - 1;
	if (new_x < game->map.width && game->map.grid[game->player_y][new_x] != '1')
	{
		if (game->map.grid[game->player_y][new_x] == 'C')
		{
			game->collected++;
			position_x(game, new_x);
		}
		else if (game->map.grid[game->player_y][new_x] == 'E')
		{
			if (game->collected == game->collectibles)
			{
				position_y(game, new_x);
				ft_printf("\033[32m""YOU WIN\n");
				cleanup(game);
				exit(0);
			}
			else
				ft_printf("You need to collect all the collectibles\n");
		}
		else
			position_x(game, new_x);
	}
}

void	move_right(t_game *game)
{
	int	new_x;

	new_x = game->player_x + 1;
	if (new_x < game->map.width && game->map.grid[game->player_y][new_x] != '1')
	{
		if (game->map.grid[game->player_y][new_x] == 'C')
		{
			game->collected++;
			position_x(game, new_x);
		}
		else if (game->map.grid[game->player_y][new_x] == 'E')
		{
			if (game->collected == game->collectibles)
			{
				position_y(game, new_x);
				ft_printf("\033[32m""YOU WIN\n");
				cleanup(game);
				exit(0);
			}
			else
				ft_printf("You need to collect all the collectibles \n");
		}
		else
			position_x(game, new_x);
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		cleanup(game);
		exit(0);
	}
	if (keycode == 119)
		move_up(game);
	if (keycode == 115)
		move_down(game);
	if (keycode == 97)
		move_left(game);
	if (keycode == 100)
		move_right(game);
	return (0);
}
