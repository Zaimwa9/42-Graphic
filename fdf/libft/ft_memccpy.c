/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:26:03 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/15 18:41:21 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;
	size_t			i;

	i = 0;
	tmp = (unsigned char*)dest;
	tmp2 = (unsigned char*)src;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		if (tmp[i] == (unsigned char)c)
			return (tmp + i + 1);
		i++;
	}
	return (NULL);
}
