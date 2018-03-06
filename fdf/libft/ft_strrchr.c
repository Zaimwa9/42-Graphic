/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:01:53 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/12 18:08:32 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		flag;

	flag = -1;
	i = 0;
	while ((s[i]))
	{
		if (s[i] == c)
			flag = i;
		i++;
	}
	if (s[i] == '\0' && c == 0)
		return ((char*)&s[i]);
	if (flag == -1)
		return (NULL);
	return ((char*)&s[flag]);
}
