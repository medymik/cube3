/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:27:18 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:25:55 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	new_img(void)
{
	if (g_e.img.ptr)
		mlx_destroy_image(g_e.ptr, g_e.img.ptr);
	g_e.img.ptr = mlx_new_image(g_e.ptr, g_e.r.w, g_e.r.h);
	g_e.img.data = (int*)mlx_get_data_addr(g_e.img.ptr, &g_e.img.bpp,
	&g_e.img.sl, &g_e.img.en);
}

void	save_or_put(void)
{
	if (!g_e.save)
		mlx_put_image_to_window(g_e.ptr, g_e.win, g_e.img.ptr, 0, 0);
	else
	{
		save_bmp();
		exit_game(0);
	}
}

int		cast_rays(void)
{
	int		x;
	t_ray	r;
	double	zbuffer[g_e.r.w];

	new_img();
	dist_sprite();
	draw_floor_ceilling();
	x = 0;
	while (x < g_e.r.w)
	{
		r = new_ray(2 * x / (double)g_e.r.w - 1);
		calculate_steps(&r);
		dda_perform(&r);
		calculate_distance(&r);
		calculate_draw_points(&r);
		setup_coordinate(&r);
		draw_wall(&r, x);
		zbuffer[x] = r.perp;
		x++;
	}
	draw_sprites(zbuffer);
	save_or_put();
	return (0);
}
