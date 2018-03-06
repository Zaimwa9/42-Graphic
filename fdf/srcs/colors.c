/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:11:47 by wzaim             #+#    #+#             */
/*   Updated: 2017/12/28 18:12:08 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		change_color(int keycode, t_fdf *fdf)
{
	if (keycode == 15)
		fdf->color = 0x00B9121B;
	else if (keycode == 5)
		fdf->color = 0x00079423;
	else if (keycode == 11)
		fdf->color = 0x0001B0F0;
	mlx_draw(fdf);
}
