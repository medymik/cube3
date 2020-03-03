/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:25:28 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:23:33 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		setup(int i)
{
	g_e.sprites[i].sp.x = g_e.sprites[i].pos.x - g_p.pos.x;
	g_e.sprites[i].sp.y = g_e.sprites[i].pos.y - g_p.pos.y;
	g_e.sprites[i].invdt = 1.0 /
	(g_p.plane.x * g_p.dir.y - g_p.dir.x * g_p.plane.y);
	g_e.sprites[i].transx = g_e.sprites[i].invdt *
	(g_p.dir.y * g_e.sprites[i].sp.x - g_p.dir.x * g_e.sprites[i].sp.y);
	g_e.sprites[i].transy = g_e.sprites[i].invdt *
	(-g_p.plane.y * g_e.sprites[i].sp.x + g_p.plane.x * g_e.sprites[i].sp.y);
	g_e.sprites[i].sp_sc_x = (int)((g_e.r.w / 2) *
	(1 + g_e.sprites[i].transx / g_e.sprites[i].transy));
	g_e.sprites[i].sph = abs((int)(g_e.r.h / (g_e.sprites[i].transy)));
	g_e.sprites[i].spw = abs((int)(g_e.r.h / (g_e.sprites[i].transy)));
}

void		setup_draw_start_end(int i)
{
	g_e.draw_starty = -g_e.sprites[i].sph / 2 + g_e.r.h / 2;
	if (g_e.draw_starty < 0)
		g_e.draw_starty = 0;
	g_e.draw_endy = g_e.sprites[i].sph / 2 + g_e.r.h / 2;
	if (g_e.draw_endy >= g_e.r.h)
		g_e.draw_endy = g_e.r.h - 1;
	g_e.draw_startx = -g_e.sprites[i].spw / 2 + g_e.sprites[i].sp_sc_x;
	if (g_e.draw_startx < 0)
		g_e.draw_startx = 0;
	g_e.draw_endx = g_e.sprites[i].spw / 2 + g_e.sprites[i].sp_sc_x;
	if (g_e.draw_endx >= g_e.r.w)
		g_e.draw_endx = g_e.r.w - 1;
}

void		draw_sprite(int i, double zbuffer[g_e.r.w])
{
	t_vec2i	tex;
	int		stripe;
	int		d;
	int		y;

	stripe = g_e.draw_startx;
	while (stripe < g_e.draw_endx)
	{
		tex.x = (int)((stripe - (-g_e.sprites[i].spw /
		2 + g_e.sprites[i].sp_sc_x)) * g_e.tex[4].w / g_e.sprites[i].spw);
		y = g_e.draw_starty - 1;
		if (g_e.sprites[i].transy > 0 && stripe > 0 && stripe < g_e.r.w
		&& g_e.sprites[i].transy < zbuffer[stripe])
			while (++y < g_e.draw_endy)
			{
				d = (y) * 256 - g_e.r.h * 128 + g_e.sprites[i].sph * 128;
				tex.y = ((d * g_e.tex[4].h) / g_e.sprites[i].sph) / 256;
				if ((g_e.tex[4].img.data[g_e.tex[4].w * tex.y + tex.x]
				& 0x00FFFFFF) != 0)
					draw_pixel(y, stripe,
					g_e.tex[4].img.data[g_e.tex[4].w * tex.y + tex.x]);
			}
		stripe++;
	}
}

void		draw_sprites(double zbuffer[g_e.r.w])
{
	int i;

	i = 0;
	while (i < g_e.sprites_count)
	{
		setup(i);
		setup_draw_start_end(i);
		draw_sprite(i, zbuffer);
		i++;
	}
}
