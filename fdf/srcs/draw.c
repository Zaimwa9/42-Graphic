/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:14:53 by wzaim             #+#    #+#             */
/*   Updated: 2017/12/29 19:20:05 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mlx_draw(t_fdf *fdf)
{
	int	y;
	int	x;

	mlx_clear_window(fdf->mlx, fdf->win);
	if (fdf->x_max == 1 && fdf->y_max == 1)
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->map[0][0].x + fdf->center_x,
		fdf->map[0][0].y + fdf->center_y, fdf->color);
	y = -1;
	while (++y < fdf->y_max)
	{
		x = -1;
		while (++x < fdf->x_max - 1)
			mlx_draw_lines(fdf, fdf->map[y][x], fdf->map[y][x + 1]);
	}
	x = -1;
	while (++x < fdf->x_max)
	{
		y = -1;
		while (++y < fdf->y_max - 1)
			mlx_draw_lines(fdf, fdf->map[y][x], fdf->map[y + 1][x]);
	}
}

void	mlx_draw_lines(t_fdf *fdf, t_point_3d p1, t_point_3d p2)
{
	float i;
	float dx;
	float dy;

	i = 0;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (p1.x < p2.x)
		mlx_draw_p_lines(fdf, p1, p2);
	else if (p1.x > p2.x)
		mlx_draw_v_lines(fdf, p1, p2);
	else
	{
		if (p1.y < p2.y)
		{
			while (p1.y + i < p2.y)
			{
				if (p1.x + fdf->center_x > 0 && p1.y + i + fdf->center_y > 0)
					mlx_pixel_put(fdf->mlx, fdf->win, p1.x + fdf->center_x,
									p1.y + i + fdf->center_y, fdf->color);
				i += 0.1;
			}
		}
	}
}

void	mlx_draw_p_lines(t_fdf *fdf, t_point_3d p1, t_point_3d p2)
{
	float i;
	float a;
	float dx;
	float dy;

	i = 0;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	while (p1.x + i < p2.x)
	{
		if (dx != 0)
			a = dy / dx;
		else
			a = 0;
		if (p1.x + i + fdf->center_x > 0 && p1.y + (a * i) + fdf->center_y > 0)
			mlx_pixel_put(fdf->mlx, fdf->win, p1.x + i + fdf->center_x,
							p1.y + (a * i) + fdf->center_y, fdf->color);
		i += 0.1;
	}
}

void	mlx_draw_v_lines(t_fdf *fdf, t_point_3d p1, t_point_3d p2)
{
	float i;
	float a;
	float dx;
	float dy;

	i = 0;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	while (p2.x + i < p1.x)
	{
		if (dx != 0)
			a = dy / dx;
		else
			a = 0;
		if (p2.x + i + fdf->center_x > 0 && p2.y + (a * i) + fdf->center_y > 0)
			mlx_pixel_put(fdf->mlx, fdf->win, p2.x + i + fdf->center_x,
							p2.y + (a * i) + fdf->center_y, fdf->color);
		i += 0.1;
	}
}
