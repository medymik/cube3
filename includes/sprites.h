/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:20:47 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:44:56 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H
# include "vector.h"
# include "cube3d.h"

int			count_sprites(void);
void		find_sprites(void);
void		dist_sprite(void);
void		draw_sprites(double zbuffer[]);
#endif
