/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <tbigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:27:58 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/09 17:11:11 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		free_all2(t_all *all)
{
	if (all->tmap.we)
		mlx_destroy_image(all->twdw.ptr, all->tmap.we);
	if (all->tmap.ea)
		mlx_destroy_image(all->twdw.ptr, all->tmap.ea);
	if (all->tsprt.s)
		mlx_destroy_image(all->twdw.ptr, all->tsprt.s);
	if (all->tmap.map)
		free_malloc_2d(all->tmap.map);
	if (all->tsprt.wray)
		free(all->tsprt.wray);
	if (all->tvsprt)
		free_tvsprt(all);
	if (all->twdw.ptr)
	{
		if (!all->twdw.win)
			free(all->twdw.ptr);
		else
			mlx_destroy_window(all->twdw.ptr, all->twdw.win);
	}
	free(all);
}

void			free_all(t_all *all, char *msg, int i, int line)
{
	int	j;

	if (all)
	{
		if (line)
			free(all->line);
		if (all->twdw.img_ptr)
			mlx_destroy_image(all->twdw.ptr, all->twdw.img_ptr);
		if (all->twdw.img_mn_ptr)
			mlx_destroy_image(all->twdw.ptr, all->twdw.img_mn_ptr);
		if (all->tmap.no)
			mlx_destroy_image(all->twdw.ptr, all->tmap.no);
		if (all->tmap.so)
			mlx_destroy_image(all->twdw.ptr, all->tmap.so);
		free_all2(all);
	}
	if (i == 1)
	{
		j = ft_strlen(msg);
		write(i, msg, j);
	}
	exit(i);
}
