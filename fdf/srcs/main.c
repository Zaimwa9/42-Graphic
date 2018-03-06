/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:24:12 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/02 16:08:50 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		fdf_save_map(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	if (!(fdf->first_map = (t_point_3d **)malloc(sizeof(t_point_3d *)
		* fdf->y_max)))
		ft_exit();
	while (i < fdf->y_max)
	{
		if (!(fdf->first_map[i] = (t_point_3d *)malloc(sizeof(t_point_3d)
			* fdf->x_max)))
			ft_exit();
		j = 0;
		while (j < fdf->x_max)
		{
			fdf->first_map[i][j].z = fdf->map[i][j].z;
			fdf->first_map[i][j].x = fdf->map[i][j].x;
			fdf->first_map[i][j].y = fdf->map[i][j].y;
			j++;
		}
		i++;
	}
}

void		fdf_init(t_fdf *fdf)
{
	fdf->x_max = 0;
	fdf->y_max = 0;
	fdf->center_x = 0;
	fdf->center_y = 0;
	fdf->is_isometric = 1;
	fdf->map = NULL;
	fdf->first_map = NULL;
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->color = 0x00FFFFFF;
}

void		fdf_to_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_X, WIN_Y, "fdf");
	mlx_draw(fdf);
	mlx_key_hook(fdf->win, my_key_func, fdf);
	mlx_loop(fdf->mlx);
}

void		fdf_print_commands(void)
{
	ft_putendl("\t<<<<<<<<<< COMMANDS >>>>>>>>>>\n");
	ft_putendl("R ==> Color to red");
	ft_putendl("G ==> Color to green");
	ft_putendl("B ==> Color to blue");
	ft_putendl("C ==> Reset");
	ft_putendl("Direction arrows ==> Vectorial translation");
	ft_putendl("PavNum 6 ==> Clockwise rotation");
	ft_putendl("PavNum 4 ==> Counter-clockwise rotation");
	ft_putendl("'+' ==> Zoom-in");
	ft_putendl("'-' ==> Zoom-out");
	ft_putendl("ESC ==> Close window");
}

int			main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		ft_exit();
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		ft_exit();
	fdf_init(fdf);
	fdf_parse(fdf, argv[1]);
	fdf_save_map(fdf);
	fdf_print_commands();
	fdf_to_mlx(fdf);
	return (0);
}
