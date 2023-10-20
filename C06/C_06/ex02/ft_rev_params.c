/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:40:50 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/03 16:09:55 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	str_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*reverse_arr(char *str, unsigned int size)
{
	char	temp;
	int		idx;

	idx = 0;
	while (idx < size / 2)
	{
		temp = str[idx];
		str[idx] = str[size - idx - 1];
		str[size - idx - 1] = temp;
		idx++;
	}
	return (str);
}

void	print_arr(char *str)
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
		print_arr(reverse_arr(argv[i], str_len(argv[i])));
		i++;
	}
}
