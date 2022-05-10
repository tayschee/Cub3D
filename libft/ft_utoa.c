/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:25:31 by tbigot            #+#    #+#             */
/*   Updated: 2019/11/15 11:10:39 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_chiffre(long int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_utoa(unsigned int nbr)
{
	int			i;
	char		*nb;

	i = 0;
	i += nb_chiffre(nbr);
	if (i == 0)
		i = 1;
	if (!(nb = (char *)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	if (nbr == 0)
		nb[0] = '0';
	while (nbr > 0)
	{
		nb[--i] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (nb);
}
