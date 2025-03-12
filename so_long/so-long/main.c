/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:22:33 by mlibucha          #+#    #+#             */
/*   Updated: 2025/03/11 20:33:11 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *game)
{
	int	i;
	int	y;
	int	x;
	int	totalcells;

	i = 0;
	totalcells = game->map.height * game->map.width;
	while (i < totalcells)
	{
		y = i / game->map.width;
		x = i % game->map.width;
		if (game->map.grid[y][x] == 'P')
		{
			game->player_x = x;
			game->player_y = y;
			return ;
		}
		i++;
	}
}

void	render_text(t_game *game)
{
	int		x;
	int		y;
	int		color;
	char	*str2;
	char	*str3;

	str2 = ft_itoa(game->steps);
	str3 = ft_strjoin("GAME STEPS = ", str2);
	x = (game->window_width - (ft_strlen(str3) * 10));
	y = 30;
	color = 0x00FF00;
	mlx_string_put(game->mlx, game->win, x, y, color, str3);
	free(str2);
	free(str3);
}

int	game_loop(t_game *game)
{
	update_enemy(game);
	render_map(game);
	render_text(game);
	return (0);
}

int	hook_all(t_game game)
{
	calculate_tile_size(&game);
	game.win = mlx_new_window(game.mlx, game.window_width,
			game.window_height, "so_long");
	if (!game.win)
		return (cleanup(&game), 1);
	load_textures(&game);
	init_enemy(&game);
	render_map(&game);
	colectibles(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_loop(game.mlx);
	cleanup(&game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.steps = 0;
	if (argc != 2)
	{
		printf("Error: Invalid number of arguments.\n");
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	if (!parse_map(argv[1], &game.map, &game))
		return (cleanup(&game), 1);
	find_player(&game);
	if (!is_map_solvable(&game))
	{
		printf("Error: The map is not solvable!\n");
		cleanup(&game);
		return (1);
	}
	hook_all(game);
	return (0);
}
