/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:58:36 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:39:20 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	set_north(int i, int j)
{
	g_p.pos.x = j + 0.5;
	g_p.pos.y = i + 0.5;
	g_p.dir.x = 0;
	g_p.dir.y = -1;
	g_p.plane.x = 0.66;
	g_p.plane.y = 0;
}

void	set_south(int i, int j)
{
	g_p.pos.x = j + 0.5;
	g_p.pos.y = i + 0.5;
	g_p.dir.x = 0;
	g_p.dir.y = 1;
	g_p.plane.x = -0.66;
	g_p.plane.y = 0;
}

void	set_west(int i, int j)
{
	g_p.pos.x = j + 0.5;
	g_p.pos.y = i + 0.5;
	g_p.dir.x = -1;
	g_p.dir.y = 0;
	g_p.plane.x = 0;
	g_p.plane.y = -0.66;
}

void	set_east(int i, int j)
{
	g_p.pos.x = j + 0.5;
	g_p.pos.y = i + 0.5;
	g_p.dir.x = 1;
	g_p.dir.y = 0;
	g_p.plane.x = 0;
	g_p.plane.y = 0.66;
}

void	init_player(int i, int j)
{
	if (g_e.map[i][j] == 'N')
		set_north(i, j);
	if (g_e.map[i][j] == 'S')
		set_south(i, j);
	if (g_e.map[i][j] == 'E')
		set_east(i, j);
	if (g_e.map[i][j] == 'W')
		set_west(i, j);
	g_e.map[i][j] = '0';
}
