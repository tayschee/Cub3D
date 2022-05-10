/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horiz_inter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:05:31 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/01 16:07:50 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		define_position_wall_horiz(t_all *data,
double posx, double posy, double v)
{
	if (what_case(data, posx, posy) == '2')
		sprite(data, posx, posy, v);
	if (what_case(data, posx, posy) == '1')
		return (1);
	return (0);
}

static void		check_next_horiz(t_all *data, int down, int right, double v)
{
	int		y_step;
	double	x_step;
	double	posx;
	double	posy;

	y_step = DIMENSION;
	y_step *= down ? 1 : -1;
	x_step = DIMENSION / tan(v);
	x_step *= !right && x_step > 0 ? -1 : 1;
	x_step *= right && x_step < 0 ? -1 : 1;
	posx = data->twall.x;
	posy = data->twall.y;
	if (!down)
		posy -= DIMENSION;
	while (posx >= 0 && posx < data->twall.size_x
	&& posy >= 0 && posy < data->twall.size_y)
	{
		if (define_position_wall_horiz(data, posx, posy, v))
			break ;
		data->twall.x += x_step;
		data->twall.y += y_step;
		posx += x_step;
		posy += y_step;
	}
}

void			check_horizontal(t_all *data, double x, double y, double v)
{
	int	down;
	int right;

	down = 0;
	right = 0;
	if (v > 0 && v < M_PI)
		down = 1;
	if ((v >= 0 && v < M_PI / 2) || (v > 1.5 * M_PI && v <= 2 * M_PI))
		right = 1;
	data->twall.y = (int)(y / DIMENSION) * DIMENSION;
	data->twall.y += down ? DIMENSION : 0;
	data->twall.x = x + ((data->twall.y - y) / tan(v));
	check_next_horiz(data, down, right, v);
}
