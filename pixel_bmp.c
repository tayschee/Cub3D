/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <tbigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:28:23 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/09 20:27:46 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bit_map_pixel_data(int fd, t_all *data, char *txt)
{
	int pos_on_img;
	int x;
	int y;
	int k;
	int max;

	y = data->twdw.height - 1;
	max = 0;
	while (y >= 0)
	{
		x = 0;
		while (x < data->twdw.width)
		{
			pos_on_img = x * 4 + y * data->twdw.size_line;
			k = -1;
			while (++k < 4)
				txt[max++] = data->twdw.img_data[pos_on_img + k];
			x++;
		}
		y--;
	}
	write(fd, txt, data->twdw.width * 4 + data->twdw.size_line
	* data->twdw.height);
}
