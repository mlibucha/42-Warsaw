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

int main(int argc, char **argv)
{
	t_game game;
	game.steps = 0;
	if(argc != 2)
	{
		printf("Error: Invalid number of arguments.\n");
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	if (!parse_map(argv[1], &game.map))
		return (cleanup(&game), 1);
	calculate_tile_size(&game);
	game.win = mlx_new_window(game.mlx, game.window_width, game.window_height, "so_long");
	if (!game.win)
		return (cleanup(&game), 1);
	FindPlayerPosition(&game);
	load_textures(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_loop(game.mlx);
	cleanup(&game);
	return (0);
}
