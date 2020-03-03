/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:21:39 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:25:26 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_pixel(int row, int col, int color)
{
	g_e.img.data[row * g_e.r.w + col] = color;
}

void	draw_vertline(int col, int ds, int de, int color)
{
	while (ds < de)
	{
		draw_pixel(ds, col, color);
		ds++;
	}
}

void	draw_floor_ceilling(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_e.r.h)
	{
		j = 0;
		while (j < g_e.r.w)
		{
			if (i < g_e.r.h / 2)
				draw_pixel(i, j, g_e.cc.r * 65536 + g_e.cc.g * 256 + g_e.cc.b);
			else
				draw_pixel(i, j, g_e.fc.r * 65536 + g_e.fc.g * 256 + g_e.fc.b);
			j++;
		}
		i++;
	}
}
