/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:55:26 by tbigot            #+#    #+#             */
/*   Updated: 2020/03/12 14:04:35 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	pythagore(double c1, double c2)
{
	return (sqrt(c1 * c1 + c2 * c2));
}

int		*long_to_orgb(long int color)
{
	int			i;
	long int	sub_color;
	int			*rgb;

	sub_color = 0;
	if (!(rgb = malloc(sizeof(int) * 4)))
		return (NULL);
	i = 0;
	while (++i <= 24)
	{
		if (color & 1 << (32 - i))
			sub_color = sub_color + pow(2, (24 - i));
	}
	sub_color = sub_color << 8;
	i = -1;
	while (++i < 4)
	{
		rgb[3 - i] = color - sub_color;
		color = color >> 8;
		sub_color = sub_color >> 16;
		sub_color = sub_color << 8;
	}
	return (rgb);
}

double	trigo_pi(double angle)
{
	while (angle > 2 * M_PI)
		angle = angle - 2 * M_PI;
	while (angle < 0)
		angle = 2 * M_PI + angle;
	return (angle);
}

int		verifchar(char c, char *valid)
{
	int	i;

	i = 0;
	while (valid[i])
	{
		if (c == valid[i])
			return (1);
		i++;
	}
	return (0);
}
