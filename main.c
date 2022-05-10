/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:56:20 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/09 20:14:50 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	verif_file_cub(char *txt, int ret)
{
	int	i;

	i = ft_strlen(txt);
	if (i > 4)
	{
		if (!ft_strncmp(&txt[i - 4], ".cub", 5))
			return (ret);
	}
	return (0);
}

static int	check_argv(int c, char **v)
{
	if (c == 3)
	{
		if (!ft_strncmp(v[2], "--save", 7))
			return (verif_file_cub(v[1], 2));
		else
			return (0);
	}
	if (c == 2)
		return (verif_file_cub(v[1], 1));
	else
		return (0);
}

int			main(int c, char **v)
{
	char	*map;
	int		mode;
	t_all	*data;

	if ((mode = check_argv(c, v)) > 0)
	{
		data = 0;
		data = initialise_struct_all(mode);
		map = v[1];
		window(map, data);
		return (0);
	}
	else
	{
		write(2, "ERROR : invalid argument\n", 25);
		return (1);
	}
	return (0);
}
