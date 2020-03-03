/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:17:27 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:44:53 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "vector.h"

typedef struct	s_ray
{
	t_vec2		dir;
	t_vec2i		map;
	t_vec2		sided;
	t_vec2		deltad;
	double		perp;
	t_vec2i		step;
	int			hit;
	int			side;
	int			lineh;
	int			draws;
	int			drawe;
	t_vec2i		tex;
}				t_ray;
t_ray			new_ray(double camera);
void			calculate_steps(t_ray *ray);
void			dda_perform(t_ray *ray);
void			calculate_distance(t_ray *ray);
void			calculate_draw_points(t_ray *ray);
#endif
