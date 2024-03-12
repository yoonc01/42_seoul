/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:30:06 by yunhyojun         #+#    #+#             */
/*   Updated: 2024/03/11 12:29:34 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list *argp, int *len)
{
	char	c;

	c = va_arg(*argp, int);
	put_c(c, len);
}

void	print_s(va_list *argp, int *len)
{
	char	*p;

	p = va_arg(*argp, char *);
	if (p == (char *) 0)
		p = "(null)";
	while (*p != '\0')
	{
		put_c(*p, len);
		p++;
	}
}

void	positive(long n, int *len, char *digits)
{
	if (0 <= n && n < 10)
		put_c(digits[n], len);
	else
	{
		positive(n / 10, len, digits);
		put_c(digits[n % 10], len);
	}
}

void	negative(long n, int *len, char *digits)
{
	if (-10 < n && n <= 0)
		put_c(digits[-1 * n], len);
	else
	{
		negative(n / 10, len, digits);
		put_c(digits[-(n % 10)], len);
	}
}

void	print_d(va_list *argp, int *len)
{
	int	n;

	n = va_arg(*argp, int);
	if (n < 0)
	{
		put_c('-', len);
		negative(n, len, "0123456789");
	}
	else
		positive(n, len, "0123456789");
}
