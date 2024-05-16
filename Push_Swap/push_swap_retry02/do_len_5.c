/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_len_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:27:40 by yunhyojun         #+#    #+#             */
/*   Updated: 2024/05/15 23:28:32 by yunhyojun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_len_5(int *arr)
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
