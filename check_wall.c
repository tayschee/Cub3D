/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:00:20 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/12 11:58:37 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	what_case(t_all *data, double x, double y)
{
	return (data->tmap.map[(int)(y)][(int)(x)]);
}

int		check_player_position(t_all *data, double vx, double vy)
{
	double	x;
	double	y;
	double	angle;

	data->tchar.vx = vx;
	data->tchar.vy = vy;
	angle = -M_PI / 2;
	x = data->tchar.x + vx;
	y = data->tchar.y + vy;
	while (angle < M_PI / 2)
	{
		if (data->tmap.map[(int)(y + (DIMENSION_PLAYER / 2)
		* (vy + sin(angle)) / DIMENSION)]
		[(int)(x + (DIMENSION_PLAYER / 2) * (vx + cos(angle)))
		/ DIMENSION] == '1')
			return (0);
		angle += M_PI / 6;
	}
	data->tchar.x = x;
	data->tchar.y = y;
	data->tchar.vvx = vx;
	data->tchar.vvy = vy;
	return (0);
}
