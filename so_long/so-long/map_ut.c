/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:25:55 by e                 #+#    #+#             */
/*   Updated: 2025/03/28 12:22:13 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(int fd, t_map *map)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (count == 0)
			map->width = ft_strlen(line) - 1;
		free(line);
		count++;
		line = get_next_line(fd);
	}
	return (count);
}

static void	set_enemy_position(t_map *map, t_game *game, int i, char *line)
{
	int	j;

	j = 0;
	while (j < map->width)
	{
		if (line[j] == 'X')
		{
			game->enemy_x = j;
			game->enemy_y = i;
			line[j] = '0';
		}
		j++;
	}
}

int	read_map(int fd, t_map *map, t_game *game)
{
	char	*line;
	int		i;

	map->grid = (char **)malloc(sizeof(char *) * map->height);
	if (!map->grid)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->grid[i] = ft_strdup(line);
		if (!map->grid[i])
			return (0);
		set_enemy_position(map, game, i, map->grid[i]);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (1);
}
