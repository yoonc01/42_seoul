/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:57:01 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/04/30 14:37:42 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractol *fractal)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 69)
		fractal->it_max = fractal->it_max + 50;
	else if (keycode == 78)
		fractal->it_max = fractal->it_max - 50;
	else if (keycode == 123)
		fractal->x = fractal->x - 30 / fractal->zoom;
	else if (keycode == 124)
		fractal->x = fractal->x + 30 / fractal->zoom;
	else if (keycode == 125)
		fractal->y = fractal->y + 30 / fractal->zoom;
	else if (keycode == 126)
		fractal->y = fractal->y - 30 / fractal->zoom;
	else if (keycode == 45)
		fractal->color = (fractal->color << 8) % 0xFFFFFF;
	else if (keycode == 34)
		init_fractal(fractal);
	do_fractal(fractal);
	return (0);
}

void	_zoom_in(int x, int y, t_fractol *fractal)
{
	fractal->x = (x / fractal->zoom + fractal->x) - x / (1.3 * fractal->zoom);
	fractal->y = (y / fractal->zoom + fractal->y) - y / (1.3 * fractal->zoom);
	fractal->zoom = 1.3 * fractal->zoom;
	fractal->it_max++;
}

void	_zoom_out(int x, int y, t_fractol *fractal)
{
	fractal->x = (x / fractal->zoom + fractal->x) - x / (fractal->zoom / 1.3);
	fractal->y = (y / fractal->zoom + fractal->y) - y / (fractal->zoom / 1.3);
	fractal->zoom = fractal->zoom / 1.3;
	fractal->it_max--;
}

int	mouse_hook(int mousecode, int x, int y, t_fractol *fractal)
{
	if (mousecode == 4 || mousecode == 1)
		_zoom_in(x, y, fractal);
	else if (mousecode == 5 || mousecode == 2)
		_zoom_out(x, y, fractal);
	do_fractal(fractal);
	return (0);
}
