#include "so_long.h"

void	cleanup(t_game *game)
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
	if (game->wall_texture)
		mlx_destroy_image(game->mlx, game->wall_texture);
	if (game->floor_texture)
		mlx_destroy_image(game->mlx, game->floor_texture);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
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