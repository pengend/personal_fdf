/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 18:03:20 by pxia              #+#    #+#             */
/*   Updated: 2014/12/27 23:51:31 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_trace_d(t_3d *c1, t_3d *c2, t_img *im, int c)
{
	int		i;

	i = 0;
	if (c == 1)
		while (i <= ABS(c2->y - c1->y))
		{
			(c2->y > c1->y) ? ppixel1(c1, 0, i, im) : ppixel2(c1, 0, i, im);
			i++;
		}
	else
	{
		while (i <= ABS(c2->x - c1->x))
		{
			(c2->x > c1->x) ? ppixel1(c1, i, 0, im) : ppixel2(c1, i, 0, im);
			i++;
		}
	}
}

void		ft_trace1(double a, t_3d *c1, t_3d *c2, t_img *im)
{
	double	tmp;
	double	b;
	int		ent;
	int		i;
	int		j;

	i = 1;
	j = 0;
	tmp = 0;
	while (i <= ABS(c2->x - c1->x))
	{
		b = i * ABS(a) - tmp;
		ent = (b - floor(b) >= floor(b) + 1 - b) ?
			floor(b) + 1 : floor(b);
		tmp += ent;
		while (ent--)
		{
			(c2->x > c1->x) ? ppixel1(c1, i, j, im) : ppixel2(c1, i, j, im);
			j += (a < 0) ? -1 : 1;
		}
		i++;
	}
}

void		ft_trace0(double a, t_3d *c1, t_3d *c2, t_img *im)
{
	int		i;
	int		j;
	int		max;
	double	tmp;

	i = 1;
	j = 0;
	max = ABS(c1->x - c2->x);
	tmp = 0;
	while (i <= max)
	{
		while (i * ABS(a) - tmp < 1 && i <= max)
		{
			(c2->x > c1->x) ? ppixel1(c1, i, j, im) : ppixel2(c1, i, j, im);
			i++;
		}
		tmp = floor(i * ABS(a));
		j += (a < 0) ? -1 : 1;
	}
}
