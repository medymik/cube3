/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:45:12 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:46:37 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include "vector.h"
# include "parser.h"
# include "helpers.h"
# include "game.h"
# include "movement.h"
# include "ray.h"
# include "sprites.h"
# include "draw.h"
# include "mlx.h"
# include "math.h"
# include "bmp.h"
# include "textures.h"

typedef struct	s_img
{
	int		bpp;
	int		sl;
	int		en;
	void	*ptr;
	int		*data;
}				t_img;
typedef struct	s_texture
{
	int		set;
	char	*fname;
	int		w;
	int		h;
	t_img	img;
}				t_texture;
typedef struct	s_color
{
	int r;
	int g;
	int b;
}				t_color;
typedef	struct	s_sprite
{
	t_vec2		pos;
	double		dist;
	t_vec2		sp;
	double		invdt;
	double		transx;
	double		transy;
	int			sp_sc_x;
	int			sph;
	int			spw;
}				t_sprite;
typedef struct	s_reso
{
	int w;
	int h;
}				t_reso;
typedef struct	s_player
{
	t_vec2		pos;
	t_vec2		dir;
	t_vec2		plane;
	int			set;
}				t_player;
typedef struct	s_env
{
	t_reso		r;
	t_color		fc;
	t_color		cc;
	t_texture	tex[5];
	char		**map;
	void		*ptr;
	void		*win;
	t_img		img;
	int			save;
	int			sprites_count;
	t_sprite	*sprites;
	int			draw_starty;
	int			draw_endy;
	int			draw_startx;
	int			draw_endx;
}				t_env;
typedef struct	s_check
{
	int			fc;
	int			cc;
	int			r;
}				t_check;
t_check			g_check;
t_env			g_e;
t_player		g_p;
int				load_textures(void);
int				cast_rays(void);
int				exit_game(int status);
#endif
