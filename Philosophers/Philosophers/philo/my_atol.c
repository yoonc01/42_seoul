/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:48:28 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/06/24 21:13:26 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	not_long(long a, long b)
{
	if (a > 9223372036854775807 - b && b > 0)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

long	my_atol(const char *str)
{
	long	result;

	result = 0;
	if (*str == '+')
	{
		str++;
		if (*str == '\0')
			return (-1);
	}
	while (*str != '\0')
	{
		if (!ft_isdigit(*str) || not_long(10 * result, *str - '0'))
			return (-1);
		result = 10 * result + (*str - '0');
		str++;
	}
	return (result);
}
