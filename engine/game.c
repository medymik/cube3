/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:10:39 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:24:40 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	game_loop(void)
{
	g_e.ptr = mlx_init();
	if (!g_e.save)
		g_e.win = mlx_new_window(g_e.ptr, g_e.r.w, g_e.r.h, "CUBE3D");
	if (!load_textures())
		return ;
	cast_rays();
	if (!g_e.save)
	{
		mlx_hook(g_e.win, 17, 0, &exit_game, NULL);
		mlx_hook(g_e.win, 2, 0, &handle_key, NULL);
		mlx_loop(g_e.ptr);
	}
}
