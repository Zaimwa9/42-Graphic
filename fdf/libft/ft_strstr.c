/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:42:45 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/12 16:10:27 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	const char	*dest;

	i = 0;
	if (ft_strlen(needle) == 0)
	{
		dest = &haystack[i];
		return ((char*)dest);
	}
	while ((haystack[i]))
	{
		if (haystack[i] == *needle)
		{
			if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
			{
				dest = &haystack[i];
				return ((char*)dest);
			}
		}
		i++;
	}
	return (NULL);
}
