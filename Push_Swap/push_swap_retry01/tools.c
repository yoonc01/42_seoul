/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhyojun <hyoyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:35:18 by yunhyojun         #+#    #+#             */
/*   Updated: 2024/05/12 16:55:39 by hyoyoon          ###   ########.fr       */
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

void	print_ans(int *ans, int len)
{
	char	**cmd;
	int		idx;

	cmd = (char **)malloc(sizeof(char *) * 3);
	if (cmd == 0)
		exit(EXIT_FAILURE);
	cmd[0] = "sa\n";
	cmd[1] = "ra\n";
	cmd[2] = "rra\n";
	idx = 0;
	while (idx < len)
	{
		if (ans[idx] != 2)
			write(1, cmd[ans[idx]], 3);
		else
			write(1, cmd[ans[idx]], 4);
		idx++;
	}
}

int	check_sorted(int *arr, int len)
{
	int	idx;

	idx = 0;
	while (idx < len - 1)
	{
		if (arr[idx] > arr[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}

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
