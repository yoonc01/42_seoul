/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:51:37 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/10 14:51:01 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	calset(char *a, char *cal, char *b)
{
	int	x;
	int	y;

	x = ft_atoi(a);
	y = ft_atoi(b);
	if (ft_strcmp(cal, "+") == 0)
		plus(x, y);
	else if (ft_strcmp(cal, "-") == 0)
		minus(x, y);
	else if (ft_strcmp(cal, "/") == 0)
		div(x, y);
	else if (ft_strcmp(cal, "*") == 0)
		mul(x, y);
	else if (ft_strcmp(cal, "%") == 0)
		mod(x, y);
	else
		write(2, "0\n", 2);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	else
		calset(av[1], av[2], av[3]);
	return (0);
}
