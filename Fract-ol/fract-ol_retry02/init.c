/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:25:52 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/05/07 12:25:55 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot_init(t_fractol *fractal)
{
	fractal->it_max = 50;
	fractal->zoom = 300;
	fractal->x = -2.05;
	fractal->y = -1.3;
	fractal->color = 265;
}

static void	julia_init(t_fractol *fractal)
{
	fractal->it_max = 500;
	fractal->zoom = 200;
	fractal->x = -2.0;
	fractal->y = -1.9;
	fractal->color = 265 << 8;
}

static void	burningship_init(t_fractol *fractal)
{
	fractal->it_max = 50;
	fractal->zoom = 220;
	fractal->x = -2.2;
	fractal->y = -2.5;
	fractal->color = 265 << 16;
}

void	init_fractal(t_fractol *fractal)
{
	if (fractal->name == 0)
		mandelbrot_init(fractal);
	else if (fractal->name == 1)
		julia_init(fractal);
	else
		burningship_init(fractal);
}

void	init_mlx_win(t_fractol *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fractol");
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
}
