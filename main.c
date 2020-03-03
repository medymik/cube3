/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:19:20 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:48:58 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "helpers.h"
#include "parser.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "cube3d.h"

int		is_mapvalid(void)
{
	if (g_e.map)
	{
		find_sprites();
		game_loop();
	}
	ft_puterror("Empty Map");
	return (0);
}

void	clear_conf(void)
{
	int i;

	i = -1;
	while (++i < 5)
		if (g_e.tex[i].set)
			free(g_e.tex[i].fname);
	if (g_e.map)
		ft_tableclear(g_e.map);
}

int		main(int argc, char **argv)
{
	char	**tab;
	int		status;

	if (ft_paramshandle(argc, argv) == 1)
	{
		if ((tab = ft_filehandler(argv[1])))
		{
			status = handler(tab);
			ft_tableclear(tab);
			if (status)
				status = is_mapvalid();
			clear_conf();
			return (!status);
		}
		ft_puterror(strerror(errno));
		return (1);
	}
	ft_puterror("Wrong program parameteres");
	return (1);
}
