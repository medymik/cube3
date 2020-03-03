/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:39:17 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:26:33 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	get_direction(t_ray *ray)
{
	if (ray->side == 1)
	{
		if (ray->dir.y * -1 > 0)
			return ('N');
		else
			return ('S');
	}
	else
	{
		if (ray->dir.x * 1 < 0)
			return ('E');
		else
			return ('W');
	}
}

int		textures_index(t_ray *ray)
{
	if (get_direction(ray) == 'S')
		return (0);
	else if (get_direction(ray) == 'N')
		return (1);
	else if (get_direction(ray) == 'E')
		return (2);
	else if (get_direction(ray) == 'W')
		return (3);
	return (0);
}

void	setup_coordinate(t_ray *ray)
{
	double wall;

	if (ray->side == 0)
		wall = g_p.pos.y + ray->perp * ray->dir.y;
	else
		wall = g_p.pos.x + ray->perp * ray->dir.x;
	wall -= floor(wall);
	ray->tex.x = (int)(wall * (double)g_e.tex[textures_index(ray)].w);
	if (ray->side == 0 && ray->dir.x > 0)
		ray->tex.x = g_e.tex[textures_index(ray)].w - ray->tex.x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		ray->tex.x = g_e.tex[textures_index(ray)].w - ray->tex.x - 1;
}

void	draw_wall(t_ray *ray, int x)
{
	double	step;
	double	text_pos;
	int		y;
	int		color;

	step = 1.0 * g_e.tex[textures_index(ray)].h / ray->lineh;
	text_pos = (ray->draws - g_e.r.h / 2 + ray->lineh / 2) * step;
	y = ray->draws;
	while (y < ray->drawe)
	{
		ray->tex.y = (int)text_pos & (g_e.tex[textures_index(ray)].w - 1);
		text_pos += step;
		color = g_e.tex[textures_index(ray)].
		img.data[(g_e.tex[textures_index(ray)].w *
		ray->tex.y + ray->tex.x)];
		draw_pixel(y, x, color);
		y++;
	}
}
