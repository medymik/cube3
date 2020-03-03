/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:52:44 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:39:31 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		player_count(char *line)
{
	int	count;
	int x;

	count = 0;
	x = 0;
	while (line[x])
	{
		if (line[x] == 'N' || line[x] == 'S' ||
		line[x] == 'W' || line[x] == 'E')
			count++;
		x++;
	}
	return (count);
}

int		get_player_x(char *line)
{
	int x;

	x = 0;
	while (line[x])
	{
		if (line[x] == 'N' || line[x] == 'S' ||
		line[x] == 'W' || line[x] == 'E')
			return (x);
		x++;
	}
	return (-1);
}

int		find_player(void)
{
	int y;
	int count;
	int x;

	y = 0;
	count = 0;
	while (g_e.map[y])
	{
		if ((x = get_player_x(g_e.map[y])) != -1)
		{
			if (g_p.set != 0 || player_count(g_e.map[y]) > 1)
			{
				ft_puterror("Dupplicated player");
				return (0);
			}
			init_player(y, x);
			g_p.set += 1;
		}
		y++;
	}
	if (g_p.set == 1)
		return (1);
	ft_puterror("Player not found");
	return (0);
}

void	get_textures_data(void)
{
	int i;

	i = 0;
	while (i < 5)
	{
		g_e.tex[i].img.ptr = mlx_xpm_file_to_image(g_e.ptr,
		g_e.tex[i].fname,
		&g_e.tex[i].w, &g_e.tex[i].h);
		g_e.tex[i].img.data = (int*)mlx_get_data_addr(g_e.tex[i].img.ptr,
		&g_e.tex[i].img.bpp, &g_e.tex[i].img.sl, &g_e.tex[i].img.en);
		i++;
	}
}

int		load_textures(void)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		g_e.tex[i].img.ptr = mlx_xpm_file_to_image(g_e.ptr,
		g_e.tex[i].fname, &g_e.tex[i].w, &g_e.tex[i].h);
		if (!g_e.tex[i].img.ptr)
		{
			ft_puterror("Texture or Sprite error");
			return (0);
		}
		i++;
	}
	get_textures_data();
	return (1);
}
