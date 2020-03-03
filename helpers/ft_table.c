/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:28:10 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:28:13 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

char	**ft_tabnew(void)
{
	char **tab;

	tab = (char**)malloc(sizeof(char*));
	if (tab)
		*tab = NULL;
	return (tab);
}

size_t	ft_tablecount(char **tab)
{
	size_t i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**ft_tablejoin(char **tab, char *line)
{
	size_t	len;
	char	**new_tab;
	size_t	i;

	len = ft_tablecount(tab);
	new_tab = (char**)malloc(sizeof(char*) * (len + 2));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < len)
		new_tab[i] = ft_strdup(tab[i]);
	new_tab[i++] = ft_strdup(line);
	new_tab[i] = NULL;
	ft_tableclear(tab);
	return (new_tab);
}

void	ft_tableclear(char **tab)
{
	size_t i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	tab = NULL;
}
