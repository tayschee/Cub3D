/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <tbigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:28:43 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/09 14:23:18 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_screen(t_all *data)
{
	if (data->mode == 2)
		screen(data);
	if (data->twdw.print_map == 1)
		mlx_put_image_to_window(data->twdw.ptr,
		data->twdw.win, data->twdw.img_mn_ptr, 0, 0);
	else if (data->twdw.print_map == 0)
		mlx_put_image_to_window(data->twdw.ptr,
		data->twdw.win, data->twdw.img_ptr, 0, 0);
}

int			raycasting(t_all *data)
{
	view(data, data->tchar.view, long_to_orgb(WHITE));
	if (data->twdw.print_map == 0)
		print_sprite(data);
	print_screen(data);
	map_without_x(data);
	free_tvsprt(data);
	return (0);
}
