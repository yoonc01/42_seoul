/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:38:31 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/03/12 14:41:54 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	positive_u(unsigned long n, int *len, char *digits)
{
	if (0 <= n && n < 16)
		put_c(digits[n], len);
	else
	{
		positive_u(n / 16, len, digits);
		put_c(digits[n % 16], len);
	}
}

void	print_u(va_list *argp, int *len)
{
	unsigned int	n;

	n = va_arg(*argp, unsigned int);
	positive(n, len, "0123456789");
}

void	print_x(va_list *argp, int *len, char *digits)
{
	unsigned int	n;

	n = va_arg(*argp, unsigned int);
	positive_u(n, len, digits);
}

void	print_p(va_list *argp, int *len)
{
	unsigned long	p;

	p = va_arg(*argp, unsigned long);
	put_c('0', len);
	put_c('x', len);
	positive_u(p, len, "0123456789abcdef");
}
