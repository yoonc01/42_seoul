/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:32:39 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/08/28 13:30:21 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (' ' <= str[i] && str[i] <= '~')
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[(str[i]) / 16], 1);
			write(1, &"0123456789abcdef"[(str[i]) % 16], 1);
		}
		i++;
	}
}
