/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:12:54 by e                 #+#    #+#             */
/*   Updated: 2025/03/28 13:05:43 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_single_cell(t_game *g, t_bfs player, t_bfs cell)
{
	if (g->map.grid[cell.y][cell.x] == 'C' && !bfs(g, player, cell))
		return (0);
	if (g->map.grid[cell.y][cell.x] == 'E' && !bfs(g, player, cell))
		return (0);
	return (1);
}

int	check_cells(t_game *g, t_bfs player, char type)
{
	t_bfs	cell;
	int		y;
	int		x;
	int		found;

	y = 0;
	found = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			if (g->map.grid[y][x] == type)
			{
				found = 1;
				cell.y = y;
				cell.x = x;
				if (!check_single_cell(g, player, cell))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (found);
}

void	colectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->collectibles = 0;
	game->collected = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'C')
				game->collectibles++;
			x++;
		}
		y++;
	}
}
