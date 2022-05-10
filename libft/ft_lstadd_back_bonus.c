/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:14:01 by tbigot            #+#    #+#             */
/*   Updated: 2019/10/21 12:17:22 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*newchain;

	if (alst && !*alst)
		*alst = new;
	else if (alst && *alst)
	{
		newchain = ft_lstlast(*alst);
		newchain->next = new;
	}
}
