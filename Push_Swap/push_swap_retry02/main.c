/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:27:25 by hyoyoon           #+#    #+#             */
/*   Updated: 2024/05/16 15:03:18 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_arr(int *arr, int *sorted_arr)
{
	free(arr);
	free(sorted_arr);
}

static void	check_input_sorted(int *arr, int *sorted_arr, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		if (arr[idx] != sorted_arr[idx])
			return ;
		idx++;
	}
	exit(EXIT_SUCCESS);
}

static char	**join_av_and_split(int ac, char **av)
{
	int		i;
	char	*join_result;
	char	*temp;
	char	**split_result;

	i = 1;
	while (i < ac)
	{
		if (i == 1)
			join_result = strjoin("", av[i]);
		else
		{
			temp = strjoin(join_result, av[i]);
			free(join_result);
			join_result = temp;
		}
		i++;
	}
	split_result = split(join_result);
	free(join_result);
	return (split_result);
}

static int	*get_arr(char **split, int len)
{
	int	idx;
	int	*result;

	idx = 0;
	result = (int *)malloc(sizeof(int) * len);
	if (result == 0)
		exit(EXIT_FAILURE);
	while (idx < len)
	{
		result[idx] = my_atoi(split[idx]);
		free(split[idx]);
		idx++;
	}
	free(split);
	return (result);
}

int	main(int ac, char **av)
{
	int		len;
	int		*arr;
	int		*sorted_arr;
	char	**splited;

	len = 0;
	if (ac == 1)
		exit(EXIT_FAILURE);
	splited = join_av_and_split(ac, av);
	while (splited[len] != 0)
		len++;
	arr = get_arr(splited, len);
	sorted_arr = sorted(arr, len);
	check_input_sorted(arr, sorted_arr, len);
	do_low_swap(arr, len);
	do_push_swap(arr, sorted_arr, len);
	free_arr(arr, sorted_arr);
}
