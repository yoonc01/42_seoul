/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:10:39 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/05/14 13:21:02 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	not_int(int a, int b, int sign)
{
	if (sign && a == 2147483640 && b == 8)
		return (0);
	else if (a > 0 && b > 2147483647 - a)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static int	get_sign(char *str)
{
	int	sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '\0')
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (sign);
}

int	my_atoi(char *str)
{
	int	ans;
	int	sign;

	ans = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		sign = get_sign(str);
		str++;
	}
	while (*str != '\0')
	{
		if (!ft_isdigit(*str) || not_int(10 * ans, *str - '0', sign))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		ans = 10 * ans + (*str - '0');
		str++;
	}
	return (sign * ans);
}
