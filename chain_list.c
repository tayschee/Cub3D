/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <tbigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:27:07 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/09 20:21:19 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		closest_sprite_to_further(t_all *data)
{
	t_vsprt	*point;
	t_vsprt	*begin;
	t_vsprt	*sprite;

	point = NULL;
	begin = data->tvsprt;
	while (data->tvsprt)
	{
		sprite = data->tvsprt;
		data->tvsprt = data->tvsprt->next;
		if (data->tvsprt && sprite->dist < data->tvsprt->dist)
		{
			if (begin == sprite)
				begin = data->tvsprt;
			sprite->next = data->tvsprt->next;
			data->tvsprt->next = sprite;
			if (point)
				point->next = data->tvsprt;
			data->tvsprt = begin;
			point = NULL;
		}
		else
			point = sprite;
	}
	data->tvsprt = begin;
}

void		map_without_x(t_all *data)
{
	t_vsprt	*save;

	save = data->tvsprt;
	while (data->tvsprt)
	{
		data->tmap.map[(int)data->tvsprt->y]
		[(int)data->tvsprt->x] = data->tvsprt->c;
		data->tvsprt = data->tvsprt->next;
	}
	data->tvsprt = save;
}

static void	end_of_tvsprt(t_all *data, t_vsprt **sprite)
{
	t_vsprt*save;

	save = data->tvsprt;
	while (data->tvsprt)
	{
		*sprite = data->tvsprt;
		data->tvsprt = data->tvsprt->next;
	}
	data->tvsprt = save;
}

void		free_tvsprt(t_all *data)
{
	t_vsprt		*save;
	t_vsprt		*sprite;

	sprite = data->tvsprt;
	save = data->tvsprt;
	while (data->tvsprt)
	{
		while (data->tvsprt->next)
		{
			sprite = data->tvsprt;
			data->tvsprt = data->tvsprt->next;
		}
		if (sprite == data->tvsprt)
		{
			free(data->tvsprt);
			data->tvsprt = NULL;
			break ;
		}
		else
		{
			free(sprite->next);
			sprite->next = NULL;
		}
		data->tvsprt = save;
	}
}

void		sprite(t_all *data, int posx, int posy, double v)
{
	t_vsprt		*save;
	t_vsprt		*new;
	t_vsprt		*sprt;

	sprt = NULL;
	end_of_tvsprt(data, &sprt);
	if (!(new = malloc(sizeof(t_vsprt))))
		free_all(data, "ERROR : malloc", 1, 0);
	new->x = posx / DIMENSION + (double)(DIMENSION) / 2;
	new->y = (int)(posy / DIMENSION) + (double)(DIMENSION) / 2;
	new->dist_x = data->tchar.x - new->x;
	new->dist_y = data->tchar.y - new->y;
	new->c = data->tmap.map[(int)new->y][(int)new->x];
	data->tmap.map[(int)new->y][(int)new->x] = 'X';
	new->dist = pythagore(new->dist_x, new->dist_y);
	new->angle = v;
	new->next = NULL;
	if (!sprt)
		data->tvsprt = new;
	else
		sprt->next = new;
	save = data->tvsprt;
	while (data->tvsprt)
		data->tvsprt = data->tvsprt->next;
	data->tvsprt = save;
}
