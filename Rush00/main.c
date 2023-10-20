/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:07:04 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/27 17:58:23 by seongcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	is_int(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || '9' < *str)
			return (0);
		str++;
	}
	return (1);
}

int	a_to_i(char *str)
{
	int	ans;
	int	negative;

	ans = 0;
	negative = 0;
	if (*str == '-')
	{
		negative = 1;
		str++;
	}
	while (*str != '\0')
	{
		ans = 10 * ans + (*str - '0');
		str++;
	}
	if (negative)
		ans = -1 * ans;
	return (ans);
}

int	main(int argc, char *argv[])
{
	int	arg1;
	int	arg2;

	if (argc == 1)
		rush(5, 3);
	else if (argc == 3)
	{
		if (is_int(argv[1]) && is_int(argv[2]))
		{
			arg1 = a_to_i(argv[1]);
			arg2 = a_to_i(argv[2]);
			rush(arg1, arg2);
		}
		else
		{
			write(1, "ERROR!", 6);
			return (1);
		}
	}
	else
	{
		write(1, "ERROR!", 6);
		return (1);
	}
	return (0);
}
