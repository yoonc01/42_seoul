/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:45:36 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/03 17:45:27 by hyoyoon          ###   ########.fr       */
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

int	not_valid(char	*base)
{
	char	*current;
	char	*cmp;

	current = base;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (*current != '\0')
	{
		if (*current == '+' || *current == '-')
			return (1);
		cmp = current + 1;
		while (*cmp != '\0')
		{
			if (*current == *cmp)
				return (1);
			cmp++;
		}
		current++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	num;
	long long	digit;

	num = (long long) nbr;
	digit = (long long) str_len(base);
	if (not_valid(base))
		return ;
	if (0 <= num && num < digit)
	{
		write(1, &base[num], 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		num = -1 * num;
	}
	ft_putnbr_base(num / digit, base);
	write(1, &base[num % digit], 1);
}
