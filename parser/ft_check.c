/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:49:45 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 11:20:14 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		ft_extcheck(char *ext)
{
	size_t len;

	len = ft_strlen(ext);
	if (!ft_strncmp(&ext[len - 4], ".cub", 4))
		return (1);
	return (0);
}

int		ft_compare(char *s1, char *s2)
{
	size_t	len;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	len = (lens1 > lens2) ? lens1 : lens2;
	if (!ft_strncmp(s1, s2, len))
		return (1);
	return (0);
}

int		ft_checklines(void)
{
	int		len;
	size_t	width;
	int		i;

	len = (g_e.map) ? ft_tablecount(g_e.map) : 0;
	width = (len > 0) ? ft_strlen(g_e.map[0]) : 0;
	i = 1;
	if (len > 0)
	{
		while (i < len)
		{
			if (ft_strlen(g_e.map[i]) != width)
			{
				ft_puterror("Map Invalid");
				return (0);
			}
			i++;
		}
	}
	return (1);
}

int		check_first_last(void)
{
	int		len;
	int		i;

	len = (g_e.map) ? ft_tablecount(g_e.map) : 0;
	if (g_e.map)
	{
		i = 0;
		while (g_e.map[0][i])
		{
			if (g_e.map[0][i] != '1' || g_e.map[len - 1][i] != '1')
			{
				ft_puterror("Map Invalid");
				return (0);
			}
			i++;
		}
	}
	return (1);
}

int		ft_checksides(void)
{
	int		len;
	int		i;

	i = 0;
	len = (g_e.map) ? ft_tablecount(g_e.map) : 0;
	while (i < len)
	{
		if (g_e.map[i][0] != '1' ||
		g_e.map[i][ft_strlen(g_e.map[i]) - 1] != '1')
		{
			ft_puterror("Map Invalid");
			return (0);
		}
		i++;
	}
	return (check_first_last());
}
