/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:48:38 by tbigot            #+#    #+#             */
/*   Updated: 2020/01/28 18:26:08 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*newtab;
	size_t		size;
	size_t		i;

	i = 0;
	size = ft_strlen(s);
	if (size < start)
		len = 0;
	if (!(newtab = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (i < len)
	{
		newtab[i] = s[start + i];
		i++;
	}
	return (newtab);
}
