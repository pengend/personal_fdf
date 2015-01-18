/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 15:28:27 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 15:25:51 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_init(t_img *i, t_env *e)
{
	int dec_x;
	int dec_y;

	if (i->n == 1)
		ft_bzero(i->data, 1000 * e->i->size_line + e->i->bpp / 8 * 2000);
	else
	{
		dec_x = 2000;
		dec_y = 1000;
		i->img = mlx_new_image(e->mlx, dec_x, dec_y);
		i->data = mlx_get_data_addr(i->img, &(i->bpp),
									&(i->size_line), &(i->endian));
		i->n = 1;
	}
}

void	view_angle(int keycode, t_env *e)
{
	if (keycode == 65361)
		get_trans(e, rotationy, -(M_PI / 18));
	else if (keycode == 65363)
		get_trans(e, rotationy, M_PI / 18);
	else if (keycode == 65362)
		get_trans(e, rotationx, M_PI / 18);
	else if (keycode == 65364)
		get_trans(e, rotationx, -(M_PI / 18));
	else if (keycode == 97)
		e->ts->x -= 100;
	else if (keycode == 119)
		e->ts->y -= 100;
	else if (keycode == 100)
		e->ts->x += 100;
	else if (keycode == 115)
		e->ts->y += 100;
	else if (keycode == 113)
		e->zoom *= 2;
	else if (keycode == 101)
		e->zoom /= 2;
	get_affi(e->c, e->a, e->ts, e->zoom);
	img_init(e->i, e);
	ft_trace_h(e);
	ft_trace_v(e);
	mlx_put_image_to_window(e->mlx, e->win, e->i->img, 0, 0);
}

int		expose_hook(t_env *e)
{
	trans(e->c);
	e->a = get_init(e);
	img_init(e->i, e);
	ft_trace_h(e);
	ft_trace_v(e);
	mlx_put_image_to_window(e->mlx, e->win, e->i->img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	else
		view_angle(keycode, e);
	return (0);
}
