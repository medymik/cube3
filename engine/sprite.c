/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:20:07 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:24:51 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		count_sprites(void)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (g_e.map[i])
	{
		j = 0;
		while (g_e.map[i][j])
		{
			if (g_e.map[i][j] == '2')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

void	sort_sprites(void)
{
	int			i;
	int			sorted;
	t_sprite	tmp;

	sorted = 0;
	while (sorted == 0)
	{
		i = 0;
		sorted = 1;
		while (i < g_e.sprites_count - 1)
		{
			if (g_e.sprites[i].dist < g_e.sprites[i + 1].dist)
			{
				tmp = g_e.sprites[i];
				g_e.sprites[i] = g_e.sprites[i + 1];
				g_e.sprites[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}

void	dist_sprite(void)
{
	int i;

	i = 0;
	while (i < g_e.sprites_count)
	{
		g_e.sprites[i].dist = (pow(g_p.pos.x -
					g_e.sprites[i].pos.x, 2) +
				pow(g_p.pos.y - g_e.sprites[i].pos.y, 2));
		i++;
	}
	sort_sprites();
}

void	find_sprites(void)
{
	int i;
	int j;
	int count;

	i = 0;
	count = count_sprites();
	g_e.sprites_count = count;
	g_e.sprites = malloc(sizeof(t_sprite) * count);
	count = 0;
	while (g_e.map[i])
	{
		j = 0;
		while (g_e.map[i][j])
		{
			if (g_e.map[i][j] == '2')
			{
				g_e.sprites[count].pos.x = j + 0.5;
				g_e.sprites[count].pos.y = i + 0.5;
				count++;
			}
			j++;
		}
		i++;
	}
}
