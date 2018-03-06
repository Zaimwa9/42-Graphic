/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:11:18 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/14 15:14:43 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	if (!(f) || !(s))
		return (NULL);
	i = ft_strlen(s);
	if ((str = ft_memalloc(i + 1)) == NULL)
		return (NULL);
	while (i > 0)
	{
		str[j] = f((unsigned int)j, s[j]);
		j++;
		i--;
	}
	return (str);
}
