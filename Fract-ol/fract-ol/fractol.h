/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:42:18 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/04/30 14:46:30 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH	800
# define HEIGHT	800

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractol
{
	int			name;
	int			color;
	int			it_max;
	t_img		img;
	void		*mlx;
	void		*win;
	double		x;
	double		y;
	double		zoom;
	t_complex	c;
}				t_fractol;

void	_burningship(t_fractol *fractal);
int		key_hook(int keycode, t_fractol *fractal);
void	_zoom_in(int x, int y, t_fractol *fractal);
void	_zoom_out(int x, int y, t_fractol *fractal);
int		mouse_hook(int mousecode, int x, int y, t_fractol *fractal);
void	init_fractal(t_fractol *fractal);
void	init_mlx_win(t_fractol *fractal);
void	_julia(t_fractol *fractal);
void	do_fractal(t_fractol *fractal);
void	_mandelbrot(t_fractol *fractal);
int		ft_strncmp(char *s1, char *s2, size_t n);
double	atodb(char *str);
void	put_pxl_to_img(t_fractol *fractal, int x, int y, int color);

#endif
