/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:29:44 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:30:03 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		ft_paramshandle(char argc, char **argv)
{
	int status;

	status = 0;
	if (argc >= 2 && argc <= 3)
	{
		status = (argc == 2) ? 0 : -1;
		status += ft_extcheck(argv[1]);
		status += (argc == 3) ? ft_compare(argv[2], "--save") : 0;
		if (argc == 3)
			g_e.save = 1;
	}
	return (status);
}
