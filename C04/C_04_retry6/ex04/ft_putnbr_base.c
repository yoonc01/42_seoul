/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:45:36 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/05 16:11:09 by hyoyoon          ###   ########.fr       */
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

void	positive(int nb, char *base, int digit)
{
	int	idx;

	if (0 <= nb && nb < digit)
	{
		write(1, &base[nb], 1);
		return ;
	}
	positive(nb / digit, base, digit);
	idx = nb % digit;
	write(1, &base[idx], 1);
}

void	negative(int nb, char *base, int digit)
{
	int	idx;

	if (-digit + 1 <= nb && nb <= 0)
	{
		write(1, &base[-nb], 1);
		return ;
	}
	negative(nb / digit, base, digit);
	idx = -(nb % digit);
	write(1, &base[idx], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	digit;

	digit = str_len(base);
	if (not_valid(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		negative(nbr, base, digit);
	}
	else
		positive(nbr, base, digit);
}
