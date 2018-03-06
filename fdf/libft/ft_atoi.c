/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:53:21 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/16 14:36:01 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	result;
	int		flag;

	result = 0;
	flag = 1;
	while (*str == '\t' || *str == '\n' || *str == 32 || *str == '\r' \
			|| *str == '\b' || *str == '\v' || *str == '\a' || *str == '\f')
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) == 1 && (*str))
		result = result * 10 + (*str++ - 48);
	return ((int)result * flag);
}
