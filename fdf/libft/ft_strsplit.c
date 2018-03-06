/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:35:23 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/17 18:31:36 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_w(char const *s, char c)
{
	int		k;
	int		i;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			k++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (k);
}

static	char	*ft_extract_word(char const *s, int index, char c)
{
	int		j;
	size_t	len;
	char	*dest;

	j = index;
	len = 0;
	while (s[j] != c && s[j] != '\0')
	{
		j++;
		len++;
	}
	if ((dest = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	j = 0;
	while (s[index] != c && s[index] != '\0')
		dest[j++] = s[index++];
	dest[j] = '\0';
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**sp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(s) || c == '\0')
		return (NULL);
	if ((sp = (char**)malloc(sizeof(char*) * (ft_count_w(s, c) + 1))) == NULL)
		return (NULL);
	while (i < ft_count_w(s, c))
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		if (s[j] != '\0')
		{
			sp[i] = ft_extract_word(s, j, c);
			i++;
		}
		while (s[j] != c && s[j] != '\0')
			j++;
	}
	sp[i] = NULL;
	return (sp);
}
