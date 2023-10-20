/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:49:44 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/03 16:10:42 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	str_sort(char *str, int size)
{
	int		i;
	int		j;
	int		min_idx;
	char	temp;

	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if ((unsigned char) str[min_idx] > (unsigned char) str[j])
				min_idx = j;
			j++;
		}
		temp = str[i];
		str[i] = str[min_idx];
		str[min_idx] = temp;
		i++;
	}
}

void	print_str(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		str_sort(argv[i], str_len(argv[i]));
		print_str(argv[i]);
		i++;
	}
}
