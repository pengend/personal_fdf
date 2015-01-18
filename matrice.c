/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 15:32:47 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 15:28:38 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void rotationx(t_3d *c, double rad)
{
	double tmp1;
	double tmp2;
	double tmp3;

	tmp1 = c->x;
	tmp2 = c->y;
	tmp3 = c->z;
	c->x = tmp1;
	c->y = tmp2 * cos(rad) - tmp3 * sin(rad);
	c->z = tmp2 * sin(rad) + tmp3 * cos(rad);
}

void rotationy(t_3d *c, double rad)
{
	double tmp1;
	double tmp2;
	double tmp3;

	tmp1 = c->x;
	tmp2 = c->y;
	tmp3 = c->z;
	c->x = tmp1 * cos(rad) + tmp3 * sin(rad);
	c->y = tmp2;
	c->z = tmp1 * sin(rad) * (-1) + tmp3 * cos(rad);
}

void rotationz(t_3d *c, double rad)
{
	double tmp1;
	double tmp2;
	double tmp3;

	tmp1 = c->x;
	tmp2 = c->y;
	tmp3 = c->z;
	c->x = tmp1 * cos(rad) - tmp2 * sin(rad);
	c->y = tmp1 * sin(rad) + tmp2 * cos(rad);
	c->z = tmp3;
}

void trans(t_3d ***c)
{
	int i;
	int j;

	i = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			rotationx(c[i][j], M_PI / 6);
			rotationy(c[i][j], -(M_PI / 6));
			j++;
		}
		i++;
	}
}

void get_trans(t_env *e, void (f)(t_3d*, double), double n)
{
	int i;
	int j;

	i = 0;
	while (e->c[i])
	{
		j = 0;
		while (e->c[i][j])
		{
			(f)(e->c[i][j], n);
			j++;
		}
		i++;
	}
}
