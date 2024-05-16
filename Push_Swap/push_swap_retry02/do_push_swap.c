/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:19:12 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/05/15 23:37:01 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	digit_num(int len)
{
	long	power;
	int		cnt;

	power = 1;
	cnt = 1;
	while (!(power <= (long) len && (long) len < 2 * power))
	{
		power = 2 * power;
		cnt++;
	}
	return (cnt);
}

static t_deque	*relative_dq(int *arr, int *sorted_arr, int n)
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

void	do_push_swap(int *arr, int *sorted_arr, int len)
{
	int		i;
	int		repeat;
	t_deque	*dq1;
	t_deque	*dq2;

	i = 0;
	repeat = digit_num(len);
	dq1 = relative_dq(arr, sorted_arr, len);
	dq2 = create_deque();
	while (i < repeat)
	{
		do_swap(dq1, dq2, len, 1 << i);
		i++;
	}
	while (dq1->front != 0)
		delete_front(dq1);
	free(dq1);
	free(dq2);
}
