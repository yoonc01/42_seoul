/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:11:18 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/03/28 18:18:10 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

int	ft_atoi(const char *str)
{
	int		ans;
	int		minus;

	ans = 0;
	minus = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		minus = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		ans = 10 * ans + (*str - '0');
		str++;
	}
	if (minus)
		ans = -1 * ans;
	return (ans);
}
