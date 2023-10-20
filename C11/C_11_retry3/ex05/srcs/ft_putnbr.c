/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:24:09 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/11 15:20:07 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

void	negative(int nb)
{
	char	d;

	if (-9 <= nb && nb <= 0)
	{
		d = -nb + '0';
		write(1, &d, 1);
		return ;
	}
	d = -1 * (nb % 10) + '0';
	negative(nb / 10);
	write(1, &d, 1);
}

void	positive(int nb)
{
	char	d;

	if (0 <= nb && nb < 10)
	{
		d = nb + '0';
		write(1, &d, 1);
		return ;
	}
	d = nb % 10 + '0';
	positive(nb / 10);
	write(1, &d, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		negative(nb);
	}
	else
		positive(nb);
}
