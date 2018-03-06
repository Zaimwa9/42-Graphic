/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:00:10 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/14 15:10:01 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		str[j] = f(s[j]);
		j++;
		i--;
	}
	return (str);
}
