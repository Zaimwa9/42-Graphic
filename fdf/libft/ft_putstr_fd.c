/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:42:22 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/14 18:47:27 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t	i;
	size_t	size;

	if (!(s))
		return ;
	size = ft_strlen(s);
	i = 0;
	while (i < size)
		ft_putchar_fd(s[i++], fd);
}
