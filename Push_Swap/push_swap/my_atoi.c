/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:10:39 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/04/13 11:19:09 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	not_int(int a, int b)
{
	if (a == 2147483640 && b == 8)
		return (0);
	else if (a > 0 && b > 2147483647 - a)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	my_atoi(char *str)
{
	int	ans;
	int	minus;

	ans = 0;
	minus = 0;
	if (*str == '-')
	{
		minus = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str) || not_int(10 * ans, *str - '0'))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		ans = 10 * ans + (*str - '0');
		str++;
	}
	if (minus)
		ans = -1 * ans;
	return (ans);
}
