/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:04:56 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/03/12 14:24:00 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
void	put_c(char c, int *len);
void	_doprnt(const char *fmt, va_list *argp, int *len);
void	print_c(va_list *argp, int *len);
void	print_s(va_list *argp, int *len);
void	positive(long n, int *len, char *digits);
void	positive_u(unsigned long n, int *len, char *digits);
void	negative(long n, int *len, char *digits);
void	print_d(va_list *argp, int *len);
void	print_u(va_list *argp, int *len);
void	print_x(va_list *argp, int *len, char *digits);
void	print_p(va_list *argp, int *len);

#endif
