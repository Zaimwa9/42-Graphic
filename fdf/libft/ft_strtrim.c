/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:25:16 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/17 17:24:22 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;
	char	*dest;

	start = 0;
	if (!(s))
		return (NULL);
	while (s[start] == '\t' || s[start] == '\n' || s[start] == ' ')
		start++;
	len = ft_strlen(s) - 1;
	while ((s[len] == '\t' || s[len] == '\n' || s[len] == ' ') && len > 0)
		len--;
	if ((s) && start == ft_strlen(s))
		return (ft_strnew(0));
	dest = ft_strsub(s, start, (len - start + 1));
	return (dest);
}
