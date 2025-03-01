// #include "so_long.h"

// void calculate_tile_size(t_game *game)
// {
// 	int tile_width = WINDOW_WIDTH / game->map.width;
// 	int tile_height = WINDOW_HEIGHT / game->map.height;
// 	game->tile_size = (tile_width < tile_height) ? tile_width : tile_height;

// 	if (game->tile_size < 1)
// 	{
// 		printf("Error: Map is too large to fit within the window.\n");
// 		cleanup(game);
// 		exit(1);
// 	}
// }

// void render_map(t_game *game)
// {
// 	int x, y;
// 	int tile_size = game->tile_size;

// 	for (y = 0; y < game->map.height; y++)
// 	{
// 		for (x = 0; x < game->map.width; x++)
// 		{
// 			if (game->map.grid[y][x] == '1')
// 				mlx_put_image_to_window(game->mlx, game->win, game->wall_texture, x * tile_size, y * tile_size);
// 			else if (game->map.grid[y][x] == '0')
// 				mlx_put_image_to_window(game->mlx, game->win, game->floor_texture, x * tile_size, y * tile_size);
// 		}
// 	}
// 	// Draw the player
// 	mlx_put_image_to_window(game->mlx, game->win, game->player_texture, game->player_x * tile_size, game->player_y * tile_size);
// }