/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <tbigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:29:01 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/11 17:30:11 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		write_bit(int fd, char *c, int size, int repeat)
{
	char	char0;
	int		j;

	char0 = 0;
	j = 0;
	if (c)
	{
		write(fd, c, size);
		j++;
	}
	while (j < repeat)
	{
		write(fd, &char0, 1);
		j++;
	}
}

static void		write_number_in_bit(int fd, int nb, int repeat)
{
	char	c;
	int		nb2;

	while (repeat-- > 0)
	{
		nb2 = nb;
		nb2 >>= 8;
		nb2 <<= 8;
		nb2 = nb - nb2;
		nb >>= 8;
		c = nb2;
		if (!nb2)
			write_bit(fd, NULL, 1, 1);
		else
			write_bit(fd, &c, 1, 1);
	}
}

static void		bit_map_file_header(int fd)
{
	write_bit(fd, "BM", 2, 1);
	write_bit(fd, NULL, 1, 4);
	write_bit(fd, NULL, 1, 2);
	write_bit(fd, NULL, 1, 2);
	write_bit(fd, "6", 1, 4);
}

static void		bit_map_in_fo_header(int fd, int width, int height)
{
	char	c1;
	int		bpp;

	c1 = 1;
	bpp = 32;
	write_bit(fd, "(", 1, 4);
	write_number_in_bit(fd, width, 4);
	write_number_in_bit(fd, height, 4);
	write_bit(fd, &c1, 1, 2);
	write_number_in_bit(fd, bpp, 2);
	write_bit(fd, NULL, 1, 4);
	write_number_in_bit(fd, 0, 4);
	write_bit(fd, NULL, 1, 4);
	write_bit(fd, NULL, 1, 4);
	write_number_in_bit(fd, 0, 4);
	write_bit(fd, NULL, 1, 4);
}

void			screen(t_all *data)
{
	int		fd;
	char	*txt;

	fd = open("screen/Cub3D.bmp", O_RDWR | O_CREAT | O_TRUNC, 0666);
	bit_map_file_header(fd);
	bit_map_in_fo_header(fd, data->twdw.width, data->twdw.height);
	if (!(txt = ft_calloc(data->twdw.width * 4 +
	data->twdw.size_line * data->twdw.height + 1, sizeof(char))))
		free_all(data, "ERROR : malloc\n", 1, 0);
	bit_map_pixel_data(fd, data, txt);
	close(fd);
	free_all(data, "ERROR", 0, 0);
}
