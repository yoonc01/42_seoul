/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:23:38 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/04 10:19:21 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	int_to_char(int	*arr, char *ans)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ans[i] = arr[i] + '0';
		i++;
	}
}

int	check(int row, int column, int	*arr)
{
	int	left_d;
	int	middle;
	int	right_d;
	int	std;

	left_d = column - 1;
	middle = column;
	right_d = column + 1;
	std = row - 1;
	while (0 <= std)
	{
		if (arr[std] == left_d || arr[std] == middle || arr[std] == right_d)
			return (0);
		std--;
		left_d--;
		right_d++;
	}
	return (1);
}

void	recursive(int *arr, char *ans, int row, int *cnt)
{
	int	i;

	i = 0;
	if (row == 10)
	{
		int_to_char(arr, ans);
		write(1, ans, 10);
		write(1, "\n", 1);
		(*cnt)++;
		return ;
	}
	while (i < 10)
	{
		arr[row] = i;
		if (check(row, i, arr))
			recursive(arr, ans, row + 1, cnt);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		cnt[1];
	int		arr[10];
	char	ans[10];

	recursive(arr, ans, 0, cnt);
	return (*cnt);
}
