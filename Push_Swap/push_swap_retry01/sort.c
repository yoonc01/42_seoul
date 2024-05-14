/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:02:03 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/05/06 14:40:52 by hyoyoon          ###   ########.fr       */
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

void	sort_arr(int *arr, int n)
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
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (idx < n)
	{
		result[idx] = arr[idx];
		idx++;
	}
	sort_arr(result, n);
	return (result);
}

t_deque	*relative_dq(int *arr, int *sorted_arr, int n)
{
	int		i;
	int		j;
	t_deque	*dq;

	i = 0;
	dq = create_deque();
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (arr[i] == sorted_arr[j])
			{
				insert_rear(dq, j + 1);
				break ;
			}
			j++;
		}
		i++;
	}
	return (dq);
}
