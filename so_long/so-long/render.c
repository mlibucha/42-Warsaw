/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:12:54 by e                 #+#    #+#             */
/*   Updated: 2025/03/11 20:32:58 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_bfs_data(t_game *game, t_bfs *bfs, int start_y, int start_x)
{
	int	i;
	int	j;

	bfs->visited = (bool **)malloc(sizeof(bool *) * game->map.height);
	bfs->queue = (int **)malloc(sizeof(int *) * (game->map.height
				* game->map.width));
	i = 0;
	while (i < game->map.height)
	{
		bfs->visited[i] = (bool *)malloc(sizeof(bool) * game->map.width);
		j = 0;
		while (j < game->map.width)
		{
			bfs->visited[i][j] = false;
			j++;
		}
		i++;
	}
	bfs->front = 0;
	bfs->rear = 0;
	bfs->visited[start_y][start_x] = true;
	bfs->queue[bfs->rear] = (int *)malloc(sizeof(int) * 2);
	bfs->queue[bfs->rear][0] = start_y;
	bfs->queue[bfs->rear][1] = start_x;
	bfs->rear++;
	bfs->dy[0] = -1;
	bfs->dy[1] = 1;
	bfs->dy[2] = 0;
	bfs->dy[3] = 0;
	bfs->dx[0] = 0;
	bfs->dx[1] = 0;
	bfs->dx[2] = -1;
	bfs->dx[3] = 1;
}

bool	process_neighbors(t_game *game, t_bfs *bfs, int y, int x)
{
	int	i;
	int	new_y;
	int	new_x;

	i = 0;
	while (i < 4)
	{
		new_y = y + bfs->dy[i];
		new_x = x + bfs->dx[i];
		if (new_y >= 0 && new_y < game->map.height && new_x >= 0
			&& new_x < game->map.width && game->map.grid[new_y][new_x] != '1'
			&& !bfs->visited[new_y][new_x])
		{
			bfs->visited[new_y][new_x] = true;
			bfs->queue[bfs->rear] = (int *)malloc(sizeof(int) * 2);
			bfs->queue[bfs->rear][0] = new_y;
			bfs->queue[bfs->rear][1] = new_x;
			bfs->rear++;
		}
		i++;
	}
	return (false);
}

bool	bfs(t_game *game, int start_y, int start_x, int target_y, int target_x)
{
	t_bfs	bfs;
	int		y;
	int		x;

	init_bfs_data(game, &bfs, start_y, start_x);
	while (bfs.front < bfs.rear)
	{
		y = bfs.queue[bfs.front][0];
		x = bfs.queue[bfs.front][1];
		bfs.front++;
		if (y == target_y && x == target_x)
			return (true);
		process_neighbors(game, &bfs, y, x);
	}
	return (false);
}

static int	check_collectibles(t_game *game, int player_y, int player_x)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'C'
					&& !bfs(game, player_y, player_x, y, x))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	check_exit(t_game *game, int player_y, int player_x)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'E'
					&& !bfs(game, player_y, player_x, y, x))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_map_solvable(t_game *game)
{
	int	player_y;
	int	player_x;

	player_y = game->player_y;
	player_x = game->player_x;
	if (!check_collectibles(game, player_y, player_x))
		return (0);
	if (!check_exit(game, player_y, player_x))
		return (0);
	return (1);
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
