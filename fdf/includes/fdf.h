/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:41:53 by wzaim             #+#    #+#             */
/*   Updated: 2017/12/29 19:18:52 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define WIN_X	1280
# define WIN_Y	720

typedef struct	s_point_3d
{
	float		x;
	float		y;
	float		z;
}				t_point_3d;

typedef struct	s_fdf
{
	t_point_3d	**map;
	t_point_3d	**first_map;
	void		*mlx;
	void		*win;
	int			x_max;
	int			y_max;
	int			center_x;
	int			center_y;
	int			is_isometric;
	int			color;
}				t_fdf;

int				main(int argc, char **argv);

t_fdf			*fdf_parse(t_fdf *fdf, char *path);
void			fdf_get_dim(t_fdf *fdf, char *path);
int				fdf_check_parse_error(char *path, t_fdf *fdf);
void			fdf_fill_map(t_fdf *fdf, char **tmp, int i);
void			fdf_free_tab(char **tab);
void			fdf_save_map(t_fdf *fdf);
void			fdf_print_commands(void);

void			fdf_to_mlx(t_fdf *fdf);

void			mlx_draw(t_fdf *fdf);
void			mlx_draw_lines(t_fdf *fdf, t_point_3d p1, t_point_3d p2);
void			mlx_draw_p_lines(t_fdf *fdf, t_point_3d p1, t_point_3d p2);
void			mlx_draw_v_lines(t_fdf *fdf, t_point_3d p1, t_point_3d p2);

int				my_key_func(int keycode, t_fdf *fdf);
void			trans_horizontal(int keycode, t_fdf *fdf);
void			trans_vertical(int keycode, t_fdf *fdf);
void			rotate(int keycode, t_fdf *fdf);
void			counter_rotate(t_fdf *fdf, int y, int x, double a);
void			reset(t_fdf *fdf);
void			zoom(int keycode, t_fdf *fdf);
void			change_color(int keycode, t_fdf *fdf);
void			escape(t_fdf *fdf);

#endif
