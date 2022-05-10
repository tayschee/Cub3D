/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:29:05 by tbigot            #+#    #+#             */
/*   Updated: 2019/10/18 14:11:53 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*abort_mission(t_list *start, void (*del)(void *))
{
	t_list	*startnull;
	t_list	*next;

	startnull = start;
	while (start)
	{
		next = start->next;
		ft_lstdelone(start, del);
		start = next;
	}
	return (startnull);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*start;

	if (lst && f && del)
	{
		start = ft_lstnew(f(lst->content));
		newlist = start;
		while (start && lst->next)
		{
			lst = lst->next;
			newlist->next = ft_lstnew(f(lst->content));
			if (!newlist->next)
				return (abort_mission(start, del));
			newlist = newlist->next;
		}
		return (start);
	}
	return (0);
}
