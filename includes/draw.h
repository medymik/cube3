/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:23:22 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:44:45 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

void	draw_pixel(int row, int col, int color);
void	draw_vertline(int col, int ds, int de, int color);
void	draw_floor_ceilling(void);
#endif
