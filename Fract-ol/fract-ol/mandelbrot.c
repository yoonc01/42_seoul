/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:45:45 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/04/30 13:51:14 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	do_mandelbrot(int x, int y, t_fractol *fractal)
{
	t_complex	c;
	t_complex	z;
	t_complex	next;
	int			i;

	c.r = x / fractal->zoom + fractal->x;
	c.i = y / fractal->zoom + fractal->y;
	z.r = 0;
	z.i = 0;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < fractal->it_max)
	{
		next.r = z.r * z.r - z.i * z.i + c.r;
		next.i = 2 * z.r * z.i + c.i;
		z.r = next.r;
		z.i = next.i;
		i++;
	}
	if (i == fractal->it_max)
		put_pxl_to_img(fractal, x, y, 0x000000);
	else
		put_pxl_to_img(fractal, x, y, (fractal->color * i));
}

void	_mandelbrot(t_fractol *fractal)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			do_mandelbrot(x, y, fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win,
		fractal->img.img_ptr, 0, 0);
}
