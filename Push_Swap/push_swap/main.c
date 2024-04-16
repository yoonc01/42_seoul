/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:27:25 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/04/16 18:04:04 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_av(char **av, int start, int n)
{
	int	idx;
	int	*result;

	idx = 0;
	result = (int *)malloc(sizeof(int) * n);
	if (result == 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (idx < n)
	{
		result[idx] = my_atoi(av[idx + start]);
		idx++;
	}
	return (result);
}

void	check_input_sorted(int *arr, int *sorted_arr, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		if (arr[idx] != sorted_arr[idx])
			return ;
		idx++;
	}
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	int		len;
	int		*arr;
	int		*sorted_arr;

	if (ac == 1)
		exit(EXIT_FAILURE);
	len = ac - 1;
	if (ac == 2)
	{
		len = 0;
		av = ft_split(av[1], ' ');
		while (av[len] != 0)
			len++;
		arr = get_av(av, 0, len);
		free_split(av);
	}
	else
		arr = get_av(av, 1, len);
	sorted_arr = sorted(arr, len);
	check_input_sorted(arr, sorted_arr, len);
	do_push_swap(arr, sorted_arr, len);
	free_arr(arr, sorted_arr);
}
