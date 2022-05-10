/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:53:48 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/12 15:50:25 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		height_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void		position_player(char c, int x, int y, t_all *data)
{
	data->tchar.x = x * DIMENSION + (float)(DIMENSION * 0.5);
	data->tchar.y = y * DIMENSION + (float)(DIMENSION * 0.5);
	if (c == 'S')
		data->tchar.view = M_PI / 2;
	else if (c == 'N')
		data->tchar.view = 3 * M_PI / 2;
	if (c == 'W')
		data->tchar.view = M_PI;
	else if (c == 'E')
		data->tchar.view = 0;
	data->tchar.vx = cos(data->tchar.view);
	data->tchar.vy = sin(data->tchar.view);
	data->tchar.vvx = cos(data->tchar.view);
	data->tchar.vvy = sin(data->tchar.view);
}

static void		validchar(char *line, char *accept, t_all *data, int y)
{
	int i;
	int j;

	i = -1;
	while (line[++i])
	{
		j = -1;
		if (line[i] == ' ')
			check_void(data, i, y);
		else if (line[i] == 'N' || line[i] == 'S'
		|| line[i] == 'E' || line[i] == 'W')
		{
			if (data->tchar.view != -1)
				free_all(data, "ERROR : 2 characters or more on map\n", 1, 0);
			position_player(line[i], i, y, data);
		}
		while (accept[++j] != line[i])
		{
			if (accept[j] != line[i] && accept[j + 1] == '\0')
				free_all(data, "ERROR : Invalid map\n", 1, 0);
		}
	}
	if ((line[i - 1] != ' ' && line[i - 1] != '1') || (line[0]
	!= ' ' && line[0] != '1'))
		free_all(data, "ERROR : Invalid map\n", 1, 0);
}

void			verifmap(t_all *data)
{
	int i;

	i = 0;
	data->twall.size_y = height_map(data->tmap.map);
	validchar(data->tmap.map[0], " 1", data, i);
	while (data->tmap.map[i + 1])
	{
		validchar(data->tmap.map[i],
		" 0WENS12", data, i);
		i++;
	}
	if (data->tchar.view == -1)
		free_all(data, "ERROR : any character\n", 1, 0);
	validchar(data->tmap.map[i], " 1", data, i);
	define_dimension(data, data->twall.size_x, data->twall.size_y);
}
