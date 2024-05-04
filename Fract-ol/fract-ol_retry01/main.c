
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:41:43 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/04/30 14:50:36 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_fractal(t_fractol *fractal)
{
	if (fractal->name == 0)
		_mandelbrot(fractal);
	else if (fractal->name == 1)
		_julia(fractal);
	else
		_burningship(fractal);
}

static int	close_win(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

static void	classify_fractal(int ac, char **av, t_fractol *fractal)
{
	if (ac == 2 && (ft_strcmp(av[1], "mandelbrot") == 0))
		fractal->name = 0;
	else if (ac == 2 && (ft_strcmp(av[1], "burningship") == 0))
		fractal->name = 2;
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		fractal->name = 1;
		fractal->c.r = atodb(av[2]);
		fractal->c.i = atodb(av[3]);
	}
	else
	{
		write(2, "mandelbrot, julia (double) (double), burningship\n", 49);
		exit(EXIT_FAILURE);
	}
	init_fractal(fractal);
	do_fractal(fractal);
}

int	main(int ac, char **av)
{
	t_fractol	*fractal;

	fractal = (t_fractol *)malloc(sizeof(t_fractol));
	if (fractal == 0)
		return (1);
	init_mlx_win(fractal);
	classify_fractal(ac, av, fractal);
	mlx_hook(fractal->win, 17, 0L, close_win, fractal);
	mlx_key_hook(fractal->win, key_hook, fractal);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
	mlx_loop(fractal->mlx);
	free(fractal);
	return (0);
}
