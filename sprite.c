/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <tbigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:29:26 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/03 18:36:30 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	verif_black(t_all *data, int pos_on_text, char *txt, int x)
{
	int i;

	i = 0;
	if (data->tsprt.wray[x + data->tsprt.left]
	< data->tvsprt->dist)
		return (-1);
	while (i < 3)
	{
		if (((unsigned char *)txt)[pos_on_text + i] != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ratio_text(t_all *data, int x, int y, int pos_on_img)
{
	double	ratio_x;
	double	ratio_y;
	int		pos_on_text;
	int		k;
	int		ret;

	k = 0;
	ratio_x = (double)data->tsprt.dim_s[0] / data->twall.size;
	ratio_y = (double)data->tsprt.dim_s[1] / data->twall.size;
	pos_on_text = (int)(ratio_x * x) * 4 +
	data->tsprt.sl_s * (int)(y * ratio_y);
	if (!(ret = verif_black(data, pos_on_text, data->tsprt.sc, x)))
	{
		while (k < 4)
		{
			data->twdw.img_data[pos_on_img + k] =
			data->tsprt.sc[pos_on_text + k];
			k++;
		}
	}
	return (ret);
}

static void	apply_sprite_text(t_all *data, int top, int left,
double sprite_size)
{
	int x;
	int y;
	int pos_on_img;

	x = left < 0 ? -left : 0;
	x = x < 0 ? 0 : x;
	x = 0;
	data->tsprt.left = left;
	data->twall.size = sprite_size;
	while (x < sprite_size && x + left < data->twdw.width)
	{
		if (x + left >= 0)
		{
			y = top < 0 ? -top : 0;
			while (y < sprite_size && y + top < data->twdw.height)
			{
				pos_on_img = (x + left) * 4 + data->twdw.size_line
				* (y + top);
				ratio_text(data, x, y, pos_on_img);
				y++;
			}
		}
		x++;
	}
}

static void	define_position_sprite_on_window(t_all *data)
{
	double	sprite_dir;
	double	sprite_size;
	int		top_sprt;
	int		left_sprt;

	sprite_dir = atan2(data->tvsprt->y - data->tchar.y,
	data->tvsprt->x - data->tchar.x);
	while (sprite_dir - data->tchar.view > M_PI)
		sprite_dir -= 2 * M_PI;
	while (sprite_dir - data->tchar.view < -M_PI)
		sprite_dir += 2 * M_PI;
	data->tvsprt->dist *= cos((sprite_dir - data->tchar.view));
	sprite_size = data->twdw.width / data->tvsprt->dist;
	left_sprt = tan(sprite_dir - data->tchar.view)
	* data->twdw.width / (M_PI / 3) + (data->twdw.width / 2 - sprite_size / 2);
	top_sprt = data->twdw.height / 2 - sprite_size / 2;
	apply_sprite_text(data, top_sprt, left_sprt, sprite_size);
}

void		print_sprite(t_all *data)
{
	t_vsprt		*begin;

	closest_sprite_to_further(data);
	begin = data->tvsprt;
	while (data->tvsprt)
	{
		define_position_sprite_on_window(data);
		data->tvsprt = data->tvsprt->next;
	}
	data->tvsprt = begin;
}
