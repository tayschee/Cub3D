/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:02:51 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/11 17:29:31 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		quit_mouse(t_all *data)
{
	free_all(data, "ERROR", 0, 0);
	return (0);
}

static void		choice_screen(t_all *data, int keycode)
{
	if (keycode == TAB)
	{
		if (data->twdw.print_map == 1)
			data->twdw.print_map = 0;
		else
			data->twdw.print_map = 1;
	}
}

static int		input(int keycode, t_all *data)
{
	if (keycode == ESC)
		free_all(data, "ERROR", 0, 0);
	choice_screen(data, keycode);
	if (keycode == UP)
		check_player_position(data, SPEED * cos(data->tchar.view),
		SPEED * sin(data->tchar.view));
	if (keycode == DOWN)
		check_player_position(data, -SPEED * cos(data->tchar.view),
		SPEED * -1 * sin(data->tchar.view));
	if (keycode == LEFT)
		check_player_position(data, -SPEED * cos(data->tchar.view + M_PI / 2),
		SPEED * -1 * sin(data->tchar.view + M_PI / 2));
	if (keycode == RIGHT)
		check_player_position(data, SPEED * cos(data->tchar.view + M_PI / 2),
		SPEED * sin(data->tchar.view + M_PI / 2));
	if (keycode == ROTATE_RIGHT)
		data->tchar.view += ROTATE_SPEED;
	if (keycode == ROTATE_LEFT)
		data->tchar.view -= ROTATE_SPEED;
	trigo_pi(data->tchar.view);
	data->tchar.vvx = cos(data->tchar.view);
	data->tchar.vvy = sin(data->tchar.view);
	what_case(data, data->tchar.x, data->tchar.y);
	return (keycode);
}

void			window(char *map, t_all *data)
{
	data->twdw.ptr = mlx_init();
	parsing(map, data);
	data->twdw.img_ptr = mlx_new_image(data->twdw.ptr, data->twdw.width,
	data->twdw.height);
	data->twdw.img_data =
	mlx_get_data_addr(data->twdw.img_ptr, &data->twdw.bpp,
	&data->twdw.size_line, &data->twdw.end);
	data->twdw.img_mn_ptr =
	mlx_new_image(data->twdw.ptr, data->twdw.width, data->twdw.height);
	data->twdw.img_mn_data = mlx_get_data_addr(data->twdw.img_mn_ptr,
	&data->twdw.bpp, &data->twdw.size_line, &data->twdw.end);
	if (data->mode == 2)
		raycasting(data);
	data->twdw.win = mlx_new_window(data->twdw.ptr, data->twdw.width,
	data->twdw.height, "Cub3D");
	mlx_loop_hook(data->twdw.ptr, raycasting, data);
	mlx_hook(data->twdw.win, 17, 1L << 17, quit_mouse, data);
	mlx_hook(data->twdw.win, 2, 1, input, data);
	mlx_loop(data->twdw.ptr);
}
