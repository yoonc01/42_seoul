/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:15:01 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/24 21:41:57 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_last(int *visited, int num)
{
	int	i;
	int	end;

	i = 9;
	end = 1;
	while (9 - num < i)
	{
		if (!visited[i])
			end = 0;
		i--;
	}
	return (end);
}

void	print_ans(int *visited, int num)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		if (visited[(int)(c - 48)])
		{
			write(1, &c, 1);
		}
		c++;
	}
	if (!check_last(visited, num))
		write(1, ", ", 2);
}

void	combination(int index, int count, int num, int *visited)
{
	int	i;
	int	end;

	end = 1;
	if (count == num)
	{
		print_ans(visited, num);
		return ;
	}
	i = index;
	while (i <= 9)
	{
		if (visited[i])
		{
			i++;
			continue ;
		}
		visited[i] = 1;
		combination(i + 1, count + 1, num, visited);
		visited[i] = 0;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	visited[10];
	int	i;

	i = 0;
	while (i <= 9)
	{
		visited[i] = 0;
		i++;
	}
	combination(0, 0, n, visited);
}
