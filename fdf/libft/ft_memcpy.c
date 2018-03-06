/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:48:14 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/15 18:40:19 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
		i++;
	}
	dest = tmp;
	return (dest);
}
