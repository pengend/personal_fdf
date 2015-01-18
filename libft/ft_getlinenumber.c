/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlinenumber.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 17:54:36 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 15:41:33 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_getlinenumber(char *filename)
{
	int		fd;
	char	buff[100];
	int		i;
	int		nline;
	int		ret;

	fd = open(filename, O_RDONLY);
	nline = 0;
	while ((ret = (read(fd, buff, 100))))
	{
		buff[ret] = '\0';
		i = 0;
		while (buff[i])
		{
			if (buff[i] == '\n')
				nline++;
			i++;
		}
	}
	close(fd);
	return (nline);
}
