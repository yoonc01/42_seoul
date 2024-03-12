/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:29:47 by yunhyojun         #+#    #+#             */
/*   Updated: 2024/03/12 15:05:45 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_c(char c, int *len)
{
	*len = *len + write(1, &c, 1);
}

void	_doprnt(const char *fmt, va_list *argp, int *len)
{
	if (*fmt == 'c')
		print_c(argp, len);
	else if (*fmt == 's')
		print_s(argp, len);
	else if (*fmt == 'd' || *fmt == 'i')
		print_d(argp, len);
	else if (*fmt == 'u')
		print_u(argp, len);
	else if (*fmt == 'p')
		print_p(argp, len);
	else if (*fmt == 'x')
		print_x(argp, len, "0123456789abcdef");
	else if (*fmt == 'X')
		print_x(argp, len, "0123456789ABCDEF");
	else if (*fmt == '%')
		put_c('%', len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	listp;
	int		len;

	len = 0;
	va_start(listp, fmt);
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			put_c(*fmt, &len);
			fmt++;
			continue ;
		}
		fmt++;
		_doprnt(fmt, &listp, &len);
		fmt++;
	}
	va_end(listp);
	return (len);
}
