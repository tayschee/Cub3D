/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:41:51 by tbigot            #+#    #+#             */
/*   Updated: 2019/10/10 16:52:39 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char		txt;
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
	}
	if (nb > 9)
	{
		txt = nb % 10 + '0';
		nb = nb / 10;
		ft_putnbr_fd(nb, fd);
		write(fd, &txt, 1);
	}
	else
	{
		txt = nb + '0';
		write(fd, &txt, 1);
	}
}
