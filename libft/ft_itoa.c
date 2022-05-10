/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:25:31 by tbigot            #+#    #+#             */
/*   Updated: 2019/10/16 18:15:52 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nb_chiffre(long int n)
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

char	*ft_itoa(int n)
{
	int			i;
	char		*nb;
	long int	nbr;

	i = 0;
	nbr = n;
	if (n < 0)
	{
		i += 1;
		nbr = nbr * -1;
	}
	i += nb_chiffre(nbr);
	if (i == 0)
		i = 1;
	if (!(nb = (char *)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	nb[0] = '-';
	if (n == 0)
		nb[0] = '0';
	while (nbr > 0)
	{
		nb[--i] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (nb);
}
