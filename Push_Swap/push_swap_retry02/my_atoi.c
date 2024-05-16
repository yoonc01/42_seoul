/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:10:39 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/05/16 00:11:50 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(long a, long b)
{
	long	result;

	result = a + b;
	return (-2147483648 <= result && result <= 2147483647);
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static int	get_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	if (**str == '\0')
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (sign);
}

int	my_atoi(char *str)
{
	long	ans;
	int		sign;

	ans = 0;
	sign = 1;
	sign = get_sign(&str);
	while (*str != '\0')
	{
		if (!ft_isdigit(*str) || !is_int(sign * ans * 10, sign * (*str - '0')))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		ans = 10 * ans + (*str - '0');
		str++;
	}
	return (sign * ans);
}
