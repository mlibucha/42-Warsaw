/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:29:09 by e                 #+#    #+#             */
/*   Updated: 2025/02/07 17:29:11 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		cleanup(game);
		exit(0);
	}
	if (keycode == 119)
		move_up();
	if (keycode == 115)
		move_down();
	if (keycode == 97)
		move_left();
	if (keycode == 100)
		move_right();
	return (0);
}

void	move_up(void)
{
	printf("up\n");
}

void	move_down(void)
{
	printf("down\n");
}

void	move_left(void)
{
	printf("left\n");
}

void	move_right(void)
{
	printf("right\n");
}