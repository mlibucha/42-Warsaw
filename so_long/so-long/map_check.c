/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:13:14 by e                 #+#    #+#             */
/*   Updated: 2025/03/28 13:10:31 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	process_single_neighbor(t_game *g, t_bfs *b, t_bfs pos, int i)
{
	t_bfs	new;

	new.y = pos.y + b->dy[i];
	new.x = pos.x + b->dx[i];
	if (new.y >= 0 && new.y < g->map.height && new.x >= 0
		&& new.x < g->map.width && g->map.grid[new.y][new.x] != '1'
			&& !b->visited[new.y][new.x])
	{
		b->visited[new.y][new.x] = true;
		b->queue[b->rear] = (int *)malloc(sizeof(int) * 2);
		if (!b->queue[b->rear])
			return ;
		b->queue[b->rear][0] = new.y;
		b->queue[b->rear][1] = new.x;
		b->rear++;
	}
}

bool	process_neighbors(t_game *game, t_bfs *bfs, t_bfs pos)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		process_single_neighbor(game, bfs, pos, i);
		i++;
	}
	return (false);
}

static void	init_bfs_arrays(t_game *game, t_bfs *bfs)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		bfs->visited[i] = (bool *)malloc(sizeof(bool) * game->map.width);
		if (!bfs->visited[i])
			return ;
		j = 0;
		while (j < game->map.width)
			bfs->visited[i][j++] = false;
		i++;
	}
}

void	init_bfs_data(t_game *game, t_bfs *bfs, int y, int x)
{
	bfs->visited = (bool **)malloc(sizeof(bool *) * game->map.height);
	bfs->queue = (int **)malloc(sizeof(int *)
			* (game->map.height * game->map.width));
	if (!bfs->visited || !bfs->queue)
		return ;
	init_bfs_arrays(game, bfs);
	bfs->front = 0;
	bfs->rear = 0;
	bfs->visited[y][x] = true;
	bfs->queue[bfs->rear] = (int *)malloc(sizeof(int) * 2);
	bfs->queue[bfs->rear][0] = y;
	bfs->queue[bfs->rear][1] = x;
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

bool	bfs(t_game *game, t_bfs start, t_bfs target)
{
	t_bfs	bfs;
	bool	result;
	t_bfs	current;

	result = false;
	init_bfs_data(game, &bfs, start.y, start.x);
	while (bfs.front < bfs.rear && !result)
	{
		current.y = bfs.queue[bfs.front][0];
		current.x = bfs.queue[bfs.front][1];
		if (current.y == target.y && current.x == target.x)
			result = true;
		else
			process_neighbors(game, &bfs, current);
		bfs.front++;
	}
	free_bfs_data(game, &bfs);
	return (result);
}
