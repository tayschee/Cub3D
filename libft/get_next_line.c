/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:21:13 by tbigot            #+#    #+#             */
/*   Updated: 2020/01/29 10:49:24 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		free_all(char **stc, int i)
{
	if (*stc)
		free(*stc);
	*stc = NULL;
	return (i);
}

static int		lineornot(char *txt)
{
	int i;

	i = 0;
	if (txt)
	{
		while (txt[i] && txt[i] != '\n')
			i++;
		if (txt[i] == '\n')
			return (i);
	}
	return (-1);
}

static int		for_line(char **stc, char **line, int len)
{
	int		size;
	char	*tmp;

	size = ft_strlen(*stc);
	if (!(*line = ft_substr(*stc, 0, len)))
		return (free_all(stc, -1));
	if (!(tmp = ft_substr(*stc, len + 1, size - len)))
		return (free_all(stc, -1));
	free_all(stc, 1);
	*stc = tmp;
	return (1);
}

static int		ft_return(char **stc, char **line, int i)
{
	int n;

	if (i < 0)
		return (free_all(stc, -1));
	if (!*stc || !**stc)
	{
		if (!(*line = ft_substr("", 0, 1)))
			return (free_all(stc, -1));
		return (free_all(stc, 0));
	}
	if ((n = lineornot(*stc)) != -1)
		return (for_line(stc, line, n));
	else
	{
		if (!(*line = ft_substr(*stc, 0, ft_strlen(*stc))))
			return (free_all(stc, -1));
		return (free_all(stc, 0));
	}
}

int				get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*stc;
	char			*tmp;
	int				i;

	if (!line || fd < 0)
		return (free_all(&stc, -1));
	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (!(tmp = ft_strjoin(stc, buf)))
			return (free_all(&stc, -1));
		free_all(&stc, 1);
		stc = tmp;
		if ((lineornot(stc)) != -1)
			break ;
	}
	return (ft_return(&stc, line, i));
}
