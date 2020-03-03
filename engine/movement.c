/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:14:14 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:26:41 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	move_up_down(int key)
{
	if (key == 13)
	{
		if (g_e.map[(int)(g_p.pos.y + g_p.dir.y * 0.4)][(int)g_p.pos.x] == '0')
			g_p.pos.y += g_p.dir.y * 0.4;
		if (g_e.map[(int)g_p.pos.y][(int)(g_p.pos.x + g_p.dir.x * 0.4)] == '0')
			g_p.pos.x += g_p.dir.x * 0.4;
	}
	else if (key == 1)
	{
		if (g_e.map[(int)(g_p.pos.y - g_p.dir.y * 0.4)][(int)g_p.pos.x] == '0')
			g_p.pos.y -= g_p.dir.y * 0.4;
		if (g_e.map[(int)g_p.pos.y][(int)(g_p.pos.x - g_p.dir.x * 0.4)] == '0')
			g_p.pos.x -= g_p.dir.x * 0.4;
	}
}

void	move_left_right(int key)
{
	if (key == 2)
	{
		if (g_e.map[(int)(g_p.pos.y + g_p.plane.y * 0.4)]
		[(int)g_p.pos.x] == '0')
			g_p.pos.y += g_p.plane.y * 0.4;
		if (g_e.map[(int)g_p.pos.y]
		[(int)(g_p.pos.x + g_p.plane.x * 0.4)] == '0')
			g_p.pos.x += g_p.plane.x * 0.4;
	}
	else if (key == 0)
	{
		if (g_e.map[(int)(g_p.pos.y - g_p.plane.y * 0.4)]
		[(int)g_p.pos.x] == '0')
			g_p.pos.y -= g_p.plane.y * 0.4;
		if (g_e.map[(int)g_p.pos.y]
		[(int)(g_p.pos.x - g_p.plane.x * 0.4)] == '0')
			g_p.pos.x -= g_p.plane.x * 0.4;
	}
}

void	rotate_player(int key)
{
	double olddirx;
	double planex;

	if (key == 123)
	{
		olddirx = g_p.dir.x;
		g_p.dir.x = g_p.dir.x * cos(-0.1) - g_p.dir.y * sin(-0.1);
		g_p.dir.y = olddirx * sin(-0.1) + g_p.dir.y * cos(-0.1);
		planex = g_p.plane.x;
		g_p.plane.x = g_p.plane.x * cos(-0.1) - g_p.plane.y * sin(-0.1);
		g_p.plane.y = planex * sin(-0.1) + g_p.plane.y * cos(-0.1);
	}
	if (key == 124)
	{
		olddirx = g_p.dir.x;
		g_p.dir.x = g_p.dir.x * cos(0.1) - g_p.dir.y * sin(0.1);
		g_p.dir.y = olddirx * sin(0.1) + g_p.dir.y * cos(0.1);
		planex = g_p.plane.x;
		g_p.plane.x = g_p.plane.x * cos(0.1) - g_p.plane.y * sin(0.1);
		g_p.plane.y = planex * sin(0.1) + g_p.plane.y * cos(0.1);
	}
}

int		handle_key(int key)
{
	if (key == 53)
		exit_game(0);
	move_up_down(key);
	move_left_right(key);
	rotate_player(key);
	cast_rays();
	return (0);
}
