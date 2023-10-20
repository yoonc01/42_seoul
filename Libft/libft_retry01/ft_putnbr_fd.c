/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:03:03 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/10/15 19:49:32 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	positive(int n, int fd)
{
	char	d;

	if (0 <= n && n < 10)
	{
		d = n + '0';
		write(fd, &d, 1);
		return ;
	}
	positive(n / 10, fd);
	d = n % 10 + '0';
	write(fd, &d, 1);
}

static void	negative(int n, int fd)
{
	char	d;

	if (-10 < n && n <= 0)
	{
		d = -1 * n + '0';
		write(fd, &d, 1);
		return ;
	}
	negative(n / 10, fd);
	d = -1 * (n % 10) + '0';
	write(fd, &d, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	write(fd, "-", n < 0);
	if (n < 0)
		negative(n, fd);
	else
		positive(n, fd);
}
