/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:28:33 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/04 17:16:43 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*fdf_parse(t_fdf *fdf, char *path)
{
	int		fd;
	char	**tmp;
	char	*line;
	int		i;

	i = 0;
	fdf_get_dim(fdf, path);
	if (fdf->y_max == 0 || fdf->x_max == 0)
		ft_exit();
	fd = fdf_check_parse_error(path, fdf);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = 0;
		tmp = ft_strsplit(line, ' ');
		fdf_fill_map(fdf, tmp, i);
		i++;
		free(line);
		fdf_free_tab(tmp);
	}
	if (i != 0)
		free(line);
	fdf->center_x = (WIN_X / 2) - (fdf->map[fdf->y_max / 2][fdf->x_max / 2].x);
	fdf->center_y = (WIN_Y / 2) - (fdf->map[fdf->y_max / 2][fdf->x_max / 2].y);
	return (fdf);
}

void	fdf_get_dim(t_fdf *fdf, char *path)
{
	char	**tmp;
	char	*line;
	int		i;
	int		fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		ft_exit();
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		tmp = ft_strsplit(line, ' ');
		while (tmp[i])
			i++;
		if (!fdf->x_max)
			fdf->x_max = i;
		else if (i != fdf->x_max)
			ft_exit();
		fdf->y_max++;
		free(line);
		fdf_free_tab(tmp);
	}
	if (i != 0)
		free(line);
	if (close(fd) == -1)
		ft_exit();
}

int		fdf_check_parse_error(char *path, t_fdf *fdf)
{
	int fd;

	if ((fd = open(path, O_RDONLY)) == -1
		|| !(fdf->map = (t_point_3d **)malloc(sizeof(t_point_3d *)
			* fdf->y_max)))
		ft_exit();
	return (fd);
}

void	fdf_fill_map(t_fdf *fdf, char **tmp, int i)
{
	int	j;

	j = 0;
	if (!(fdf->map[i] = (t_point_3d *)malloc(sizeof(t_point_3d) * fdf->x_max)))
		ft_exit();
	while (j < fdf->x_max)
	{
		fdf->map[i][j].z = ft_atoi(tmp[j]);
		if (fdf->map[i][j].z > 50)
			fdf->map[i][j].z = 50;
		if (fdf->map[i][j].z < -50)
			fdf->map[i][j].z = -50;
		fdf->map[i][j].y = (-fdf->map[i][j].z + (0.5 * i) + (j * 0.5)) * 20;
		fdf->map[i][j].x = (j - i) * 20;
		j++;
	}
}

void	fdf_free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
