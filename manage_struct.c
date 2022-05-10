/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:37:08 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/03 19:05:35 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map	initialise_struct_map(void)
{
	t_map	map;

	map.no = NULL;
	map.so = NULL;
	map.we = NULL;
	map.ea = NULL;
	map.noc = NULL;
	map.soc = NULL;
	map.wec = NULL;
	map.eac = NULL;
	map.fc = -1;
	map.cc = -1;
	map.map = NULL;
	map.dim_no[0] = 0;
	map.dim_no[1] = 0;
	map.dim_so[0] = 0;
	map.dim_so[1] = 0;
	map.dim_we[0] = 0;
	map.dim_we[1] = 0;
	map.dim_ea[0] = 0;
	map.dim_ea[1] = 0;
	return (map);
}

static t_wdw	initialise_struct_wdw(void)
{
	t_wdw	wdw;

	wdw.ptr = NULL;
	wdw.win = NULL;
	wdw.height = -1;
	wdw.width = -1;
	wdw.x = 0;
	wdw.y = 0;
	wdw.bpp = 32;
	wdw.size_line = 0;
	wdw.sl_no = 0;
	wdw.sl_so = 0;
	wdw.sl_we = 0;
	wdw.sl_ea = 0;
	wdw.end = 0;
	wdw.img_ptr = NULL;
	wdw.img_data = NULL;
	wdw.img_mn_ptr = NULL;
	wdw.img_mn_data = NULL;
	wdw.dim_mini = DIMENSION;
	wdw.print_map = 0;
	return (wdw);
}

static t_char	initialise_struct_char(void)
{
	t_char	charac;

	charac.view = -1;
	charac.vvx = -1;
	charac.vvy = -1;
	charac.vx = -1;
	charac.vy = -1;
	charac.x = -1;
	charac.y = -1;
	charac.dim = DIMENSION_PLAYER;
	charac.ray = 0;
	return (charac);
}

static t_sprt	initialise_struct_sprt(void)
{
	t_sprt	sprt;

	sprt.s = NULL;
	sprt.sc = NULL;
	sprt.sl_s = 0;
	sprt.dim_s[0] = 0;
	sprt.dim_s[1] = 0;
	sprt.wray = NULL;
	sprt.beg = -1;
	sprt.left = 0;
	return (sprt);
}

t_all			*initialise_struct_all(int mode)
{
	t_all	*all;

	if (!(all = malloc(sizeof(t_all))))
		exit(1);
	all->tmap = initialise_struct_map();
	all->tchar = initialise_struct_char();
	all->twdw = initialise_struct_wdw();
	all->tvsprt = NULL;
	all->tsprt = initialise_struct_sprt();
	all->mode = mode;
	all->line = NULL;
	all->twall.x = 0;
	all->twall.y = 0;
	all->twall.xbis = 0;
	all->twall.ybis = 0;
	all->twall.hyp = 0;
	all->twall.size_x = 0;
	all->twall.size_y = 0;
	all->twall.horiz = 0;
	all->twall.text = NULL;
	all->twall.size_line = 0;
	all->twall.width = 0;
	all->twall.height = 0;
	all->twall.size = 0;
	return (all);
}
