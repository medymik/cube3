/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mymik <mymik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:34:45 by mymik             #+#    #+#             */
/*   Updated: 2020/03/03 10:44:24 by mymik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# define SIZE 2
# pragma pack(2)

typedef struct	s_bmp
{
	char		file_type[SIZE];
	int			file_size;
	int			reserved;
	int			offset;
	int			header_size;
	int			width;
	int			height;
	char		plane[SIZE];
	char		bpp[SIZE];
	int			compression;
	int			bit_size;
	int			perpexx;
	int			perpexy;
	int			num_color;
	int			imp_color;
}				t_bmp;
void			save_bmp(void);
#endif
