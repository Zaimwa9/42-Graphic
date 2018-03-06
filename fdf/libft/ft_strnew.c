/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:16:18 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/13 18:29:20 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	if ((str = ft_memalloc(size + 1)) == NULL)
		return (NULL);
	while (size > 0)
	{
		str[i++] = '\0';
		size--;
	}
	return (str);
}
