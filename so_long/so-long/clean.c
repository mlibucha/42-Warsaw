/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:36:20 by e                 #+#    #+#             */
/*   Updated: 2025/03/31 18:20:18 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_destroy_all(t_game *game)
{
	if (game->wall_texture)
		mlx_destroy_image(game->mlx, game->wall_texture);
	if (game->floor_texture)
		mlx_destroy_image(game->mlx, game->floor_texture);
	if (game->player_texture)
		mlx_destroy_image(game->mlx, game->player_texture);
	if (game->cole_texture)
		mlx_destroy_image(game->mlx, game->cole_texture);
	if (game->exit_texture)
		mlx_destroy_image(game->mlx, game->exit_texture);
	if (game->enemy_texture)
		mlx_destroy_image(game->mlx, game->enemy_texture);
	return ;
}

int	cleanup(t_game *game)
{
	int	i;

	if (game->map.grid)
	{
		i = 0;
		while (i < game->map.height)
		{
			free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
	}
	if (game->mlx)
	{
		mlx_destroy_all(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->enemy = false;
	}
	exit (0);
}

char	*ft_strdup(const char *src)
{
	int		a;
	char	*p;

	a = 0;
	p = malloc(ft_strlen(src) + 1);
	if (p == NULL)
		return (NULL);
	while (src[a] != '\0')
	{
		p[a] = src[a];
		a++;
	}
	p[a] = '\0';
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
