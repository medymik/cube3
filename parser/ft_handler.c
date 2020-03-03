/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:49:42 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:51:19 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../includes/cube3d.h"

void	init(void)
{
	int i;

	i = -1;
	g_check.r = 0;
	g_check.fc = 0;
	g_check.cc = 0;
	while (++i < 5)
		g_e.tex[i].set = 0;
	g_e.map = NULL;
}

int		handle_line(char *line)
{
	int status;

	status = 0;
	if (!ft_strncmp(line, "R", 1))
		status = ft_parseresolution(line);
	else if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
		status = ft_parsecolor(line);
	else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) ||
		!ft_strncmp(line, "EA", 2) || !ft_strncmp(line, "WE", 2) ||
		!ft_strncmp(line, "S", 1))
		status = ft_parsetextures(line);
	else if (ft_isdigit(*line))
		status = ft_parsemap(line);
	else if (ft_strlen(line) == 0 && g_e.map)
		ft_puterror("Map structure");
	else if (ft_strlen(line) == 0)
		status = 1;
	else
		ft_puterror("Map structure");
	return (status);
}

int		handler(char **tab)
{
	size_t	i;
	int		status;

	i = -1;
	init();
	if ((status = ft_tablecount(tab)) == 0)
		ft_puterror("Empty file");
	while (tab[++i])
	{
		status = handle_line(tab[i]);
		if (!status)
			break ;
	}
	if (g_e.map && ft_tablecount(g_e.map) > 0)
		if (status && (!ft_checklines() || !ft_checksides() || !find_player()))
			status = 0;
	return (status);
}
