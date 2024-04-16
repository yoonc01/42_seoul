/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:19:12 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/04/16 17:51:21 by hyoyoon          ###   ########.fr       */
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
	free_dq(dq1, dq2);
}
