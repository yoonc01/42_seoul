/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:46:00 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/11 15:19:22 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	plus(int a, int b)
{
	ft_putnbr(a + b);
	write(1, "\n", 1);
}

void	minus(int a, int b)
{
	ft_putnbr(a - b);
	write(1, "\n", 1);
}

void	mul(int a, int b)
{
	ft_putnbr(a * b);
	write(1, "\n", 1);
}

void	div(int a, int b)
{
	if (b == 0)
		write(2, "Stop : division by zero\n", 24);
	else
	{
		ft_putnbr(a / b);
		write(1, "\n", 1);
	}
}

void	mod(int a, int b)
{
	if (b == 0)
		write(2, "Stop : division by zero\n", 24);
	else
	{
		ft_putnbr(a % b);
		write(1, "\n", 1);
	}
}
