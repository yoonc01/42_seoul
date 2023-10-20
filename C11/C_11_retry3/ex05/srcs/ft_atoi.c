/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:10:11 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/11 15:19:49 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sign(char c)
{
	if (c == '+' || c == '-')
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

	ans = 0;
	minus = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	while (is_sign(*str))
	{
		if (*str == '-')
			minus = !minus;
		str++;
	}
	while (is_digit(*str))
	{
		ans = ans * 10 + (*str - '0');
		str++;
	}
	if (minus)
		ans = -1 * ans;
	return (ans);
}
