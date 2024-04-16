/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:42:00 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/04/16 18:02:37 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_dq(t_deque *dq1, t_deque *dq2)
{
	while (dq1->front != 0)
		delete_front(dq1);
	free(dq1);
	free(dq2);
}

void	free_split(char **split)
{
	int	idx;

	idx = 0;
	while (split[idx] != 0)
	{
		free(split[idx]);
		idx++;
	}
	free(split);
}

void	free_arr(int *arr, int *sorted_arr)
{
	free(arr);
	free(sorted_arr);
}
