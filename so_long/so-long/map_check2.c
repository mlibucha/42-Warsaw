/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:10:54 by e                 #+#    #+#             */
/*   Updated: 2025/03/28 13:06:38 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_queue(t_bfs *bfs)
{
	int	i;

	if (!bfs->queue)
		return ;
	i = 0;
	while (i < bfs->rear)
		free(bfs->queue[i++]);
	free(bfs->queue);
}

void	free_visited(t_game *game, t_bfs *bfs)
{
	int	i;

	if (!bfs->visited)
		return ;
	i = 0;
	while (i < game->map.height)
		free(bfs->visited[i++]);
	free(bfs->visited);
}

void	free_bfs_data(t_game *game, t_bfs *bfs)
{
	free_visited(game, bfs);
	free_queue(bfs);
}

int	is_map_solvable(t_game *game)
{
	t_bfs	player;

	player.y = game->player_y;
	player.x = game->player_x;
	if (!check_cells(game, player, 'C'))
		return (0);
	if (!check_cells(game, player, 'E'))
		return (0);
	return (1);
}
