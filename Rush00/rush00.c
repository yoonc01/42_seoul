/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:18:16 by yaekim            #+#    #+#             */
/*   Updated: 2023/08/27 17:54:57 by seongcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_row(int x, char *c_ptr)
{
	ft_putchar(c_ptr[0]);
	x--;
	while (x > 1)
	{
		ft_putchar(c_ptr[1]);
		x--;
	}
	if (x == 1)
		ft_putchar(c_ptr[2]);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x < 1 || y < 1)
	{
		write(1, "ERROR!", 6);
		return ;
	}
	print_row(x, "o-o");
	y--;
	while (y > 1)
	{
		print_row(x, "| |");
		y--;
	}
	if (y == 1)
		print_row(x, "o-o");
}