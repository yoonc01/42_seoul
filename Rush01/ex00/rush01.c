/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseuki <minseuki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:53:57 by minseuki          #+#    #+#             */
/*   Updated: 2023/09/03 18:13:28 by minseuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

int	check_build(int *input[], int *result[], int row, int col);

int	check_null(int *result[], int size)
{
	int	i;

	i = 0;
	if (result == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (i < size)
	{
		if (result[i] == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

void	print_result(int *result[], int size)
{
	int		i;
	int		j;
	char	result_char;

	i = 0;
	if (result[size][0])
		return ;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			result_char = result[i][j] + '0';
			write(1, &result_char, 1);
			if (j != size -1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			j++;
		}
		i++;
	}
}

void	solve(int *input[], int *result[], int row, int col)
{
	int	i;
	int	size;

	size = 0;
	while (input[0][size] != 0)
		size++;
	i = 0;
	if (row == size)
	{
		print_result(result, size);
		result[size][0] = 1;
		return ;
	}
	while (i++ < size)
	{
		result[row][col] = i;
		if (check_build(input, result, row, col))
		{
			if (col == size -1)
				solve(input, result, row + 1, 0);
			else
				solve(input, result, row, col + 1);
		}
		result[row][col] = 0;
	}
}

void	rush01(int *input[], int size)
{
	int	**result;
	int	i;
	int	j;

	i = -1;
	j = -1;
	result = (int **) malloc(sizeof (int *) * (size + 1));
	while (i++ < size)
		result[i] = (int *) malloc(sizeof (int) * (size + 1));
	if (!check_null(result, size +1))
		return ;
	i = -1;
	while (i++ < size)
	{
		while (j++ < size -1)
			result[i][j] = 0;
	}
	solve(input, result, 0, 0);
	if (!result[size][0])
		write(1, "Error\n", 6);
	i = -1;
	while (i++ < size)
		free(result[i]);
	free(result);
}
