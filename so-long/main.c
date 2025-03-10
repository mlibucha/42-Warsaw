#include "so_long.h"

void FindPlayerPosition(t_game *game)
{
	int i;
	int y;
	int x;
	int totalCells;

	i = 0;
	totalCells = game->map.height * game->map.width;
	while (i < totalCells)
	{
		y = i / game->map.width;
		x = i % game->map.width;
		if (game->map.grid[y][x] == 'P')
		{
			game->player_x = x;
			game->player_y = y;
			return;
		}
		i++;
	}
}

void render_text(t_game *game)
{
	int x;
	int y;
	int color;

	char *str1 = "ilość kroków = ";
	char *str2 = ft_itoa(game->steps);
	char *str3 = ft_strjoin(str1, str2);
	x = (game->window_width - (ft_strlen(str3) * 10));
	y = 30;
	color = 0x000000;
	mlx_string_put(game->mlx, game->win, x, y, color, str3);
}
int game_loop(t_game *game)
{
	update_enemy(game);
	render_map(game);
	render_text(game);
	return (0);
}

int main(int argc, char **argv)
{
	t_game game;

	game.steps = 0;
	game.collected = 0;
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
	FindPlayerPosition(&game);
	if (!is_map_solvable(&game))
	{
		printf("Error: The map is not solvable!\n");
		cleanup(&game);
		return (1);
	}
	calculate_tile_size(&game);
	game.win = mlx_new_window(game.mlx, game.window_width, game.window_height, "so_long");
	if (!game.win)
		return (cleanup(&game), 1);
	load_textures(&game);
	init_enemy(&game);
	render_map(&game);
	colelctibles(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_loop(game.mlx);
	cleanup(&game);
	return (0);
}
