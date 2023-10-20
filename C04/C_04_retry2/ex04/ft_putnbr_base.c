/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoyoon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:45:36 by hyoyoon           #+#    #+#             */
/*   Updated: 2023/09/02 21:35:04 by hyoyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *base)
{
	int	len;

	len = 0;
	while (base[len] != '\0')
		len++;
	return (len);
}

int	not_valid(char	*base)
{
	char	*current;
	char	*cmp;

	current = base;
	if (*current == '\0' || str_len(base) == 1)
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
	int			digit;

	num = (long long) nbr;
	digit = str_len(base);
	if (not_valid(base))
		return ;
	if (0 <= nbr && nbr < digit)
	{
		write(1, &base[nbr], 1);
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
