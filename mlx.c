/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 19:19:47 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 15:31:49 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_win(t_3d ***c, t_2d *info)
{
	t_env e;

	if ((e.mlx = mlx_init()) == NULL)
		exit(0);
	e.win = mlx_new_window(e.mlx, 2000, 1000, "42");
	e.c = c;
	e.max_y = info->y;
	e.max_x = info->x;
	e.ts = (t_2d*)malloc(sizeof(t_2d));
	e.ts->x = 900;
	e.ts->y = 400;
	e.zoom = 2;
	e.i = (t_img*)malloc(sizeof(t_img));
	e.i->mlx = e.mlx;
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
