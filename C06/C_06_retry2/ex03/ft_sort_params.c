/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:49:44 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/03 19:27:59 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_cmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return (1);
	else
		return (-1);
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
	int		i;
	int		j;
	int		min_idx;
	char 	*temp;
	
	i = 1;
	while (i < argc - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < argc)
		{
			if (str_cmp(argv[min_idx], argv[j]) > 0)
				min_idx = j;
			j++;
		}
		temp = argv[i];
		argv[i] = argv[min_idx];
		argv[min_idx] = temp;
		i++;
	}
	i = 1;
	while (i < argc)
	{
		print_str(argv[i]);
		i++;
	}
}
