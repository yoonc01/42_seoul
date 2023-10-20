/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseuki <minseuki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:32:24 by minseuki          #+#    #+#             */
/*   Updated: 2023/09/03 18:19:26 by minseuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	num_arr(char *str, int *arr)
{
	int	len;
	int	even;
	int	max;

	len = str_len(str);
	if ((len + 1) % 8 != 0)
		return (0);
	even = 1;
	max = (len + 1) / 8;
	while (*str != '\0')
	{
		if (even)
		{
			if ('1' <= *str && *str <= ('0' + max))
				*arr = *str - '0';
			else
				return (0);
			arr++;
		}
		else if (*str != ' ')
			return (0);
		str++;
		even = !even;
	}
	return (1);
}

int	get_argv(char *str, int *arr, int **input)
{
	int	num;
	int	i;
	int	j;

	num = (str_len(str) + 1) / 8;
	i = 0;
	if (arr == 0 || input == 0 || num_arr(str, arr) == 0)
		return (0);
	while (i < 4)
	{
		if (input[i] == 0)
			return (0);
		j = 0;
		while (j <= num)
		{
			if (j == num)
				input[i][j] = 0;
			else
				input[i][j] = arr[i * num + j];
			j++;
		}
		i++;
	}
	return (1);
}
