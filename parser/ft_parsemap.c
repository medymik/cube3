/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:41:30 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:33:00 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../includes/cube3d.h"

int		ft_validchar(char c)
{
	if (c == '1' || c == '0' || c == 'S'
	|| c == 'W' || c == 'E' || c == 'N' || c == '2' || c == ' ')
		return (1);
	return (0);
}

int		ft_fullinfovalid(void)
{
	int		i;

	i = -1;
	if (g_check.r == 0 || g_check.fc == 0 || g_check.cc == 0)
		return (0);
	while (++i < 5)
		if (g_e.tex[i].set == 0)
			return (0);
	return (1);
}

int		ft_checkline(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_validchar(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void	parseline(char *str)
{
	char	**sp;
	size_t	i;
	char	*line;
	char	*tmp;

	line = NULL;
	if (!g_e.map)
		g_e.map = ft_tabnew();
	sp = ft_split(str, ' ');
	i = -1;
	while (sp[++i])
	{
		if (!line)
			line = ft_strdup("");
		tmp = line;
		line = ft_strjoin(line, sp[i]);
		free(tmp);
	}
	g_e.map = ft_tablejoin(g_e.map, line);
	ft_tableclear(sp);
	free(line);
}

int		ft_parsemap(char *line)
{
	int i;

	i = -1;
	if (ft_fullinfovalid() && ft_checkline(line) == 1)
	{
		parseline(line);
		return (1);
	}
	ft_puterror("Invalid map");
	return (0);
}
