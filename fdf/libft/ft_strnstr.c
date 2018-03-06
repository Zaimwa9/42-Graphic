/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:21:11 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/16 13:02:28 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)&haystack[0]);
	while ((haystack[i]) && (size_t)i <= n)
	{
		if (haystack[i] == *needle && (ft_strlen(needle) + i <= n))
		{
			if ((ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0))
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
