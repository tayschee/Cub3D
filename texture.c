/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <tbigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:29:42 by tbigot            #+#    #+#             */
/*   Updated: 2020/05/27 12:29:44 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	pos_text(t_all *data)
{
	if (data->twall.horiz)
	{
		if (data->tchar.ray > M_PI
		&& data->tchar.ray < 2 * M_PI)
			return (data->twall.x - (int)data->twall.x);
		else
			return (1 + (int)data->twall.x - data->twall.x);
	}
	else
	{
		if (data->tchar.ray < M_PI / 2
		|| data->tchar.ray > 3 * M_PI / 2)
			return (data->twall.y - (int)data->twall.y);
		else
			return (1 + (int)data->twall.y - data->twall.y);
	}
}

int		apply_text(t_all *data, double proj_wall, double start_text, int y)
{
	int		x;
	double	ratio;
	int		pos_on_img;
	int		begin_text;

	begin_text = (data->twdw.height - proj_wall) / 2 < 0
	? -(data->twdw.height - proj_wall) / 2 : 0;
	x = start_text * data->twall.width;
	ratio = data->twall.height / proj_wall;
	pos_on_img = 4 * x + data->twall.size_line *
	(int)((y + begin_text) * ratio);
	return (pos_on_img);
}
