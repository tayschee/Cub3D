/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:46:37 by tbigot            #+#    #+#             */
/*   Updated: 2019/11/13 13:45:29 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!dst || !src)
		return (0);
	while (dst[i] && i < dstsize)
		i++;
	while (src[j])
		j++;
	if (dstsize <= i)
		j += dstsize;
	else
		j += i;
	while (src[k] && (i + k + 1) < dstsize)
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i < dstsize)
		dst[i + k] = '\0';
	return (j);
}
