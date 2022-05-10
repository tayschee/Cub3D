/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:01:07 by tbigot            #+#    #+#             */
/*   Updated: 2020/01/29 10:02:49 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(tab = ft_calloc((size + 1), sizeof(char))))
		return (NULL);
	while (s1 && s1[j])
	{
		tab[j] = s1[j];
		j++;
	}
	while (s2 && s2[i])
	{
		tab[i + j] = s2[i];
		i++;
	}
	return (tab);
}
