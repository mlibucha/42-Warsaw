/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:50:45 by mlibucha          #+#    #+#             */
/*   Updated: 2025/03/11 17:23:59 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	resize_texture_pixel(t_texture_data *tex, t_size *sizes)
{
	int	pos[3];
	int	old_pos[2];
	int	index[2];

	pos[0] = -1;
	while (++pos[0] < sizes->new_height)
	{
		pos[1] = -1;
		while (++pos[1] < sizes->new_width)
		{
			old_pos[0] = pos[1] * sizes->old_width / sizes->new_width;
			old_pos[1] = pos[0] * sizes->old_height / sizes->new_height;
			index[0] = (old_pos[1] * sizes->old_width + old_pos[0])
				* (tex->bpp / 8);
			index[1] = (pos[0] * sizes->new_width + pos[1]) * (tex->bpp / 8);
			pos[2] = -1;
			while (++pos[2] < (tex->bpp / 8))
				tex->new_data[index[1] + pos[2]] = tex->old_data[index[0]
					+ pos[2]];
		}
	}
}

void	*resize_texture(void *mlx, void *img, t_size *sizes)
{
	void			*new_img;
	t_texture_data	tex;

	tex.old_data = mlx_get_data_addr(img, &tex.bpp,
			&tex.size_line, &tex.endian);
	new_img = mlx_new_image(mlx, sizes->new_width, sizes->new_height);
	tex.new_data = mlx_get_data_addr(new_img, &tex.bpp,
			&tex.size_line, &tex.endian);
	resize_texture_pixel(&tex, sizes);
	mlx_destroy_image(mlx, img);
	return (new_img);
}

static void	load_single_texture(t_game *game, void **texture, char *path)
{
	t_size	sizes;

	*texture = mlx_xpm_file_to_image(game->mlx, path,
			&sizes.old_width, &sizes.old_height);
	if (!*texture)
	{
		printf("Error: Failed to load texture %s.\n", path);
		cleanup(game);
		exit(1);
	}
	sizes.new_width = game->tile_size;
	sizes.new_height = game->tile_size;
	*texture = resize_texture(game->mlx, *texture, &sizes);
}

void	load_textures(t_game *game)
{
	load_single_texture(game, &game->wall_texture, "textures/floor.xpm");
	load_single_texture(game, &game->floor_texture, "textures/wall.xpm");
	load_single_texture(game, &game->player_texture, "textures/player.xpm");
	load_single_texture(game, &game->cole_texture, "textures/cole.xpm");
	load_single_texture(game, &game->exit_texture, "textures/exit.xpm");
	load_single_texture(game, &game->enemy_texture, "textures/enemy.xpm");
}
