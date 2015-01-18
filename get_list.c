/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 22:52:22 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 15:26:08 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void get_affi(t_3d ***c, t_3d ***a, t_2d *ts, double zoom)
{
	int i;
	int j;

	i = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			a[i][j]->x = en(c[i][j]->x * zoom + ts->x);
			a[i][j]->y = en(c[i][j]->y * zoom + ts->y);
			a[i][j]->z = en(c[i][j]->z * zoom);
			j++;
		}
		i++;
	}
}

t_3d ***get_init(t_env *e)
{
	t_3d	***a;
	int		i;
	int		j;

	i = 0;
	a = (t_3d***)malloc(sizeof(t_3d**) * e->max_y + 1);
	while (e->c[i])
	{
		j = 0;
		a[i] = (t_3d**)malloc(sizeof(t_3d*) * e->max_x + 1);
		ft_bzero(a[i], e->max_x);
		while (e->c[i][j])
		{
			a[i][j] = (t_3d*)malloc(sizeof(t_3d));
			a[i][j]->x = en(e->c[i][j]->x * 2 + 900);
			a[i][j]->y = en(e->c[i][j]->y * 2 + 400);
			a[i][j]->z = en(e->c[i][j]->z * 2);
			a[i][j]->color = e->c[i][j]->color;
			j++;
		}
		a[i][j] = '\0';
		i++;
	}
	a[i] = '\0';
	return (a);
}
