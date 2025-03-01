/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:29:09 by e                 #+#    #+#             */
/*   Updated: 2025/03/01 15:11:23 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(t_game *game)
{
	int new_y = game->player_y - 1;
	if (game->map.grid[new_y][game->player_x] != '1')
	{
		game->map.grid[game->player_y][game->player_x] = '0'; // Clear old position
		game->player_y = new_y;
		game->map.grid[game->player_y][game->player_x] = 'P'; // Update new position
		game->steps++;
		printf("number of steps %d\n", game->steps);
		render_map(game);
	}
	// if (game->map.grid[game->player_y][new_y] == 'E')
	// 	exit_map(game);
}

void move_down(t_game *game)
{
	int new_y = game->player_y + 1;
	if (game->map.grid[new_y][game->player_x] != '1')
	{
		game->map.grid[game->player_y][game->player_x] = '0'; // Clear old position
		game->player_y = new_y;
		game->map.grid[game->player_y][game->player_x] = 'P'; // Update new position
		game->steps++;
		printf("number of steps %d\n", game->steps);
		render_map(game);
	}
	// if (game->map.grid[game->player_y][new_y] == 'E')
	// 	exit_map(game);
}

void move_left(t_game *game)
{
	int new_x = game->player_x - 1;
	if (game->map.grid[game->player_y][new_x] != '1')
	{
		game->map.grid[game->player_y][game->player_x] = '0'; // Clear old position
		game->player_x = new_x;
		game->map.grid[game->player_y][game->player_x] = 'P'; // Update new position
		game->steps++;
		printf("number of steps %d\n", game->steps);
		render_map(game);
	}
	// if (game->map.grid[game->player_y][new_x] == 'E')
	// 	exit_map(game);
}

void move_right(t_game *game)
{
	int new_x = game->player_x + 1;
	if (game->map.grid[game->player_y][new_x] != '1')
	{
		game->map.grid[game->player_y][game->player_x] = '0'; // Clear old position
		game->player_x = new_x;
		game->map.grid[game->player_y][game->player_x] = 'P'; // Update new position
		game->steps++;
		printf("number of steps %d\n", game->steps);
		render_map(game);
	}
	// if (game->map.grid[game->player_y][new_x] == 'E')
	// 	exit_map(game);
}

int handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307) // ESC key
	{
		cleanup(game);
		exit(0);
	}
	if (keycode == 119) // W key
		move_up(game);
	if (keycode == 115) // S key
		move_down(game);
	if (keycode == 97) // A key
		move_left(game);
	if (keycode == 100) // D key
		move_right(game);
	return (0);
}