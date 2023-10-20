/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseuki <minseuki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:21:11 by minseuki          #+#    #+#             */
/*   Updated: 2023/09/03 14:36:35 by minseuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_up(int size, int *result[], int col)
{
	int	i;
	int	height;
	int	cnt;

	i = -1;
	cnt = 0;
	height = 0;
	while (i++ < size -1)
	{
		if (height < result[i][col])
		{
			height = result[i][col];
			cnt++;
		}
	}
	return (cnt);
}

int	count_down(int size, int *result[], int col)
{
	int	i;
	int	height;
	int	cnt;

	i = size;
	cnt = 0;
	height = 0;
	while (i-- > 0)
	{
		if (height < result[i][col])
		{
			height = result[i][col];
			cnt++;
		}
	}
	return (cnt);
}

int	count_left(int size, int *result[], int row)
{
	int	i;
	int	height;
	int	cnt;

	i = -1;
	cnt = 0;
	height = 0;
	while (i++ < size -1)
	{
		if (height < result[row][i])
		{
			height = result[row][i];
			cnt ++;
		}
	}
	return (cnt);
}

int	count_right(int size, int *result[], int row)
{
	int	i;
	int	height;
	int	cnt;

	i = size;
	cnt = 0;
	height = 0;
	while (i-- > 0)
	{
		if (height < result[row][i])
		{
			height = result[row][i];
			cnt++;
		}
	}
	return (cnt);
}

int	check_build(int *input[], int *result[], int row, int col)
{
	int	size;
	int	i;

	size = 0;
	i = -1;
	while (input[0][size] != 0)
		size ++;
	while (i++ < size -1)
	{
		if (i != row && result[i][col] == result[row][col])
			return (0);
		if (i != col && result[row][i] == result[row][col])
			return (0);
	}
	if (row == size -1 && (count_down(size, result, col) != input[1][col]
		|| count_up(size, result, col) != input[0][col]))
		return (0);
	if (col == size -1 && (count_right(size, result, row) != input[3][row]
		|| count_left(size, result, row) != input[2][row]))
		return (0);
	return (1);
}
