/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:46:57 by tbigot            #+#    #+#             */
/*   Updated: 2019/10/17 15:50:34 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	if (!(tab = malloc(size * count)))
		return (NULL);
	while (i < count)
	{
		tab[i] = '\0';
		i++;
	}
	return ((void *)tab);
}
