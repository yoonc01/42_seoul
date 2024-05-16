/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_len_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:05:54 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/05/14 10:06:17 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_len_3(int *arr)
{
	int	top0;
	int	top1;
	int	top2;

	top0 = idx_when_sorted(arr, arr[0], 3);
	top1 = idx_when_sorted(arr, arr[1], 3);
	top2 = idx_when_sorted(arr, arr[2], 3);
	if (top0 == 0 && top1 == 2 && top2 == 1)
		write(1, "sa\nra\n", 6);
	else if (top0 == 1 && top1 == 0 && top2 == 2)
		write(1, "sa\n", 3);
	else if (top0 == 1 && top1 == 2 && top2 == 0)
		write(1, "rra\n", 4);
	else if (top0 == 2 && top1 == 0 && top2 == 1)
		write(1, "ra\n", 3);
	else if (top0 == 2 && top1 == 1 && top2 == 0)
		write(1, "ra\nsa\n", 6);
}
