/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:01:35 by e                 #+#    #+#             */
/*   Updated: 2025/02/04 13:20:55 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define ESC_KEY 53

int handle_keypress(int keycode, void *param)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(param, *(void **)param);
		exit(0);
	}
	return 0;
}

int main(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "MiniLibX Window");
	if (!win)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (1);
	}
	mlx_hook(win, 2, 1L << 0, handle_keypress, mlx);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	return 0;
}
