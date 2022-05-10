/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:04:55 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/12 12:20:39 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	change_map(t_all *data)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (data->tmap.map[i])
	{
		size = ft_strlen(data->tmap.map[i]);
		if (size > data->twall.size_x)
			data->twall.size_x = size;
		i++;
	}
	add_space(data);
}

static char	*ft_strjoin_mark_free(char *s1, char *s2, char *mark)
{
	char	*x;
	char	*final;

	if (!ft_strncmp(s2, "", 1))
	{
		free(s2);
		s2 = NULL;
		s2 = ft_strdup(" ");
	}
	x = ft_strjoin(s1, mark);
	free(s1);
	s1 = NULL;
	final = ft_strjoin(x, s2);
	if (x)
	{
		free(x);
		x = NULL;
	}
	free(s2);
	s2 = NULL;
	return (final);
}

static void	pars_map(int fd, t_all *data, char *line_pars)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 1;
	tmp = line_pars;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		tmp = ft_strjoin_mark_free(tmp, line, "/");
	}
	data->tmap.map = ft_split(tmp, '/');
	free(tmp);
	if (close(fd) < 0)
		free_all(data, "ERROR fd no close\n", 1, 0);
	if (line)
		free(line);
	change_map(data);
	verifmap(data);
}

static char	*parsing_text(int fd, t_all *data)
{
	int	i;
	int	j;

	while ((i = get_next_line(fd, &data->line)) > 0)
	{
		j = 0;
		while (data->line[j] == ' ')
		{
			if (data->line[j] == '1')
				break ;
			j++;
		}
		if (data->line[j] == '1')
			break ;
		else if (ft_strncmp(data->line, "\0", 1) != 0)
			for_parsing_text(data);
		free(data->line);
		data->line = NULL;
	}
	if (i == 0)
		free_all(data, "ERROR gnl\n", 1, 1);
	verif_pars(data);
	return (data->line);
}

void		parsing(char *file_name, t_all *data)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	pars_map(fd, data, parsing_text(fd, data));
}
