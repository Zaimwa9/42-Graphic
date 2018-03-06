/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_include.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:03:59 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/17 20:54:41 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_include(char **argv, char *needle, size_t n)
{
	size_t	i;

	i = 0;
	if (!(argv) || !(needle))
		return (0);
	while (i < n)
	{
		if (ft_strcmp(argv[i], needle) == 0)
			return (i);
		i++;
	}
	return (-1);
}
