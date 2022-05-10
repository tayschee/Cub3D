/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:49:34 by tbigot            #+#    #+#             */
/*   Updated: 2019/11/14 16:51:05 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strldup(const char *s1, int max)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	while (s1[i] != '\0' && i < max)
		i++;
	if (!(cpy = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i > j && j < max)
	{
		cpy[j] = s1[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}
