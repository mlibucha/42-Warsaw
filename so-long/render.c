#include "so_long.h"

void	colelctibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->collectibles = 0;
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

static void	init_bfs(t_game *game, bool visited[game->map.height][game->map.width])
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
			visited[i][j++] = false;
		i++;
	}
}

static bool	bfs(t_game *game, int start_y, int start_x, int target_y, int target_x)
{
	bool	visited[game->map.height][game->map.width];
	int		queue[game->map.height * game->map.width][2];
	int		front;
	int		rear;
	int		dy[4];
	int		dx[4];
	int		y;
	int		x;
	int		i;

	init_bfs(game, visited);
	front = 0;
	rear = 0;
	visited[start_y][start_x] = true;
	queue[rear][0] = start_y;
	queue[rear][1] = start_x;
	rear++;
	dy[0] = -1;
	dy[1] = 1;
	dy[2] = 0;
	dy[3] = 0;
	dx[0] = 0;
	dx[1] = 0;
	dx[2] = -1;
	dx[3] = 1;
	while (front < rear)
	{
		y = queue[front][0];
		x = queue[front][1];
		front++;
		if (y == target_y && x == target_x)
			return (true);
		i = 0;
		while (i < 4)
		{
			int new_y = y + dy[i];
			int new_x = x + dx[i];
			if (new_y >= 0 && new_y < game->map.height && new_x >= 0
				&& new_x < game->map.width && game->map.grid[new_y][new_x] != '1'
				&& !visited[new_y][new_x])
			{
				visited[new_y][new_x] = true;
				queue[rear][0] = new_y;
				queue[rear][1] = new_x;
				rear++;
			}
			i++;
		}
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
			if (game->map.grid[y][x] == 'C' && !bfs(game, player_y, player_x, y, x))
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
			if (game->map.grid[y][x] == 'E' && !bfs(game, player_y, player_x, y, x))
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