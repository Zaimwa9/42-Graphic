/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:35:40 by wzaim             #+#    #+#             */
/*   Updated: 2017/12/25 17:35:42 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_right_fd(t_list **list, int fd)
{
	t_list		*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)(tmp->content_size) == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(list, tmp);
	return (tmp);
}

static int		fill_line(char *content, char **line)
{
	int i;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	*line = ft_strncpy(ft_strnew(i), content, i);
	if (content[i] == '\n')
		i++;
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	int					ret;
	char				buff[BUFF_SIZE + 1];
	char				*tmp;
	t_list				*first_list;
	static	t_list		*list;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (-1);
	first_list = list;
	list = get_right_fd(&first_list, fd);
	while (!ft_strchr(list->content, '\n') && (ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		tmp = list->content;
		list->content = ft_strjoin(list->content, buff);
		free(tmp);
	}
	ret = fill_line((char *)list->content, line);
	tmp = list->content;
	list->content = ft_strdup(list->content + ret);
	free(tmp);
	list = first_list;
	return (ret ? 1 : 0);
}
