/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vert_inter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:07:17 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/01 16:08:13 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		define_position_wall_vert(t_all *data,
double posx, double posy, double angle)
{
	if (what_case(data, posx, posy) == '2')
		sprite(data, posx, posy, angle);
	if (what_case(data, posx, posy) == '1')
		return (1);
	return (0);
}

static void		check_next_vert(t_all *data, int down, int right, double v)
{
	double	y_step;
	int		x_step;
	double	posx;
	double	posy;

	x_step = DIMENSION;
	x_step *= !right ? -1 : 1;
	y_step = DIMENSION * tan(v);
	y_step *= !down && y_step > 0 ? -1 : 1;
	y_step *= down && y_step < 0 ? -1 : 1;
	posx = data->twall.xbis;
	posy = data->twall.ybis;
	if (!right)
		posx -= DIMENSION;
	while (posx >= 0 && posx < data->twall.size_x
	&& posy >= 0 && posy < data->twall.size_y)
	{
		if (define_position_wall_vert(data, posx, posy, v))
			break ;
		data->twall.xbis += x_step;
		data->twall.ybis += y_step;
		posx += x_step;
		posy += y_step;
	}
}

void			check_vertical(t_all *data, double x, double y, double v)
{
	int	down;
	int right;

	down = 0;
	right = 0;
	if (v > 0 && v < M_PI)
		down = 1;
	if (v < M_PI / 2 || v > 1.5 * M_PI)
		right = 1;
	data->twall.xbis = (int)(x / DIMENSION) * DIMENSION;
	data->twall.xbis += right ? DIMENSION : 0;
	data->twall.ybis = y + ((data->twall.xbis - x) * tan(v));
	check_next_vert(data, down, right, v);
}
