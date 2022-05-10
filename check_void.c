/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_void.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <tbigot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:29:58 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/09 17:01:20 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_void(t_all *data, int i, int j)
{
	if (j > 0 && data->tmap.map[j - 1][i] != ' '
	&& data->tmap.map[j - 1][i] != '1')
		free_all(data, "ERROR : invalid map\n", 1, 0);
	if (data->tmap.map[j + 1] && data->tmap.map[j + 1][i] != ' '
	&& data->tmap.map[j + 1][i] != '1')
		free_all(data, "ERROR : invalid map\n", 1, 0);
	if (i > 0 && data->tmap.map[j][i - 1] != ' '
	&& data->tmap.map[j][i - 1] != '1')
		free_all(data, "ERROR : invalid map\n", 1, 0);
	if (data->tmap.map[j][i + 1] != '\0'
	&& data->tmap.map[j][i + 1] != ' '
	&& data->tmap.map[j][i + 1] != '1')
		free_all(data, "ERROR : invalid map\n", 1, 0);
}

void	add_space(t_all *data)
{
	char	*new;
	char	*tmp;
	int		size;
	int		i;

	i = 0;
	while (data->tmap.map[i])
	{
		size = ft_strlen(data->tmap.map[i]);
		if (size < data->twall.size_x)
		{
			size = data->twall.size_x - size;
			if (!(new = malloc((size + 1) * sizeof(char))))
				free_all(data, "ERROR : malloc\n", 1, 0);
			new[size] = 0;
			tmp = ft_strjoin(data->tmap.map[i], ft_memset(new, ' ', size));
			free(new);
			free(data->tmap.map[i]);
			data->tmap.map[i] = tmp;
		}
		i++;
	}
	i = 0;
	while (data->tmap.map[i])
		i++;
}
