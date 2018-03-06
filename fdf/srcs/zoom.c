/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:42:07 by wzaim             #+#    #+#             */
/*   Updated: 2017/12/28 18:42:40 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(int keycode, t_fdf *fdf)
{
	int		y;
	int		x;

	y = -1;
	while (++y < fdf->y_max)
	{
		x = -1;
		while (++x < fdf->x_max)
		{
			if (keycode == 24)
			{
				fdf->map[y][x].x = fdf->map[y][x].x * 1.1;
				fdf->map[y][x].y = fdf->map[y][x].y * 1.1;
			}
			else
			{
				fdf->map[y][x].x = fdf->map[y][x].x * 0.9;
				fdf->map[y][x].y = fdf->map[y][x].y * 0.9;
			}
		}
	}
	mlx_draw(fdf);
}
