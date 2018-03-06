/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:42:07 by wzaim             #+#    #+#             */
/*   Updated: 2017/11/15 19:52:55 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*nextnode;

	if (!(alst) || !(del))
		return ;
	tmp = *alst;
	while (tmp)
	{
		nextnode = tmp->next;
		ft_lstdelone(&tmp, del);
		tmp = nextnode;
	}
	*alst = NULL;
}
