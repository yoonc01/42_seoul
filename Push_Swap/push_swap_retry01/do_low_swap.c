/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_low_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:32:09 by yunhyojun         #+#    #+#             */
/*   Updated: 2024/05/12 18:23:35 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_len_5(int *arr)
{
	int	top;

	top = idx_when_sorted(arr, arr[0], 5);
	write(1, "pb\n", 3);
	do_len_4(arr + 1);
	if (top == 0)
		write(1, "pa\n", 3);
	else if (top == 1)
		write(1, "pa\nsa\n", 6);
	else if (top == 2)
		write(1, "ra\nra\npa\nrra\nrra\n", 17);
	else if (top == 3)
		write(1, "rra\npa\nra\nra\n", 13);
	else
		write(1, "pa\nra\n", 6);
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
