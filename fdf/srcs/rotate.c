/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:30:50 by wzaim             #+#    #+#             */
/*   Updated: 2017/12/28 18:40:20 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate(int keycode, t_fdf *fdf)
{
	int		y;
	int		x;
	double	a;

	a = 0.05;
	y = -1;
	while (++y < fdf->y_max)
	{
		x = -1;
		while (++x < fdf->x_max)
		{
			if (keycode == 88)
			{
				fdf->map[y][x].x = fdf->map[y][x].x * cos(a)
									- fdf->map[y][x].y * sin(a);
				fdf->map[y][x].y = fdf->map[y][x].y * cos(a)
									+ fdf->map[y][x].x * sin(a);
			}
			else
				counter_rotate(fdf, y, x, a);
		}
	}
	mlx_draw(fdf);
}

void	counter_rotate(t_fdf *fdf, int y, int x, double a)
{
	fdf->map[y][x].x = fdf->map[y][x].x * cos(-a) - fdf->map[y][x].y * sin(-a);
	fdf->map[y][x].y = fdf->map[y][x].y * cos(-a) + fdf->map[y][x].x * sin(-a);
}
