/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:42:12 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/16 11:44:21 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	int result;

	if (power < 0)
		return (0);
	if (power > 1)
		result = nb * ft_power(nb, power - 1);
	if (power == 1)
		return (nb);
	if (power == 0)
		return (1);
	return (result);
}
