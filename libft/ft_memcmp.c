/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:32:41 by tbigot            #+#    #+#             */
/*   Updated: 2019/10/16 18:54:53 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s12;
	unsigned char	*s22;

	i = 0;
	if (s1 == s2 || n == 0)
		return (0);
	s12 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (s12[i] == s22[i] && i < n - 1)
		i++;
	return (s12[i] - s22[i]);
}
