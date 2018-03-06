/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:38:25 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/12 22:09:12 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;
	char	*tmp2;
	size_t	i;

	i = len;
	tmp = (char*)dst;
	tmp2 = (char*)src;
	if (dst > src)
	{
		while (len > 0)
		{
			tmp[len - 1] = tmp2[len - 1];
			len--;
		}
		dst = tmp;
	}
	else
	{
		while (len-- > 0)
			*tmp++ = *tmp2++;
		dst = tmp - i;
	}
	return (dst);
}
