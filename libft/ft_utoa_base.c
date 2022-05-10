/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:33 by tbigot            #+#    #+#             */
/*   Updated: 2019/11/15 11:26:23 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	respect_condition(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			if (base[j] <= 31 || base[j] >= 127
			|| base[j] == '+' || base[j] == '-')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	if (base[0] == '+' || base[0] == '-' || i <= 1)
		return (0);
	else
		return (1);
}

static int	count_malloc(unsigned nb, int size_base)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / size_base;
		i++;
	}
	return (i);
}

static char	*nbr_base_in_char(char *txt, unsigned int nbr, char *base, int i)
{
	int size_base;

	size_base = strlen(base);
	while (nbr > 0)
	{
		txt[i - 1] = base[nbr % size_base];
		nbr = nbr / size_base;
		i--;
	}
	if (i > 0)
		txt[i - 1] = '-';
	return (txt);
}

char		*ft_utoa_base(unsigned int nbr, char *base)
{
	char		*txt;
	int			malloc_size;
	int			size_base;

	if (!respect_condition(base))
		return (0);
	malloc_size = 0;
	size_base = strlen(base);
	malloc_size = count_malloc(nbr, size_base);
	if (!(txt = calloc((malloc_size + 1), sizeof(char))))
		return (NULL);
	if (nbr == 0)
		txt[0] = 0 + 48;
	else
		txt = nbr_base_in_char(txt, nbr, base, malloc_size);
	return (txt);
}
