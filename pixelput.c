/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 22:40:35 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 15:26:24 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void put_pixel_to_img(t_img *im, int x, int y, unsigned int cl)
{
	unsigned int color;

	if (x >= 2000 || x < 0 || y >= 1000 || y < 0)
		return ;
	color = mlx_get_color_value(im->mlx, cl);
	im->data[y * im->size_line + im->bpp / 8 * x] = (color & 0xFF);
	im->data[y * im->size_line + im->bpp / 8 * x + 1] = (color & 0xFF00) >> 8;
	im->data[y * im->size_line + im->bpp / 8 * x + 2] =
		(color & 0xFF0000) >> 16;
}

void ppixel1(t_3d *c1, int i, int j, t_img *im)
{
	put_pixel_to_img(im, c1->x + i, c1->y + j, im->color);
}

void ppixel2(t_3d *c1, int i, int j, t_img *im)
{
	put_pixel_to_img(im, c1->x - i, c1->y - j, im->color);
}
