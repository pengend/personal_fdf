/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 03:36:09 by pxia              #+#    #+#             */
/*   Updated: 2014/12/27 23:53:44 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_trace_line(t_3d *c1, t_3d *c2, t_img *im)
{
	double			a;

	a = (c2->y - c1->y) / (c2->x - c1->x);
	if (ABS(c2->x - c1->x) == 0)
	{
		ft_trace_d(c1, c2, im, 1);
	}
	else if (ABS(c2->y - c1->y) == 0)
	{
		ft_trace_d(c1, c2, im, 0);
	}
	else
	{
		if (ABS(a) > 1)
			ft_trace1(a, c1, c2, im);
		else
			ft_trace0(a, c1, c2, im);
	}
}

void				ft_trace_v(t_env *e)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (j < e->max_x)
	{
		i = 0;
		while (i < e->max_y - 1)
		{
			while ((i < e->max_y - 1) && (!(e->a[i][j]) || !(e->a[i + 1][j])))
				i++;
			if (i == e->max_y - 1)
				break ;
			e->i->color = e->a[i][j]->color >= e->a[i + 1][j]->color ?
				e->a[i + 1][j]->color : e->a[i][j]->color;
			ft_trace_line(e->a[i][j], e->a[i + 1][j], e->i);
			i++;
		}
		j++;
	}
}

void				ft_trace_h(t_env *e)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while ((e->a[i]))
	{
		j = 0;
		while (e->a[i][j + 1])
		{
			e->i->color = e->a[i][j]->color >= e->a[i][j + 1]->color ?
				e->a[i][j + 1]->color : e->a[i][j]->color;
			ft_trace_line(e->a[i][j], e->a[i][j + 1], e->i);
			j++;
		}
		i++;
	}
}
