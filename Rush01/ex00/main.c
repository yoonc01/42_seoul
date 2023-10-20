/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseuki <minseuki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:43:06 by minseuki          #+#    #+#             */
/*   Updated: 2023/09/03 15:22:40 by minseuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	rush01(int *input[], int size);
int		str_len(char *str);
void	free_input(int **input);
int		get_argv(char *str, int *arr, int **input);

int	main(int argc, char *argv[])
{
	int	**input;
	int	*arr;
	int	i;
	int	size;

	if (argc != 2 || 37 <= (str_len(argv[1]) + 1) / 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	size = ((str_len(argv[1]) + 1) / 2);
	i = -1;
	arr = (int *) malloc(sizeof (int) * size);
	input = (int **) malloc(sizeof (int *) * 4);
	while (i++ < 3)
		input[i] = (int *) malloc(sizeof (int) * (size / 4 + 1));
	if (get_argv(argv[1], arr, input) == 0)
	{
		free_input(input);
		write(1, "Error\n", 6);
		return (0);
	}
	rush01(input, size / 4);
	free_input(input);
	return (0);
}

void	free_input(int **input)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(input[i]);
		i ++;
	}
	free(input);
}
