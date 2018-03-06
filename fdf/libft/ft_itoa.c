/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:07:22 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/15 16:07:28 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_nb_digits(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 1)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*dest;
	long	nb;
	size_t	len;

	nb = n;
	len = get_nb_digits(nb);
	if ((dest = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	if (nb < 0)
		nb = -nb;
	dest[len] = '\0';
	while (len > 0)
	{
		dest[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
