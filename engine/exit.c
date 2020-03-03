/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:29:11 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 09:30:59 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		exit_game(int status)
{
	int i;

	i = 0;
	if (g_e.map)
	{
		ft_tableclear(g_e.map);
	}
	while (i < 5)
	{
		if (g_e.tex[i].set)
			free(g_e.tex[i].fname);
		i++;
	}
	if (g_e.win && g_e.ptr)
		mlx_destroy_window(g_e.ptr, g_e.win);
	exit(status);
}
