/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:43:58 by tbigot            #+#    #+#             */
/*   Updated: 2019/10/16 17:50:30 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(char const s1, char const *set)
{
	int j;

	j = 0;
	while (set[j])
	{
		if (s1 == set[j])
			return (0);
		j++;
	}
	return (1);
}

static int		ft_strlen2(char const *s1, char const *set, int size)
{
	int count;

	count = 0;
	while (check(*s1, set) == 0 && --size)
	{
		s1--;
		count++;
	}
	return (count);
}

static int		ft_strlen3(char const *s1, char const *set)
{
	int	count;

	count = 0;
	while (check(*s1, set) == 0 && s1)
	{
		count++;
		s1++;
	}
	return (count);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*newtab;
	int		mallocsize;
	int		i;
	int		debut;
	int		fin;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup((char *)s1));
	debut = ft_strlen3(s1, set);
	fin = ft_strlen2(&s1[ft_strlen(s1) - 1], set, ft_strlen(s1));
	mallocsize = ft_strlen(s1) - (debut + fin);
	if (mallocsize < 0)
		mallocsize = 0;
	if (!(newtab = ft_calloc(mallocsize + 1, sizeof(char))))
		return (NULL);
	while (i < mallocsize)
	{
		newtab[i] = s1[debut + i];
		i++;
	}
	return (newtab);
}
