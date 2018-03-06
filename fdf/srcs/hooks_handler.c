/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:12:22 by wzaim             #+#    #+#             */
/*   Updated: 2017/12/28 18:28:39 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		my_key_func(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		escape(fdf);
	if (keycode == 123 || keycode == 124)
		trans_horizontal(keycode, fdf);
	if (keycode == 125 || keycode == 126)
		trans_vertical(keycode, fdf);
	if (keycode == 88 || keycode == 86)
		rotate(keycode, fdf);
	if (keycode == 24 || keycode == 27)
		zoom(keycode, fdf);
	if (keycode == 15 || keycode == 11 || keycode == 5)
		change_color(keycode, fdf);
	if (keycode == 8)
		reset(fdf);
	return (1);
}

void	reset(t_fdf *fdf)
{
	int	y;
	int	x;

	y = -1;
	while (++y < fdf->y_max)
	{
		x = -1;
		while (++x < fdf->x_max)
		{
			fdf->map[y][x].z = fdf->first_map[y][x].z;
			fdf->map[y][x].y = fdf->first_map[y][x].y;
			fdf->map[y][x].x = fdf->first_map[y][x].x;
		}
	}
	fdf->color = 0x00FFFFFF;
	mlx_draw(fdf);
}

void	escape(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf);
	exit(1);
}
