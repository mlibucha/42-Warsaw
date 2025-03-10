/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:07:44 by e                 #+#    #+#             */
/*   Updated: 2025/03/08 14:41:14 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void position_x(t_game *game, int x)
{
	int new_x;

	new_x = x;
	game->map.grid[game->player_y][game->player_x] = '0'; // Clear old position
	game->player_x = new_x;
	game->map.grid[game->player_y][game->player_x] = 'P'; // Update new position
	game->steps++;
	printf("number of steps %d\n", game->steps);
	render_map(game);
}

void position_y(t_game *game, int y)
{
	int new_y;
	
	new_y = y;
	game->map.grid[game->player_y][game->player_x] = '0'; // Clear old position
	game->player_y = new_y;
	game->map.grid[game->player_y][game->player_x] = 'P'; // Update new position
	game->steps++;
	printf("number of steps %d\n", game->steps);
	render_map(game);
}
