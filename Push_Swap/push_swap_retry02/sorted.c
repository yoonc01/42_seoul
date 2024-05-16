/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:02:03 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/05/15 23:34:26 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *arr, int idx_a, int idx_b)
{
	int	temp;

	temp = arr[idx_a];
	arr[idx_a] = arr[idx_b];
	arr[idx_b] = temp;
}

static void	sort_arr(int *arr, int n)
{
	int	idx;
	int	j;
	int	min_idx;

	idx = 0;
	while (idx < n)
	{
		min_idx = idx;
		j = idx + 1;
		while (j < n)
		{
			if (arr[min_idx] > arr[j])
				min_idx = j;
			else if (arr[min_idx] == arr[j])
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		swap(arr, idx, min_idx);
		idx++;
	}
}

int	*sorted(int *arr, int n)
{
	int	idx;
	int	*result;

	idx = 0;
	result = (int *)malloc(sizeof(int) * n);
	if (result == 0)
		exit(EXIT_FAILURE);
	while (idx < n)
	{
		result[idx] = arr[idx];
		idx++;
	}
	sort_arr(result, n);
	return (result);
}
