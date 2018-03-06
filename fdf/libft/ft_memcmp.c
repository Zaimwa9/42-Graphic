/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:11:53 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/13 15:32:26 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	while (n-- > 0)
	{
		if ((unsigned char)*tmp1 != (unsigned char)*tmp2)
			return ((unsigned char)(*tmp1) - (unsigned char)(*tmp2));
		tmp1++;
		tmp2++;
	}
	return (0);
}
