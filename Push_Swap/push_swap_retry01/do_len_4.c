/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_len_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:32:09 by yunhyojun         #+#    #+#             */
/*   Updated: 2024/05/14 10:06:38 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_4_1(int top1, int top2, int top3)
{
	if (top1 == 0 && top2 == 2 && top3 == 3)
		write(1, "sa\n", 3);
	else if (top1 == 0 && top2 == 3 && top3 == 2)
		write(1, "pb\npb\nss\npa\npa\n", 15);
	else if (top1 == 2 && top2 == 0 && top3 == 3)
		write(1, "pb\nsa\npa\nsa\n", 12);
	else if (top1 == 2 && top2 == 3 && top3 == 0)
		write(1, "rra\n", 4);
	else if (top1 == 3 && top2 == 0 && top3 == 2)
		write(1, "rra\nsa\nrra\n", 11);
	else if (top1 == 3 && top2 == 2 && top3 == 0)
		write(1, "pb\nsa\npa\nrra\n", 13);
}

static void	_4_2(int top1, int top2, int top3)
{
	if (top1 == 0 && top2 == 1 && top3 == 3)
		write(1, "sa\nra\nsa\nrra\n", 13);
	else if (top1 == 0 && top2 == 3 && top3 == 1)
		write(1, "sa\nrra\nsa\n", 10);
	else if (top1 == 1 && top2 == 0 && top3 == 3)
		write(1, "sa\npb\nsa\npa\nsa\n", 15);
	else if (top1 == 1 && top2 == 3 && top3 == 0)
		write(1, "sa\nrra\n", 7);
	else if (top1 == 3 && top2 == 0 && top3 == 1)
		write(1, "ra\nra\n", 6);
	else if (top1 == 3 && top2 == 1 && top3 == 0)
		write(1, "ra\nra\nsa\n", 9);
}

static void	_4_3(int top1, int top2, int top3)
{
	if (top1 == 0 && top2 == 1 && top3 == 2)
		write(1, "ra\n", 3);
	else if (top1 == 0 && top2 == 2 && top3 == 1)
		write(1, "ra\npb\nsa\npa\n", 12);
	else if (top1 == 1 && top2 == 0 && top3 == 2)
		write(1, "ra\nsa\n", 6);
	else if (top1 == 1 && top2 == 2 && top3 == 0)
		write(1, "rra\nsa\nra\n", 10);
	else if (top1 == 2 && top2 == 0 && top3 == 1)
		write(1, "sa\nra\nra\n", 9);
	else if (top1 == 2 && top2 == 1 && top3 == 0)
		write(1, "sa\nra\nra\nsa\n", 12);
}

void	do_len_4(int *arr)
{
	int	top0;
	int	top1;
	int	top2;
	int	top3;

	top0 = idx_when_sorted(arr, arr[0], 4);
	top1 = idx_when_sorted(arr, arr[1], 4);
	top2 = idx_when_sorted(arr, arr[2], 4);
	top3 = idx_when_sorted(arr, arr[3], 4);
	if (top0 == 0)
	{
		write(1, "pb\n", 3);
		do_len_3(arr + 1);
		write(1, "pa\n", 3);
	}
	else if (top0 == 1)
		_4_1(top1, top2, top3);
	else if (top0 == 2)
		_4_2(top1, top2, top3);
	else
		_4_3(top1, top2, top3);
}
