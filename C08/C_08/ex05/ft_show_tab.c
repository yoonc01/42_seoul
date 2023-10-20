/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:46:22 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/06 14:50:27 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	print_str(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	positive(int num)
{
	char	d;

	if (0 <= num && num < 10)
	{
		d = num + '0';
		write(1, &d, 1);
		return ;
	}
	positive(num / 10);
	d = num % 10 + '0';
	write(1, &d, 1);
}

void	print_next_line(void)
{
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *ptr)
{
	while ((*ptr).str != 0)
	{
		positive((*ptr).size);
		print_next_line();
		print_str((*ptr).str);
		print_next_line();
		print_str((*ptr).copy);
		print_next_line();
		ptr++;
	}
}
