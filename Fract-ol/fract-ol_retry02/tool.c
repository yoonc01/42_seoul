/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:30:42 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/05/04 17:26:10 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

static int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return (1);
	else
		return (-1);
}

double	atodb(char *str)
{
	double	ans;
	double	pow;
	int		sign;

	ans = 0;
	sign = 1;
	pow = 0.1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (ft_isdigit(*str))
		ans = 10 * ans + (*str++ - '0');
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
	{
		ans = ans + (*str - '0') * pow;
		pow = pow / 10;
		str++;
	}
	return (sign * ans);
}

void	put_pxl_to_img(t_fractol *fractal, int x, int y, int color)
{
	char			*src;
	char			*dst;
	unsigned long	i;

	if (x < WIDTH && y < HEIGHT)
	{
		i = 0;
		color = mlx_get_color_value(fractal->mlx, color);
		src = (char *)&color;
		dst = fractal->img.pixel_ptr + 4 * WIDTH * y + 4 * x;
		while (i < 4)
		{
			*dst = *src;
			dst++;
			src++;
			i++;
		}
	}
}
