/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 16:48:43 by pxia              #+#    #+#             */
/*   Updated: 2015/01/08 21:33:05 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_rp(const int fd, t_2d *info)
{
	int		i;
	int		n;
	int		ret;
	char	buff[100];

	n = 0;
	while ((ret = read(fd, buff, 100)))
	{
		buff[ret] = '\0';
		i = 0;
		while (buff[i])
		{
			if (buff[i] >= '0' && buff[i] <= '9' && n++)
				while (buff[i] && buff[i] >= '0' && buff[i] <= '9')
					i++;
			if ((buff[i]) == '\n')
			{
				info->y++;
				if (n > info->x)
					info->x = n;
				n = 0;
			}
			i += buff[i] ? 1 : 0;
		}
	}
}

t_2d		*ft_getinfo(char *filename)
{
	t_2d	*info;
	int		fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	info = (t_2d*)malloc(sizeof(t_2d));
	info->x = 0;
	info->y = 0;
	ft_rp(fd, info);
	close(fd);
	return (info);
}
