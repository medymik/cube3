/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:17:56 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:26:23 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_ray	new_ray(double camera)
{
	t_ray ray;

	ray.dir.x = g_p.dir.x + g_p.plane.x * camera;
	ray.dir.y = g_p.dir.y + g_p.plane.y * camera;
	ray.map.x = (int)g_p.pos.x;
	ray.map.y = (int)g_p.pos.y;
	ray.deltad.x = fabs(1 / ray.dir.x);
	ray.deltad.y = fabs(1 / ray.dir.y);
	ray.hit = 0;
	return (ray);
}

void	calculate_steps(t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->sided.x = (g_p.pos.x - ray->map.x) * ray->deltad.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sided.x = (ray->map.x + 1.0 - g_p.pos.x) * ray->deltad.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->sided.y = (g_p.pos.y - ray->map.y) * ray->deltad.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sided.y = (ray->map.y + 1.0 - g_p.pos.y) * ray->deltad.y;
	}
}

void	dda_perform(t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->sided.x < ray->sided.y)
		{
			ray->sided.x += ray->deltad.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sided.y += ray->deltad.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (g_e.map[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
}

void	calculate_distance(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp = (ray->map.x - g_p.pos.x +
		(1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->perp = (ray->map.y - g_p.pos.y +
		(1 - ray->step.y) / 2) / ray->dir.y;
}

void	calculate_draw_points(t_ray *ray)
{
	ray->lineh = (int)(g_e.r.h / ray->perp);
	ray->draws = -ray->lineh / 2 + g_e.r.h / 2;
	ray->draws = (ray->draws < 0) ? 0 : ray->draws;
	ray->drawe = ray->lineh / 2 + g_e.r.h / 2;
	ray->drawe = (ray->drawe >= g_e.r.h) ? g_e.r.h - 1 : ray->drawe;
}
