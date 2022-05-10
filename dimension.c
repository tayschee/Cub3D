/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:50:20 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/05 11:23:48 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_dimension(t_all *data, int map_w, int map_h)
{
	int map_size;

	map_size = data->twdw.width / map_w <= data->twdw.height / map_h ?
	data->twdw.width / map_w : data->twdw.height / map_h;
	data->twdw.dim_mini *= map_size;
	data->tchar.dim *= data->twdw.dim_mini;
}
