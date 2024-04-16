/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:03:22 by yunhyojun         #+#    #+#             */
/*   Updated: 2024/04/16 17:10:56 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_pa(t_deque *dq1, t_deque *dq2, int data)
{
	insert_front(dq1, data);
	delete_front(dq2);
	write(1, "pa\n", 3);
}

static void	do_pb(t_deque *dq1, t_deque *dq2, int data)
{
	insert_front(dq2, data);
	delete_front(dq1);
	write(1, "pb\n", 3);
}

static void	do_ra(t_deque *dq1, int data)
{
	insert_rear(dq1, data);
	delete_front(dq1);
	write(1, "ra\n", 3);
}

void	do_swap(t_deque *dq1, t_deque *dq2, int len, int bit)
{
	int	idx;
	int	data;
	int	moved;

	idx = 0;
	moved = 0;
	while (idx < len)
	{
		data = dq1->front->data;
		if ((data & bit) == 0)
		{
			do_pb(dq1, dq2, data);
			moved++;
		}
		else
			do_ra(dq1, data);
		idx++;
	}
	while (0 < moved)
	{
		data = dq2->front->data;
		do_pa(dq1, dq2, data);
		moved--;
	}
}
