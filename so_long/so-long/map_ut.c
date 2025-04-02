/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:25:55 by e                 #+#    #+#             */
/*   Updated: 2025/04/02 19:35:13 by e                ###   ########.fr       */
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	a;

	a = 0;
	while ((s1[a] != '\0' || s2[a] != '\0'))
	{
		if (s1[a] != s2[a])
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		a++;
	}
	return (0);
}

int	is_valid_filename(char *filename, t_game *game)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len <= 4)
	{
		cleanup(game);
		exit (0);
	}
	if (ft_strcmp(filename + len - 4, ".ber") != 0)
	{
		cleanup(game);
		exit (0);
	}
	return (0);
}
