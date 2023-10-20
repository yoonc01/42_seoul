/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:55:59 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/30 15:55:48 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_plus(char c)
{
	if (c == '+')
		return (1);
	return (0);
}

int	is_minus(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	ans;
	int	minus;
	int	start_digit;

	ans = 0;
	minus = 0;
	start_digit = 0;
	while (*str != '\0')
	{
		if (is_digit(*str))
		{
			start_digit = 1;
			ans = ans * 10 + (*str - '0');
		}
		else if (start_digit)
			break ;
		else if (is_minus(*str))
			minus = !minus;
		str++;
	}
	if (minus)
		ans = -1 * ans;
	return (ans);
}
