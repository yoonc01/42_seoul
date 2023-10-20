/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:35:43 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/23 16:55:04 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int a)
{
	char	tens;
	char	ones;

	tens = a / 10 + '0';
	ones = a % 10 + '0';
	write(1, &tens, 1);
	write(1, &ones, 1);
}

void	print_result(int a, int b)
{
	print(a);
	write(1, " ", 1);
	print(b);
	if (!(a == 98 && b == 99))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_result(a, b);
			b++;
		}
		a++;
	}
}
