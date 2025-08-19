/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:22:33 by mlibucha          #+#    #+#             */
/*   Updated: 2025/07/06 10:30:53 by e                ###   ########.fr       */
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
			game->amount_p++;
		}
		i++;
	}
	if (game->amount_p != 1)
	{
		printf("ERROR INCORECT AMOUNT OF PLAYERS\n");
		cleanup(game);
	}
	return ;
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
	if (!is_map_solvable(&game))
	{
		write(2, "Error:\n The map is not solvable!\n", 33);
		cleanup(&game);
		exit (0);
	}
	calculate_tile_size(&game);
	is_valid_map_chars(&game);
	borders(&game);
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
	mlx_hook(game.win, 17, 0, cleanup, &game);
	mlx_loop(game.mlx);
	cleanup(&game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	game.steps = 0;
	if (argc != 2)
	{
		ft_printf("Error:\n Invalid number of arguments\n");
		return (1);
	}
	if (is_valid_filename(argv[1], &game))
	{
		ft_printf("Error:\n Invalid map format\n");
		return (1);
	}
	if (!parse_map(argv[1], &game.map, &game))
		return (1);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		cleanup(&game);
		return (1);
	}
	find_player(&game);
	hook_all(game);
	return (1);
}
