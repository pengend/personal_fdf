/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 20:41:46 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 15:30:45 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			get_xy(t_3d *tc, int nb, int y)
{
	tc->x = nb * 10;
	tc->y = y * 10;
}

unsigned int	getcolor(int z)
{
	if (z < 0)
		return (0x00FFFF - z * 655);
	if (z >= 0 && z < 100)
		return (0x66CC00 + z * 3);
	if (z > 100)
		return (0xFFFFFF);
	return (0x000000);
}

t_3d			**ft_strsplit(const char *s, char c, int y, t_2d *info)
{
	t_3d		**tc;
	int			nb;
	int			i;
	int			o;

	i = 0;
	if ((tc = (t_3d**)malloc(sizeof(t_3d*) * (info->x + 1))) == NULL)
		return (0);
	nb = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		o = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		tc[nb] = (t_3d*)malloc(sizeof(t_3d));
		get_xy(tc[nb], nb, y);
		(tc[nb])->z = ft_atoi(s + o);
		(tc[nb])->color = getcolor((tc[nb])->z);
		nb++;
	}
	return (tc);
}

int				en(double n)
{
	int ent;

	ent = floor(n);
	ent = n - ent >= ent + 1 - n ? ent + 1 : ent;
	return (ent);
}
