/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:24:09 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/23 16:37:31 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	negative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

int	digits(int n)
{
	int		i;

	i = 1;
	while (n / 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	tens_sq(int digit)
{
	int		n;

	n = 1;
	digit--;
	while (digit)
	{
		n = 10 * n;
		digit--;
	}
	return (n);
}

int	save_result(char *arr, int n, int digit)
{
	int		index;
	int		ans;

	index = 0;
	if (negative(n))
	{
		arr[0] = '-';
		index++;
		n = -n;
	}
	while (digit)
	{
		ans = n / tens_sq(digit);
		arr[index] = ans + '0';
		n = n - ans * tens_sq(digit);
		index++;
		digit--;
	}
	return (index);
}

void	ft_putnbr(int nb)
{
	char	arr[12];
	int		index;
	int		digit;

	digit = digits(nb);
	index = save_result(arr, nb, digit);
	write(1, arr, index);
}
