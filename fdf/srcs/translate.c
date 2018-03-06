/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:40:33 by wzaim             #+#    #+#             */
/*   Updated: 2017/12/28 18:42:02 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	trans_horizontal(int keycode, t_fdf *fdf)
{
	int		y;
	int		x;

	y = -1;
	while (++y < fdf->y_max)
	{
		x = -1;
		while (++x < fdf->x_max)
		{
			if (keycode == 124)
				fdf->map[y][x].x += 10;
			else
				fdf->map[y][x].x -= 10;
		}
	}
	mlx_draw(fdf);
}

void	trans_vertical(int keycode, t_fdf *fdf)
{
	int		y;
	int		x;

	y = -1;
	while (++y < fdf->y_max)
	{
		x = -1;
		while (++x < fdf->x_max)
		{
			if (keycode == 125)
				fdf->map[y][x].y += 10;
			else
				fdf->map[y][x].y -= 10;
		}
	}
	mlx_draw(fdf);
}
