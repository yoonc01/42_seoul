/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_low_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:32:09 by yunhyojun         #+#    #+#             */
/*   Updated: 2024/05/15 23:29:10 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	idx_when_sorted(int *arr, int value, int size)
{
	int	i;
	int	idx;

	i = 0;
	idx = 0;
	while (i < size)
	{
		if (value > arr[i])
			idx++;
		i++;
	}
	return (idx);
}

void	do_low_swap(int *arr, int len)
{
	if (len >= 6)
		return ;
	if (len == 2)
		write(1, "sa\n", 3);
	else if (len == 3)
		do_len_3(arr);
	else if (len == 4)
		do_len_4(arr);
	else if (len == 5)
		do_len_5(arr);
	exit(EXIT_SUCCESS);
}
