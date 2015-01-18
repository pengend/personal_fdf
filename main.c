/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 17:29:29 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 15:28:13 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_puterror(int c)
{
	if (c == 0)
		ft_putstr("Error : wrong arguments.\n");
	else
		ft_putstr("Error : map does not exist.\n");
	exit(0);
}

void		ft_check_error(t_2d *info, int argc)
{
	if (argc != 2)
		ft_puterror(0);
	if (info == NULL)
		ft_puterror(1);
}

int			main(int argc, char **argv)
{
	t_3d	***c;
	char	*line;
	int		fd;
	int		j;
	t_2d	*info;

	info = ft_getinfo(argv[1]);
	ft_check_error(info, argc);
	c = (t_3d***)malloc(sizeof(t_3d**) * info->y + 1);
	fd = open(argv[1], O_RDONLY);
	j = 0;
	while (j < info->y)
	{
		get_next_line(fd, &line);
		c[j] = ft_strsplit(line, ' ', j, info);
		free(line);
		line = NULL;
		j++;
	}
	c[j] = NULL;
	close(fd);
	ft_win(c, info);
	return (0);
}
