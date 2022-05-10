/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:44:40 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/11 17:37:02 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		draw_sky(t_all *data, int proj_wall, int x, int *orgb)
{
	int pos_on_img;
	int i;
	int k;

	i = 0;
	while (i < (int)((data->twdw.height / 2) - (proj_wall / 2)))
	{
		pos_on_img = (int)x * 4 + data->twdw.size_line
		* i;
		k = 0;
		while (k < 4)
		{
			((unsigned char *)data->twdw.img_data)
			[pos_on_img + k] = orgb[3 - k];
			k++;
		}
		i++;
	}
	free(orgb);
	return (i);
}

static void		draw_ground(t_all *data, int i, int x, int *orgb)
{
	int	pos_on_img;
	int	k;

	while (i < data->twdw.height)
	{
		pos_on_img = (int)x * 4 + data->twdw.size_line * i;
		k = 0;
		while (k < 4)
		{
			((unsigned char *)data->twdw.img_data)
			[pos_on_img + k] = orgb[3 - k];
			k++;
		}
		i++;
	}
	free(orgb);
}

static void		choice_text(t_all *data, int horiz, double angle)
{
	int	i;

	if (horiz == 1)
	{
		data->twall.text = angle < M_PI ?
		data->tmap.soc : data->tmap.noc;
		data->twall.size_line = angle < M_PI ?
		data->twdw.sl_so : data->twdw.sl_no;
		data->twall.width = angle < M_PI ?
		data->tmap.dim_so[0] : data->tmap.dim_no[0];
		data->twall.height = angle < M_PI ?
		data->tmap.dim_so[1] : data->tmap.dim_no[1];
		return ;
	}
	i = angle > M_PI / 2 && angle < 3 * M_PI / 2 ? 1 : 0;
	data->twall.text = i ? data->tmap.wec : data->tmap.eac;
	data->twall.size_line = i ? data->twdw.sl_we : data->twdw.sl_ea;
	data->twall.width = i ? data->tmap.dim_we[0] : data->tmap.dim_ea[0];
	data->twall.height = i ? data->tmap.dim_we[1] : data->tmap.dim_ea[1];
}

static int		draw_wall(t_all *data, double proj_wall, int x, int i)
{
	int pos_on_img;
	int pos_on_text;
	int k;
	int j;

	j = 0;
	while (j < proj_wall && i + j < data->twdw.height)
	{
		pos_on_img = x * 4 + data->twdw.size_line * (i + j);
		pos_on_text = apply_text(data, proj_wall, pos_text(data), j);
		k = 0;
		while (k < 4)
		{
			data->twdw.img_data[pos_on_img + k] =
			data->twall.text[pos_on_text + k];
			k++;
		}
		j++;
	}
	return (i + j);
}

void			print3d(t_all *data, int x, double angle)
{
	double	dist_proj;
	double	proj_wall;
	double	perp_dist;
	int		i;

	perp_dist = data->twall.hyp * cos(angle - data->tchar.view);
	dist_proj = DIMENSION * data->twdw.width / (2 * tan(M_PI / (3 * 2)));
	proj_wall = (DIMENSION / perp_dist) * dist_proj;
	i = draw_sky(data, proj_wall, x, long_to_orgb(data->tmap.cc));
	choice_text(data, data->twall.horiz, angle);
	i = draw_wall(data, proj_wall, x, i);
	draw_ground(data, i, x, long_to_orgb(data->tmap.fc));
}
