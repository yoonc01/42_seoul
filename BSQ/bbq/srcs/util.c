/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:41:55 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/13 23:32:23 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my.h"

int	**str_to_matrix(char *str, t_map *map)
{
	int		**int_matrix;

	while (*str != '\0' && *str != '\n')
		str++;
	str++;
	int_matrix = split(str, "\n", map);
	if (int_matrix == 0)
		return (0);
	return (int_matrix);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_atoi(char *str, int n)
{
	int	ans;
	int	idx;

	ans = 0;
	idx = 0;
	while (str[idx] != '\0' && idx < n)
	{
		if ('0' <= str[idx] && str[idx] <= '9')
			ans = ans * 10 + (str[idx] - '0');
		else
			return (0);
		idx++;
	}
	return (ans);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
