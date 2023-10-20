/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:03:06 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/14 15:23:15 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_atoi(char *str)
{
	int	ans;

	ans = 0;
	while (*str != '\0')
	{
		if ('0' <= *str && *str <= '9')
			ans = 10 * ans + (*str - '0');
		str++;
	}
	return (ans);
}

void	print_reverse(char *str, int given)
{
	int i;

	i = 0;
	while(*str != '\0')
		str++;
	str--;
	while (i < given)
	{
		write(1, str, 1);
		str--;
		i++;
	}
}
