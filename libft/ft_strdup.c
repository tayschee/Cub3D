/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:20:57 by tbigot            #+#    #+#             */
/*   Updated: 2019/11/09 17:02:03 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	if (!(cpy = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i > j)
	{
		cpy[j] = s1[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}
