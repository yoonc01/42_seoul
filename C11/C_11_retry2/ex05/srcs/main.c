/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:51:37 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/11 15:22:53 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	plus(int x, int y);
void	minus(int x, int y);
void	div(int x, int y);
void	mul(int x, int y);
void	mod(int x, int y);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);

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
